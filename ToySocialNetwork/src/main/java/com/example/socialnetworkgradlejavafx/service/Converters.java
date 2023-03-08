package com.example.socialnetworkgradlejavafx.service;




import com.example.socialnetworkgradlejavafx.domain.*;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class Converters {
    private static Converters instance;

    private Converters() {
    }

    /**
     * The method builds an User by its components
     * @param idUser : the id of the user
     * @param name : the name of the user
     * @param email : the email of the user
     * @return : the new user
     */
    public User getUser(String idUser, String email, String name, String lastname) {
        Long id = Long.parseLong(idUser);
        return new User(id, email, name, lastname);
    }

    /**
     * The method builds a Friendship by its components
     * @param idFriendship : the id of the friendship
     * @param idUser1 : the id of the first user
     * @param idUser2 : the id of the second user
     * @return the new friendship
     * @throws ValidationException
     */
    public Friendship getFriendship(Long idFriendship, String idUser1, String idUser2, LocalDateTime friendsFrom) throws ValidationException {
        try {
            Long id1 = Long.parseLong(idUser1);
            Long id2 = Long.parseLong(idUser2);
            return new Friendship(idFriendship, id1, id2, friendsFrom);
        } catch (NumberFormatException exception) {
            throw new ValidationException("Invalid friendship!\n");
        }
    }

    public FriendshipRequest getFriendshipRequest(Long idFriendship, String idUser1, String idUser2, LocalDateTime friendsFrom, FriendshipREnum friendshipREnum) throws ValidationException {
        try {
            Long id1 = Long.parseLong(idUser1);
            Long id2 = Long.parseLong(idUser2);
            return new FriendshipRequest(idFriendship, id1, id2, friendsFrom, friendshipREnum);
        } catch (NumberFormatException exception) {
            throw new ValidationException("Invalid friendship!\n");
        }
    }

    /**
     * The method puts all the friendships into a graph
     * @param friendships the list of the friendships we want to put in the graph
     * @return the graph
     */
    public Graph<Long> getFriendshipsToGraph(List<Friendship> friendships) {
        List<Pair<Long, Long>> nodesList = new ArrayList<>();
        for (Friendship friendship : friendships) {
            nodesList.add(new Pair<>(friendship.getIdUser1(), friendship.getIdUser2()));
        }
        Graph<Long> graph = new Graph<>(nodesList);
        return graph;
    }

    public static Converters getInstance() {
        if (instance == null) instance = new Converters();
        return instance;
    }
}
