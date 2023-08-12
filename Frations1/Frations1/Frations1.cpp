#include <iostream>
#include "Fraction.h" 
using namespace std;

int main() {
    // Create two Fraction objects with initial values
    Fraction a(7, 2413); 
    Fraction b(3, 9468); 

    // Perform arithmetic operations on the fractions
    Fraction sum = a.add(b); 
    Fraction diff = a.subtract(b);
    Fraction product = a.multiply(b); 

    // Display the original fractions and their results
    cout << "Fraction a: ";
    a.display();
    cout << endl;

    cout << "Fraction b: ";
    b.display();
    cout << endl;

    cout << "Sum: ";
    sum.display();
    cout << endl;

    cout << "Difference: ";
    diff.display();
    cout << endl;

    cout << "Product: ";
    product.display();
    cout << endl;

    // Compare the fractions for equality
    if (a.isEqualTo(b)) {
        cout << "a and b are equal." << endl;
    }
    else {
        cout << "a and b are not equal." << endl;
    }

    return 0;
}
