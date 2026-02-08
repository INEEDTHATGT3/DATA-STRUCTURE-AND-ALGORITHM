#include<iostream>
#include<string>
#include<vector>
using namespace std;

// polymorphism : function overloading
class Maths{
    public:
    int sum(int a, int b){
        cout << " first signature" << endl;
        return a+b;
    }
    int sum(int a,int b, int c){
        cout << "second signature" << endl;
        return a+b+c; 
    }
    int sum(int a, float b){
        cout << "third signature" << endl;
        return a+b+10;
    }
};

// operator overloading
class parameter{
    public:
    int val;

    void operator + (parameter& obj2){
        int value1 = this->val;
        int value2 = obj2.val;
        cout << "value of obj1 - obj2 is" << value1 - value2 << endl;
    }
};

int main(){
    Maths obj;

    cout << obj.sum(2,5) << endl;
    cout << obj.sum(2,5,7) << endl;
    cout << obj.sum(2,5.56f) << endl;

    parameter obj1, obj2;
    obj1.val = 7;
    obj2.val = 10;
    //this should print diff b/w them
    obj1 + obj2;
    return 0;
}