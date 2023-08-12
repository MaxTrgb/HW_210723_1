#include "Fraction.h" // Include the Fraction class header
#include <iostream>

// Constructor with initialization list to set the integer and fractional parts
Fraction::Fraction(long int integer, unsigned short int fractional)
    : integerPart(integer), fractionalPart(fractional) {}

// Display the fraction (no modification of the object, so it's marked const)
void Fraction::display() const {
    std::cout << integerPart << "." << fractionalPart;
}

// Add another fraction to the current fraction (no modification, const)
Fraction Fraction::add(const Fraction& other) const {
    long int newIntegerPart = integerPart + other.integerPart;
    unsigned short int newFractionalPart = fractionalPart + other.fractionalPart;

    if (newFractionalPart >= 10000) {
        newFractionalPart -= 10000;
        newIntegerPart += 1;
    }

    return Fraction(newIntegerPart, newFractionalPart);
}

// Subtract another fraction from the current fraction (no modification, const)
Fraction Fraction::subtract(const Fraction& other) const {
    long int newIntegerPart = integerPart - other.integerPart;
    int newFractionalPart = fractionalPart - other.fractionalPart;

    if (newFractionalPart < 0) {
        newFractionalPart += 10000;
        newIntegerPart -= 1;
    }

    return Fraction(newIntegerPart, newFractionalPart);
}

// Multiply the current fraction by another fraction (no modification, const)
Fraction Fraction::multiply(const Fraction& other) const {
    long int intPart1 = integerPart;
    unsigned short int fracPart1 = fractionalPart;
    long int intPart2 = other.integerPart;
    unsigned short int fracPart2 = other.fractionalPart;

    // Convert fractional parts to a decimal value (0.7500 -> 0.75)
    double fracValue1 = double(fracPart1) / 10000.0;
    double fracValue2 = double(fracPart2) / 10000.0;

    // Calculate the product
    double productValue = (intPart1 + fracValue1) * (intPart2 + fracValue2);

    // Separate integer and fractional parts
    long int newIntegerPart = long(productValue);
    unsigned short int newFractionalPart = unsigned short((productValue - newIntegerPart) * 10000);

    // Adjust for potential rounding errors
    if (newFractionalPart == 10000) {
        newIntegerPart += 1;
        newFractionalPart = 0;
    }

    return Fraction(newIntegerPart, newFractionalPart);
}

// Check if two fractions are equal (no modification, const)
bool Fraction::isEqualTo(const Fraction& other) const {
    return (integerPart == other.integerPart) && (fractionalPart == other.fractionalPart);
}

// Check if two fractions are not equal (no modification, const)
bool Fraction::isNotEqualTo(const Fraction& other) const {
    return !isEqualTo(other);
}
