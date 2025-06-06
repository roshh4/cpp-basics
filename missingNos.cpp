#include<iostream>
#include<vector>

using namespace std;

int main()
{   
    vector <int> a = {1,3,2,6,0,5,7};
    int x1 = 0, x2 = 0;
    for(int i = 0; i < a.size(); i++)
    {
        x1 = x1 ^ a[i];
        x2 = x2 ^ i;
    }
    x2 = x2 ^ a.size();
    cout << (x1 ^ x2);
}
