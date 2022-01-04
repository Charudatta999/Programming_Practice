
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> rotateLeft(int d, vector<int> arr)
{
    int size = d;
    for (int i = 0; i < size; i++)
    {
        int temp = arr[i];
        arr.push_back(temp);
        d--;
    }
    for (int j = 0; j < size; j++)
        arr.erase(arr.begin());

    return arr;
}

int main()
{

    int n, d;
    cin >> n;
    cin >> d;
    vector<int> arr(n);
    int input;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cout << temp;
        arr[i] = temp;
    }
    cout << endl;

    vector<int> result = rotateLeft(d, arr);
    for (int j = 0; j < n; j++)
    {
        std::cout << result[j];
    }
    cout << endl;

    return 0;
}