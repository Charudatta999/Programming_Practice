#include<iostream>
#include<string>
using namespace std;

class Base{
    public:
        void baseFun(int i,int j){
            cout << i + j << endl;
        }
};

class LevelOne: public Base{
 public:
    void baseFun(int i, int j){
        cout << i * j << endl;
    }
};

class LevelTwo: public Base{
 public:
    void baseFun(int i, int j){
        cout << i / j << endl;
    }
};

int main(){
    Base b;
    LevelOne l1;
    LevelTwo l2;
    b.baseFun(10, 15);
    l1.baseFun(10, 15);
    l2.baseFun(15, 15);

    return 0;
}