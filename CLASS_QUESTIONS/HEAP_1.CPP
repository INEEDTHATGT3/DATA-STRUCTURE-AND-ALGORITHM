#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<queue>
#include<stack>
using namespace std;

class Heap{
    public:
    int arr[101]; //h.w make it as dynamic array
    int size;

    Heap(){
        size=0; 
    }

    void Insert(int value){
        //value insert karo end me
        size = size+1;
        int index = size;
        arr[index] = value;

        //now placing at correct position
        while(index>1){
            int parentIndex = index/2;

            if(arr[index] > arr[parentIndex]){
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    int Delete(){

        int ans = arr[1];
        //replace root node value with last node data
        arr[1] = arr[size];
        size--;
        
        //place root node ka data on its correct position
        int index =1;
        while(index < size){
            int left = 2*index;
            int right = 2*index+1;

            int largest = index;
            if(left < size && arr[largest] < arr[left]){
                largest = left;
            }
            if(right<size && arr[largest] < arr[right]){
                largest = right;
            }
            if(largest == index){
                //value at correct position
                break;
            }
            else{
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
        return ans;
    }
};

void heapify(int arr[], int n, int i){
    int index = i;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;

    int largest = index;

    if(leftIndex<=n && arr[largest] < arr[leftIndex]){
        largest = leftIndex;
    }
    if(rightIndex<=n && arr[largest] < arr[rightIndex]){
        largest = rightIndex;
    }

    if(index != largest){
        //left ya right child me se koi > hogya currentNode se
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr,n,index);
    }
}

void bulidHeap(int arr[], int n){
    for(int i=n/2; i>0; i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[], int n){
    int index = n;

    while(n != 1){
        swap(arr[1], arr[n]);
        index--;
        n--;

        //heapify
        heapify(arr, n, 1);
    }
}

int main(){
    Heap h;
    
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;

    h.size = 5;

    cout << "printing the heap" << endl;
    for(int i=0; i<=h.size; i++){
        cout << h.arr[i] << " ";
    }cout << endl;

    h.Insert(110);
    cout << endl << "printing the heap" << endl;
    for(int i=0; i<=h.size; i++){
        cout << h.arr[i] << " ";
    }cout << endl;

    int arr[]= {-1,12,15,13,11,14};
    int n = 5;
    bulidHeap(arr, n);

    cout<< "printing the heap" << endl;
    for(int i=0; i<=n; i++){
        cout <<arr[i] << " ";
    }
    cout << endl;

    heapSort(arr,n);
    cout<< "printing the heap" << endl;
    for(int i=1; i<=n; i++){
        cout <<arr[i] << " ";
    }

    return 0;
}