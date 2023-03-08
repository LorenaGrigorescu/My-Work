package com.example.socialnetworkgradlejavafx.controller;

import com.example.socialnetworkgradlejavafx.domain.Chat;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.service.ChatsService;
import com.example.socialnetworkgradlejavafx.utils.events.EntityChangeEvent;
import com.example.socialnetworkgradlejavafx.utils.observer.Observable;
import com.example.socialnetworkgradlejavafx.utils.observer.Observer;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.stage.Stage;

import java.sql.SQLException;
import java.time.LocalDateTime;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

public class ChatsController implements Observer<EntityChangeEvent> {

    private final ObservableList<Chat> chatsModel = FXCollections.observableArrayList();

    private ChatsService chatsService;

    @FXML
    private TableView<Chat> chatsTableView;

    @FXML
    private TableColumn<Chat, String> usernameColumn;

    @FXML
    private TableColumn<Chat, String> messageColumn;

    @FXML
    private TableColumn<Chat, String> sentAtColumn;

    @FXML
    private TableColumn<Chat, String> toWhomColumn;

    @FXML
    private TextField usernameTF;

    @FXML
    private TextField messageTF;

    private Long loggedUser = 1L;

    @FXML
    public Button goBackToYourFriends;

    public void setLoggedUser(Long loggedUser) {
        this.loggedUser = loggedUser;
    }

    @FXML
    public void initialize() {
        usernameColumn.setCellValueFactory(p -> new SimpleStringProperty(this.chatsService.getUsernameByID(p.getValue().getIduser1())));
        messageColumn.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getMessage()));
        sentAtColumn.setCellValueFactory(p -> new SimpleStringProperty(String.valueOf(p.getValue().getSentAt())));
        toWhomColumn.setCellValueFactory(p -> new SimpleStringProperty(this.chatsService.getUsernameByID(p.getValue().getIduser2())));
        chatsTableView.setItems(chatsModel);
    }

    @Override
    public void update(EntityChangeEvent entityChangeEvent) {
        initModel();
    }

    public void setService(ChatsService chatsService) {
        this.chatsService = chatsService;
        this.chatsService.addObserver(this);
        initModel();
    }

    private void initModel() {
        Iterable<Chat> chats = chatsService.getAllChats(loggedUser);
        List<Chat> chatList = StreamSupport.stream(chats.spliterator(), false).collect(Collectors.toList());
        chatsModel.setAll(chatList);
    }


    public void onAddChat(ActionEvent actionEvent) {
        String username = usernameTF.getText();
        String message = messageTF.getText();
        LocalDateTime sentAt = LocalDateTime.now();
        Long iduser2 = -1L;
        try {
            iduser2 = this.chatsService.getUserID(username);
            messageTF.clear();
        } catch (ValidationException | SQLException exception) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText("There is no such user with this username!\n");
            usernameTF.clear();
            messageTF.clear();
            alert.showAndWait();
        }
        try {
            if (iduser2 != -1)
                this.chatsService.addChat(loggedUser, iduser2, message, sentAt);
        } catch (
                ValidationException validationException) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText(validationException.getMessage());
            alert.showAndWait();
        }
    }

    public void onGoBackToYourFriends(ActionEvent actionEvent) {
        Stage stage = (Stage) goBackToYourFriends.getScene().getWindow();
        stage.close();

    }
}

