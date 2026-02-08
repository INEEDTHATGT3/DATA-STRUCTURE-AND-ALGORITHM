#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class abc{
    int x;
    int *y;
    public:
    abc(){
        x=0;
        y= new int(0);
    }

    int getX() const{
        return x;
    }

    void setX(int _val){
        x = _val;
    }
    
    int getY(){
        return *y;
    }

    void setY(int _val){
        *y = _val;
    }
};

int main(){
    const int cx = 5;
    // cx=10; not possible

    //previous old mathod to vhange const
    //int *p = &cx;
    //*p = 10;
    //cout<< cx << endl;

    //const with pointers
    const int *a1 = new int(2);
    cout << *a1 <<endl; //const data, non const pointer
    int b = 5;
    a1 = &b; //pointer reassigned
    cout << *a1 << endl;

    int *const a2 = new int(2); //const pointer but non const data
    *a2 = 20;
    cout << *a2 << endl;

    const int *const a3 = new int(10);
    cout << *a3 << endl;

    abc obj;
    cout << obj.getX() << endl;
    cout << obj.getY() << endl;
    return 0;
}