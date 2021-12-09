package com.example;

import com.example.interfaces.Logger;

public class ErrorLogger extends Logger {

    protected ErrorLogger(int level) {
        super(level);
    }

    @Override
    protected void write(String message) {
        System.out.println("[ERROR] Console::Logger: " + message);
    }
}
