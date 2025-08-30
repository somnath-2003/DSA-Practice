#include <bits/stdc++.h>
using namespace std;

// Mock Master API for local testing
class Master {
    string secret;
public:
    Master(string s) : secret(s) {}
    int guess(string word) {
        int count = 0;
        for (int i = 0; i < 6; i++) {
            if (word[i] == secret[i]) count++;
        }
        cout << "Guessed: " << word << " -> MatchCount: " << count << "\n";
        return count;
    }
};

class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        srand(time(0));
        int matchCount = 0;

        for (int attempt = 0; attempt < 30 && matchCount < 6; attempt++) {
            string guessed = words[rand() % words.size()];
            matchCount = master.guess(guessed);

            vector<string> secret;
            for (auto& word : words) {
                int count = 0;
                for (int j = 0; j < 6; j++) {
                    if (word[j] == guessed[j]) count++;
                }
                if (count == matchCount) {
                    secret.push_back(word);
                }
            }
            words = secret;
        }
    }
};

int main() {
    // Sample word list
    vector<string> words = {
        "acckzz", "ccbazz", "eiowzz", "abcczz", "acckzz"
    };

    string secret = "acckzz"; // the actual secret word
    Master master(secret);

    Solution sol;
    sol.findSecretWord(words, master);

    return 0;
}
