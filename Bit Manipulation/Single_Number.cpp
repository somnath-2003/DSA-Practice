#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i: nums){
            result=result ^i;
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<int>nums={4,1,2,1,2};
    cout<<"the single number is:"<<sol.singleNumber(nums);
    return 0;
}