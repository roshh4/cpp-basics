#include<vector>
#include<iostream>

using namespace std;
int main()
{
    vector<int> stocks = {7,1,5,3,6,4};
    int min = stocks[0], diff = 0;
    for(int i = 0; i < stocks.size(); i++)
    {
        if(stocks[i] < min)
        {
            min = stocks[i];
        }
        if(stocks[i] > min && diff < stocks[i] - min)
        {
            diff = stocks[i] - min;
        }
    }
    cout << diff;
}