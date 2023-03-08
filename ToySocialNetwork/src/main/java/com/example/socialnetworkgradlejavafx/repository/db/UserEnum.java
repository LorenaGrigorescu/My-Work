package com.example.socialnetworkgradlejavafx.repository.db;

public enum UserEnum {
    ID, NAME, LASTNAME, EMAIL;


    public String getSqlValue() {
        switch (this) {
            case ID:
                return "idUser";
            case NAME:
                return "name";
            case LASTNAME:
                return "lastname";
            case EMAIL:
                return "email";
            default:
                return "";
        }

    }
}
