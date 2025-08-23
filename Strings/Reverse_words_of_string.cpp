#include <bits/stdc++.h>
using namespace std;



class Solution1 {
public:
    string reverseWords(string s) {
        string result, stack;
        int st = -2, end = -1;
        int first=0;
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ' && st==-2) {
                stack.push_back(s[i]);
                end=0;
                st=0;
                
            } else if(s[i] != ' ' && st==0){
                stack.push_back(s[i]);
                end++;


            }else if(s[i]==' ' && st==-2){
                continue;
            }else if(s[i]==' '&& st==0 && end!=-1 ){
                if(first!=0 || i==0) {
                    stack.push_back(' ');
                    end++;
                    
                }
                
                while (end>=0) {
                    result.push_back(stack[end--]);
                }
                stack="";
                st = 0;
                first++;
                end=-1;
                
                
            }else{
                continue;
            }
            
        }
        if(end!=-1&& st==0 && first!=0){
            result.push_back(' ');
        }
        while(end>=0){
            if(stack[end]!=' ')
                result.push_back(stack[end--]);
            
        }
        return result;

    }

};

class Solution2 {
public:
    string reverseWords(string s) {
        int n = s.size();
        string result = "", word = "";
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                word = s[i] + word;   // build word
            } else if (!word.empty()) {
                if (!result.empty()) result += " ";
                result += word;
                word = "";
            }
        }
        if (!word.empty()) {
            if (!result.empty()) result += " ";
            result += word;
        }
        return result;
    }
};


int main() {
    Solution1 sol1;
    Solution2 sol2;
    string s = "  hello   world  ";   // sample input
    cout << "Original: \"" << s << "\"" << endl;
    cout << "Reversed words using sol1: \"" << sol1.reverseWords(s) << "\"" << endl;
    cout << "Reversed words using sol2: \"" << sol2.reverseWords(s) << "\"" << endl;
    return 0;
}