#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector <int> a = {1,1,2,2,3,4,4,5,5};
    int x = 0;
    for(int i : a)
    {
        x = x ^ i;
    }
    cout << x;
}