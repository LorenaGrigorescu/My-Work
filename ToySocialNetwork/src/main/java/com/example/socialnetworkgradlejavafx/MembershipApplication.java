package com.example.socialnetworkgradlejavafx;

import com.example.socialnetworkgradlejavafx.controller.ChatsController;
import com.example.socialnetworkgradlejavafx.controller.FriendshipRequestController;
import com.example.socialnetworkgradlejavafx.controller.MembershipController;
import com.example.socialnetworkgradlejavafx.repository.db.*;
import com.example.socialnetworkgradlejavafx.service.ChatsService;
import com.example.socialnetworkgradlejavafx.service.FriendshipRequestService;
import com.example.socialnetworkgradlejavafx.service.RequestDTOService;
import com.example.socialnetworkgradlejavafx.service.UserCredentialsService;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.io.IOException;

public class MembershipApplication extends Application {

    @Override
    public void start(Stage stage) throws IOException {
        String url = "jdbc:postgresql://localhost:5432/SocialNetwork";
        String username = "postgres";
        String password = "postgres";

        DBUserCredentialsRepository dbUserCredentialsRepository = new DBUserCredentialsRepository(url, username, password);
        DBUserRepository dbUserRepository = new DBUserRepository(url, username, password);
        DBFriendshipRequestRepository dbFriendshipRequestRepository = new DBFriendshipRequestRepository(url, username, password);
        RequestDTORepository dtoRepository = new RequestDTORepository(url, username, password);
        DBChats dbChats = new DBChats(url, username, password);
        FXMLLoader fxmlLoaderMembership = new FXMLLoader(MembershipApplication.class.getResource("hello-viewMembership.fxml"));
        FXMLLoader fxmlLoaderRegister = new FXMLLoader(MembershipApplication.class.getResource("hello-viewRegister.fxml"));
        FXMLLoader fxmlLoaderFriendshipRequest = new FXMLLoader(MembershipApplication.class.getResource("hello-viewFriendshipRequest.fxml"));
        Scene membershipScene = new Scene(fxmlLoaderMembership.load(), 800, 480);
        Scene registerScene = new Scene(fxmlLoaderRegister.load(), 800, 480);
        Scene friendshipRequestScene = new Scene(fxmlLoaderFriendshipRequest.load(), 800, 480);

        MembershipController membershipController = fxmlLoaderMembership.getController();
        MembershipController registerController = fxmlLoaderRegister.getController();
        UserCredentialsService userCredentialsService = new UserCredentialsService(dbUserCredentialsRepository);
        FriendshipRequestService friendshipRequestService = new FriendshipRequestService(dbFriendshipRequestRepository, dbUserRepository, dbUserCredentialsRepository);
        RequestDTOService requestDTOService = new RequestDTOService(dtoRepository);
        ChatsService chatsService = new ChatsService(dbChats);
        membershipController.setService(userCredentialsService);
        membershipController.setServiceFriendship(friendshipRequestService);
        membershipController.setServiceDTO(requestDTOService);
        membershipController.setServiceChats(chatsService);
        registerController.setService(userCredentialsService);

        stage.setTitle("LogIn or Registration");
        stage.setScene(friendshipRequestScene);
        stage.setScene(registerScene);
        stage.setScene(membershipScene);
        stage.resizableProperty().setValue(false);
        stage.initStyle(StageStyle.UNDECORATED);
        stage.show();

    }

}
