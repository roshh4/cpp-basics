#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0, end = arr.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start + k;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    int result = sol.findKthPositive(arr, k);
    cout << "The " << k << "-th missing positive number is: " << result << endl;

    return 0;
}
