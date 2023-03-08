package com.example.socialnetworkgradlejavafx.service;

import com.example.socialnetworkgradlejavafx.domain.User;
import com.example.socialnetworkgradlejavafx.domain.UserCredentials;
import com.example.socialnetworkgradlejavafx.exception.ExceptionCredentials;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.exception.ValidationExceptionCredentials;
import com.example.socialnetworkgradlejavafx.repository.db.DBUserCredentialsRepository;
import com.example.socialnetworkgradlejavafx.validators.UserValidator;
import com.example.socialnetworkgradlejavafx.validators.ValidatorCredentials;

import javax.security.auth.login.CredentialException;
import java.util.List;

public class UserCredentialsService {
    private final DBUserCredentialsRepository dbUserCredentialsRepository;
    private final UserValidator userValidator = new UserValidator();

    public UserCredentialsService(DBUserCredentialsRepository dbUserCredentialsRepository) {
        this.dbUserCredentialsRepository = dbUserCredentialsRepository;
    }

    public void addUserCredentials(String username, String password, String name, String lastname, String email) throws CredentialException, ValidationException, ExceptionCredentials {
        UserCredentials userCredentials = new UserCredentials(1L, username, password);
        User user = new User(1L, email, name, lastname);
        ValidatorCredentials.validateCredential(userCredentials);
        userValidator.validate(user);
        this.dbUserCredentialsRepository.addUserCredentials(userCredentials, user);
    }

    public void deleteUserCredentials(Long idUser) {
        this.dbUserCredentialsRepository.deleteUserCredentials(idUser);
    }

    public boolean findOne(String username) {
        return this.dbUserCredentialsRepository.findOne(username);
    }

    public boolean findPassword(String username, String password) {
        return this.dbUserCredentialsRepository.findPassword(username, password);
    }

    public Long getUserID(String username)
    {
        return this.dbUserCredentialsRepository.getUserID(username);
    }

    public String getUsernameById(Long idUser){return  this.dbUserCredentialsRepository.getUsernameById(idUser);}


}
