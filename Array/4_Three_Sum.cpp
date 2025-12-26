#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Two pointer approach
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) j++;
                else if (sum > 0) k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    // Skip duplicates
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> result = obj.threeSum(nums);

    cout << "Triplets with sum 0:\n";
    for (auto &triplet : result) {
        cout << "[ ";
        for (int x : triplet) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
