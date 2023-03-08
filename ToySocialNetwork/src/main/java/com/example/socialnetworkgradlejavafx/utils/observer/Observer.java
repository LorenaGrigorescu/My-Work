package com.example.socialnetworkgradlejavafx.utils.observer;


import com.example.socialnetworkgradlejavafx.utils.events.Event;

public interface Observer <E extends Event> {
    void update (E e);
}

