package com.example;

public class Main {
    public static void main(String[] args) {
        Context context = new Context();
        
        StartState start = new StartState();
        start.doAction(context);

        System.out.println("State in context: " + context.getState().toString());
        System.out.println();

        StopState stop = new StopState();
        stop.doAction(context);

        System.out.println("State in context: " + context.getState().toString());
        System.out.println();
    }
}