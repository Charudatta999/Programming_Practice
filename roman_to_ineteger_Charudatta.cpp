class Solution
{
public:
    int value(char a)
    {
        if (a == 'I')
        {
            return 1;
        }

        if (a == 'V')
        {
            return 5;
        }

        if (a == 'X')
        {
            return 10;
        }

        if (a == 'L')
        {
            return 50;
        }

        if (a == 'C')
        {
            return 100;
        }

        if (a == 'D')
        {
            return 500;
        }

        if (a == 'M')
        {
            return 1000;
        }
        return -1;
    }

    int romanToInt(string s)
    {
        int res = 0;

        for (int i = 0; i < s.length(); i++)
        {
            // res+=value(s[i]);
            int n1 = value(s[i - 1]);
            int n2 = value(s[i]);
            if (n1 < n2)
            {
                res -= n1;
                res += n2 - n1;
            }
            else
            {
                res += n2;
            }
        }
        return res;
    }
};
