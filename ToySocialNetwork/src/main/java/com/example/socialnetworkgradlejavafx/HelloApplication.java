package com.example.socialnetworkgradlejavafx;

import com.example.socialnetworkgradlejavafx.controller.FriendshipController;
import com.example.socialnetworkgradlejavafx.controller.MainGUIController;
import com.example.socialnetworkgradlejavafx.controller.UserController;
import com.example.socialnetworkgradlejavafx.domain.User;
import com.example.socialnetworkgradlejavafx.repository.Repository;
import com.example.socialnetworkgradlejavafx.repository.db.DBFriendshipRepository;
import com.example.socialnetworkgradlejavafx.repository.db.DBUserRepository;
import com.example.socialnetworkgradlejavafx.service.FriendshipService;
import com.example.socialnetworkgradlejavafx.service.UserService;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.io.IOException;
import java.util.Objects;

public class HelloApplication extends Application {


    @Override
    public void start(Stage stage) throws IOException {
        String url = "jdbc:postgresql://localhost:5432/SocialNetwork";
        String username = "postgres";
        String password = "postgres";
        Repository<Long, User> dbUserRepository = new DBUserRepository(url, username, password);
        DBFriendshipRepository dbFriendshipRepository = new DBFriendshipRepository(url, username, password);

        FXMLLoader fxmlLoaderUser = new FXMLLoader(HelloApplication.class.getResource("hello-viewUsers.fxml"));
        FXMLLoader fxmlLoaderFriendship = new FXMLLoader(HelloApplication.class.getResource("hello-viewFriendships.fxml"));

        Scene sceneUser = new Scene(fxmlLoaderUser.load(), 800, 480);
        UserController userController = fxmlLoaderUser.getController();
        UserService userService = new UserService(dbUserRepository, dbFriendshipRepository);
        userController.setService(userService);
//        stage.setTitle("Users");

        Scene sceneFriendship = new Scene(fxmlLoaderFriendship.load(), 800, 480);
        FriendshipController friendshipController = fxmlLoaderFriendship.getController();
        FriendshipService friendshipService = new FriendshipService(dbFriendshipRepository, dbUserRepository);
        friendshipController.setService(friendshipService);
//        stage.setTitle("Friendships");
        stage.setScene(sceneUser);
        stage.setScene(sceneFriendship);
//        stage.show();

        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-viewMainGUI.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 800, 480);
        MainGUIController mainGUIController = fxmlLoader.getController();
        mainGUIController.setService(userService, friendshipService);
        stage.setTitle("All");
        stage.setScene(scene);
        stage.resizableProperty().setValue(false);
        stage.initStyle(StageStyle.UNDECORATED);
        stage.show();
    }

    @FXML
    public static void main(String[] args) {
        launch();
    }
}