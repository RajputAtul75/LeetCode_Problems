#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // For nums[i]
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            // For nums[j]
            for(int j = i + 1; j < n; ) {
                int k = j + 1, l = n - 1;

                while(k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum < target) {
                        k++;
                    }
                    else if(sum > target) {
                        l--;
                    }
                    else {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        // remove duplicates for k
                        while(k < l && nums[k] == nums[k - 1]) k++;
                    }
                }
                j++;
                while(j < n && nums[j] == nums[j - 1]) j++;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = obj.fourSum(nums, target);

    for(auto &quad : result) {
        for(int x : quad) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
