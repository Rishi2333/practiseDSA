class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int score = INT_MIN;
        int zeros = 0;
        int ones = 0;

        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                zeros++;
            } else {
                ones--;
            }
            score = max(score, zeros + ones);
        }
        return score;
    }
};