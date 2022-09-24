#include <iostream>
#include <string>
using namespace std;

int value(char c)
{
    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;
    else
        return -1;
}
int main()
{
    string s;
    cout << "Enter a roman string: ";
    cin >> s;
    int n1, n2, sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        n1 = value(s[i]);

        if (i + 1 < s.length())
        {
            n2 = value(s[i + 1]);

            if (n1 >= n2)
            {
                sum += n1;
            }
            if (n1 < n2)
            {
                sum = sum + n2 - n1;
                i++;
            }
        }
        else
        {
            sum += n1;
        }
    }

    cout << "integer is: " << sum << endl;

    return 0;
}