#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //------> Space Complexity ---->O(n)
        // int n=nums.size();
        // vector<int>ans(n,1);
        // vector<int>prefix(n,1);
        // vector<int>suffix(n,1);
        // for(int i=1;i<n;i++){
        //     prefix[i]=prefix[i-1]*nums[i-1];
        
        // }
        // for(int i=n-2;i>=0;i--){
        //     suffix[i]=suffix[i+1]*nums[i+1];
        // }
        // for(int i=0;i<n;i++){
        //     ans[i]=prefix[i]*suffix[i];
        // }
        // return ans;

        //Space Complexity ---->O(1)
        int n= nums.size();
        vector<int>ans(n,1);
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];

        }
        int suffix =1;
        for(int i=n-2;i>=0;i--){
            suffix=suffix*nums[i+1];
            ans[i]=ans[i]*suffix;

        }
        return ans;

    }
};
int main(){
    Solution sol;
    vector<int> nums={1,2,3,4};
    vector<int> result = sol.productExceptSelf(nums);

    cout << "The product of array except the number itself is : ";
    for(int x: result){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}