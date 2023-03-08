package com.example.socialnetworkgradlejavafx.service;

import com.example.socialnetworkgradlejavafx.domain.Friendship;
import com.example.socialnetworkgradlejavafx.domain.FriendshipREnum;
import com.example.socialnetworkgradlejavafx.domain.FriendshipRequest;
import com.example.socialnetworkgradlejavafx.domain.User;
import com.example.socialnetworkgradlejavafx.exception.ExistingException;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.repository.Repository;
import com.example.socialnetworkgradlejavafx.repository.db.DBFriendshipRequestRepository;
import com.example.socialnetworkgradlejavafx.repository.db.DBUserCredentialsRepository;
import com.example.socialnetworkgradlejavafx.utils.events.ChangeEventType;
import com.example.socialnetworkgradlejavafx.utils.events.EntityChangeEvent;
import com.example.socialnetworkgradlejavafx.utils.observer.Observable;
import com.example.socialnetworkgradlejavafx.validators.ValidatorType;

import java.time.LocalDateTime;
import java.util.List;
import java.util.stream.Collectors;

public class FriendshipRequestService extends BaseEntityService<Long, FriendshipRequest> implements Observable<EntityChangeEvent> {
    private final Repository<Long, User> userRepository;

    private final DBFriendshipRequestRepository friendshipRequestRepository;
    private final DBUserCredentialsRepository dbUserCredentialsRepository;



    public FriendshipRequestService(DBFriendshipRequestRepository entityRepository, Repository<Long, User> userRepository, DBUserCredentialsRepository dbUserCredentialsRepository) {
        super(ValidatorType.FRIENDSHIPREQUEST, entityRepository);
        this.userRepository = userRepository;
        this.friendshipRequestRepository = entityRepository;
        this.dbUserCredentialsRepository=dbUserCredentialsRepository;
    }

    public void addFriendshipRequest(String idFriendship, String idUser1, String idUser2, LocalDateTime friendsFrom, FriendshipREnum friendshipREnum) throws ValidationException {
        Converters instance = Converters.getInstance();
        Long _idFriendship = Long.parseLong(idFriendship);
        if(this.friendshipRequestRepository.searchFriendship(Long.valueOf(idUser1), Long.valueOf(idUser2)))
        {
            throw new ExistingException("There is already a friendship between them\n");
        }
        FriendshipRequest friendshipRequest = instance.getFriendshipRequest(_idFriendship, idUser1, idUser2, friendsFrom, friendshipREnum);
//        Friendship friendship = instance.getFriendship(_idFriendship, idUser1, idUser2, friendsFrom);
        Friendship friendship = new Friendship(friendshipRequest.getId(), friendshipRequest.getIdUser1(), friendshipRequest.getIdUser2(), friendshipRequest.getFriendsFrom());
        if (userRepository.findOne(friendship.getIdUser1()) == null)
            throw new ExistingException("There is no such user1!\n");
        if (userRepository.findOne(friendship.getIdUser2()) == null)
            throw new ExistingException("There is no such user2!\n");

        super.addEntity(friendshipRequest);
        this.notifyObservers(new EntityChangeEvent(ChangeEventType.ADD, friendshipRequest));
        return;
    }

    public FriendshipRequest updateFriendship(String idFriendship, String idUser1, String idUser2, LocalDateTime friendsFrom, FriendshipREnum friendshipREnum) throws IllegalArgumentException, ValidationException {
        Converters converters = Converters.getInstance();
        Long _idFriendship = Long.valueOf(idFriendship);
        FriendshipRequest friendshipRequest = converters.getFriendshipRequest(_idFriendship, idUser1, idUser2, friendsFrom, friendshipREnum);
        var friendship = super.updateEntity(friendshipRequest);
        this.notifyObservers(new EntityChangeEvent(ChangeEventType.UPDATE, friendshipRequest));
        return friendship;

    }

    public List<FriendshipRequest> getAllByID(Long loggedUserId) {
        return friendshipRequestRepository.findAll().stream()
                .filter(friendshipRequest -> friendshipRequest.getIdUser1().equals(loggedUserId) || friendshipRequest.getIdUser2().equals(loggedUserId))
                .collect(Collectors.toList());
    }

    public String getUsernameByID(Long idUser)
    {
        return this.dbUserCredentialsRepository.getUsernameById(idUser);
    }

    public int deleteFriendship(Long idUser1, Long idUser2)
    {
        var bool =  this.friendshipRequestRepository.deleteFriendship(idUser1, idUser2);
        this.notifyObservers(new EntityChangeEvent(ChangeEventType.DELETE, null));
        return bool;
    }

}