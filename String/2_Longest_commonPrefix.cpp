#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size() - 1];

        int i = 0;
        while (i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }

        return first.substr(0, i);
    }
};

int main() {
    Solution obj;
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    cout << obj.longestCommonPrefix(strs);
    return 0;
}
