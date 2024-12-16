package org.example.logic;

import org.springframework.web.bind.annotation.RequestBody;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;

public class PetModel implements Serializable {

    private static final PetModel instance = new PetModel();

    private final Map<Integer, Pet> model;

    public PetModel() {

        model = new HashMap<Integer, Pet>();

    }

    public static PetModel getInstance() {
        return instance;
    }

    public String addPet(@RequestBody Pet pet, int id) {
        model.put(id, pet);
        if (id == 1) {
            return "Поздравляем! Вы создали первого питомца!";
        } else {
            return "Питомец успешно создан!";
        }
    }

    public Pet getFromList(int id) {
        return model.get(id);
    }

    public Map<Integer, Pet> getAll() {
        return model;
    }

    public Pet removePet(int id) {
        return model.remove(id);
    }

    public void updatePet(int id, Pet pet) {
        if (model.containsKey(id)) {
            model.put(id, pet);
        }
    }
}