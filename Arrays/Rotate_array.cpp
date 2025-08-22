#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()>1 ){
            
            k=k%nums.size();
            vector<int>temp;
            for(int i=0;i<nums.size()-k;i++){
                temp.push_back(nums[i]);
            }
            int m=k,l=0;
            for(int j=0;j<nums.size();j++){
                if(j<k){
                    nums[j]=nums[nums.size()-m];
                    m--;
                }else{
                    nums[j]=temp[l++];
                }
            }

        }

    }
};


class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return;

        k = k % n;
        vector<int> temp(nums.begin(), nums.begin() + n - k);

        for (int j = 0; j < k; j++) {
            nums[j] = nums[n - k + j];
        }

        for (int j = k; j < n; j++) {
            nums[j] = temp[j - k];
        }
    }
};

class Solution3 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // handle k > n
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


int main() {
    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;
    

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    sol1.rotate(nums, k);

    cout << "Array after rotation Using sol1: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    nums = {1, 2, 3, 4, 5, 6, 7};
     k = 3;
    sol2.rotate(nums, k);

    cout << "Array after rotation using sol2: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;



    nums = {1, 2, 3, 4, 5, 6, 7};
     k = 3;
    sol3.rotate(nums, k);

    cout << "Array after rotation using sol3: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}