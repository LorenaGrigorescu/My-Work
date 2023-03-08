package com.example.socialnetworkgradlejavafx.repository;

import com.example.socialnetworkgradlejavafx.domain.Entity;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;


import java.util.List;

public interface Repository <ID, E extends Entity<ID>> {
    /**
     * The method saves an entity(user or friendship)
     * @param entity : the entity to be saved
     * @return : the entity
     * @throws ValidationException
     */
    E save (E entity) throws ValidationException;

    /**
     * The metohod deletes an entity by its id
     * @param idEntity : the id of the entity we want to delete
     * @return the id
     */
    ID delete (ID idEntity);

    /**
     * The method updates the entity
     * @param entity : the entity to be updated
     * @return the entity
     */
    E update (E entity) throws IllegalArgumentException;

    /**
     * The method finds the entity only by its id
     * @param idEntity : the id entity we search by
     * @return the entity we found or null
     */

    E findOne(ID idEntity);

    /**
     * Gets the entire list of entities
     * @return list of entities
     */

    List<E> findAll();



}
