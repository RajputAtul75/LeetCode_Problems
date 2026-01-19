#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        /* Brute Force
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
        */
        // Using hashMap
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        if (m1 == m2) return true;
        else return false;
    }
};

int main() {
    string s, t;

    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    Solution obj;
    bool result = obj.isAnagram(s, t);

    if (result)
        cout << "The strings are Anagrams." << endl;
    else
        cout << "The strings are NOT Anagrams." << endl;
    return 0;
}
