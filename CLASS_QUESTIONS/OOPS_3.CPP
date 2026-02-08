#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Animal{
    public:
    Animal(){
        cout << "Animal constructor" << endl;
    }
    virtual void speak(){
        cout << "speaking" << endl;
    }
};

class Dog: public Animal{
    public:

    Dog(){
        cout << "Dog constructor" << endl;
    }
    //overriding
    void speak(){
        cout << "barking" << endl;
    }
};

int main(){
    // Animal a;
    // a.speak();
    
    // Animal* no= new Animal();
    // no -> speak();

    //upcasting : parent class pointer can point to child class object
    Animal* sam= new Dog();
    sam-> speak();

    //downcasting : child class pointer cannot point to parent class object
    Dog* b = (Dog*) new Animal();
    b->speak();

    //2d array by dyanmic memory allocation
    int row = 5;
    int col = 4;

    int** arr = new int*[row];
    for(int i=0; i<row; i++){
        arr[i]= new int[col];
    }

    //printing 2d array
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }

    //deleting 2d array
    for(int i=0; i<row; i++){
        delete []arr[i];
    }
    delete []arr;

    //2d array by vector
    vector<vector<int>> arr2d(row, vector<int>(col,0));

    return 0;
}