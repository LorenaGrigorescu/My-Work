package com.example.socialnetworkgradlejavafx.tests;

import java.security.Provider;
import java.time.LocalDateTime;

public class ServiceTest implements Test {
    public ServiceTest() {

    }

    @Override
    public void runAll() {
//        Repository<Long, User> userRepository = new InMemoryRepository<>();
//        Repository<Long, Friendship> friendshipRepository = new InMemoryRepository<>();
//        Validators<User> userValidators = new UserValidator();
//        Validators<Friendship> friendshipValidators = new FriendshipValidator();
//        UserService userService = new UserService(userRepository, friendshipRepository);
//        FriendshipService friendshipService = new FriendshipService(friendshipRepository, userRepository);
//
//        Long userID1 = Long.valueOf(1);
//        String userName1 = "Adrian";
//        String userLastName1 = "Despot";
//        String userEmail1 = "adrian_22@gmail.com";
//        User firstUser = new User(userID1, userName1, userLastName1, userEmail1);
//
//        Long userID2 = Long.valueOf(2);
//        String userName2 = "Daniela";
//        String userLastName2 = "Chira";
//        String userEmail2 = "daniela_dana@gmail.com";
//        User secondUser = new User(userID2, userName2, userLastName2, userEmail2);
//
//        userRepository.save(firstUser);
//        userRepository.save(secondUser);
//
//        assert userService.getAll().size() == 2;
//
//        userService.deleteUser(Long.valueOf(1));
//        assert userService.getAll().size() == 1;
//
//        try {
//            friendshipService.addFriendship(Long.valueOf(1).toString(), firstUser.getIdUser().toString(), secondUser.getIdUser().toString(), LocalDateTime.now());
//        } catch (ValidationException exception) {
//            System.out.println(exception.getMessage());
//        }
//        assert friendshipService.getAll().size() == 1;
//        friendshipService.deleteEntity(Long.valueOf(1));
//        assert friendshipService.getAll().size() == 0;


    }
}
