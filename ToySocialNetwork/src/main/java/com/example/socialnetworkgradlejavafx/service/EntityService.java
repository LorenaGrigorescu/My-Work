package com.example.socialnetworkgradlejavafx.service;


import com.example.socialnetworkgradlejavafx.domain.Entity;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;

public interface EntityService <ID, E extends Entity<ID>>{

        /**
         * The method saves an entity
         * @param entity the entity we want to save
         * @throws ValidationException
         */
        void addEntity(E entity) throws ValidationException, ValidationException;

        /**
         * The method deletes an entity
         * @param idEntity the id of the entity we want to delete
         * @return the id
         */

        ID deleteEntity(ID idEntity);

        E updateEntity(E entity) throws IllegalArgumentException;
}
