#include <iostream>
using namespace std;

class A {
    private :
        int a;
        int b;

    public  :
        int c = 100;
        A(){
            cout<<"wow "<<c<<endl;
        }
};

class B:public A{
    private : 
        int a;
        int b;
        int c;
    public:
        int d = 1000;
        void wow(){
            cout<<"hello";
        }
};


int main(){

    A a,b,c;
    B d;
    d.wow();
    return 0;
}
