#include<vector>
#include<iostream>

using namespace std;
int main()
{
    vector <int> input = {1,2,3,-1,-2,-3};
    vector <int> output(input.size());
    int pos = 0, neg = 1;
    for(int i : input )
    {
        if(i > 0)
        {
            output[pos] = i;
            pos += 2;
        }
        else
        {
            output[neg] = i;
            neg += 2;
        }
    }
    for(int i : output)
    {
        cout << i << " ";
    }
}