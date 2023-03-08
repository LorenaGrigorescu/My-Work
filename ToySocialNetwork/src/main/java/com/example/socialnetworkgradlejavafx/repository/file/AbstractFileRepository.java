package com.example.socialnetworkgradlejavafx.repository.file;


import com.example.socialnetworkgradlejavafx.domain.Entity;
import com.example.socialnetworkgradlejavafx.exception.ExistingException;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;
import com.example.socialnetworkgradlejavafx.repository.memory.InMemoryRepository;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public abstract class AbstractFileRepository<ID, E extends Entity<ID>> extends InMemoryRepository<ID, E> {

    private final String filepath;

    protected AbstractFileRepository(String filepath) {
        this.filepath = filepath;
        loadData();
    }

    private void loadData() {
        try {
            File CSVfile = new File(filepath);
            Scanner scanner = new Scanner(CSVfile);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] arguments = line.split(";");
                E entity = buildEntity(arguments);
                super.save(entity);
            }
        } catch (IOException exception) {
            System.out.println(exception.getMessage());
        } catch (ValidationException e) {
            System.out.println(e.getMessage());
        }
    }

    private void writeDataToFile(E entity) {
        try {
            FileWriter fileWriter = new FileWriter(filepath, true);
            fileWriter.write(entity.toString());
            fileWriter.write("\n");
            fileWriter.close();
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }

    private void clearFile() {
        try {
            FileWriter fileWriter = new FileWriter(filepath, false);
            fileWriter.write("");
        } catch (IOException exception) {
            exception.printStackTrace();
        }
    }

    public E save(E entity) throws IllegalArgumentException, ValidationException {
        if (super.save(entity) == null)
            return null;
        writeDataToFile(entity);
        return entity;
    }

    public ID delete(ID idEntity) {
        if (super.entities.get(idEntity) == null) throw new ExistingException("There is no such user!\n");
        ID deletedEntity = super.delete(idEntity);
        clearFile();
        super.findAll().forEach(this::writeDataToFile);
        return deletedEntity;
    }


    abstract E buildEntity(String[] arguments);
}