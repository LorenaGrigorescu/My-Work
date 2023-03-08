package com.example.socialnetworkgradlejavafx.repository.db;

import com.example.socialnetworkgradlejavafx.cryptingPassword.CryptingPasswordSHA256;
import com.example.socialnetworkgradlejavafx.domain.User;
import com.example.socialnetworkgradlejavafx.domain.UserCredentials;
import com.example.socialnetworkgradlejavafx.exception.ExceptionCredentials;

import javax.security.auth.login.CredentialException;
import java.security.NoSuchAlgorithmException;
import java.sql.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DBUserCredentialsRepository {
    private final String url;
    private final String username;
    private final String password;

    public DBUserCredentialsRepository(String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
    }

    private PreparedStatement getStatement(String sql) throws SQLException {
        Connection connection = DriverManager.getConnection(url, username, password);
        return connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
    }

    public UserCredentials addUserCredentials(UserCredentials userCredentials, User user) throws CredentialException, ExceptionCredentials {
        String sqlStatementUsers = "INSERT INTO users (name, lastname, email) VALUES (?, ?, ?)";
        String sqlStatement = "INSERT INTO credentials (iduser, username, password) VALUES (?, ?, ?)";
        String sqlFindIDStatement = "SELECT iduser FROM users WHERE name=? AND lastname=?";
        try {
            PreparedStatement statementUsers = getStatement(sqlStatementUsers);
            statementUsers.setString(1, user.getName());
            statementUsers.setString(2, user.getLastname());
            statementUsers.setString(3, user.getEmail());
            statementUsers.executeUpdate();
            statementUsers.getGeneratedKeys().next();
            userCredentials.setUserId(statementUsers.getGeneratedKeys().getLong(1));
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, userCredentials.getUserId());
            statement.setString(2, userCredentials.getUsername());
            String cryptedPassword = CryptingPasswordSHA256.toHexString(CryptingPasswordSHA256.getSHA(userCredentials.getPassword()));
            statement.setString(3, cryptedPassword);
            statement.executeUpdate();
            return userCredentials;
        } catch (SQLException | NoSuchAlgorithmException exception) {
            System.out.println(exception.getMessage());
            System.out.println(Arrays.toString(exception.getStackTrace()));
            throw new CredentialException("An existing username with these credentials already exists!\n");
        }
    }

    public Long deleteUserCredentials(Long idUser) {
        String SqlStatement = "DELETE FROM credentials WHERE iduser=idUser";
        String SqlStatementUsers = "DELETE FROM users WHERE iduser=idUser";
        try {
            PreparedStatement statement = getStatement(SqlStatement);
            statement.setLong(1, idUser);
            statement.executeUpdate();
            PreparedStatement statement1 = getStatement(SqlStatementUsers);
            statement1.setLong(1, idUser);
            statement1.executeUpdate();
            return idUser;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }

    public boolean findOne(String username) {
        String sqlStatement = "SELECT * FROM credentials where username=?";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setString(1, username);
            ResultSet resultSet = statement.executeQuery();
            return resultSet.next();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }

    public boolean findPassword(String username, String password) {
        String sqlStatement = "SELECT * FROM credentials where password = ? AND username=?";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            String cryptedPassword = CryptingPasswordSHA256.toHexString(CryptingPasswordSHA256.getSHA(password));
            statement.setString(1, cryptedPassword);
            statement.setString(2, username);
            ResultSet resultSet = statement.executeQuery();
            return resultSet.next();
        } catch (SQLException | NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return false;
    }

    public Long getUserID(String username) {
        String sqlStatement = "SELECT iduser FROM credentials where username=?";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setString(1, username);
            ResultSet resultSet = statement.executeQuery();
            resultSet.next();
            Long idUser = resultSet.getLong(1);
            return idUser;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return -1L;
    }

    public String getUsernameById(Long idUser)
    {
        String sqlStatement = "SELECT username FROM credentials WHERE iduser=?";
        try{
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setLong(1, idUser);
            ResultSet resultSet = statement.executeQuery();
            resultSet.next();
            String username = resultSet.getString(1);
            return username;
        }catch (SQLException sqlException)
        {
            sqlException.printStackTrace();
        }
        return null;
    }

}
