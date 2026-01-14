#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if(m == 0) return 0;
        for(int i = 0; i<=n-m; i++){

            int j = 0;
            while(j < m && haystack[i + j] == needle[j]){
                j++;
            }
            if(j == m) return i;
        }
        return -1;
    }
};

int main() {
    string haystack, needle;
    cout << "Enter haystack string: ";
    cin >> haystack;
    cout << "Enter needle string: ";
    cin >> needle;

    Solution obj;
    int result = obj.strStr(haystack, needle);

    if(result == -1)
        cout << "Substring not found" << endl;
    else
        cout << "Substring found at index: " << result << endl;

    return 0;
}
