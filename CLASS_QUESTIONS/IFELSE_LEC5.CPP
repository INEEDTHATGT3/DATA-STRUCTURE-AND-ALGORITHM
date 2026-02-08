#include <iostream>
using namespace std;

int main()
{
    // std::cout << "hello\n" ;
    int score;
    cout << "Enter your score: " << endl;
    cin >> score;

    if(score < 300) {
        cout << "india wins" << endl;
    }
    else {
        cout << "pak wins" << endl;
    }

    // another case nest conditions

    int marks;
    cin>> marks;
    if(marks < 40) {
        cout << "fail" << endl;
    }
    else {
        if(marks < 60) {
        cout << "pass" << endl;
    }
        else {
            if(marks < 80) {
            cout << "good" << endl;
            }
            else {
            cout << "excellent" << endl;
            } 
        }
    }
    // if-elseif-else

    if(marks < 40) {
        cout << "fail" << endl;
    }
    else if(marks < 60) {
        cout << "pass" << endl;
    }
    else if(marks < 80) {
        cout << "good" << endl;
    }
    else {
        cout << "excellent" << endl;
    }

    return 0;
}
