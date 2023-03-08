package com.example.socialnetworkgradlejavafx.repository.db;

import com.example.socialnetworkgradlejavafx.domain.FriendshipREnum;
import com.example.socialnetworkgradlejavafx.domain.RequestDTO;

import javax.xml.transform.Result;
import java.sql.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

public class RequestDTORepository {

    private final String url;
    private final String username;
    private final String password;

    public RequestDTORepository(String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
    }

    private PreparedStatement getStatement(String sql) throws SQLException {
        Connection connection = DriverManager.getConnection(url, username, password);
        return connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
    }

    public List<RequestDTO> findAll(Long idUserFriend) {
        String sqlStatement = "select distinct localdatetime, username, status\n" +
                "from credentials join friendships \n" +
                "on ((credentials.iduser = idUser1 or credentials.iduser = idUser2)\n" +
                "   and credentials.idUser in (\n" +
                "\tselect idUser1 \n" +
                "from friendships where idUser2=?\n" +
                "union\n" +
                "select idUser2\n" +
                "from friendships where idUser1=?\n" +
                "))\n" +
                "where idUser1 = ? or idUser2 = ?";
        List<RequestDTO> requestDTOS = new ArrayList<>();
        try {
            PreparedStatement preparedStatement = getStatement(sqlStatement);
            preparedStatement.setLong(1, idUserFriend);
            preparedStatement.setLong(2, idUserFriend);
            preparedStatement.setLong(3, idUserFriend);
            preparedStatement.setLong(4, idUserFriend);
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {

                LocalDateTime localDateTime = LocalDateTime.parse(resultSet.getString(1));
                String username = resultSet.getString(2);
                FriendshipREnum friendshipREnum = FriendshipREnum.valueOf(resultSet.getString(3));
                RequestDTO requestDTO = new RequestDTO(username, localDateTime, friendshipREnum);
                requestDTOS.add(requestDTO);
            }
            return requestDTOS;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }

    public List<String> findAll() {
        List<String> usernames = new ArrayList<>();
        String sqlStatement = "select username from credentials join users on credentials.iduser=users.iduser";
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                String username = resultSet.getString(1);
                usernames.add(username);
            }
            return usernames;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }

    public Long getIdByUsername(String username) {
        String sqlStatement = "select iduser from credentials where username=?";
        Long idUserFound = -1L;
        try {
            PreparedStatement statement = getStatement(sqlStatement);
            statement.setString(1, username);
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next())
                idUserFound = resultSet.getLong(1);
            return idUserFound;
        } catch (SQLException sqlException) {
            sqlException.printStackTrace();
        }
        return null;
    }


}
