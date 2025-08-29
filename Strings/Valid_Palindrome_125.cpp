#include <bits/stdc++.h>
using namespace std;

class Solution {
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
int main() {
    Solution sol;
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if(sol.isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is NOT a palindrome." << endl;
    }

    return 0;
}


