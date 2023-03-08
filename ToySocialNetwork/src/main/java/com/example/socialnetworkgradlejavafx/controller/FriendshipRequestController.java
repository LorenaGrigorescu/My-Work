package com.example.socialnetworkgradlejavafx.controller;

import com.example.socialnetworkgradlejavafx.MembershipApplication;
import com.example.socialnetworkgradlejavafx.domain.*;
import com.example.socialnetworkgradlejavafx.exception.ExistingException;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.service.*;
import com.example.socialnetworkgradlejavafx.utils.events.EntityChangeEvent;
import com.example.socialnetworkgradlejavafx.utils.observer.Observable;
import com.example.socialnetworkgradlejavafx.utils.observer.Observer;
import javafx.beans.binding.SetBinding;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.io.IOException;
import java.time.LocalDateTime;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

public class FriendshipRequestController implements Observer<EntityChangeEvent> {
    private final ObservableList<RequestDTO> friendshipRequestsModel = FXCollections.observableArrayList();
    private final ObservableList<String> usernamesModel = FXCollections.observableArrayList();
    private FriendshipRequestService friendshipRequestService;
    private RequestDTOService requestDTOService;

    private ChatsService chatsService;


    @FXML
    private TableView<RequestDTO> friendshipRequestTableView;

    @FXML
    private TableView<String> tableView;

    @FXML
    private TableColumn<String, String> usernames;


    @FXML
    private TableColumn<RequestDTO, String> usernameFriendColumn;
    @FXML
    private TableColumn<RequestDTO, String> localDateTimeColumn;
    @FXML
    private TableColumn<RequestDTO, String> statusFriendshipColumn;

    @FXML
    private Button goBackToMenu;

    @FXML
    private Button sendFriendRequestButton;

    @FXML
    private Label myusernameLabel;
    @FXML
    private Label mydateautentificationLabel;

    private Long loggedUser = 1L;

    @FXML
    private TextField usernameToAddTF;
    private String currentSelectedUsername = "";


