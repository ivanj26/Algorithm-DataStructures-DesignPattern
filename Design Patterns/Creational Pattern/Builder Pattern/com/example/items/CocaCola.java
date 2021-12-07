package com.example.items;

public class CocaCola extends ColdDrink {

    @Override
    public float price() {
        return 8000;
    }

    @Override
    public String name() {
        return this.getClass().getName();
    }
}
