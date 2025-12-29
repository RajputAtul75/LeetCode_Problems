#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        for (int k = 0; k <= n - 3; k++) {
            int i = k + 1;
            int j = n - 1;

            while (i < j) {
                int currSum = nums[k] + nums[i] + nums[j];

                if (abs(target - currSum) < abs(target - closestSum)) {
                    closestSum = currSum;
                }

                if (currSum < target)
                    i++;
                else
                    j--;
            }
        }
        return closestSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout << "Closest sum: " << sol.threeSumClosest(nums, target) << endl;

    return 0;
}
