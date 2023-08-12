#pragma once 
#include <iostream>

class Fraction {
private:
    long int integerPart; // Stores the integer part of the fraction
    unsigned short int fractionalPart; // Stores the fractional part of the fraction

public:
    // Constructor with default values to initialize the Fraction object
    Fraction(long int integer = 0, unsigned short int fractional = 0);

    // Method to display the fraction
    void display() const;

    // Methods to perform arithmetic operations on fractions
    Fraction add(const Fraction& other) const; 
    Fraction subtract(const Fraction& other) const; 
    Fraction multiply(const Fraction& other) const; 

    // Methods to compare fractions for equality and inequality
    bool isEqualTo(const Fraction& other) const; 
    bool isNotEqualTo(const Fraction& other) const; 
};
