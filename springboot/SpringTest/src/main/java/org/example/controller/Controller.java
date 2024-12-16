package org.example.controller;

import org.example.logic.Pet;
import org.example.logic.PetModel;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;

@RestController
public class Controller {

    private static final PetModel petModel = PetModel.getInstance();
    private static final AtomicInteger newId = new AtomicInteger(1);

    @PostMapping(value = "/createPet", consumes = "application/json")
    public ResponseEntity<String> createPet(@RequestBody Pet pet) {
        String message = petModel.addPet(pet, newId.getAndIncrement());
        return ResponseEntity.ok(message);
    }

    @GetMapping(value = "/getAll", produces = "application/json")
    public Map<Integer, Pet> getAll() {
        return petModel.getAll();
    }

    @GetMapping(value = "/getPet", consumes = "application/json", produces = "application/json")
    public Pet getPet(@RequestBody Map<String, Integer> id) {
        return petModel.getFromList(id.get("id"));
    }

    @DeleteMapping(value = "/deletePet",consumes = "application/json", produces = "application/json")
    public ResponseEntity<String> deletePet(@RequestBody Map<String, Integer> id) {

        Pet deletedPet = petModel.removePet(id.get("id"));

        if (deletedPet != null) {
            return ResponseEntity.ok("Питомец успешно удален!");
        } else {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Питомца с таким ID " + id.get("id") + " нет!");
        }
    }

    @PutMapping(value = "/updatePet",consumes = "application/json", produces = "application/json")
    public Map<Integer,Pet> updatePet(@RequestBody Map<Integer, Pet> mapUpdatePet) {
        for (Integer id : mapUpdatePet.keySet()) {
            petModel.updatePet(id, mapUpdatePet.get(id));
        }
       return petModel.getAll();
    }
}