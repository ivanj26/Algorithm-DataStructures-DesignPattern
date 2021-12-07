package com.example.packings;

import com.example.interfaces.Packing;

public class Bottle implements Packing {

    @Override
    public String name() {
        return "Bottle";
    }

}
