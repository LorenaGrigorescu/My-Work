package com.example.socialnetworkgradlejavafx;

import com.example.socialnetworkgradlejavafx.domain.Friendship;
import com.example.socialnetworkgradlejavafx.domain.User;
import com.example.socialnetworkgradlejavafx.exception.ExistingException;
import com.example.socialnetworkgradlejavafx.repository.Repository;
import com.example.socialnetworkgradlejavafx.repository.db.DBFriendshipRepository;
import com.example.socialnetworkgradlejavafx.repository.db.DBUserRepository;
import com.example.socialnetworkgradlejavafx.repository.file.FriendshipFileRepository;
import com.example.socialnetworkgradlejavafx.repository.file.UserFileRepository;
import com.example.socialnetworkgradlejavafx.repository.memory.InMemoryRepository;
import com.example.socialnetworkgradlejavafx.service.FriendshipService;
import com.example.socialnetworkgradlejavafx.service.UserService;
import com.example.socialnetworkgradlejavafx.tests.Test;
import com.example.socialnetworkgradlejavafx.tests.TestEnum;
import com.example.socialnetworkgradlejavafx.tests.TestFactory;
import com.example.socialnetworkgradlejavafx.ui.ConsoleUI;

public class Main {
    public static void main(String[] args) {
        try {
            TestFactory testFactory = TestFactory.getInstance();
//            CapabilitiesFilter.Test repositoryTest = testFactory.createTest(TestEnum.REPOSITORY);
//            repositoryTest.runAll();
            Test serviceTest = testFactory.createTest(TestEnum.SERVICE);
            serviceTest.runAll();
        } catch (ExistingException exception) {
        }
        Repository<Long, User> InMemoryUserRepository = new InMemoryRepository<>();
        Repository<Long, Friendship> InMemoryFriendshipRepository = new InMemoryRepository<>();
        Repository<Long, User> InFileUserRepository = new UserFileRepository("C:\\Users\\Lorena\\Desktop\\Anul 2-FMI UBB Cluj\\Metode Avansate de Programare\\LABORATOARE\\SocialNetworkGradle\\src\\main\\resources\\users.csv");
        Repository<Long, Friendship> InFileFriendshipRepository = new FriendshipFileRepository("C:\\Users\\Lorena\\Desktop\\Anul 2-FMI UBB Cluj\\Metode Avansate de Programare\\LABORATOARE\\SocialNetworkGradle\\src\\main\\resources\\friendships.csv");

        String url = "jdbc:postgresql://localhost:5432/SocialNetwork";
        String username = "postgres";
        String password = "postgres";
        Repository<Long, User> dbUserRepository = new DBUserRepository(url, username, password);
        DBFriendshipRepository dbFriendshipRepository = new DBFriendshipRepository(url, username, password);
//        UserService userService = new UserService(InMemoryUserRepository, InMemoryFriendshipRepository);
//        UserService userService = new UserService(InFileUserRepository, InMemoryFriendshipRepository);
        UserService userService = new UserService(dbUserRepository, dbFriendshipRepository);
//        FriendshipService friendshipService = new FriendshipService(InMemoryFriendshipRepository, InMemoryUserRepository);
//        FriendshipService friendshipService = new FriendshipService(InFileFriendshipRepository, InFileUserRepository);
        FriendshipService friendshipService = new FriendshipService(dbFriendshipRepository, dbUserRepository);
        ConsoleUI consoleUI = new ConsoleUI(userService, friendshipService);
        consoleUI.showUI();
    }
}