package com.example;

import com.example.items.ChickenBurger;
import com.example.items.CocaCola;
import com.example.items.Pepsi;
import com.example.items.VegetableBurger;

public class MealBuilder {
    public Meal buildRegularMeal() {
        Meal regMeal = new Meal();
        
        regMeal.addItem(new ChickenBurger());
        regMeal.addItem(new ChickenBurger());
        regMeal.addItem(new Pepsi());
        regMeal.addItem(new CocaCola());

        return regMeal;
    }

    public Meal buildVegMeal() {
        Meal vegMeal = new Meal();

        vegMeal.addItem(new VegetableBurger());
        vegMeal.addItem(new CocaCola());

        return vegMeal;
    }
}
