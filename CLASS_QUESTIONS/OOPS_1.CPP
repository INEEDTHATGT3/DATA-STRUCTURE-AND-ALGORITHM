#include <iostream>
#include <string>
#include <vector>
using namespace std;

class animal {
    //state or properties
    private: 
    int weight;
    public:
    int age;
    string name;

    // default constructor -> overwriiten already present constructor 
    animal(){
        this->weight = 0;
        this->age = 0;
        this->name = "";
        cout << "constructor called" << endl;
    }

    //parameterized constructor called
    animal(int age){
        this->age = age;
        cout << "parameterized constructor called" << endl;
    }

    animal(int age, int weight,string name){
        this->age = age;
        this->weight = weight;
        this->name = name;
        cout << "parameterized constructor 3 called" << endl;
    }

    //copy constructor
    animal(const animal& obj){
        this->age = obj.age;
        this->weight = obj.weight;
        this->name = obj.name;
        cout << "copy constructor called" << endl;
    }


    //behaviour or functions
    void eat(){
        cout << "eating" << endl;
    }

    void sleep(){
        cout << "sleeping" << endl;
    }

    int getweight(){
        return weight;
    }

    int setweight(int weight){
        this->weight = weight;
    }
};

int main(){
    //object creation

    //static memory allocation
    animal ramesh;
    ramesh.age = 15;
    ramesh.name = "lion";
    cout << "age of ramesh is" << ramesh.age << endl;
    cout << "name of ramesh is:" << ramesh.name << endl;
    
    ramesh.eat();
    ramesh.sleep();

    // to private member
    ramesh.setweight(100);
    cout << "weight of ramesh is:" << ramesh.getweight() << endl;

    //dynamic memory allocation

    animal* suresh = new animal;
    suresh->age = 15;
    suresh->name = "billi";

    //alternative 
    (*suresh).age = 19;
    (*suresh).name = "kutta";
    suresh->eat();

    animal a(10); // static memory
    animal* b = new animal(100, 10, "babbar"); //dyanmic memory

    animal b = a; //copy constructor called
    //or 
    animal b(a);

    animal c;
    c.age = 100;
    c.name = "tom";
    c.setweight(100);

    return 0;
}