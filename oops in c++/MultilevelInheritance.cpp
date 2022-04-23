#include<iostream>

using namespace std;

class Base{
    public:
        int a = 0;
};

class Parent: public Base{
    public:
        int b = 1;
};

class Child:public Parent
{
    public:
        int a = 5;
};

int main(){

    Child c;
    cout << c.a<<endl;
    cout << c.b << endl;
    cout << c.Base::a << endl;

    return 0;
}