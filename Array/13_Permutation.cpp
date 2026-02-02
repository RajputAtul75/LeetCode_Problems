#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solution(vector<int>&nums, vector<vector<int>>& ans, int index){
        //Base case
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        //choose all element to swap one another to find all possible permutations
        for(int j = index; j<nums.size(); j++){
            swap(nums[index], nums[j]);
            //Recursion call
            solution(nums,ans,index+1);
            //backtrack
            swap(nums[index], nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solution(nums,ans,index);
        return ans;
    }
};
int main() {
    Solution obj;
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<vector<int>> result = obj.permute(nums);

    for(auto &v : result){
        for(int x : v){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
