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

class LevelTwo{
 public:
    void baseFun(int i, int j){
        cout << i / j << endl;
    }
};

int main(){
    Base b;
    b.baseFun(10, 15);
    b.baseFun(10, 15);
    b.baseFun(15, 15);

    return 0;
}