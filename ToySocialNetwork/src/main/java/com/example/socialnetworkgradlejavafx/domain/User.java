package com.example.socialnetworkgradlejavafx.domain;

import java.util.Objects;

public class User extends Entity<Long> {

        private Long idUser;
    private String name;
    private String email;

    private String lastname;


    public User(Long idUser, String email, String name, String lastname) {
        super(idUser);
        this.idUser = idUser;
        this.name = name;
        this.email = email;
        this.lastname = lastname;
    }

    public Long getIdUser() {
        return getId();
    }


    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public String getLastname() {
        return lastname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        User user = (User) o;
        return getId().equals(user.getId()) && email.equals(user.email);
    }

    @Override
    public int hashCode() {
        return Objects.hash(getId(), email);
    }

    @Override
    public String toString() {
        return getIdUser().toString() + ";" + getEmail() + ";" + getName()+";"+getLastname();
    }


}