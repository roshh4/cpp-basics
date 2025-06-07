#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string s = "hi im rosh how are you";
    string w;
    vector <string> v;
    stringstream ss(s);
    while(ss >> w)
    {
        v.push_back(w);
    }
    w = "";
    for(int i = v.size()-1; i >= 0; i--)
    {
        w += v[i];
        if(i > 0)
        {
            w += " ";
        }
    }
    cout << w;
}