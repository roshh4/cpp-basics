#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
    vector <vector <int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    for(auto i : matrix )
    {
        for(int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = i+1; j < matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(auto i : matrix )
    {
        for(int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    for(auto i : matrix )
    {
        for(int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}