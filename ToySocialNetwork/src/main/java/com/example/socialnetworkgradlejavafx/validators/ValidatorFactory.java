package com.example.socialnetworkgradlejavafx.validators;

public class ValidatorFactory {
    private static ValidatorFactory instance;

    private ValidatorFactory() {
    }

    public Validators createValidator(ValidatorType validatorType) {
        if (validatorType.equals(ValidatorType.USER))
            return new UserValidator();
        if(validatorType.equals(ValidatorType.FRIENDSHIP))
        return new FriendshipValidator();
        return new FriendshipRequestValidator();
    }

    public static ValidatorFactory getInstance() {
        if (instance == null) {
            instance = new ValidatorFactory();
            return instance;
        }
        return instance;
    }
}
