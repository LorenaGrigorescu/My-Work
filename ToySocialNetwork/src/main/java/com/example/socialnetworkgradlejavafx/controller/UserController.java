package com.example.socialnetworkgradlejavafx.controller;

import com.example.socialnetworkgradlejavafx.domain.User;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.service.UserService;
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

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

public class UserController implements Observer<EntityChangeEvent> {
    private final ObservableList<User> usersModel = FXCollections.observableArrayList();
    private UserService userService;
    @FXML
    private TableView<User> usersTableView;
    @FXML
    private TableColumn<User, Long> idColumn;
    @FXML
    private TableColumn<User, String> nameColumn;
    @FXML
    private TableColumn<User, String> lastnameColumn;
    @FXML
    private TableColumn<User, String> emailColumn;

    @FXML
    private TextField idTF;
    @FXML
    private TextField nameTF;
    @FXML
    private TextField lastnameTF;
    @FXML
    private TextField emailTF;

    private User selectedUser = null;

    @FXML
    public Button goBackToMenu;


    @FXML
    public void initialize() {

//       idColumn.setCellValueFactory(new PropertyValueFactory<>("idUser"));
//       nameColumn.setCellValueFactory(new PropertyValueFactory<>("name"));
//       lastnameColumn.setCellValueFactory(new PropertyValueFactory<>("lastname"));
//       emailColumn.setCellValueFactory(new PropertyValueFactory<>("email"));
        idColumn.setCellValueFactory(p -> new SimpleLongProperty(p.getValue().getIdUser()).asObject());
        nameColumn.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getName()));
        lastnameColumn.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getLastname()));
        emailColumn.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().getEmail()));
        usersTableView.setItems(usersModel);
    }

    private void clearTextFields() {
        nameTF.clear();
        lastnameTF.clear();
        emailTF.clear();
    }

    private void initModel() {
        Iterable<User> users = userService.getAll();
        List<User> userList = StreamSupport.stream(users.spliterator(), false).collect(Collectors.toList());
        usersModel.setAll(userList);
    }

    public void setService(UserService userService) {
        this.userService = userService;
        userService.addObserver(this);
        initModel();
    }

    @Override
    public void update(EntityChangeEvent entityChangeEvent) {
        initModel();
    }

    public void onAddUser(ActionEvent actionEvent) {
        String userName = nameTF.getText();
        String userLastname = lastnameTF.getText();
        String userEmail = emailTF.getText();
        try {
            this.userService.addUser("0", userEmail, userName, userLastname);
        } catch (ValidationException e) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText(e.getMessage());
            alert.showAndWait();
            return;
        }
        clearTextFields();
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Success!");
        alert.setHeaderText("Addition successfully done!");
        alert.showAndWait();
    }

    public void onDeleteUser(ActionEvent actionEvent) {
        if (selectedUser == null) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText("No user was selected!");
            alert.showAndWait();
            return;
        }
        clearTextFields();
        userService.deleteUser(selectedUser.getIdUser());
        selectedUser = null;
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Success!");
        alert.setHeaderText("Deletion successfully done!");
        alert.showAndWait();
    }

    public void onUpdateUser(ActionEvent actionEvent) {
        if (selectedUser == null) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText("No user was selected!");
            alert.showAndWait();
            return;
        }
        selectedUser.setName(nameTF.getText());

        selectedUser.setLastname(lastnameTF.getText());
        selectedUser.setEmail(emailTF.getText());
        clearTextFields();
        userService.updateUser(selectedUser.getIdUser().toString(), selectedUser.getEmail(), selectedUser.getName(), selectedUser.getLastname());
        selectedUser = null;
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Success!");
        alert.setHeaderText("Update successfully done!");
        alert.showAndWait();
    }

    public void onSelectedRow(MouseEvent mouseEvent) {
        var selectedRow = usersTableView.getSelectionModel().getSelectedItem();
        nameTF.setText(selectedRow.getName());
        lastnameTF.setText(selectedRow.getLastname());
        emailTF.setText(selectedRow.getEmail());
        selectedUser = selectedRow;
    }

    public void onGoBackToMenu(ActionEvent actionEvent) {
            Stage stage = (Stage)goBackToMenu.getScene().getWindow();
            stage.close();
    }
}