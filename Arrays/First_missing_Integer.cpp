#include <bits/stdc++.h>
using namespace std;
class Solution1{
    public:
    int firstMissingPositive(vector<int>& nums){
        int n=INT_MAX;
        int result=0,i=0;
        unordered_map<int,int>mp;
        for(auto num:nums){
            mp[num]++;
        }
        for( i=1;i<n;i++){
            if(mp[i]==0){
                result=i;
                break;
            }
        }
        if(result==0){
            result=i;
        }
        return result;
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    

        int n=nums.size();
        int i=0;
        int result=1;
        while(i<n){
            if(nums[i]>0 &&nums[i]<=n && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            else{
                i++;
            }
        }
        for(int j=0;j<n;j++){
            if(nums[j] != j+1) {
                return j+1;
                
            }

        }
        return n+1;
    }
};

int main() {
    Solution sol;
    Solution1 sol1;

    vector<int> nums1 = {1, 2, 0};
    vector<int> nums2 = {3, 4, -1, 1};
    vector<int> nums3 = {7, 8, 9, 11, 12};
    vector<int> nums4 = {1};
    vector<int> nums5 = {2};

    cout << "Missing Positive in {1,2,0}: " << sol.firstMissingPositive(nums1) << endl;
    cout << "Missing Positive in {3,4,-1,1}: " << sol1.firstMissingPositive(nums2) << endl;
    cout << "Missing Positive in {7,8,9,11,12}: " << sol.firstMissingPositive(nums3) << endl;
    cout << "Missing Positive in {1}: " << sol1.firstMissingPositive(nums4) << endl;
    cout << "Missing Positive in {2}: " << sol.firstMissingPositive(nums5) << endl;

    return 0;
}