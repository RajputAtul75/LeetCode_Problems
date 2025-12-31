#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Using two pointers
        int n = nums.size();
        if (n == 0) return 0;

        int p = 0;
        for (int i = 0; i < n; i++) {
            if (nums[p] != nums[i]) {
                p++;
                nums[p] = nums[i];
            }
        }
        return p + 1; // Total unique element count
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};
    int k = sol.removeDuplicates(nums);

    cout << "Unique count: " << k << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
