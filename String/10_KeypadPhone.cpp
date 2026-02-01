#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(string digits, string op, int idx,
               vector<string>& ans, string mapping[]) {
        // Base case
        if (idx >= digits.length()) {
            ans.push_back(op);
            return;
        }

        int num = digits[idx] - '0';
        string value = mapping[num];

        for (int i = 0; i < value.length(); i++) {
            op.push_back(value[i]);
            solve(digits, op, idx + 1, ans, mapping);
            op.pop_back(); // backtracking
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) {
            return ans;
        }

        string op = "";
        int idx = 0;

        string mapping[10] = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        solve(digits, op, idx, ans, mapping);
        return ans;
    }
};

int main() {
    Solution sol;

    string digits;
    cout << "Enter digits: ";
    cin >> digits;

    vector<string> result = sol.letterCombinations(digits);

    cout << "Letter combinations are:\n";
    for (string s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
