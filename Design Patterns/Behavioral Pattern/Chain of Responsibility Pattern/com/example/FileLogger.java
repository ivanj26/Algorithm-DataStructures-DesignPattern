package com.example;

import com.example.interfaces.Logger;

public class FileLogger extends Logger {
    public FileLogger(int level) {
        super(level);
    }

    @Override
    protected void write(String message) {
        System.out.println("[DEBUG] File::Logger: " + message);
    }
}
