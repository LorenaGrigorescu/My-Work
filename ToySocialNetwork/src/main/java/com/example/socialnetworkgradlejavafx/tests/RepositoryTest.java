package com.example.socialnetworkgradlejavafx.tests;


public abstract class RepositoryTest implements Test {

//    public RepositoryTest() {
//    }
//
//    @Override
//    public void runAll() throws ValidationException {
//        Repository<Long, User> userRepository = new InMemoryRepository<>();
//        Repository<Long, Friendship> friendshipRepository = new InMemoryRepository<>();
//        Validators<User> userValidators = new UserValidator();
//        Validators<Friendship> friendshipValidators = new FriendshipValidator();
//        User firstUser, secondUser, thirdUser;
//        try {
//            Long userID = Long.valueOf(1);
//            String userName = "Adrian";
//            String userLastname = "Despot";
//            String userEmail = "adrian_22@gmail.com";
//            firstUser = new User(userID, userName, userLastname, userEmail);
//            assert firstUser.getIdUser() == userID;
//            assert firstUser.getName() == userName;
//            assert firstUser.getMail() == userEmail;
//            userValidators.validate(firstUser);
//            userRepository.save(firstUser);
//        } catch (ValidationException validationException) {
//        }
//
//        try {
//            Long userID = Long.valueOf(2);
//            String userName = "Daniela";
//            String userLastname = "Chira";
//            String userEmail = "";
//            secondUser = new User(userID, userName, userLastname, userEmail);
//            assert secondUser.getIdUser() == userID;
//            assert secondUser.getName() == userName;
//            assert secondUser.getLastname() == userLastname;
//            assert secondUser.getMail() == userEmail;
//            userValidators.validate(secondUser);
//            userRepository.save(secondUser);
//        } catch (ValidationException validationException) {
//        }
//
//        try {
//            Long userID = Long.valueOf(3);
//            String userName = "Daniela";
//            String userLastname = "Chira";
//            String userEmail = "daniela_dana@gmail.com";
//            thirdUser = new User(userID, userName, userLastname, userEmail);
//            assert thirdUser.getIdUser() == userID;
//            assert thirdUser.getName() == userName;
//            assert thirdUser.getLastname() == userLastname;
//            assert thirdUser.getMail() == userEmail;
//            userValidators.validate(thirdUser);
//            userRepository.save(thirdUser);
//        } catch (ValidationException validationException) {
//        }
//        assert userRepository.findAll().size() == 2;
//        try {
//            Long userIdDeleted = userRepository.delete(Long.valueOf(1));
//            assert userIdDeleted == 1;
//            assert userRepository.findAll().size() == 1;
//        } catch (ValidationException exception) {
//        }
//        try {
//            Long userIdDeleted = userRepository.delete(Long.valueOf(1));
//            assert userIdDeleted == 1;
//            assert userRepository.findAll().size() == 1;
//        } catch (ValidationException exception) {
//        }
//        Long userID = Long.valueOf(1);
//        String userName = "Adrian";
//        String userLastName = "Despot";
//        String userEmail = "adrian_22@gmail.com";
//        firstUser = new User(userID, userName, userLastName, userEmail);
//        userRepository.save(firstUser);
//    }
}
