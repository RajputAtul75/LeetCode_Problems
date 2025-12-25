#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        /*Brute force approach
        int maxWater = 0;
        // For left boundary
        for(int i = 0; i < height.size(); i++){
            // For right boundary
            for(int j = i + 1; j < height.size(); j++){
                int width = (j - i);
                int ht = min(height[i], height[j]);
                int area = (width * ht);

                maxWater = max(maxWater, area);
            }
        }
        return maxWater;
        */
        // Two pointer approach
        int max_Water = 0;
        int left_ptr = 0, right_ptr = height.size() - 1;

        while(left_ptr < right_ptr){
            int width = (right_ptr - left_ptr);
            int ht = min(height[left_ptr], height[right_ptr]);
            int area = width * ht;

            max_Water = max(max_Water, area);

            height[left_ptr] < height[right_ptr] ? left_ptr++ : right_ptr--;
        }
        return max_Water;
    }
};

int main() {
    Solution obj;

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << "Maximum water that can be stored: "
         << obj.maxArea(height) << endl;

    return 0;
}
