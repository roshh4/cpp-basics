#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

int main()
{
    string s = "aabcbaa";
    int sum = 0;
    for(int i = 0; i < s.length(); i++)
    {
        unordered_map <char, int> map;
        for(int j = i; j < s.length(); j++)
        {
            map[s[j]]++;
            int ma = 0;
            int mi = INT_MAX;
            for(auto k : map)
            {
                ma = max(k.second, ma);
                mi = min(k.second, mi);
            }
            sum += (ma - mi);
        }
    }
    cout << sum;
}