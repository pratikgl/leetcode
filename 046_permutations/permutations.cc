#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> stack;
        vector<bool> used(nums.size());
        dfs(nums, used, stack, res);
        return res;
    }

private:
    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& stack, vector<vector<int>>& res) {
        if (stack.size() == nums.size()) {
            res.push_back(stack);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (!used[i]) {
                    used[i] = true;
                    stack.push_back(nums[i]);
                    dfs(nums, used, stack, res);
                    stack.pop_back();
                    used[i] = false;
                }
            }
        }
    }
};
