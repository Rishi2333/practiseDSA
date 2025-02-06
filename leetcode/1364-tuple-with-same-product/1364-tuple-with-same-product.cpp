
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // Step 1: Generate all possible products and count their frequencies
        unordered_map<int, int> product_count;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                product_count[product]++;
            }
        }
        
        // Step 2: Count the number of valid tuples
        int result = 0;
        for (auto& [product, count] : product_count) {
            if (count >= 2) {
                // Number of ways to choose 2 distinct pairs for the same product
                int ways = count * (count - 1) / 2; // Equivalent to C(count, 2)
                // Each combination contributes 8 valid tuples (permutations)
                result += ways * 8;
            }
        }
        
        return result;
    }
};