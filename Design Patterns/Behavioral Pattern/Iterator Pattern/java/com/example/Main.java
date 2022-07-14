package com.example;

import com.example.interfaces.Iterator;

public class Main {
    public static void main(String[] args) {
        Container container = new Container();

        for (Iterator it = container.getIterator(); it.hasNext();) {
            String name = it.next();

            System.out.printf("Name: %s\n", name);
        }
    }
}
