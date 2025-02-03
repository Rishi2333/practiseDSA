class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int inc_length = 1;
        int dec_length = 1;
        int max_length = 1;
        
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                inc_length += 1;
                dec_length = 1;
            } else if (nums[i] < nums[i-1]) {
                dec_length += 1;
                inc_length = 1;
            } else {
                inc_length = 1;
                dec_length = 1;
            }
            
            max_length = std::max(max_length, std::max(inc_length, dec_length));
        }
        
        return max_length;
    }
};