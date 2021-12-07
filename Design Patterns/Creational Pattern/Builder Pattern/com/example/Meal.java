package com.example;

import java.util.ArrayList;

import com.example.interfaces.Item;

public class Meal {
    private ArrayList<Item> items;

    public Meal() {
        items = new ArrayList<>();
    }

    public void addItem(Item item) {
        items.add(item);
    }

    public float getTotalPrice() {
        float total = 0;

        for (Item item : items) {
            total += item.price();
        }

        return total;
    }
}
