#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> a = {0,0,0,0,1,0,2,0,3,0,4};
    int n = a.size();
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
        {
            rotate(a.begin() + i, a.begin() + i + 1, a.end());
            n--;
        }
    }
    for(int i : a)
    {
        cout << i << " ";
    }
}