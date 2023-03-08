package com.example.socialnetworkgradlejavafx.validators;


import com.example.socialnetworkgradlejavafx.domain.Friendship;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;

public class FriendshipValidator extends BaseValidator<Friendship> {

    @Override
    public void validate(Friendship friendship) throws ValidationException {
        if (friendship.getIdUser1() == null || friendship.getIdUser2() == null) {
            throw new ValidationException("At least one user is invalid!Invalid friendship!\n");
        }
    }
}
