#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
       
       
       //-----USING SORTING------

        //sort(nums.begin(), nums.end());

        ////APPROACH 1.--->RETURN THE MIDDLE ELEMENT sorting-->O(nlog(n)) + O(1)
        //return nums[nums.size()/2];

        ////APPROACH 2.--->ITERATE THE VECTOR FOR MAJORITY ELEMENT --->0(nlog(n)) + O(n)
        // int element=nums[0],count=1,i=0,maxCount=0;
        // while(i<nums.size()-1){
        //     if(nums[i]==nums[i+1]){
        //         count++;
        //     }else{
        //         count=1;
        //     }

        //     if(count>maxCount){
        //         maxCount=count;
        //         element=nums[i];
                
        //     }
        //     i++;
        // }
        //return element;

        //APPROACH 3.---->USING HASHMAP CALCULATE FREQUENCY -->O(n)

        unordered_map<int,int> umap;   // store frequency of each element
        int n = nums.size();

        for(int num : nums) {
            umap[num]++;               // increment count
            if(umap[num] > n/2)       // early exit if majority found
                return num;
        }
        return -1;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << sol.majorityElement(nums) << endl; // Output: 2
    return 0;
}