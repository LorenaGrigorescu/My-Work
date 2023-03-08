package com.example.socialnetworkgradlejavafx.utils.observer;

import com.example.socialnetworkgradlejavafx.utils.events.Event;

public interface Observable<E extends Event> {
    void addObserver(Observer<E> e);

    void removeOberver(Observer<E> e);

    void notifyObservers(E t);
}
