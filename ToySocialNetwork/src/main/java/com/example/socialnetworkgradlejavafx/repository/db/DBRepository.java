package com.example.socialnetworkgradlejavafx.repository.db;

import com.example.socialnetworkgradlejavafx.domain.Entity;
import com.example.socialnetworkgradlejavafx.repository.Repository;

import java.sql.*;

public abstract class DBRepository<ID, E extends Entity<ID>> implements Repository<ID, E> {
    private final String url;
    private final String username;
    private final String password;

    public DBRepository(String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
    }

    protected PreparedStatement getStatement(String sql) throws SQLException {
        Connection connection = DriverManager.getConnection(url, username, password);
        return connection.prepareStatement(sql);
    }
}
