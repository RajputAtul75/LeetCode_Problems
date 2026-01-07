#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) return mid;

            // Left part sorted
            if (nums[st] <= nums[mid]) {
                if (nums[st] <= target && target <= nums[mid])
                    end = mid - 1;   // move to left
                else
                    st = mid + 1;    // move to right
            }
            // Right part sorted
            else {
                if (nums[mid] <= target && target <= nums[end])
                    st = mid + 1;    // move to right
                else
                    end = mid - 1;   // move to left
            }
        }
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter rotated sorted array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    int result = obj.search(nums, target);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}
