#include <iostream>
#include <string>
#include <vector>
using namespace std;

//types of inheritance
//1. single inheritance

class car{
    public:
    string name;
    int weight;
    int age;

    void speedup(){
        cout << "speeding up"<< endl;
    }

    void brake(){
        cout << "braking" << endl;
    }
};

class innova: public car{
    public:
    int capacity;
};

//2. multi level inheritance
class engine: public innova{
    public:
    int horsepower;
};

//3. multiple inheritance

class chassis: public innova{
    public:
    char ladderframe;
};

class fortuner: public engine, public chassis{
    public:
    int capacity;
};

//hierarchial inheritance
// innova is parent class and engine and chassis are child classes of innova

//hybrid inheritance
// already present in code

int main(){
    innova meri;
    meri.speedup();

    //multi level inheritance
    engine diesel;
    diesel.brake();

    //multiple inheritance
    fortuner toyotasuv;
    toyotasuv.capacity = 2.7;
    toyotasuv.horsepower = 300;

    return 0;
}
