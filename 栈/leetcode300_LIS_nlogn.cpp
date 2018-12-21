// 贪心+二分
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > dp[dp.size()-1])
                dp.push_back(nums[i]);
            if (nums[i] < dp[dp.size()-1]) {
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                *it = nums[i];
            }
        }
        return dp.size();
    }
};
