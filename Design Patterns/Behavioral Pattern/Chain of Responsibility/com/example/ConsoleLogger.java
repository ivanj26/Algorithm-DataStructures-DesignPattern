package com.example;

import com.example.interfaces.Logger;

public class ConsoleLogger extends Logger {
    protected ConsoleLogger(int level) {
        super(level);
    }

    @Override
    protected void write(String message) {
        System.out.println("[INFO] Console::Logger: " + message);
    }
}
