package com.example.socialnetworkgradlejavafx.repository.memory;




import com.example.socialnetworkgradlejavafx.domain.Entity;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.repository.Repository;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class InMemoryRepository<ID, E extends Entity<ID>> implements Repository<ID, E> {
    protected Map<ID, E> entities;

    public InMemoryRepository() {
        this.entities = new HashMap<>();
    }

    @Override
    public E save(E entity) throws ValidationException {
        if(entity==null) throw new ValidationException("Entity cannot be null!\n");
        if (entity.getId() == null) throw new IllegalArgumentException("ID must not be null!\n");
        if (entities.get(entity.getId()) != null) return null;
        entities.put(entity.getId(), entity);
        return entity;
    }

    @Override
    public ID delete(ID idEntity) {
        if (entities.get(idEntity) == null) return null;
        entities.remove(idEntity);
        return idEntity;
    }

    @Override
    public E update(E entity) throws IllegalArgumentException{

        if(entity==null) throw new IllegalArgumentException("Entity is null!");
        if(entities.get(entity.getId())==null) return null;
        else {
            entities.put(entity.getId(), entity);
            return entity;
        }
    }

    @Override
    public E findOne(ID idEntity) {
        if(idEntity==null)
            return null;
        return entities.get(idEntity);
    }

    @Override
    public List<E> findAll() {
        return new ArrayList<E>(entities.values()).stream().toList();
    }
}
