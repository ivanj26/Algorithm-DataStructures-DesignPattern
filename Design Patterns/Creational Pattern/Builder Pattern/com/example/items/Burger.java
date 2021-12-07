package com.example.items;

import com.example.interfaces.Item;
import com.example.interfaces.Packing;
import com.example.packings.PlasticWrapper;

public abstract class Burger implements Item {
    @Override
    public String name() {
        return this.getClass().getName();
    }

    @Override
    public Packing packing() {
        return new PlasticWrapper();
    }
}