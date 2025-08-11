// LeetCode Problem: 4. Median of Two Sorted Arrays
// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Difficulty: Hard
// Language: C++
// Approach: Merge both arrays into a temp vector, sort, and find median.
// Time Complexity: O((m + n) log(m + n))
// Space Complexity: O(m + n)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp(nums1.size()+nums2.size());
        double sum=0;
        for(int i=0;i<(nums1.size()+nums2.size());i++){
            if(i<nums1.size()){
                temp[i]=nums1[i];
                
            }
            else{
                temp[i]=nums2[i-nums1.size()];
                
            }
        
        }
        sort(temp.begin(),temp.end());
        int n=temp.size();
        if(n%2!=0){
            return temp[n/2];
        }
        else{
            return ( (temp[(n-1)/2]+temp[((n-1)/2)+1])/2.0);
        }
    }
};
