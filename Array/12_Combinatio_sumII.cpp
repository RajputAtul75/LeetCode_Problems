#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getAllComb(vector<int>& arr, vector<int>& combin, int idx, int target, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        if (idx == arr.size() || target < 0) return;

        for (int i = idx; i < arr.size(); i++) {

            // skip duplicates at same level
            if (i > idx && arr[i] == arr[i - 1]) continue;

            if (arr[i] > target) break; // pruning

            combin.push_back(arr[i]);
            getAllComb(arr, combin, i + 1, target - arr[i], ans);
            combin.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combin;

        getAllComb(candidates, combin, 0, target, ans);
        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> result = obj.combinationSum2(candidates, target);

    cout << "Combinations are:\n";
    for (auto &v : result) {
        cout << "[ ";
        for (int x : v) {
            cout << x << " ";
        }
        cout << "]\n";
    }
    return 0;
}
