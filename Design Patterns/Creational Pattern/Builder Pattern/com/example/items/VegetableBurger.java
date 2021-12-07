package com.example.items;

public class VegetableBurger extends Burger {

    @Override
    public float price() {
        return 50000;
    }

    @Override
    public String name() {
        return "Vegetable " + super.name();
    }
    
}
