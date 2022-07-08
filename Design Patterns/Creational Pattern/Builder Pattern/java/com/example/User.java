package com.example;

import com.example.interfaces.Builder;

public class User {
    private int age;
    private String firstName;
    private String lastName;
    private String phoneNumber;
    private String address;

    private User(UserBuilder builder) {
        this.age = builder.age;
        this.firstName = builder.firstName;
        this.lastName = builder.lastName;
        this.phoneNumber = builder.phoneNumber;
        this.address = builder.address;
    }

    public static class UserBuilder implements Builder<User> {
        private String phoneNumber;
        private int age;
        private String firstName;
        private String lastName;
        private String address;

        public UserBuilder setPhoneNumber(String phoneNumber) {
            this.phoneNumber = phoneNumber;
            return this;
        }

        public UserBuilder setAge(int age) {
            this.age = age;
            return this;
        }

        public UserBuilder setFirstName(String firstName) {
            this.firstName = firstName;
            return this;
        }

        public UserBuilder setLastName(String lastName) {
            this.lastName = lastName;
            return this;
        }

        public UserBuilder setAddress(String address) {
            this.address = address;
            return this;
        }

        @Override
        public User build() {
            return new User(this);
        }
    }

    public int getAge() {
        return age;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public String getAddress() {
        return address;
    }
}