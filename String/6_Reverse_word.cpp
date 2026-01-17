#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        reverse(s.begin(), s.end());
        for(int i = 0; i < n; i++){

            string word = "";
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }
            // Pick the word and reverse the string individually
            reverse(word.begin(), word.end());
            if(word.length() > 0){
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};
int main() {
    Solution obj;
    string s;
    getline(cin, s);   // input full line

    cout << obj.reverseWords(s);
    return 0;
}
