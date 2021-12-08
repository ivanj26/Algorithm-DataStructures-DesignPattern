package com.example;

import com.example.interfaces.Shape;

public class Rectangle extends Shape {
    Rectangle(Long id) {
        super(id);

        this.type = "rectangle";
    }

    @Override
    public void draw() {
        System.out.println("Drawing a rectangle...");
    }
}
