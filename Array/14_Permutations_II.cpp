#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solution(vector<int>& nums, vector<vector<int>>& ans, int index) {
        // Base case
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        // Set to avoid duplicates at the same recursion level
        unordered_set<int> used;
        for (int j = index; j < nums.size(); j++) {

            if (used.count(nums[j])) continue; // Skip duplicate
            used.insert(nums[j]);


            swap(nums[index], nums[j]);
            // Recursive call
            solution(nums, ans, index + 1);
            // Backtrack
            swap(nums[index], nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solution(nums, ans, 0);
        return ans;
    }
};

int main() {
    Solution obj;

    // Input array (with duplicates)
    vector<int> nums = {1, 1, 2};
    // Get unique permutations
    vector<vector<int>> result = obj.permuteUnique(nums);
    // Print result
    cout << "Unique Permutations are:\n";
    for (auto perm : result) {
        cout << "[ ";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}
