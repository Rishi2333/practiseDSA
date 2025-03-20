class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operations = 0;

        // Step 1: Starting se n-2 tak loop chalao
        for (int i = 0; i < n - 2; i++) {
            // Agar current element 0 hai, toh flip karo
            if (nums[i] == 0) {
                // 3 consecutive elements flip karo
                nums[i] = 1 - nums[i];     // 0 ko 1 ya 1 ko 0
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
                operations++; // Operation count badhao
            }
        }

        // Step 2: Last 2 elements check karo
        if (nums[n - 2] != 1 || nums[n - 1] != 1) {
            return -1; // Agar last 2 elements 1 nahi hain, toh impossible hai
        }

        return operations; // Total operations return karo
    }
};