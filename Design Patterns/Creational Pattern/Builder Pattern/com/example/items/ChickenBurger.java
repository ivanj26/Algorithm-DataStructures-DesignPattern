package com.example.items;

public class ChickenBurger extends Burger {

    @Override
    public float price() {
        return 10000;
    }
    
    @Override
    public String name() {
        return "Chicken " + super.name();
    }
}
