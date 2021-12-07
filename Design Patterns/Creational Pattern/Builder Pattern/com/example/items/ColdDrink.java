package com.example.items;

import com.example.interfaces.Item;
import com.example.interfaces.Packing;
import com.example.packings.Bottle;

public abstract class ColdDrink implements Item {
    @Override
    public Packing packing() {
        return new Bottle();
    }
}
