package com.example.socialnetworkgradlejavafx.service;

import com.example.socialnetworkgradlejavafx.domain.Chat;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.repository.db.DBChats;
import com.example.socialnetworkgradlejavafx.utils.events.ChangeEventType;
import com.example.socialnetworkgradlejavafx.utils.events.EntityChangeEvent;
import com.example.socialnetworkgradlejavafx.utils.observer.Observable;
import com.example.socialnetworkgradlejavafx.utils.observer.Observer;

import java.sql.SQLException;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class ChatsService implements Observable<EntityChangeEvent> {
    private final DBChats dbChats;

    private final List<Observer<EntityChangeEvent>> observers = new ArrayList<>();

    public ChatsService(DBChats dbChats) {
        this.dbChats = dbChats;
    }

    public Chat addChat(Long iduser1, Long iduser2, String message, LocalDateTime sentAt) throws ValidationException {
        if (message.equals("")) {
            throw new ValidationException("Your message must not be empty!\n");
        }
        Chat chat = new Chat(1L, iduser1, iduser2, message, sentAt);
        var trimis = dbChats.addMessage(chat);
        this.notifyObservers(new EntityChangeEvent(ChangeEventType.ADD, chat));
        return trimis;
    }

    public List<Chat> getAllChats(Long loggedUser) {
        return dbChats.getChats(loggedUser);
    }


    @Override
    public void addObserver(Observer<EntityChangeEvent> e) {
        observers.add(e);
    }

    @Override
    public void removeOberver(Observer<EntityChangeEvent> e) {
        observers.remove(e);
    }

    @Override
    public void notifyObservers(EntityChangeEvent t) {
        observers.stream().forEach(x -> x.update(t));
    }

    public Long getUserID(String username) throws ValidationException, SQLException
    {
        Long iduser = this.dbChats.getUserID(username);
        if(iduser!=-1)
            return iduser;
        else {
            throw new ValidationException("There is no such user with this username!\n");
        }
    }

    public String getUsernameByID(Long iduser)
    {
        return this.dbChats.getUsernameById(iduser);
    }
}
