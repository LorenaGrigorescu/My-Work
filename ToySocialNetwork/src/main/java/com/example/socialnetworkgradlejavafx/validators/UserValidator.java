package com.example.socialnetworkgradlejavafx.validators;


import com.example.socialnetworkgradlejavafx.domain.User;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;

public class UserValidator extends BaseValidator<User> {
    @Override
    public void validate(User user) throws ValidationException {
        String errors = "";
        if(!this.validateString(user.getName()))
        {
            errors += "Invalid name!\n";
        }
        if(!this.validateEmail(user.getEmail()))
        {
            errors += "Invalid email!\n";
        }
        if(!errors.equals(""))
        {
            throw new ValidationException(errors);
        }
    }
}
