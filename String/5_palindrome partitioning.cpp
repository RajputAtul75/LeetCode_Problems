#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }
    void getAllPart(string s, vector<string>& partitions, vector<vector<string>>& ans){
        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }
        for(int i = 0; i < s.size(); i++){
            string part = s.substr(0, i + 1);

            if(isPalindrome(part)){
                partitions.push_back(part);
                getAllPart(s.substr(i + 1), partitions, ans);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getAllPart(s, partitions, ans);
        return ans;
    }
};
int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;
    vector<vector<string>> result = obj.partition(s);

    cout << "All Palindrome Partitions:\n";
    for(auto &vec : result){
        for(auto &str : vec){
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
