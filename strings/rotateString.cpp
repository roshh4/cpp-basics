#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s = "abcde";
    string t = "bcdef";
    s = s + s;
    bool flag = false;
    if(s.find(t) != string::npos)
    {
        flag = true;
    }
    cout << flag;
}