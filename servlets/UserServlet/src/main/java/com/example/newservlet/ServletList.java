package com.example.newservlet;

import com.example.newservlet.logic.Model;
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

@WebServlet(urlPatterns = "/get")
public class ServletList extends HttpServlet {

    Model model = Model.getInstance();
    Gson gson = new GsonBuilder().setPrettyPrinting().create();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException{

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

        int id = jsonObj.get("id").getAsInt();

        if (id == 0){

            response.setContentType("application/json; charset=utf-8");
            PrintWriter pwAll  = response.getWriter();

            pwAll.print(gson.toJson(model.getFromList()));

        } else if (id <= model.getFromList().size()) {

            response.setContentType("application/json; charset=utf-8");
            PrintWriter pwOne = response.getWriter();

            pwOne.print(gson.toJson(model.getFromListById(id)));
        }else {

            response.setContentType("application/json; charset=utf-8");
            PrintWriter pwErr = response.getWriter();

            pwErr.print("{\"text\" : \"Такого пользователя не существует!\"}");
        }
    }

//    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
//
//        int id = Integer.parseInt(request.getParameter("id"));
//        response.setContentType("text/html; charset=UTF-8");
//        PrintWriter pw = response.getWriter();
//
//
//        if (id == 0) {
//
//            pw.print("<html>" +
//                    "<h3>Доступные пользователи:</h3><br/>" +
//                    "ID пользователя: " +
//                    "<ul>");
//            for (Map.Entry<Integer, User> entry : model.getFromList().entrySet()) {
//
//                pw.print("<li>" + entry.getKey() + "</li>" +
//                        "<ul>" +
//                        "<li>Имя: " + entry.getValue().getName() + "</li>" +
//                        "<li>Фамилия: " + entry.getValue().getSurname() + "</li>" +
//                        "<li>Зарплата: " + entry.getValue().getSalary() + "</li>" +
//                        "</ul>");
//            }
//            pw.print("</ul>" +
//                    "<a href = \"index.jsp\">Домой</a>" +
//                    "</html>");
//        } else if (id > 0) {
//
//            if (id > model.getFromList().size()) {
//
//                pw.print("<html>" +
//                        "<h3>Такого пользователя нет!</h3>" +
//                        "<a href = \"index.jsp\">Домой</a>" +
//                        "</html>");
//            } else {
//
//                pw.print("<html>" +
//                        "<h3>Запрошенный пользователь:</h3>" +
//                        "<br/>" +
//                        "Имя: " + model.getFromList().get(id).getName() + "</br>" +
//                        "Фамилия: " + model.getFromList().get(id).getSurname() + "</br>" +
//                        "Зарплата: " + model.getFromList().get(id).getSalary() + "</br>" +
//                        "<a href = \"index.jsp\">Домой</a>" +
//                        "</html>");
//
//            }
//        } else {
//
//            pw.print("<html>" +
//                    "<h3>ID должен быть больше 0</h3>" +
//                    "<a href = \"index.jsp\">Домой</a>" +
//                    "</html>");
//        }
//    }

}