#include<iostream>

int fib(int n,int a, int b){

    if(n == 1){ 
        return b;
    }
    
    // int temp = b;<<
    // b = a + b;
    // a = temp;
    // n--;
    int ans = fib(n-1,b,a+b);
    if(n == 5 ){
        std::cout<<"only when 5";
    }
    return ans;
}

int fib(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fib(n-1) + fib(n-2);
}

int main(){
    int n ;
    std::cin>>n;
    std::cout<<std::endl<<fib(n,0,1);
    std::cout<<std::endl<<fib(n);
    return 0;
}