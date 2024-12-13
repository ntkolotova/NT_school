package com.example.newservlet.logic;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;

public class Model implements Serializable {

    private static final Model instance = new Model();

    private final Map<Integer, User> model;

    public static Model getInstance(){
        return instance;
    }

    private Model(){

        model = new HashMap<>();

        model.put(1, new User("Ivan", "Ivanov", 50000));
        model.put(2, new User("Petr", "Petrov", 60000));
        model.put(3,new User("Denis", "Denisov", 70000));
        model.put(4,new User("Egor", "Egorov", 80000));

    }

    public void add(User user, int id){
        model.put(id, user);
    }

    public Map<Integer, User> getFromList(){
        return model;
    }

    public User getFromListById(Integer id){
        return model.get(id);
    }

    public void delete(int id){
        model.remove(id);
    }

    public void upgrade(int id, User user){
        model.put(id, user);
    }
}