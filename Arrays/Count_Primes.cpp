#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int countPrimes(int n) {

        // //Brute force approach
        // int i=1,count1=0,count2=0;
        // while(i<=n){
        //     int j=1;
        //     while(j<=i){
        //         if(i%j==0){
        //             count1++;
        //         }
        //         j++;
        //     }
        //     if(count1==2){
        //         count2++;
                
        //     }
        //     count1=0;
        //     i++;
        // }
        // return count2;
        
        if (n <= 2) return 0; // No primes less than 2

        vector<int> prime(n, 1); // Assume all are prime initially
        prime[0] = prime[1] = 0; // 0 and 1 are not primes

        for (int i = 2; i * i < n; i++) {
            if (prime[i]) { // If i is prime
                for (int j = i * i; j < n; j += i) {
                    prime[j] = 0; // Mark multiples as non-prime
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) count++;
        }
        return count;



    }
};

int main(){
    int n=500000;
    cout<<Solution::countPrimes(n);

    return 0;

}