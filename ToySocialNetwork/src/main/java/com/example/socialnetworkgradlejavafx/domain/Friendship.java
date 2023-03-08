package com.example.socialnetworkgradlejavafx.domain;

import java.time.LocalDate;
import java.time.LocalDateTime;

public class Friendship extends Entity<Long> {
    private LocalDateTime friendsFrom;
    private Long idUser1;
    private Long idUser2;

    public Friendship(Long id, Long idUser1, Long idUser2, LocalDateTime friendsFrom) {
        super(id);
        this.idUser1 = idUser1;
        this.idUser2 = idUser2;
        this.friendsFrom = friendsFrom;
    }

    public Long getIdUser1() {
        return idUser1;
    }

    public void setIdUser1(Long idUser1) {
        this.idUser1 = idUser1;
    }

    public Long getIdUser2() {
        return idUser2;
    }

    public void setIdUser2(Long idUser2) {
        this.idUser2 = idUser2;
    }

    public LocalDateTime getFriendsFrom() {
        return friendsFrom;
    }

    public void setFriendsFrom(LocalDateTime localDateTime) {
        this.friendsFrom = localDateTime;
    }

    @Override
    public String toString() {
//        return "Friendship{" +
//                "localDate=" + localDate +
//                '}';
        return this.getId().toString() + ";" + idUser1 + ";" + idUser2 + ";" + this.getFriendsFrom();
    }
}
