package com.example;

import com.example.interfaces.Shape;

public class Main {
    public static void main(String[] args) {
        try {
            ShapeCache.loadCache();

            Shape shapeOne = ShapeCache.getShape(1L);
            shapeOne.draw();

            Shape shapeTwo = ShapeCache.getShape(2L);
            shapeTwo.draw();

        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        System.out.println();
    }
}