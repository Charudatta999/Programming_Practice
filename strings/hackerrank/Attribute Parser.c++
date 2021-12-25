
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

vector<string> tag_stack; //tag1 tag2
map<string, string> attrs;

void insert_attr(string &name, string &val)
{
    string full;
    for (string &str : tag_stack)
        full += str + "."; //tag1.tag2.
    full.pop_back();       //tag1.tag2
    full += "~" + name;    //tag.tag2~name
    attrs[full] = val;
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> c; // taking single character <

        if (cin.peek() == '/')
        {
            string cn;
            cin >> cn;
            tag_stack.pop_back();
        }
        else
        {
            string name;
            cin >> name; //taking tag name

            if (name.back() == '>')
            {                              //<tag1>
                name.pop_back();           // tag1> => tag1
                tag_stack.push_back(name); //adding tag name int vector
            }
            else
            {
                tag_stack.push_back(name); // adding tag name int vector

                for (;;)
                {
                    string attr_name, attr_val, eq;
                    cin >> attr_name >> eq >> attr_val; //taking att value & att name
                    if (attr_val.back() == '>')
                    {                                  //"HelloWorld">
                        attr_val.pop_back();           //"HelloWorld"
                        attr_val.pop_back();           //"HelloWorld
                        attr_val = attr_val.substr(1); // HelloWorld
                        insert_attr(attr_name, attr_val);
                        break;
                    }
                    else
                    {
                        attr_val.pop_back();
                        attr_val = attr_val.substr(1);
                        insert_attr(attr_name, attr_val); 
                    }
                }
            }
        }
    }

    for (int i = 0; i < q; ++i)
    {
        string quer;
        cin >> quer;
        if (attrs.find(quer) != attrs.end())
            cout << attrs[quer] << endl;
        else
            cout << "Not Found!" << endl;
    }

    return 0;
}