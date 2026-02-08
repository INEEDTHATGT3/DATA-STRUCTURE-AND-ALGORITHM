#include <iostream>
#include <string>
#include <vector>
using namespace std;

class abc{
    public:
    int x;
    int *y;

    abc(int _x, int _y) : x(_x), y(new int(_y)){}  
    
    //default dumb copy constructor - shallow copy
    abc(const abc& obj){
        x = obj.x;
        //y = obj.y; //shallow copy
        y = new int(*obj.y); //deep copy change;
    }
    
    void print() const{
        printf("X:%d\nPTR Y:%p\ncontent of Y (*y):%d\n\n", x, y, *y);
    }
};

int main(){
    abc a(1,2);
    a.print();
    abc b = a; //call hota hai, COPY CONSTRUCTOR
    b.print();
    *b.y =20;
    b.print();

    a.print();
    return 0;
}