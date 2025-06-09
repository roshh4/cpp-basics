#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    int count = 0, max = 0;
    for(char c: s)
    {
        if(c == '(')
        {
            count++;
        }
        else if (c == ')')
        {
            if(max < count)
            {
                max = count;
            }
            count--;
        }
    }
    cout << max;
}