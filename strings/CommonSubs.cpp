#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <string> str = {"blue", "blued", "blu", "bluie", "bl"};
    string pre = str[0];
    for(int i = 1; i < str.size(); i++)
    {
        int j = 0;
        while(j < pre.size() && j < str[i].size() && pre[j] == str[i][j])
        {
            j++;
        }
        pre = pre.substr(0,j);
    }
    cout << pre;
}