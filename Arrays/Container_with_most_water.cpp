#include <bits/stdc++.h>   // GCC only (not standard C++)
using namespace std;


class Solution {
public:
    static int maxArea(vector<int>& height) {
        int st=0,end=height.size()-1,max=0,current_max=0;
        while(st<end){
            if(height[st]<height[end]){
                
                current_max=height[st]*(end-st);
                if(current_max>max){
                    max=current_max;

                }
                st++;

            }
            else{
                current_max=height[end]*(end-st);
                if(current_max>max){
                    max=current_max;

                }
                end--;

            }
        }
        return max;
        
    }
};
int main(){
    
    vector<int> height={1,8,6,2,5,4,8,3,7};
    int result=Solution::maxArea(height);
    cout<<result;

    return 0;
}