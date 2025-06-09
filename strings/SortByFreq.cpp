#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

int main()
{
    string s = "roshini";
    unordered_map <char, int> sort;
    for(char c : s)
    {
        sort[c]++;
    }
    multimap <int, char> sortedfreq;
    for(auto it : sort)
    {
        sortedfreq.insert({it.second, it.first});
    }
    string res = " ";
    for(auto i = sortedfreq.rbegin(); i != sortedfreq.rend(); i++)
    {
        res += string(i->first, i->second);
    }
    cout << res;
}