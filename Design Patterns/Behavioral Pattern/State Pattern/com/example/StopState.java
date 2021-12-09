package com.example;

import com.example.interfaces.State;

public class StopState implements State {

    @Override
    public void doAction(Context context) {
        System.out.println("Player now in stop state");
        context.setState(this);
    }
    
    @Override
    public String toString() {
        return this.getClass().getSimpleName();
    }
}
