#include <iostream>
#include <string>

using namespace std;

// sol 1
// int main()
// {
//     string s = "abb";
//     string t = "aac";
//     int x1 = 0, x2 = 0;
//     for(int i = 0; i < s.length(); i++)
//     {
//         x1 += s[i];
//         x2 += t[i];
//     }
//     if(x1 == x2)
//     {
//         cout << "valid anagram";
//     }
//     else{
//         cout << "nahhh bitch";
//     }
// }


//v2, ascii indexed array
// int main()
// {
//     string s = "rrsshh";
//     string t = "rshrhh";
//     int x1[128] = {0};
//     int x2[128] = {0};
//     for(int i = 0; i < s.length(); i++)
//     {
//         x1[s[i]]++;
//         x2[t[i]]++;
//     }
//     bool flag = true;
//     int n = sizeof(x1)/sizeof(x1[0]);
//     for(int i = 0; i < n; i++)
//     {
//         if(x1[i] != x2[i])
//         {
//             flag = false;
//             break;
//         }
//     }
//     cout << flag;
// }

//v3: array of size 26
int main()
{
    string s = "anagram";
    string t = "nagrram";
    int x1[26] = {0}, x2[26] = {0};
    for(int i = 0; i < s.length(); i++)
    {
        x1[s[i] - 'a']++;
        x2[t[i] - 'a']++;
    }
    int n = sizeof(x1)/sizeof(x1[0]);
    bool flag = true;
    for(int i = 0; i < n; i++)
    {
        if(x1[i] != x2[i])
        {
            flag = false;
            break;
        }
    }
    cout << flag;
}