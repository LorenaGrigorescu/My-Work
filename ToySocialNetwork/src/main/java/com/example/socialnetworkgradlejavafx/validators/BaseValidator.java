package com.example.socialnetworkgradlejavafx.validators;

import com.example.socialnetworkgradlejavafx.exception.ValidationException;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public abstract class BaseValidator<T> implements Validators<T> {
    public abstract void validate(T t) throws ValidationException;

    protected boolean validateString (String string)
    {
        return string.length()!=0 && string.matches("[a-zA-Z-]+") && !string.trim().isEmpty();
    }

    protected boolean validateEmail(String email)
    {
        String emailRegex = "^[A-Za-z0-9.-_]+@{1,1}(.+)$";
        Pattern pattern = Pattern.compile(emailRegex);
        Matcher matcher = pattern.matcher(email);
        return matcher.matches();
    }

}
