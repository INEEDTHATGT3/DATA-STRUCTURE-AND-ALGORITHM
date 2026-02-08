#include <iostream>
using namespace std;

void printname() {
    int n;
    cout << "Enter a number: " << endl;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "dhruv" << endl;
    }
}
 
// pass by value
void printnumber(int a){
    // This function takes a copy of the variable 'a'
    // passed from main, so changes to 'a' here do not affect the original variable.
    cout << "The number is: " << a << endl;
    a++; // This will not affect the original variable in main
    cout << "After incrementing, the number is: " << a << endl;
}

// function to add 2 numbers
int add(int a, int b) {
    int result = a + b;
    return result; // Now the function correctly returns an int
}

// function to find maximum of 3 numbers
int findmax(int a1, int b2, int c3) {
    if (a1 >= b2 && a1 >= c3) {
        return a1; // 'a' is the maximum
    } else if (b2 >= a1 && b2 >= c3) {
        return b2; // 'b' is the maximum
    } else {
        return c3; // 'c' is the maximum
    }
}

// function to print counting from 1 to n
void printcounting(int n) {// n is parameter
    cout << "Counting from 1 to " << n << ":" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;
}

// function to get grade based on marks
char getgrade(int marks) {
   switch(marks / 10) {
        case  10:
            return 'A'; break;// Grade A for marks 90-100
        case 9:
            return 'A'; break;// Grade A for marks 90-100
        case 8:
            return 'B'; break;// Grade B for marks 80-89
        case 7:
            return 'C'; break; // Grade C for marks 70-79
        case 6:
            return 'D'; break;// Grade D for marks 60-69
        case 5:
            return 'E'; break;// Grade E for marks 50-59 //break not needed here but added for habit formation
        default:
            return 'F'; // Grade F for marks below 50
    }
}

// function to get sum of even numbers up to n
int getevensum(int n) {
    int sum = 0;
    for (int i = 2; i <= n; i=i+2) {
        sum = sum + i;  // Adding only even numbers
    }
    return sum;
}

int main() {
    printname();
    printname();

    int a = 10;
    printnumber(a);
    cout << "The original number in main is still: " << a << endl;
    // The original variable 'a' remains unchanged in main
    cout << "address of a in main: " << &a << endl;

    int b;
    cout << "Enter number 1: ";
    cin >> b;
    int c;
    cout << "Enter number 2: ";
    cin >> c;
    int d;
    cout << "Enter number 3: ";
    cin >> d;

    int sum = add(b, c);
    cout << "The sum of " << b << " and " << c << " is: " << sum << endl;

    int maximumnumber = findmax(b, c, d);
    cout << "The maximum number among " << b << ", " << c << ", and " << d << " is: " << maximumnumber << endl;

    printcounting(d);
    // d is an argument to printcounting, which prints counting from 1 to d

    int marks;
    cout << "Enter your marks: ";
    cin >> marks;

    char finalgrade = getgrade(marks);
    cout << "Your final grade is: " << finalgrade << endl;

    int evenadd = getevensum(d);

    return 0;
}