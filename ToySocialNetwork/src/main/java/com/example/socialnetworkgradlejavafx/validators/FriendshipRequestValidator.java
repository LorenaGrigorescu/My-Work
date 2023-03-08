package com.example.socialnetworkgradlejavafx.validators;

import com.example.socialnetworkgradlejavafx.domain.FriendshipRequest;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;

public class FriendshipRequestValidator extends BaseValidator<FriendshipRequest> {
    @Override
    public void validate(FriendshipRequest friendship) throws ValidationException {
        if (friendship.getIdUser1() == null || friendship.getIdUser2() == null) {
            throw new ValidationException("At least one user is invalid!Invalid friendship!\n");
        }
    }
}
