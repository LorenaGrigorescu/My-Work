package com.example.socialnetworkgradlejavafx.repository.file;

import com.example.socialnetworkgradlejavafx.domain.Friendship;
import com.example.socialnetworkgradlejavafx.repository.file.AbstractFileRepository;


import java.time.LocalDateTime;

public class FriendshipFileRepository extends AbstractFileRepository<Long, Friendship> {
    public FriendshipFileRepository(String filepath) {
        super(filepath);
    }

    @Override
    public Friendship buildEntity(String[] arguments) {
        try {
            Long friendshipID = Long.valueOf(arguments[0]);
            Long firstUserID = Long.valueOf(arguments[1]);
            Long secondUserID = Long.valueOf(arguments[2]);
            LocalDateTime friendsFrom = LocalDateTime.parse(arguments[3]);
            return new Friendship(friendshipID, firstUserID, secondUserID, friendsFrom);
        } catch (NumberFormatException | ArrayIndexOutOfBoundsException exception) {
            return null;
        }
    }
}

