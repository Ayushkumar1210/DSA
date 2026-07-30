class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        auto robLinear = [](const vector<int>& arr) {
            int prev = 0, curr = 0;
            for (int num : arr) {
                int newCurr = max(prev + num, curr);
                prev = curr;
                curr = newCurr;
            }
            return curr;
        };
        
        return max(robLinear(vector<int>(nums.begin(), nums.end() - 1)), 
                   robLinear(vector<int>(nums.begin() + 1, nums.end())));
    }
};