    @FXML
    private void initialize() {
        usernameFriendColumn.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getUsername()));
        localDateTimeColumn.setCellValueFactory(p -> new SimpleStringProperty(String.valueOf(p.getValue().getFriendsFrom())));
        statusFriendshipColumn.setCellValueFactory(p -> new SimpleStringProperty(String.valueOf(p.getValue().getRequestType())));
        mydateautentificationLabel.setText(String.valueOf(LocalDateTime.now()));
        usernames.setCellValueFactory(p -> new SimpleStringProperty(p.getValue()));

        friendshipRequestTableView.setItems(friendshipRequestsModel);
        tableView.setItems(usernamesModel);
    }


    public void setService(FriendshipRequestService friendshipRequestService, RequestDTOService requestDTOService) {
        this.friendshipRequestService = friendshipRequestService;
        this.requestDTOService = requestDTOService;
        friendshipRequestService.addObserver(this);
        this.findUserLogged(loggedUser);
        initModel();
        initModelUsername();
    }


    public void setService(RequestDTOService requestDTOService) {
        this.requestDTOService = requestDTOService;
        initModel();
        initModelUsername();
    }

    public void setService(ChatsService chatsService)
    {
        this.chatsService=chatsService;
        initModel();
        initModelUsername();
    }


    public void setUserID(Long userID) {
        loggedUser = userID;
    }

    public String findUserLogged(Long loggedUser) {
        String username = this.friendshipRequestService.getUsernameByID(loggedUser);
        this.myusernameLabel.setText(username);
        return username;
    }

    private void initModel() {
        Iterable<RequestDTO> friendshipsRequest = this.requestDTOService.findAll(loggedUser);
        List<RequestDTO> friendshipList = StreamSupport.stream(friendshipsRequest.spliterator(), false).collect(Collectors.toList());
        friendshipRequestsModel.setAll(friendshipList);

    }

    private void initModelUsername() {
        Iterable<String> usernames = this.requestDTOService.findAllUsernames();
        List<String> usernamesList = StreamSupport.stream(usernames.spliterator(), false).collect(Collectors.toList());
        usernamesModel.setAll(usernamesList);
    }

    @Override
    public void update(EntityChangeEvent entityChangeEvent) {
        initModel();
        initModelUsername();
    }


    public void onGoBackToMenu(ActionEvent actionEvent) {
        Stage stage = (Stage) goBackToMenu.getScene().getWindow();
        stage.close();

    }

    public void onSelectUsernameToAddFriend(MouseEvent mouseEvent) {
        Long idUserFound = -1L;
        tableView.getSelectionModel().setCellSelectionEnabled(true);
        TablePosition tablePosition = tableView.getSelectionModel().getSelectedCells().get(0);
        var username = tablePosition.getTableColumn().getCellData(tablePosition.getRow());
        usernameToAddTF.setText(username.toString());
        currentSelectedUsername = usernameToAddTF.getText();
        if (!Objects.equals(currentSelectedUsername, "")) {
            idUserFound = this.requestDTOService.getIdUserByUsername(currentSelectedUsername);
        }
        try {
            this.friendshipRequestService.addFriendshipRequest("1", loggedUser.toString(), idUserFound.toString(), LocalDateTime.now(), FriendshipREnum.PENDING);
            var ListOfMembers = this.requestDTOService.findAllUsernames();
            ListOfMembers.remove(currentSelectedUsername);
            currentSelectedUsername = "";
        } catch (ValidationException | ExistingException exception) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText(exception.getMessage());
            alert.showAndWait();

        }
    }

    public void onAcceptFriendship(ActionEvent actionEvent) {
        Long idFound = -1L;
        friendshipRequestTableView.getSelectionModel().setCellSelectionEnabled(true);
        TablePosition tablePositionName = friendshipRequestTableView.getSelectionModel().getSelectedCells().get(0);
        friendshipRequestTableView.getSelectionModel().setCellSelectionEnabled(false);
        var username = tablePositionName.getTableColumn().getCellData(tablePositionName.getRow());
        currentSelectedUsername = username.toString();
        if (!Objects.equals(currentSelectedUsername, ""))
            idFound = this.requestDTOService.getIdUserByUsername(currentSelectedUsername);
        try {
            this.friendshipRequestService.updateFriendship("1", loggedUser.toString(), idFound.toString(), LocalDateTime.now(), FriendshipREnum.ACCEPTED);
        } catch (IllegalArgumentException | ValidationException e) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText(e.getMessage());
            alert.showAndWait();
        }

    }

    public void onDeleteFriendship(ActionEvent actionEvent) {
        Long idFound = -1L;
        friendshipRequestTableView.getSelectionModel().setCellSelectionEnabled(true);
        TablePosition tablePositionName = friendshipRequestTableView.getSelectionModel().getSelectedCells().get(0);
        friendshipRequestTableView.getSelectionModel().setCellSelectionEnabled(false);
        var username = tablePositionName.getTableColumn().getCellData(tablePositionName.getRow());
        currentSelectedUsername = username.toString();
        if (!Objects.equals(currentSelectedUsername, "")) {
            idFound = this.requestDTOService.getIdUserByUsername(currentSelectedUsername);
            this.friendshipRequestService.deleteFriendship(loggedUser, idFound);
        }

    }

    public void onSendMessage(ActionEvent actionEvent) {
        try {
            FXMLLoader fxmlLoader = new FXMLLoader(MembershipApplication.class.getResource("hello-viewChats.fxml"));
            Scene scene = new Scene(fxmlLoader.load(), 800, 480);
            Stage stage = new Stage();
            ChatsController chatsController = fxmlLoader.getController();
            chatsController.setLoggedUser(loggedUser);
            chatsController.setService(chatsService);
            stage.setTitle("Chats");
            stage.setScene(scene);
            stage.initStyle(StageStyle.UNDECORATED);
            stage.show();
        } catch (IOException ioException) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText(ioException.getMessage());
            alert.showAndWait();
        }
    }
}
