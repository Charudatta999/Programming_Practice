#include<iostream>
#include <string>
#include <sstream>
#include <vector>

int main()
{
    std::stringstream str;
    str << "807";
    int num;
    (str) >> num;
    std::cout << num << "\n";
    num = 0;
    int x =0;
    std::vector<int> numlist ={};
    while(num!=0)
    {   
        numlist.push_back(num % 10);
        int digit = num % 10 ;
        x = x *  10 + digit;
        num /= 10;
    }
    std::cout << x << std::endl;
    return 0;
}