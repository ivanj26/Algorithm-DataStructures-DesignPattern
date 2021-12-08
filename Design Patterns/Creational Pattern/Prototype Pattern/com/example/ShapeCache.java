package com.example;

import java.util.Hashtable;

import com.example.interfaces.Shape;

public class ShapeCache {
    private static boolean hasBeenLoaded = false;
    private static Hashtable<Long, Shape> table = new Hashtable<>();

    public static Shape getShape(Long id) throws CloneNotSupportedException, Exception {
        if (!hasBeenLoaded) {
            throw new Exception("Must be loaded first.. Please call loadCache() method!");
        }

        Shape cacheShape = table.get(id);

        return (Shape) cacheShape.clone();
    }

    public static void loadCache() {
        hasBeenLoaded = true;

        Circle circle = new Circle(1L);
        table.put(circle.getId(), circle);

        Rectangle rect = new Rectangle(2L);
        table.put(rect.getId(), rect);
    }
}
