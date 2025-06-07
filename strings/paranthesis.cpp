#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s = "(()()()(()()))";
    string r = "";
    int x = 0;
    for(char c : s)
    {
        if(c == '(')
        {
            if(x > 0)
            {
                r += "(";
            }
            x++;
        }
        else
        {
            x--;
            if(x > 0)
            {
                r += ")";
            }
        }
    }
    cout << r;
}