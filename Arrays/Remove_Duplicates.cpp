#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(int i: nums){
        //     mp[i]++;
        // }
        // int k=0;
        // vector<int>arr;
        // for (auto [key, value] : mp) {
        //     arr.push_back(key);
        // }
        // sort(arr.begin(), arr.end());

        // for(int i : arr){
        //     nums[k++]=i;
        // }
        // return k;
        int ptr=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]){
                nums[ptr+1]=nums[i];
                ptr++;
            }
        }
        return ptr+1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int newLength = sol.removeDuplicates(nums);

    cout << "New length: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

     return 0;
}