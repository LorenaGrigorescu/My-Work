package com.example.socialnetworkgradlejavafx.controller;

import com.example.socialnetworkgradlejavafx.MembershipApplication;
import com.example.socialnetworkgradlejavafx.domain.Friendship;
import com.example.socialnetworkgradlejavafx.domain.UserCredentials;
import com.example.socialnetworkgradlejavafx.exception.ExceptionCredentials;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.exception.ValidationExceptionCredentials;
import com.example.socialnetworkgradlejavafx.service.*;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import javax.security.auth.login.CredentialException;
import java.io.IOException;
import java.util.List;
import java.util.Objects;

public class MembershipController {

    private UserCredentialsService userCredentialsService;

//    private FriendshipService friendshipService;
    private FriendshipRequestService friendshipRequestService;
    private RequestDTOService requestDTOService;

    private ChatsService chatsService;

    @FXML
    private TextField nameTF;
    @FXML
    private TextField lastnameTF;
    @FXML
    private TextField emailTF;
    @FXML
    private TextField usernameTF;
    @FXML
    private PasswordField passwordTF;

    @FXML
    private PasswordField confirmationPasswordTF;

    @FXML
    public Button signUpButton;
    @FXML
    public Button logInButton;

    @FXML
    public Button returnToLogin;


    private void clearTextFields() {
        usernameTF.clear();
        passwordTF.clear();
    }

    public void setService(UserCredentialsService userCredentialsService) {
        this.userCredentialsService = userCredentialsService;
    }

    public void setServiceFriendship(FriendshipRequestService friendshipService) {
        this.friendshipRequestService = friendshipService;
    }

    public void setServiceChats(ChatsService chatsService)
    {
        this.chatsService = chatsService;
    }

    public void setServiceDTO(RequestDTOService requestDTOService)
    {
        this.requestDTOService=requestDTOService;
    }


    public void onSignUp(ActionEvent actionEvent) {
        try {
            FXMLLoader fxmlLoader = new FXMLLoader(MembershipApplication.class.getResource("hello-viewRegister.fxml"));
            Scene scene = new Scene(fxmlLoader.load(), 800, 480);
            MembershipController membershipController = fxmlLoader.getController();
            membershipController.setService(userCredentialsService);
            Stage stage = new Stage();
            stage.setScene(scene);
            stage.resizableProperty().setValue(false);
            stage.initStyle(StageStyle.UNDECORATED);
            stage.show();
            return;
        } catch (IOException ioException) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText(ioException.getMessage());
            alert.showAndWait();
        }
    }

    public void onRegisterNow(ActionEvent actionEvent) {
        String name = nameTF.getText();
        String lastname = lastnameTF.getText();
        String email = emailTF.getText();
        String username = usernameTF.getText();
        String password = passwordTF.getText();
        String confirmationPassword = confirmationPasswordTF.getText();
        if (name.isEmpty() || lastname.isEmpty() || email.isEmpty() || username.isEmpty() || password.isEmpty() || confirmationPassword.isEmpty()) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText("There is at least one field which is not filled. Fill every field in the blank!");
            alert.showAndWait();
        }
        if (!Objects.equals(password, confirmationPassword)) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText("Password must be identic with the confirmation password!");
            alert.showAndWait();
        }
        if (this.userCredentialsService.findOne(username)) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setHeaderText("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText("This username already exists!\n");
            alert.showAndWait();
            return;
        }
        try {
            this.userCredentialsService.addUserCredentials(username, password, name, lastname, email);
            Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
            alert.setHeaderText("Congrats!");
            alert.setContentText("You are now member of our team! Go back to login with your credentials!\n");
            alert.showAndWait();
            this.clearTextFields();
        } catch (ValidationException | CredentialException | ExceptionCredentials exception) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occurred!");
            alert.setContentText(exception.getMessage());
            alert.showAndWait();
        }
    }

    public void onReturnToLogin(ActionEvent actionEvent) {
        Stage stage = (Stage) returnToLogin.getScene().getWindow();
        stage.close();
    }

    public void onLogin(ActionEvent actionEvent) {
        String username = usernameTF.getText();
        String password = passwordTF.getText();
        if (this.userCredentialsService.findOne(username) && !this.userCredentialsService.findPassword(username,password)) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occured!");
            alert.setContentText("There is already an user with this username!");
            alert.showAndWait();
        }
        if (!this.userCredentialsService.findOne(username) && !this.userCredentialsService.findPassword(username,password)) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("An error has occured!");
            alert.setContentText("There is no such user with these credentials!Go register now!");
            alert.showAndWait();
        }
        if (this.userCredentialsService.findOne(username) && this.userCredentialsService.findPassword(username,password)) {
            try {
                FXMLLoader fxmlLoader = new FXMLLoader(MembershipApplication.class.getResource("hello-viewFriendshipRequest.fxml"));
                Scene scene = new Scene(fxmlLoader.load(), 800, 480);
                Stage stage = new Stage();
//                FriendshipController friendshipController = fxmlLoader.getController();
                FriendshipRequestController friendshipRequestController = fxmlLoader.getController();
                Long idUser = userCredentialsService.getUserID(username);
                friendshipRequestController.setUserID(idUser);
                friendshipRequestController.setService(friendshipRequestService,requestDTOService);
                friendshipRequestController.setService(chatsService);
                stage.setTitle("My friendships!");
                stage.setScene(scene);
                stage.initStyle(StageStyle.UNDECORATED);
                stage.show();
                return;
            } catch (IOException ioException) {
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Error!");
                alert.setHeaderText("An error has occurred!");
                alert.setContentText(ioException.getMessage());
                alert.showAndWait();
            }

        }
    }
}
