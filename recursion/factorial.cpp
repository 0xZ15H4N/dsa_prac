#include<iostream>
/*
1> First find out the recursion relation how to find the execution
2> After that , we need to figure out the base case of the function 


*/


int factorial(int n){

    if(n == 0){     // base case
        return 1;   
    }
    return n  * factorial(n - 1);
}

int main(){
    int n ;
    std::cout<<"enter the value of n";
    std::cin >> n;
    std::cout<<"The factorial of "<<n<<" - > "<<factorial(n);
    return 0;
}