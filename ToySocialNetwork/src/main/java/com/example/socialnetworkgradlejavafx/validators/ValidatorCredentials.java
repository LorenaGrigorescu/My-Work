package com.example.socialnetworkgradlejavafx.validators;

import com.example.socialnetworkgradlejavafx.domain.UserCredentials;
import com.example.socialnetworkgradlejavafx.exception.ExceptionCredentials;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ValidatorCredentials  {
    public static void validateCredential(UserCredentials userCredentials) throws ExceptionCredentials {
        String errors = "";
//        Pattern usernamePattern = Pattern.compile(" ^[a-zA-Z0-9]([._-](?![._-])|[a-zA-Z0-9]){3,18}[a-zA-Z0-9]$");
        Pattern usernamePattern = Pattern.compile("^_{0,4}[a-zA-Z0-9]{2,18}[_-]{0,4}$");
        Matcher usernameMatcher = usernamePattern.matcher(userCredentials.getUsername());
//        Pattern passwordPattern = Pattern.compile("^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])(?=.*[!@#&()–[{}]:;',?/*~$^+=<>]).{8,20}$");
        Pattern passwordPattern = Pattern.compile("^_{0,4}[a-zA-Z0-9]{2,18}[_-]{0,4}$");
        Matcher passwordMatcher = passwordPattern.matcher(userCredentials.getPassword());
        if (userCredentials.getUsername().isEmpty())
            errors += "Invalid username!\n";
        if (!usernameMatcher.find())
            errors += "Username doesn't match with the pattern!\n";
        if (userCredentials.getPassword().isEmpty())
            errors += "Invalid password!\n";
        if (!passwordMatcher.find())
            errors += "Password doesn't match with the pattern!\n";
        if (!errors.isEmpty()) {
            throw new ExceptionCredentials(errors);
        }
    }
}
