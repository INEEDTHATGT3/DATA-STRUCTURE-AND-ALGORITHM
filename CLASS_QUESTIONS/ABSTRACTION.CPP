#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vendor provided library
//pure virtual function
#if !defined(BIRD_H)
#define BIRD_H

class Bird{
    public:
        virtual void eat() = 0;
        virtual void fly() = 0;
        // classes that inherits this class must implement this pure virtual functions
};

class Sparrow : public Bird{
    public:
        void eat(){
            cout<< "sparrow eats" << endl;
        }
        void fly(){
            cout<< "sparrow flies" << endl;
        }
};
#endif // BIRD_H

int main(){
    vector<int> v = {3,4,1,2};
    sort(v.begin(),v.end()); //we dont know  the implementation of sort function -> abstraction
    for(auto i : v){
        cout << i << " ";
    }

    return 0;
}