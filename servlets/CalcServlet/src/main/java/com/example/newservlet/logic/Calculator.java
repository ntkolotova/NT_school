package com.example.newservlet.logic;

public class Calculator {

    public double calculation(double a, double b, String math) {

        switch (math) {

            case "+":
                return a + b;
                case "-":
                    return a - b;
                    case "*":
                        return a * b;
                        case "/":
                            if (b != 0) {
                                return a / b;
                            } else throw new IllegalArgumentException("You can't divide by zero!");

                            default: throw new IllegalArgumentException("Unknown operation: " + math);
        }
    }
}