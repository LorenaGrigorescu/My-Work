package com.example.socialnetworkgradlejavafx.service;


import com.example.socialnetworkgradlejavafx.domain.Friendship;
import com.example.socialnetworkgradlejavafx.domain.User;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.repository.Repository;
import com.example.socialnetworkgradlejavafx.utils.events.ChangeEventType;
import com.example.socialnetworkgradlejavafx.utils.events.EntityChangeEvent;
import com.example.socialnetworkgradlejavafx.utils.observer.Observable;
import com.example.socialnetworkgradlejavafx.utils.observer.Observer;
import com.example.socialnetworkgradlejavafx.validators.ValidatorType;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class UserService extends BaseEntityService<Long, User> implements Observable<EntityChangeEvent> {
    private final Repository<Long, Friendship> friendshipRepository;
    private final Repository<Long, User> userRepository;
    private final List<Observer<EntityChangeEvent>> observers = new ArrayList<>();

    public UserService(Repository<Long, User> userRepository, Repository<Long, Friendship> friendshipRepository) {
        super(ValidatorType.USER, userRepository);
        this.friendshipRepository = friendshipRepository;
        this.userRepository=userRepository;
    }


    public void addUser(String idUser, String email, String name, String lastname) throws ValidationException {
        Converters instance = Converters.getInstance();
        User newUser = instance.getUser(idUser, email, name, lastname);
        super.addEntity(newUser);
        this.notifyObservers(new EntityChangeEvent(ChangeEventType.ADD, newUser));

    }

    public Long deleteUser(Long userId) {
        User deletedUser = userRepository.findOne(userId);
        Long deletedId = super.deleteEntity(userId);
        friendshipRepository.findAll().forEach(friendship -> {
                    if (Objects.equals(friendship.getIdUser1(), userId) || Objects.equals(friendship.getIdUser2(), userId)) {
                        friendshipRepository.delete(friendship.getId());
                    }
                });
        this.notifyObservers(new EntityChangeEvent(ChangeEventType.DELETE, deletedUser));
        return deletedId;
    }



    public User updateUser(String idUser, String email, String name, String lastname) throws IllegalArgumentException{
        Converters converters = Converters.getInstance();
        User user = converters.getUser(idUser, email, name, lastname);
        super.updateEntity(user);
        this.notifyObservers(new EntityChangeEvent(ChangeEventType.UPDATE, user));
        return user;
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
      observers.stream().forEach(x->x.update(t));
    }
}
