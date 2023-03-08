package com.example.socialnetworkgradlejavafx.ui;





import com.example.socialnetworkgradlejavafx.domain.User;
import com.example.socialnetworkgradlejavafx.exception.ExistingException;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.service.FriendshipService;
import com.example.socialnetworkgradlejavafx.service.UserService;
import com.example.socialnetworkgradlejavafx.ui.UI;

import java.sql.SQLException;
import java.time.LocalDateTime;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class ConsoleUI implements UI {
    private final UserService userService;
    private final FriendshipService friendshipService;

    public ConsoleUI(UserService userService, FriendshipService friendshipService) {
        this.userService = userService;
        this.friendshipService = friendshipService;
    }

    private void showMenu() {
        System.out.println("What's your option?");
        System.out.println("0: prints all the users and their friendships");
        System.out.println("1 idUser emailUser nameUser lastnameUser : adds an user");
        System.out.println("2 friendshipUser idUser1 idUser2: creates a friendship between those users");
        System.out.println("3 userID: deletes the user with the specified id");
        System.out.println("4 friendshipID: deletes the friendship with the specified id");
        System.out.println("5: prints the number of the communities");
        System.out.println("6: prints the most sociable community");
        System.out.println("7: updates an user, if this existits");
        System.out.println("8: updates a friendship if this existits");
        System.out.println("9: exit");
    }

    private void addUser(String idUser, String emailUser, String nameUser, String lastNameUser) {
        try {
            userService.addUser(idUser, emailUser, nameUser, lastNameUser);
        } catch (ValidationException | ExistingException e) {
            System.out.println(e.getMessage());
        } catch (NumberFormatException exception) {
            System.out.println("Enter a valid user id!\n");
        }
    }

    private void deleteUser(String idUser) {
        try {
            Long _idUser = Long.parseLong(idUser);
            userService.deleteUser(_idUser);
        } catch (NumberFormatException exception) {
            System.out.println("Enter a valid user id!\n");
        } catch (ExistingException exception) {
            System.out.println(exception.getMessage());
        }
    }

    private void addFriendship(String idFriendship, String idUser1, String idUser2) {
        try {
            friendshipService.addFriendship(idFriendship, idUser1, idUser2, LocalDateTime.now());
        } catch (ExistingException ex) {
            System.out.println(ex.getMessage());
        } catch (ValidationException e) {
            System.out.println(e.getMessage());
//            throw new RuntimeException(e);
        }
    }

    private void deleteFriendship(String id) {
        try {
            friendshipService.deleteEntity(Long.parseLong(id));
        } catch (NumberFormatException ex) {
            ex.printStackTrace();
        } catch (ExistingException ex) {
            System.out.println(ex.getMessage());
        }
    }

    private void showUsers() {
        System.out.println("          USERS          ");
        for (User user : userService.getAll()) {
            System.out.println(user.toString());
        }
    }

    private void showFriendships() {
        System.out.println("          FRIENDSHIPS          ");
        Map<User, List<User>> allUsersandFriends = friendshipService.getAllUsersandFriends();
        allUsersandFriends.forEach((key, value) -> {
            System.out.println(key.getName() + " is friend with: ");
            for (User user : value) {
                System.out.println(user.getName() + " ");
            }
        });
    }

    private void updateUser(String userId, String userMail, String userName, String userLastName) {
        try {
            userService.updateUser(userId, userName, userMail, userLastName);
        } catch (IllegalArgumentException | ExistingException exception) {
            System.out.println(exception.getMessage());
        }
    }

    private void updateFriendship(String friendshipId, String idUser1, String idUser2) {
        try {
            friendshipService.updateFriendship(friendshipId, idUser1, idUser2, LocalDateTime.now());
        } catch (IllegalArgumentException | ValidationException | ExistingException exception) {
            System.out.println(exception.getMessage());
        }
    }

    @Override
    public void showUI() {
        Scanner in = new Scanner(System.in);
        while (true) {
            showMenu();
            String line = in.nextLine();
            List<String> arguments = List.of(line.split(" "));
            int option;
            try {
                option = Integer.parseInt(arguments.get(0));
            } catch (NumberFormatException exception) {
                continue;
            }
            boolean exited = false;
            switch (option) {
                case 0 -> {
                    showUsers();
                    showFriendships();
                }
                case 1 -> {
                    if (arguments.size() < 5) {
                        System.out.println("Not enough arguments!\n");
                        continue;
                    }
                    addUser(arguments.get(1), arguments.get(2), arguments.get(3), arguments.get(4));
                }
                case 2 -> {
                    if (arguments.size() < 4) {
                        System.out.println("Not enough arguments!\n");
                        continue;
                    }
                    addFriendship(arguments.get(1), arguments.get(2), arguments.get(3));
                }
                case 3 -> {
                    if (arguments.size() < 2) {
                        System.out.println("Not enough arguments!\n");
                        continue;
                    }
                    deleteUser(arguments.get(1));
                }
                case 4 -> {
                    if (arguments.size() < 2) {
                        System.out.println("Not enough arguments!\n");
                        continue;
                    }
                    deleteFriendship(arguments.get(1));
                }
                case 5 -> {
                    this.showNumberOfComponents();
                }
                case 6 -> {
                    this.showTheLongestPath();
                }
                case 7 -> {
                    if (arguments.size() < 5) {
                        System.out.println("Not enough arguments!\n");
                        continue;
                    }
                    updateUser(arguments.get(1), arguments.get(2), arguments.get(3), arguments.get(4));

                }
                case 8 -> {
                    if (arguments.size() < 4) {
                        System.out.println("Not enough arguments!\n");
                        continue;
                    }
                    updateFriendship(arguments.get(1), arguments.get(2), arguments.get(3));
                }
                case 9 -> exited = true;
            }
            if (exited)
                break;

        }
    }

    private void showNumberOfComponents() {
        System.out.print("The number of communities is: ");
        var result = this.friendshipService.getConnectedComponents().size();
        System.out.println(result);
    }

    private void showTheLongestPath() {
        System.out.print("The longest path is: ");
        var result = this.friendshipService.getLongestPathComponent();
        System.out.println(result);
    }
}


