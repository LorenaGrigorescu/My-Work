package com.example.socialnetworkgradlejavafx.domain;

import java.time.LocalDateTime;

public class FriendshipRequest extends Entity<Long> {

    private LocalDateTime friendsFrom;
    private Long idUser1;
    private Long idUser2;

    private FriendshipREnum friendshipEnum;

    public FriendshipRequest(Long id, Long idUser1, Long idUser2, LocalDateTime friendsFrom, FriendshipREnum friendshipEnum) {
        super(id);
        this.friendsFrom = friendsFrom;
        this.idUser1 = idUser1;
        this.idUser2 = idUser2;
        this.friendshipEnum=friendshipEnum;
    }

    public LocalDateTime getFriendsFrom() {
        return friendsFrom;
    }

    public void setFriendsFrom(LocalDateTime friendsFrom) {
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

    public FriendshipREnum getFriendshipEnum() {
        return friendshipEnum;
    }
}
