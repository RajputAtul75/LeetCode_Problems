#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {

        int n = s.length();
        unordered_map<char, int> m;
        queue<int> q;

        for(int i = 0; i < n; i++){

            if(m.find(s[i]) == m.end()){
                q.push(i);
            }
            // increase the freq
            m[s[i]]++;

            while(q.size() > 0 && m[s[q.front()]] > 1){
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front();
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    int ans = obj.firstUniqChar(s);
    cout << "First unique character index: " << ans << endl;
    return 0;
}
