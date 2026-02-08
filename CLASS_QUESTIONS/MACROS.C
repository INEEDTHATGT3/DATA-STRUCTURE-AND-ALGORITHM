#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define PI 3.14159465
#define MAXX(x,y) (x>y?x:y)

float circleArea(float r){
    return PI*r*r;
}

int main(){
    cout<< circleArea(65.4) << endl;
    return 0;
}