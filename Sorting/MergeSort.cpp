#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> & nums, int left, int mid, int right)
{
    int i = left, j = mid + 1;
    vector<int> temp;
    while( i <= mid && j <= right){
        if(nums[i] < nums[j]) temp.push_back(nums[i++]);
        else temp.push_back(nums[j++]);
    }
    while(i <= mid) temp.push_back(nums[i++]);
    while(j <= right) temp.push_back(nums[j++]);
    for(int k = 0; k < temp.size(); k++) {
        nums[left+k] = temp[k];
    }
}

void mergeSort(vector<int> & nums, int left, int right) {
    if(left >= right) return;
    int mid = (left+right)/2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid+1, right);
    merge(nums, left, mid, right);
}

int main(){
    vector<int> nums = {7,3,4,1,0,5,9,2};
    mergeSort(nums, 0, nums.size()-1);
    for(int i : nums) cout << i << " ";
    return 0;
}