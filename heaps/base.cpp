#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*


Quick-Notes


*/


class heap{
    public:
        int size;
        int arr[100];
    heap(){
        size = 0;
        arr[0] = -1;
    }
    
    void insertion(int val){
        size = size +1;
        arr[size] = val;
        int index = size;
        while(index > 1){
            int parent = index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1; i<= size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void deletion() {
        if(size == 0) return;

        arr[1] = arr[size];
        size--;

        int i = 1;

        while(true){
                int left = 2 * i;
                int right = 2 * i + 1;
                int largest = i;

                if(left <= size && arr[left] > arr[largest])
                    largest = left;

                if(right <= size && arr[right] > arr[largest])
                    largest = right;

                if(largest == i)
                    break;

                swap(arr[i], arr[largest]);
                i = largest;
            }
        }
};

void heapify(int arr[],int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

int main(){
    heap h;
    h.insertion(50);
    h.insertion(51);
    h.insertion(52);
    h.insertion(53);
    h.insertion(54);
    h.insertion(55);
    h.insertion(56);

    h.print();

    int arr[] = {-1,54,50,51,53,52,55,56};
    int n= 7;
    for(int i = n/2 ; i >0; i --){

        heapify(arr,n,i);
    }
    for(auto i : arr){
        cout<< i << " ";
    }
    cout<<endl;
    return 0;
    
}