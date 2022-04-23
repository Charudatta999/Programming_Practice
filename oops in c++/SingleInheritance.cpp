#include<iostream>
using namespace std;

class BaseClass{
    public:
        int num1 = 7;
};

class Derived : public BaseClass{
    public:
        int num2 = 4;
};

int main(){

    Derived d1;
    cout << d1.num1<<endl;
    cout << d1.num2 << endl;

    return 0;
}