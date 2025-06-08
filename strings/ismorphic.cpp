#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s = "foo";
    string t = "bar";
    int m1[128] = {0};
    int m2[128] = {0};
    bool f = true;
    for(int i = 0; i < s.length(); i++)
    {
        if(m1[s[i]] == 0 && m2[t[i]] == 0)
        {
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        else if ( m1[s[i]]!= t[i] || m2[t[i]] != s[i])
        {
            f = false;
        }
    }
    cout << f;
}