package com.example.socialnetworkgradlejavafx.service;


import com.example.socialnetworkgradlejavafx.Graphs.Graphs;
import com.example.socialnetworkgradlejavafx.domain.Friendship;
import com.example.socialnetworkgradlejavafx.domain.Graph;
import com.example.socialnetworkgradlejavafx.domain.User;
import com.example.socialnetworkgradlejavafx.exception.ExistingException;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.repository.Repository;
import com.example.socialnetworkgradlejavafx.utils.events.ChangeEventType;
import com.example.socialnetworkgradlejavafx.utils.events.EntityChangeEvent;
import com.example.socialnetworkgradlejavafx.utils.observer.Observable;
import com.example.socialnetworkgradlejavafx.utils.observer.Observer;
import com.example.socialnetworkgradlejavafx.validators.ValidatorType;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class FriendshipService extends BaseEntityService<Long, Friendship> implements Observable<EntityChangeEvent> {
    private final Repository<Long, User> userRepository;
    private final Repository<Long, Friendship> friendshipRepository;

    public FriendshipService(Repository<Long, Friendship> friendshipRepository, Repository<Long, User> userRepository) {
        super(ValidatorType.FRIENDSHIP, friendshipRepository);
        this.userRepository = userRepository;
        this.friendshipRepository = friendshipRepository;
    }

    public void addFriendship(String idFriendship, String idUser1, String idUser2, LocalDateTime friendsFrom) throws ValidationException {
        Converters instance = Converters.getInstance();
        Long _idFriendship = Long.parseLong(idFriendship);
        Friendship friendship = instance.getFriendship(_idFriendship, idUser1, idUser2, friendsFrom);
        if (userRepository.findOne(friendship.getIdUser1()) == null)
            throw new ExistingException("There is no such user1!\n");
        if (userRepository.findOne(friendship.getIdUser2()) == null)
            throw new ExistingException("There is no such user2!\n");
        if (getRelationByUsers(friendship.getIdUser1(), friendship.getIdUser2()) != null)
            throw new ExistingException("This friendship already exists!\n");
        super.addEntity(friendship);
        this.notifyObservers(new EntityChangeEvent(ChangeEventType.ADD, friendship));
    }

    public Friendship getRelationByUsers(Long id1, Long id2) {
        return friendshipRepository.findAll().stream()
                .filter(friendship -> friendship.getIdUser1().equals(id1) && friendship.getIdUser2().equals(id2))
                .findFirst()
                .orElse(null);
    }

    public Map<User, List<User>> getAllUsersandFriends() {
        Map<User, List<User>> userMap = new HashMap<>();
        List<Friendship> friendshipList = this.getAll();
        for (Friendship friendship : friendshipList) {
            Long idUser1 = friendship.getIdUser1();
            Long idUser2 = friendship.getIdUser2();
            User user1 = this.userRepository.findOne(idUser1);
            User user2 = this.userRepository.findOne(idUser2);
            if (user1 != null) {
                userMap.computeIfAbsent(user1, k -> new ArrayList<>());
            }
            if (user2 != null) {
                userMap.computeIfAbsent(user2, k -> new ArrayList<>());
            }
            if (user1 != null && user2 != null) {
                userMap.get(user1).add(this.userRepository.findOne(idUser2));
            }
            if (user2 != null && user1 != null)
                userMap.get(user2).add(this.userRepository.findOne(idUser1));
        }
        System.out.println(userMap);
        return userMap;
    }

    public List<List<Long>> getConnectedComponents() {
        Graph<Long> graph = Converters.getInstance().getFriendshipsToGraph(friendshipRepository.findAll());
        Graphs<Long> graphs = new Graphs<Long>(graph);
        for (Long userID : getAllUserIds()) {
            graph.addNode(userID);
        }
        return graphs.getConnectedComponents();
    }

    public List<Long> getLongestPathComponent() {
        Graph<Long> graph = Converters.getInstance().getFriendshipsToGraph(friendshipRepository.findAll());
        Graphs<Long> graphUtils = new Graphs<>(graph);
        List<List<Long>> connectedComponents = graphUtils.getConnectedComponents();
        int maxSize = 0;
        List<Long> ans = new ArrayList<>();
        List<Long> maxPath = new ArrayList<>();
        for (var component : connectedComponents) {
            List<Long> longestPathInComponent = graphUtils.longestPathInComponent(component);
            System.out.println(longestPathInComponent);
            int size = longestPathInComponent.size();
            if (size > maxSize) {
                maxSize = size;
                ans = component;
                maxPath = longestPathInComponent;
            }
        }
        System.out.println(maxPath);
        return ans;
    }

    public List<Long> getAllUserIds() {
        List<Long> ids = new ArrayList<>();
        for (User user : userRepository.findAll())
            ids.add(user.getId());
        return ids;
    }

    public Friendship updateFriendship(String idFriendship, String idUser1, String idUser2, LocalDateTime friendsFrom) throws IllegalArgumentException, ValidationException {
        Converters converters = Converters.getInstance();
        Long _idFriendship = Long.valueOf(idFriendship);
        Friendship friendship = converters.getFriendship(_idFriendship, idUser1, idUser2, friendsFrom);
        super.updateEntity(friendship);
        this.notifyObservers(new EntityChangeEvent(ChangeEventType.UPDATE, friendship));
        return friendship;

    }

    public List<Friendship> getAllByID(Long userID) {
        return friendshipRepository.findAll().stream()
                .filter(friendship -> friendship.getIdUser1().equals(userID) || friendship.getIdUser2().equals(userID))
                .collect(Collectors.toList());
    }


}

