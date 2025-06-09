#include<vector>
#include<iostream>

using namespace std;
int main()
{
    vector <vector <int>> input = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    vector <int> rows (input.size(), 0);
    vector <int> cols (input[0].size(), 0);
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < input[0].size(); j++)
        {
            if(input[i][j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < input[0].size(); j++)
        {
            if(rows[i] || cols[j])
            {
                input[i][j] = 0;
            }
        }
    }
    for(auto i : input)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}