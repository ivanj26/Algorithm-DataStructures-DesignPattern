package com.example;

import com.example.interfaces.IContainer;
import com.example.interfaces.Iterator;

public class Container implements IContainer {
    private String arr[] = { "Ivan", "Budi", "Badu", "Belli", "Budi P" };

    @Override
    public Iterator getIterator() {
        return new NameIterator();
    }

    private class NameIterator implements Iterator {
        int index = 0;

        @Override
        public String next() {
            if (hasNext()) {
                return arr[index++];
            }

            return null;
        }

        @Override
        public boolean hasNext() {
            return index < arr.length;
        }

    }
}
