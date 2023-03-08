package com.example.socialnetworkgradlejavafx.repository.db;

import com.example.socialnetworkgradlejavafx.domain.Friendship;
import com.example.socialnetworkgradlejavafx.domain.FriendshipREnum;
import com.example.socialnetworkgradlejavafx.domain.FriendshipRequest;
import com.example.socialnetworkgradlejavafx.exception.ExistingException;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class DBFriendshipRequestRepository extends DBRepository<Long, FriendshipRequest> {
    public DBFriendshipRequestRepository(String url, String username, String password) {
        super(url, username, password);
    }


    @Override
    public FriendshipRequest findOne(Long idFriendship) {
        String sqlStatement = "SELECT * FROM friendships WHERE idFriendship=?";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, idFriendship);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                return new FriendshipRequest(resultSet.getLong(FriendshipEnum.ID.getSqlValue()),
                        resultSet.getLong(FriendshipEnum.USER1.getSqlValue()),
                        resultSet.getLong(FriendshipEnum.USER2.getSqlValue()),
                        LocalDateTime.parse(resultSet.getString(FriendshipEnum.DATE_TIME.getSqlValue())),
                        FriendshipREnum.valueOf(resultSet.getString(FriendshipRequestEnum.STATUS.getSqlValue())));
            } else return null;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }

    @Override
    public List<FriendshipRequest> findAll() {
        String sqlStatement = "SELECT * FROM friendships";
        ArrayList<FriendshipRequest> friendships = new ArrayList<>();

        try {
            PreparedStatement statement = getStatement(sqlStatement);
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                FriendshipRequest friendship = new FriendshipRequest(resultSet.getLong(FriendshipEnum.ID.getSqlValue()),
                        resultSet.getLong(FriendshipEnum.USER1.getSqlValue()),
                        resultSet.getLong(FriendshipEnum.USER2.getSqlValue()),
                        LocalDateTime.parse(resultSet.getString(FriendshipEnum.DATE_TIME.getSqlValue())),
                        FriendshipREnum.valueOf(resultSet.getString(FriendshipRequestEnum.STATUS.getSqlValue())));
                friendships.add(friendship);
            }
            return friendships;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }

    @Override
    public FriendshipRequest save(FriendshipRequest entity) throws ValidationException {
        if (entity.getIdUser1().equals(entity.getIdUser2()))
            throw new ValidationException("No user can be friend with himself!\n");
        String sqlStatement = "INSERT INTO friendships(iduser1, iduser2, localdatetime,status) VALUES (?, ?, ?,?)";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, entity.getIdUser1());
            statement.setLong(2, entity.getIdUser2());
            statement.setString(3, String.valueOf(entity.getFriendsFrom()));
            statement.setString(4, String.valueOf(entity.getFriendshipEnum()));
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
    public FriendshipRequest update(FriendshipRequest entity) throws IllegalArgumentException {
        String sqlStatement = "UPDATE friendships SET status=? WHERE iduser1=? and iduser2=?";

        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setString(1, String.valueOf(entity.getFriendshipEnum()));
            statement.setLong(2, entity.getIdUser1());
            statement.setLong(3, entity.getIdUser2());
            statement.executeUpdate();
            return entity;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }

    public boolean searchFriendship(Long idUser1, Long idUser2) {
        String sqlStatement = "SELECT * FROM friendships WHERE (iduser1=? and iduser2=?) or (iduser1=? and iduser2=?)";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, idUser1);
            statement.setLong(2, idUser2);
            statement.setLong(3, idUser1);
            statement.setLong(4, idUser2);
            var resultSet = statement.executeQuery();
            return resultSet.next();
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return false;
    }

    public int deleteFriendship(Long idUser1, Long idUser2) {
        String sqlStatement = "DELETE FROM friendships WHERE (iduser1=? and iduser2=?) or (iduser1=? and iduser2=?)";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, idUser1);
            statement.setLong(2, idUser2);
            statement.setLong(3, idUser2);
            statement.setLong(4, idUser1);
            var resultSet = statement.executeUpdate();
            return resultSet;
        } catch (SQLException sqlException) {
        }
        return 0;
    }

}
