#include<iostream>
#include<string>
#include<vector>
using namespace std;

//encapsulation
class animal{
    public:

          int age;
          int weight;

          void  eat(){
            cout << "eating" << endl;

          }
          int getage(){
            return this->age;
          }
          int setage(int age){
            this->age = age;
          }
};

//inheritance
class dog : public animal{ // private, protected bhi check
public:
void print(){
    cout << this->age << endl;
}
};


int main(){

    dog D1;
    D1.eat();
    D1.age = 10;
    cout << D1.age << endl;
}
