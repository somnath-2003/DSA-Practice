#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    bool isPalindrome(string s) {
        bool result=true;
        string r="";
        for(auto i: s){
            
            if(isalnum(i)){
                r.push_back(tolower(i));
            }
        }
        int n=r.length();
        if(n==1||n==0){
            return true;
        }
        for(int i=0;i<n/2;i++){
            if(r[i]!=r[n-1-i]){
                result=false;
                break;
            }
        }
        return result;

    }
};


class Solution2 {
public:
    bool isPalindrome(string s) {

        //Two pointer approach

        int left=0,right=s.length()-1;

        while(left<right){
            while(left<right && !isalnum(s[left])){
                left++;
            }
            while(left<right && !isalnum(s[right]) ){
                right--;
            }
            if(tolower(s[left])!=tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;

    }
};
int main() {
    Solution1 sol;
    Solution2 sol2;
    string input;
    cout << "Enter a string: ";
    cin>>input;
    cout<<"using solution1"<<endl;
    if(sol.isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is NOT a palindrome." << endl;
    }
    cout<<"Using Solution 2 "<<endl;
    if(sol2.isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is NOT a palindrome." << endl;
    }

    return 0;
}


