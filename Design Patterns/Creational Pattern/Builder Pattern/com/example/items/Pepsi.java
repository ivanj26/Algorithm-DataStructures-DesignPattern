package com.example.items;

public class Pepsi extends ColdDrink {

    @Override
    public float price() {
        return 10000;
    }

    @Override
    public String name() {
        return this.getClass().getName();
    }
    
}
