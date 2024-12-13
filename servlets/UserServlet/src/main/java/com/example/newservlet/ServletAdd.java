package com.example.newservlet;

import com.example.newservlet.logic.Model;
import com.example.newservlet.logic.User;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonObject;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.concurrent.atomic.AtomicInteger;

@WebServlet(urlPatterns = "/add")
public class ServletAdd extends HttpServlet {

    private final AtomicInteger counter = new AtomicInteger(5);

    Model model = Model.getInstance();

    Gson gson = new GsonBuilder().setPrettyPrinting().create();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {

        switch (request.getContentType()){

            case "application/json":

                StringBuilder jb = new StringBuilder();
                String line;

                try {
                    BufferedReader reader = request.getReader();
                    while ((line = reader.readLine()) != null) {
                        jb.append(line);
                    }
                } catch (IOException e) {
                    System.out.println("Error");
                }

                JsonObject jsonObj = gson.fromJson(String.valueOf(jb), JsonObject.class);

                request.setCharacterEncoding("UTF-8");

                String userNameJson = jsonObj.get("name").getAsString();
                String userSurnameJson = jsonObj.get("surname").getAsString();
                double userSalaryJson = jsonObj.get("salary").getAsDouble();

                User user = new User(userNameJson, userSurnameJson, userSalaryJson);
                model.add(user, counter.getAndIncrement());

                response.setContentType("application/json; charset=utf-8");
                PrintWriter pw = response.getWriter();

                pw.print(gson.toJson(model.getFromList()));

                break;

            case "application/x-www-form-urlencoded":

                response.setContentType("text/html; charset=UTF-8");
                request.setCharacterEncoding("UTF-8");
                PrintWriter out = response.getWriter();

                String userName = request.getParameter("name");
                String userSurname = request.getParameter("surname");
                double userSalary = Double.parseDouble(request.getParameter("salary"));

                User userOne = new User(userName, userSurname, userSalary);
                model.add(userOne, counter.getAndIncrement());

                out.print("<html>"
                        + "<h3>Пользователь: " + userName + " " + userSalary + " с зарплатой= " + userSalary + " " + " успешно создан! :) </h3>" +
                        "<a href=\"addUser.html\">Создать нового пользователя</a><br/>" +
                        "<a href=\"index.jsp\">Домой</a>" +
                        "</html>");

                break;

            default:
                PrintWriter defaultPw = response.getWriter();
                defaultPw.print("ContentType не найден");
        }
    }
}