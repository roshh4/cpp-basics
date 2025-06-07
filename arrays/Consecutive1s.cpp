#include<iostream>
#include<vector>

using namespace std;

int main()
{   
    vector <int> a = {1,0,0,1,1,1,0,0,1,1};
    int max = 0, c = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == 1)
        {
            c++;
        }
        else
        {
            if (max < c)
            {
                max = c;
            }
            c = 0;
        }
        if (max < c)
        {
            max = c;
        }
    }
    cout << max;
}
