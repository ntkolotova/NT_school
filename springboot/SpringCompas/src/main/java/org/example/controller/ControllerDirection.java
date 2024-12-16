package org.example.controller;

import org.example.logic.DirectionService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.Map;

@RestController
public class ControllerDirection {

    private final DirectionService directionService;

    @Autowired
    public ControllerDirection(DirectionService directionService) {
        this.directionService = directionService;
    }

    @PostMapping(value = "/createDirection", consumes = "application/json")
    public ResponseEntity<String> setDirections(@RequestBody Map<String, String> degreesMap) {
        directionService.setDegreesMap(degreesMap);
        return ResponseEntity.ok("Вы успешно установили направления!");
    }

    @GetMapping(value = "/getDirection", consumes = "application/json", produces = "application/json")
    public Map<String, String> getDirection(@RequestBody Map<String, String> degreesMap) {
        Map<String, String> responseMap = new HashMap<>();
        int degree = Integer.parseInt(degreesMap.get("Degree"));
        String side = directionService.getDirection(degree);
        responseMap.put("Side", side);
        return responseMap;
    }
}