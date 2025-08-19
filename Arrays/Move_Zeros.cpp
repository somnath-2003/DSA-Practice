#include <iostream>
#include<vector>   
using namespace std;

class Solution {
public:
    static void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        for(int i=0,j=0;i<n;i++){
            if(nums[i]!=0){
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                j++;
            }
        }
        for (int x : nums) {
            cout << x << " ";
        }
        cout << endl;

    }
};

int main(){
    
    vector<int> arr = {0,1,0,3,12};
    Solution::moveZeroes(arr);  


    return 0;
}