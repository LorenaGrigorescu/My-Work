package com.example.socialnetworkgradlejavafx.controller;

import com.example.socialnetworkgradlejavafx.domain.Friendship;
import com.example.socialnetworkgradlejavafx.exception.ExistingException;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.service.FriendshipService;
import com.example.socialnetworkgradlejavafx.utils.events.EntityChangeEvent;
import com.example.socialnetworkgradlejavafx.utils.observer.Observer;
import javafx.beans.property.SimpleLongProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.time.LocalDateTime;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

public class FriendshipController implements Observer<EntityChangeEvent> {

    private final ObservableList<Friendship> friendshipsModel = FXCollections.observableArrayList();
    private FriendshipService friendshipService;

    @FXML
    private TableView<Friendship> friendshipTableView;
    @FXML
    private TableColumn<Friendship, Long> idFriendshipColumn;
    @FXML
    private TableColumn<Friendship, Long> idUser1Column;
    @FXML
    private TableColumn<Friendship, Long> idUser2Column;
    @FXML
    private TableColumn<Friendship, String> localDateTimeColumn;

    @FXML
    private TextField idFriendshipTF;
    @FXML
    private TextField idUser1TF;
    @FXML
    private TextField idUser2TF;
    @FXML
    private TextField localDateTimeTF;
    @FXML
    public Button goBackToMenu;

    private Long loggedUser = -1L;


    private Friendship selectedFriendship = null;

    @FXML
    private void initialize() {
        idUser1Column.setCellValueFactory(p -> new SimpleLongProperty(p.getValue().getIdUser1()).asObject());
        idUser2Column.setCellValueFactory(p -> new SimpleLongProperty(p.getValue().getIdUser2()).asObject());
        localDateTimeColumn.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getFriendsFrom().toString()));
        friendshipTableView.setItems(friendshipsModel);
    }

    private void clearTextFields() {
        idUser1TF.clear();
        idUser2TF.clear();
        localDateTimeTF.clear();
    }

    private void initModel() {
        Iterable<Friendship> friendships = friendshipService.getAllByID(loggedUser);
        List<Friendship> friendshipList = StreamSupport.stream(friendships.spliterator(), false).collect(Collectors.toList());
        friendshipsModel.setAll(friendshipList);
    }


    public void setService(FriendshipService friendshipService) {
        this.friendshipService = friendshipService;
        friendshipService.addObserver(this);
        initModel();
    }

    public void setUserID(Long userID) {
        loggedUser = userID;
    }


    @Override
    public void update(EntityChangeEvent entityChangeEvent) {
        initModel();
    }

    public void onAddFriendshipButton(ActionEvent actionEvent) {
        String idUser1 = idUser1TF.getText();
        String idUser2 = idUser2TF.getText();
        localDateTimeTF.setText(LocalDateTime.now().toString());
        String localDateTime = localDateTimeTF.getText();
        try {
            this.friendshipService.addFriendship("0", idUser1, idUser2, LocalDateTime.parse(localDateTime));
        } catch (ValidationException | ExistingException e) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText(e.getMessage());
            alert.showAndWait();
            clearTextFields();
            return;
        }
        clearTextFields();
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Success!");
        alert.setHeaderText("Addition successfully done!");
        alert.showAndWait();
    }


    public void onDeleteFriendshipButton(ActionEvent actionEvent) {
        if (selectedFriendship == null) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText("No friendship was selected!");
            alert.showAndWait();
            return;
        }
        clearTextFields();
        friendshipService.deleteEntity(selectedFriendship.getId());
        selectedFriendship = null;
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Success!");
        alert.setHeaderText("Deletion successfully done!");
        alert.showAndWait();
    }

    public void onUpdateFriendshipButton(ActionEvent actionEvent) {
        if (selectedFriendship == null) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText("No friendship was selected!");
            alert.showAndWait();
            return;
        }
        selectedFriendship.setIdUser1(Long.valueOf(idUser1TF.getText()));
        selectedFriendship.setIdUser2(Long.valueOf(idUser2TF.getText()));
        selectedFriendship.setFriendsFrom(LocalDateTime.parse(localDateTimeTF.getText()));
        if (idUser1TF.getText().equals(idUser2TF.getText())) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText("No user can be friend with himself!");
            alert.showAndWait();
            return;
        }
        clearTextFields();
        try {
            friendshipService.updateFriendship(selectedFriendship.getId().toString(), selectedFriendship.getIdUser1().toString(), selectedFriendship.getIdUser2().toString(), LocalDateTime.parse(selectedFriendship.getFriendsFrom().toString()));
        } catch (IllegalArgumentException | ValidationException e) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText(e.getMessage());
            alert.showAndWait();
            return;
        }
        selectedFriendship = null;
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Success!");
        alert.setHeaderText("Update successfully done!");
        alert.showAndWait();
    }

    public void onSelectedRow(MouseEvent mouseEvent) {
        var selectedRow = friendshipTableView.getSelectionModel().getSelectedItem();
        idUser1TF.setText(selectedRow.getIdUser1().toString());
        idUser2TF.setText(selectedRow.getIdUser2().toString());
        localDateTimeTF.setText(selectedRow.getFriendsFrom().toString());
        selectedFriendship = selectedRow;
    }

    public void onGoBackToMenu(ActionEvent actionEvent) {
        Stage stage = (Stage) goBackToMenu.getScene().getWindow();
        stage.close();
    }


}
