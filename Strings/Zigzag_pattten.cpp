#include <bits/stdc++.h>
using namespace std;
// Using 2D array
class Solution2 {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1) return s;
        string result="";
        int n=s.size();
        int row=numRows;
        int col=n;
        
        int k=0,j=0;
        bool goDown =true;
        vector<vector<char>> arr(row, vector<char>(col, ' '));
        for(auto i : s){
            arr[j][k]=i;
            
            if(goDown){
                if(j==row-1){
                    goDown=false;
                    j--;k++;
                }else{
                    j++;
                }
            }else {
                if(j==0){
                    goDown=true;
                    j++;
                }else{
                    j--;
                    k++;
                }
            }
        }
        for(int j=0;j<row;j++){
            for(int k=0;k<col;k++){
                if(arr[j][k]!=' '){
                    result+=arr[j][k];
                }
            }
            
        }
        return result;
    }
};

// Using Buckets of string
class Solution1 {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
        
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string result;
        for (string row : rows) result += row;
        return result;
    }
};

int main() {
    Solution1 sol;
    Solution2 sol2;
    string s = "PAYPALISHIRING";
    int numRows = 3;

    string result2 = sol2.convert(s, numRows);
    string result = sol.convert(s, numRows);
    cout << "Zigzag conversion (using 2d matrix) result: " << result2 << endl;
    cout << "Zigzag conversion (using bucket of strings) result: " << result << endl;

    return 0;
}