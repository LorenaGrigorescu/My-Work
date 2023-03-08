package com.example.socialnetworkgradlejavafx.service;

import com.example.socialnetworkgradlejavafx.domain.RequestDTO;
import com.example.socialnetworkgradlejavafx.repository.db.RequestDTORepository;

import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

public class RequestDTOService {

    private final RequestDTORepository requestDTORepository;

    public RequestDTOService(RequestDTORepository requestDTORepository) {
        this.requestDTORepository = requestDTORepository;
    }

    public List<RequestDTO> findAll(Long idUserFriend) {
        return this.requestDTORepository.findAll(idUserFriend);
    }

    public List<String> findAllUsernames() {
        return this.requestDTORepository.findAll();
    }

    public Long getIdUserByUsername(String username) {
        return this.requestDTORepository.getIdByUsername(username);
    }
}
