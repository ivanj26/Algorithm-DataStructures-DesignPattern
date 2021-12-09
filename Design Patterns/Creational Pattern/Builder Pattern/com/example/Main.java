package com.example;

public class Main {
    public static void main(String[] args) {
        User user = new User.UserBuilder()
                .setFirstName("Ivan")
                .setLastName("Jonathan")
                .setAddress("ABC no 60")
                .setAge(20)
                .setPhoneNumber("+628943824932")
                .build();

        System.out.println(user.getFirstName());
        System.out.println(user.getLastName());
        System.out.println(user.getAddress());
    }
}
