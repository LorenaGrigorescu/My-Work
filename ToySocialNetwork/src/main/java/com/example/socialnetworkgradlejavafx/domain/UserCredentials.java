package com.example.socialnetworkgradlejavafx.domain;

public class UserCredentials {
    private Long userId;
    private final String username;
    private final String password;

    public UserCredentials(Long userId, String username, String password) {
        this.userId = userId;
        this.username = username;
        this.password = password;
    }

    public void setUserId(Long userId) {
        this.userId = userId;
    }

    public Long getUserId() {
        return userId;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }
}
