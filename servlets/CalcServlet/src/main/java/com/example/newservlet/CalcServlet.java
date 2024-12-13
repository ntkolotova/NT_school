package com.example.newservlet;

import com.example.newservlet.logic.Calculator;
import com.google.gson.*;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/calculator")
public class CalcServlet extends HttpServlet {

    private final Calculator calculator = new Calculator();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {

        response.setContentType("application/json");

        PrintWriter pw = response.getWriter();

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

        String jsonStr = jb.toString();
        JsonObject jsonResp = new JsonObject();

        try {
            JsonObject jsonObject = JsonParser.parseString(jsonStr).getAsJsonObject();
        double a = jsonObject.get("a").getAsDouble();
        double b = jsonObject.get("b").getAsDouble();
        String math = jsonObject.get("math").getAsString();

        double result = calculator.calculation(a, b, math);

        jsonResp.addProperty("result", result);

        } catch (JsonSyntaxException | IllegalStateException | NullPointerException e) {
            jsonResp.addProperty("error", "Invalid input: " + e.getMessage());
        } catch (IllegalArgumentException e) {
            jsonResp.addProperty("error", e.getMessage());
        }

          pw.print(jsonResp);
        pw.flush();
    }
}
