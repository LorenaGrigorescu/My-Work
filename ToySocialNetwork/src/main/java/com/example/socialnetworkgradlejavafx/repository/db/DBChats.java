package com.example.socialnetworkgradlejavafx.repository.db;

import com.example.socialnetworkgradlejavafx.domain.Chat;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class DBChats {

    private final String url;
    private final String username;
    private final String password;

    public DBChats(String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
    }

    private PreparedStatement getStatement(String sql) throws SQLException {
        Connection connection = DriverManager.getConnection(url, username, password);
        return connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
    }

    public Chat addMessage(Chat chat) {
        String sqlStatement = "INSERT INTO chats (iduser, iduser2, message, sent_at) VALUES (?, ?, ?, ?)";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, chat.getIduser1());
            statement.setLong(2, chat.getIduser2());
            statement.setString(3, chat.getMessage());
            statement.setString(4, String.valueOf(chat.getSentAt()));
            var resultSet = statement.executeUpdate();
            return chat;
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
        return null;
    }

    public List<Chat> getChats(Long iduser) {
        List<Chat> chatList = new ArrayList<>();
        String sqlStatement1 = "select distinct iduser2, message,sent_at from chats where iduser=? order by sent_at";
        String sqlStatement = "select distinct iduser, message, sent_at from chats where iduser2=? order by sent_at";

        try {
            PreparedStatement statement = getStatement(sqlStatement);
            PreparedStatement statement1 = getStatement(sqlStatement1);
            statement.setLong(1, iduser);
            statement1.setLong(1, iduser);
            var resultSet = statement.executeQuery();
            while (resultSet.next()) {
                Chat chat = new Chat(1L, resultSet.getLong(1), iduser, resultSet.getString(2), LocalDateTime.parse(resultSet.getString(3)));
                chatList.add(chat);
            }
            var resultSet1 = statement1.executeQuery();
            while (resultSet1.next()) {
                Chat chat = new Chat(1L, iduser, resultSet1.getLong(1), resultSet1.getString(2), LocalDateTime.parse(resultSet1.getString(3)));
                chatList.add(chat);

            }
            return chatList;
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
        return null;
    }

    public Long getUserID(String username) throws SQLException {
        String sqlStatement = "SELECT iduser FROM credentials where username=?";
        PreparedStatement statement = getStatement(sqlStatement);
        statement.setString(1, username);
        ResultSet resultSet = statement.executeQuery();
        resultSet.next();
        Long idUser = resultSet.getLong(1);
        return idUser;
    }

    public String getUsernameById(Long idUser) {
        String sqlStatement = "SELECT username FROM credentials WHERE iduser=?";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, idUser);
            ResultSet resultSet = statement.executeQuery();
            resultSet.next();
            String username = resultSet.getString(1);
            return username;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }
}
