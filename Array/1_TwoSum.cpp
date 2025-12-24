#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Brute Force Approach
        
        /* for(int i = 0; i < nums.size(); i++) {
                int first = nums[i];
                for(int j = i + 1; j < nums.size(); j++) {
                    int second = nums[j];
                    int sum = first + second;

                    if(sum == target) {
                        return {i, j}; // return indices as a vector
                    }
                }
            }
            return {}; // return empty vector if no solution
            */
            
        // Optimized approach
        unordered_map<int,int> m;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            int first = nums[i];
            int second = target - first;

            if(m.find(second) != m.end()){
                ans.push_back(i);
                ans.push_back(m[second]);
                break;
            }
            m[first] = i;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test Case
    vector<int> nums = {3, 2, 4};
    int target = 6;
    
    vector<int> result = sol.twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No pair found." << endl;
    }
    
    return 0;
}