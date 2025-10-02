#include<iostream>
using namespace std;

int main(){
    int n =37;
    int start = 0;
    int end = n;
    double ans = -1;
    while(start < end){
        long long int mid = start + (end-start)/2;
        if((mid * mid ) ==  n){
            ans = mid;
            break;
        }else if(mid*mid > n){
            end = mid-1;
        }else{
            start = mid +1;
            ans = mid;
        }
    } 
    double factor = 1;
    double temp = ans;
    for(int i = 0;i < 3; i++){
        factor = factor / 10;
        for(double j = ans ; j*j< n;j= j + factor){
            ans = j;
        }
    }
    cout<<"The sqrt of the "<<n<<" is "<<ans;
}