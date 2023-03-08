package com.example.socialnetworkgradlejavafx.domain;

import java.time.LocalDateTime;

public class RequestDTO {
    private String username;
    private LocalDateTime friendsFrom;
    private FriendshipREnum requestType;

    public RequestDTO(String username, LocalDateTime friendsFrom, FriendshipREnum requestType) {
        this.username = username;
        this.friendsFrom = friendsFrom;
        this.requestType = requestType;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public LocalDateTime getFriendsFrom() {
        return friendsFrom;
    }

    public void setFriendsFrom(LocalDateTime friendsFrom) {
        this.friendsFrom = friendsFrom;
    }

    public FriendshipREnum getRequestType() {
        return requestType;
    }

    public void setRequestType(FriendshipREnum requestType) {
        this.requestType = requestType;
    }
}
