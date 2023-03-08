package com.example.socialnetworkgradlejavafx.service;


import com.example.socialnetworkgradlejavafx.domain.Entity;
import com.example.socialnetworkgradlejavafx.exception.ExistingException;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.repository.Repository;
import com.example.socialnetworkgradlejavafx.service.EntityService;
import com.example.socialnetworkgradlejavafx.utils.events.ChangeEventType;
import com.example.socialnetworkgradlejavafx.utils.events.EntityChangeEvent;
import com.example.socialnetworkgradlejavafx.utils.observer.Observer;
import com.example.socialnetworkgradlejavafx.validators.ValidatorFactory;
import com.example.socialnetworkgradlejavafx.validators.ValidatorType;
import com.example.socialnetworkgradlejavafx.validators.Validators;


import java.util.ArrayList;
import java.util.List;

public abstract class BaseEntityService<ID, E extends Entity<ID>> implements EntityService<ID, E> {

    private final Validators<E> validator;
    private final Repository<ID, E> entityRepository;
    protected final List<Observer<EntityChangeEvent>> observers = new ArrayList<>();


    public BaseEntityService(ValidatorType validatorType, Repository<ID, E> entityRepository) {
        ValidatorFactory instance = ValidatorFactory.getInstance();
        Validators validator = instance.createValidator(validatorType);
        this.validator = validator;
        this.entityRepository = entityRepository;
    }

    @Override
    public void addEntity(E entity) throws ValidationException {
        validator.validate(entity);
        if (this.entityRepository.save(entity) == null)
            throw new ExistingException("This entity already exists!\n");
        //daca trece de aceste throw-uri, practic aceasta entitate a fost salvata
    }

    @Override
    public E updateEntity(E entity) throws IllegalArgumentException {
        return entityRepository.update(entity);
    }

    @Override
    public ID deleteEntity(ID idEntity) {
        entityRepository.delete(idEntity);
        this.notifyObservers(new EntityChangeEvent(ChangeEventType.DELETE, entityRepository.findOne(idEntity)));
        return idEntity;
    }

    public List<E> getAll() {
        return entityRepository.findAll();
    }


    public void addObserver(Observer<EntityChangeEvent> e) {
        observers.add(e);
    }


    public void removeOberver(Observer<EntityChangeEvent> e) {
        observers.remove(e);

    }


    public void notifyObservers(EntityChangeEvent t) {
        observers.stream().forEach(x -> x.update(t));
    }
}
