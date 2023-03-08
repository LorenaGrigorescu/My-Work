package com.example.socialnetworkgradlejavafx.repository.file;


import com.example.socialnetworkgradlejavafx.domain.User;

public class UserFileRepository extends AbstractFileRepository<Long, User> {

    public UserFileRepository(String filepath) {
        super(filepath);
    }

    @Override
    User buildEntity(String[] arguments) throws NumberFormatException, ArrayIndexOutOfBoundsException{
        try {
            Long userID = Long.valueOf(arguments[0]);
            return new User(userID, arguments[1], arguments[2], arguments[3]);
        } catch (NumberFormatException | ArrayIndexOutOfBoundsException exception) {
            exception.getMessage();
            return null;
        }
    }
}
