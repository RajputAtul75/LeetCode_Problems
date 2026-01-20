#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;

        while (start <= end) {
            swap(s[start++], s[end--]);
        }
    }
};
int main() {
    Solution obj;

    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    vector<char> s(n);

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    obj.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
