#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    set<vector<int>> s;

    void getAllComb(vector<int>& arr, vector<int>& combin, int index, int target, vector<vector<int>>& ans){
        // Base case
        if (target == 0) {
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }
        if (index == arr.size() || target < 0) return;

        // Include current element (stay at same index for multiple inclusion)
        combin.push_back(arr[index]);
        getAllComb(arr, combin, index, target - arr[index], ans);     // multiple inclusion
        getAllComb(arr, combin, index + 1, target - arr[index], ans); // single inclusion
        combin.pop_back();

        // Exclude current element
        getAllComb(arr, combin, index + 1, target, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        sort(candidates.begin(), candidates.end());  // optional but good

        // Function Call
        getAllComb(candidates, combin, 0, target, ans);
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = obj.combinationSum(candidates, target);

    cout << "Combinations are:\n";
    for (auto &v : result) {
        cout << "[ ";
        for (int x : v) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
