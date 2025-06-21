#include <iostream>
using namespace std;

class Solution {
public:
    long long floorSqrt(long long n)  {
        long long start = 1, end = n, ans;
        while(start <= end)
        {
            long long mid = start + (end - start)/2;
            long long val = mid*mid;
            if(val == n)
            {
                return mid;
            }
            else if(val > n)
            {
                end = mid - 1;
            }
            else
            {
                ans = mid;
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    long long n = 1000;
    cout << "floorSqrt(" << n << ") = " << sol.floorSqrt(n) << endl;
    return 0;
}
