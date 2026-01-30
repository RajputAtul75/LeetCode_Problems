#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;

        // Count characters in magazine
        for (char ch : magazine) {
            m[ch]++;
        }

        // Check characters for ransomNote
        for (char ch : ransomNote) {
            if (m[ch] == 0) {
                return false;
            }
            m[ch]--;
        }
        return true;
    }
};

int main() {
    Solution obj;

    string ransomNote, magazine;

    cout << "Enter ransom note string: ";
    cin >> ransomNote;

    cout << "Enter magazine string: ";
    cin >> magazine;

    if (obj.canConstruct(ransomNote, magazine)) {
        cout << "True: Ransom note can be constructed." << endl;
    } else {
        cout << "False: Ransom note cannot be constructed." << endl;
    }

    return 0;
}
