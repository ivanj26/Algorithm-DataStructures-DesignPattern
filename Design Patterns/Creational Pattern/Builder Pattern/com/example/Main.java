package com.example;

public class Main {
    public static void main(String[] args) {
        MealBuilder builder = new MealBuilder();

        Meal meal = builder.buildVegMeal();
        System.out.printf("Total price of Vegetable Meal: %.2f\n", meal.getTotalPrice());
    }
}
