#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
vector<T> getSeparatedValuesFromUser(char separator = ',')
{
    stringstream ss;
    string str;
    getline(cin, str);
    replace(str.begin(), str.end(), separator, ' ');
    ss << str;

    T value{0};
    vector<T> values;
    while (ss >> value)
    {
        values.push_back(value);
    }

    return values;
}

int main()
{
    cout << "Enter , seperated values: ";
    auto values = getSeparatedValuesFromUser<int>();

    //display values
    cout << "Read values: " << endl;
    for (auto v : values)
    {
        cout << v << endl;
    }
}