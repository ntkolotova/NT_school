package org.example.logic;

import org.springframework.stereotype.Service;

import java.util.HashMap;
import java.util.Map;

@Service
public class DirectionService {

    private Map<String, String> degreesMap = new HashMap<>();

    public Map<String, String> getDegreesMap() {
        return degreesMap;
    }

    public void setDegreesMap(Map<String, String> degreesMap) {
        this.degreesMap = degreesMap;
    }

    public String getDirection(int degree) {
        for (Map.Entry<String, String> entry : getDegreesMap().entrySet()) {
            String[] bounds = entry.getValue().split("-");
            int lowerBound = Integer.parseInt(bounds[0]);
            int upperBound = Integer.parseInt(bounds[1]);
            if (degree >= lowerBound && degree <= upperBound) {
                return entry.getKey();
            }
        }
        return "Неизвестное направление!";
    }
}