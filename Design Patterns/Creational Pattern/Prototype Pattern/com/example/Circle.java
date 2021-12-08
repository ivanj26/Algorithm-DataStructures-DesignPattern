package com.example;

import com.example.interfaces.Shape;

public class Circle extends Shape {

    public Circle(Long id) {
        super(id);

        this.type = "circle";
    }

    @Override
    public void draw() {
        System.out.println("Drawing a circle...");
    }
}
