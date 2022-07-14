package com.example;

import com.example.interfaces.Shape;

public class Square implements Shape {

    @Override
    public void draw() {
        System.out.println("Shape::draw()");
    }

}
