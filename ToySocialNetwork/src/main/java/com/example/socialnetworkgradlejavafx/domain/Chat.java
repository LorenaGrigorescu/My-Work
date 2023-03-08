package com.example.socialnetworkgradlejavafx.domain;

import java.time.LocalDate;
import java.time.LocalDateTime;

public class Chat extends Entity<Long> {
    private Long iduser1;
    private Long iduser2;
    private String message;
    private LocalDateTime sentAt;

    public Chat(Long aLong, Long iduser1, Long iduser2, String message, LocalDateTime sentAt) {
        super(aLong);
        this.iduser1 = iduser1;
        this.iduser2 = iduser2;
        this.message = message;
        this.sentAt = sentAt;
    }

    public Long getIduser1() {
        return iduser1;
    }

    public void setIduser1(Long iduser1) {
        this.iduser1 = iduser1;
    }


    public Long getIduser2() {
        return iduser2;
    }

    public void setIduser2(Long iduser2) {
        this.iduser2 = iduser2;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public LocalDateTime getSentAt() {
        return sentAt;
    }

    public void setSentAt(LocalDateTime sentAt) {
        this.sentAt = sentAt;
    }
}
