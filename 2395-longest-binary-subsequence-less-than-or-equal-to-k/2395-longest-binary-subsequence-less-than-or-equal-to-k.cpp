class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        
        // Count total zeros - they can always be included
        int zeros = 0;
        for (char c : s) {
            if (c == '0') zeros++;
        }
        
        // If k is 0, we can only include zeros
        if (k == 0) return zeros;
        
        // Find the maximum number of ones we can include
        int maxOnes = 0;
        long long value = 0;
        long long power = 1;
        
        // Process from right to left (least significant bit first)
        for (int i = n - 1; i >= 0 && power <= k; i--) {
            if (s[i] == '1') {
                // Check if adding this '1' keeps us <= k
                if (value + power <= k) {
                    value += power;
                    maxOnes++;
                }
            }
            power *= 2;
            
            // If power overflows or exceeds k, no more '1's can be added
            if (power > k || power < 0) break;
        }
        
        return zeros + maxOnes;
    }
};

/*
Algorithm Explanation:
1. Count all zeros - they can always be included (leading zeros allowed)
2. Greedily select ones from right to left (LSB to MSB)
3. For each '1', check if including it keeps the value ≤ k
4. Stop when the next power of 2 would exceed k

Key Optimizations:
1. Greedy approach: always prefer rightmost '1's (smaller contribution)
2. Early termination when power exceeds k
3. Overflow protection for power calculation
4. Separate counting of zeros and ones for clarity

Time Complexity: O(n) where n is length of string
Space Complexity: O(1)

Edge Cases Handled:
- k = 0: only zeros can be included
- All zeros: return total count
- All ones: select greedily from right
- Large k: handle potential overflow
- Mixed string: optimal selection

Example Walkthrough:
s = "1001010", k = 5
- Zeros count: 4
- Process from right: "0101001"
  - i=6, s[6]='0': skip
  - i=5, s[5]='1', power=2: value=0+2=2 ≤ 5 ✓ (maxOnes=1)
  - i=4, s[4]='0': skip  
  - i=3, s[3]='1', power=8: value=2+8=10 > 5 ✗
  - i=2, s[2]='0': skip
  - i=1, s[1]='0': skip
  - i=0, s[0]='1', power=64: 64 > 5, break
- Result: 4 zeros + 1 one = 5
*/