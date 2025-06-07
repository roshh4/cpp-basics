#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "502104";
    for(int i = s.size()-1; i >= 0; i--)
    {
        if((s[i] - '0') %2 != 0)
        {
            cout << (s.substr(0,i+1));
            break;
        }
    }
}