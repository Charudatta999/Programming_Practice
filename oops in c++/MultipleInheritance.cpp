#include<iostream>

using namespace std;

class FirstClass{
//constructor it invokes when class's object is cleared
public:
FirstClass(){
          cout << "from First classs" << endl;
      }

};

class SecondClass{
public :
    SecondClass(){
    std::cout << "from Second Class" << endl;
}
};

class DerivedClass : public FirstClass, SecondClass
{

public:
    void d1()
    {
        cout << "derived Class" << endl;
    }
};

int main(){
    DerivedClass obj;
    obj.d1();

    return 0;
}