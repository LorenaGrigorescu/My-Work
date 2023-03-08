package com.example.socialnetworkgradlejavafx.controller;

import com.example.socialnetworkgradlejavafx.HelloApplication;
import com.example.socialnetworkgradlejavafx.service.FriendshipService;
import com.example.socialnetworkgradlejavafx.service.UserService;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import javafx.stage.StageStyle;
import org.controlsfx.control.action.Action;

import java.io.IOException;
import java.util.Objects;

public class MainGUIController {


    @FXML
    private UserService userService;
    @FXML
    private FriendshipService friendshipService;

    //    @FXML
//    public Button buttonMainClose;
    @FXML


    public void setService(UserService userService, FriendshipService friendshipService) {
        this.userService = userService;
        this.friendshipService = friendshipService;
    }


    public void SeeOtherUsers(ActionEvent actionEvent) {
        try {
            FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-viewUsers.fxml"));
            Scene scene = new Scene(fxmlLoader.load(), 800, 480);
            Stage stage = new Stage();
            UserController userController = fxmlLoader.getController();
            userController.setService(userService);
            stage.setTitle("Users");
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

    public void SeeMyFriends(ActionEvent actionEvent) {
        try {
            FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-viewFriendships.fxml"));
            Scene scene = new Scene(fxmlLoader.load(), 800, 480);
            Stage stage = new Stage();
            FriendshipController friendshipController = fxmlLoader.getController();
            friendshipController.setService(friendshipService);
            stage.setTitle("Friendships");
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
