package com.example;

import com.example.interfaces.Logger;

public class Main {
    private static Logger getChainOfLoggers() {
        Logger fileLogger = new FileLogger(Logger.DEBUG);
        Logger consoleLogger = new ConsoleLogger(Logger.INFO);
        Logger errorLogger = new ErrorLogger(Logger.ERROR);

        fileLogger.setNextLogger(consoleLogger);
        errorLogger.setNextLogger(fileLogger);

        return errorLogger;
    }

    public static void main(String[] args) {
        Logger logChain = getChainOfLoggers();

        logChain.logMessage(Logger.INFO,
                "This is an information.");
        System.out.println();

        logChain.logMessage(Logger.DEBUG,
                "This is an debug level information.");
        System.out.println();

        logChain.logMessage(Logger.ERROR,
                "This is an error information.");
    }
}
