package com.example.socialnetworkgradlejavafx.repository.db;


import com.example.socialnetworkgradlejavafx.domain.User;
import com.example.socialnetworkgradlejavafx.exception.ExistingException;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.repository.Repository;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class DBUserRepository implements Repository<Long, User> {
    private final String url;
    private final String username;
    private final String password;

    public DBUserRepository(String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
    }

    private PreparedStatement getStatement(String sql) throws SQLException {
        Connection connection = DriverManager.getConnection(url, username, password);
        return connection.prepareStatement(sql);
    }

    @Override
    public User findOne(Long iduser) {
        String sqlStatement = "SELECT * FROM users WHERE idUser=?";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, iduser);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                return new User(resultSet.getLong(UserEnum.ID.getSqlValue()), resultSet.getString(UserEnum.NAME.getSqlValue()),
                        resultSet.getString(UserEnum.LASTNAME.getSqlValue()), resultSet.getString(UserEnum.EMAIL.getSqlValue()));
            }
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }

    @Override
    public List<User> findAll() {
        ArrayList<User> users = new ArrayList<>();
        String sqlStatement = "SELECT * FROM users";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                User user = new User(resultSet.getLong(UserEnum.ID.getSqlValue()), resultSet.getString(UserEnum.EMAIL.getSqlValue()),
                        resultSet.getString(UserEnum.NAME.getSqlValue()), resultSet.getString(UserEnum.LASTNAME.getSqlValue()));
                users.add(user);
            }
            return users;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }

    @Override
    public User save(User entity) throws ValidationException {
        String sqlStatement = "INSERT INTO users(name, lastname, email) VALUES(?, ?, ?)";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setString(1, entity.getName());
            statement.setString(2, entity.getLastname());
            statement.setString(3, entity.getEmail());
            statement.executeUpdate();
            return entity;
        } catch (SQLException sqlException) {
//            System.out.println(sqlException.getMessage());
            throw new ExistingException("An entity with this id already exists!\n");
        }
//        return null;
    }

    @Override
    public Long delete(Long iduser) {
        String sqlStatement = "DELETE FROM users WHERE iduser=?";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, iduser);
            statement.executeUpdate();
            return iduser;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }

    @Override
    public User update(User user) {
        String sqlStatement = "UPDATE users SET name=?, lastname=?, email=? WHERE iduser=?";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setString(1, user.getName());
            statement.setString(2, user.getLastname());
            statement.setString(3, user.getEmail());
            statement.setLong(4, user.getIdUser());
            statement.executeUpdate();
            return user;
        } catch (SQLException sqlException) {
        }
        return null;
    }
}
