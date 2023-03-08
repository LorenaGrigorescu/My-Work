package com.example.socialnetworkgradlejavafx.repository.db;


import com.example.socialnetworkgradlejavafx.domain.Friendship;
import com.example.socialnetworkgradlejavafx.exception.ExistingException;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class DBFriendshipRepository extends DBRepository<Long, Friendship> {

    public DBFriendshipRepository(String url, String username, String password) {
        super(url, username, password);
    }

    @Override
    public Friendship findOne(Long idFriendship) {
        String sqlStatement = "SELECT * FROM friendships WHERE idFriendship=?";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, idFriendship);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                return new Friendship(resultSet.getLong(FriendshipEnum.ID.getSqlValue()),
                        resultSet.getLong(FriendshipEnum.USER1.getSqlValue()),
                        resultSet.getLong(FriendshipEnum.USER2.getSqlValue()),
                        LocalDateTime.parse(resultSet.getString(FriendshipEnum.DATE_TIME.getSqlValue())));
            } else return null;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }

    @Override
    public List<Friendship> findAll() {
        String sqlStatement = "SELECT * FROM friendships";
        ArrayList<Friendship> friendships = new ArrayList<>();

        try {
            PreparedStatement statement = getStatement(sqlStatement);
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                Friendship friendship = new Friendship(resultSet.getLong(FriendshipEnum.ID.getSqlValue()),
                        resultSet.getLong(FriendshipEnum.USER1.getSqlValue()),
                        resultSet.getLong(FriendshipEnum.USER2.getSqlValue()),
                        LocalDateTime.parse(resultSet.getString(FriendshipEnum.DATE_TIME.getSqlValue())));
                friendships.add(friendship);
            }
            return friendships;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }

    @Override
    public Friendship save(Friendship entity) throws ValidationException {
        if (entity.getIdUser1().equals(entity.getIdUser2()))
            throw new ValidationException("No user can be friend with himself!\n");
        String sqlStatement = "INSERT INTO friendships(iduser1, iduser2, localdatetime) VALUES (?, ?, ?)";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, entity.getIdUser1());
            statement.setLong(2, entity.getIdUser2());
            statement.setString(3, String.valueOf(entity.getFriendsFrom()));
            statement.executeUpdate();
            return entity;
        } catch (SQLException sqlException) {
//            System.out.println(sqlException.getMessage());
            throw new ExistingException("An entity with this ID already exists!\n");
        }
//        return null;
    }

    @Override
    public Long delete(Long idFriendship) {
        String sqlStatement = "DELETE FROM friendships WHERE idfriendship=?";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, idFriendship);
            statement.executeUpdate();
            return idFriendship;
        } catch (SQLException sqlException) {
        }
        return null;
    }

    @Override
    public Friendship update(Friendship entity) throws IllegalArgumentException {
        String sqlStatement = "UPDATE friendships SET iduser1=?, iduser2=?, localdatetime=? WHERE idfriendship=?";

        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, entity.getIdUser1());
            statement.setLong(2, entity.getIdUser2());
            statement.setString(3, String.valueOf(entity.getFriendsFrom()));
            statement.setLong(4, entity.getId());
            statement.executeUpdate();
            return entity;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }



}
