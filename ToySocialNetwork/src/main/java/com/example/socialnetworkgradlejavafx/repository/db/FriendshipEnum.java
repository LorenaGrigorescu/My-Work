package com.example.socialnetworkgradlejavafx.repository.db;

public enum FriendshipEnum {
    ID, USER1, USER2, DATE_TIME;

    public String getSqlValue() {
        switch (this) {
            case ID:
                return "idfriendship";
            case USER1:
                return "iduser1";
            case USER2:
                return "iduser2";
            case DATE_TIME:
                return "localDateTime";
            default:
                return "";
        }
    }
}
