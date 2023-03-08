package com.example.socialnetworkgradlejavafx.utils.events;

import com.example.socialnetworkgradlejavafx.domain.Entity;

public class EntityChangeEvent implements Event {
    private final ChangeEventType type;
    private final Entity data;


    public EntityChangeEvent(ChangeEventType type, Entity data) {
        this.type = type;
        this.data = data;
    }

    public ChangeEventType getType() {
        return type;
    }

    public Entity getData() {
        return data;
    }
}
