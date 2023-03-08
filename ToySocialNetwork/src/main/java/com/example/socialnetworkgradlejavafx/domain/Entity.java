package com.example.socialnetworkgradlejavafx.domain;

public class Entity<ID> {
    private ID id;

    public Entity(ID id) {
        this.id = id;
    }

    public void setId(ID id) {
        this.id = id;
    }

    public ID getId() {
        return id;
    }

    @Override
    public String toString() {
        return id+";";
    }
}
