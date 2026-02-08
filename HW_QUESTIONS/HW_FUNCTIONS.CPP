#include <iostream>
#include <cmath> // For sqrt function
using namespace std;

float circle_area(float r) {
    // Function to calculate the area of a circle
    const float pi = 3.14159; // Define the value of pi
    float area = pi * r * r; // Area formula: πr²
    return area; // Return the calculated area
}

bool checkeven(int n) {
    // Function to check if a number is even
    if(/* n % 2 == 0*/ n & 1 == 0) {
        // Using bitwise AND to check if n is even
        return true; // Returns true if n is even
    } else {
        return false; // Returns false if n is odd
    }
}

long long int factorial(long long int n) {
    if (n<0){
        cout << "Factorial is not defined for negative numbers." << endl;
        return -1; // Return -1 for negative input
    }
    else if(n==0 || n==1) {
        return 1; // Factorial of 0 or 1 is 1
    } else {
        long long int fact = 1; // Initialize factorial to 1
        for (long long int i = 2; i <= n; i++) {
            fact = i*fact; // Multiply to get factorial
        }
        return fact; // Return the calculated factorial
    }
}

bool checkprime(int b){
    // Function to check if a number is prime
    if (b <= 1) {
        return false; // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i < sqrt(b); i++) { // Check divisibility from 2 to sqrt(b)
        if (b % i == 0) {
            return false; // If divisible, b is not prime
        }
    }
    return true; // If no divisors found, b is prime
}

int main() {
    float radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius; // Input the radius from the user

    int n;
    cout << "Enter a number to check if it is even/odd: ";
    cin >> n; // Input the number to check
    
    if (radius < 0) {
        cout << "Radius cannot be negative." << endl; // Check for negative radius
    } else {
        float area = circle_area(radius); // Call the function to calculate area
        cout << "The area of the circle with radius " << radius << " is: " << area << endl; // Output the area
    }

    bool is_even = checkeven(n); // Call the function to check if n is even
    if (is_even) {
        cout << n << " is even." << endl; // Output if n is even
    } else {
        cout << n << " is odd." << endl; // Output if n is odd
    }
    // Additional functionality can be added here as needed
    return 0; // Return 0 to indicate successful execution

    long long int ans = factorial(n); // Call the factorial function
    if (ans != -1) { // Check if factorial was calculated successfully
        cout << "The factorial of " << n << " is: " << ans << endl; // Output the factorial
    }

    bool isprime = checkprime(n); // Call the function to check if n is prime
    if(isprime) {
        cout << n << " is a prime number." << endl; // Output if n is prime
    } else {
        cout << n << " is not a prime number." << endl; // Output if n is not prime
    }

    for(int i =2; i<= n; i++){
        bool isiprime = checkprime(i); // Check each number from 1 to n
        if(isiprime){
            cout << i << " "; // Output the prime numbers
    }
}