class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array for optimization
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int totalLeft = (m + n + 1) / 2; // Number of elements in left partition
        
        int left = 0, right = m;
        
        while (left <= right) {
            int cut1 = (left + right) / 2;           // Partition position in nums1
            int cut2 = totalLeft - cut1;             // Partition position in nums2
            
            // Elements just before the cuts
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            
            // Elements just after the cuts
            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];
            
            // Check if we found the correct partition
            if (left1 <= right2 && left2 <= right1) {
                // Found the correct partition
                if ((m + n) % 2 == 0) {
                    // Even total length - median is average of two middle elements
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    // Odd total length - median is the maximum of left partition
                    return max(left1, left2);
                }
            }
            // Adjust partition
            else if (left1 > right2) {
                // left1 is too big, move cut1 to left
                right = cut1 - 1;
            } else {
                // left2 is too big, move cut1 to right
                left = cut1 + 1;
            }
        }
        
        return 0.0; // Should never reach here with valid input
    }
};

/*
Algorithm Explanation:
We want to partition both arrays such that:
1. Left partition has exactly (m+n+1)/2 elements
2. max(left_partition) <= min(right_partition)

Visual Example:
nums1: [1, 3, 8, 9, 15]    cut1 = 2
       [1, 3] | [8, 9, 15]
       
nums2: [7, 11, 19, 21, 25] cut2 = 3  
       [7, 11, 19] | [21, 25]
       
Combined left:  [1, 3, 7, 11, 19]  (5 elements)
Combined right: [8, 9, 15, 21, 25] (5 elements)

Check: max(3, 19) <= min(8, 21) ? 19 <= 8? NO
So we need to adjust our partition.

Key Insights:
1. Binary search on the smaller array (nums1) for efficiency
2. Once we fix cut1, cut2 is determined: cut2 = totalLeft - cut1
3. Use INT_MIN/INT_MAX for boundary cases
4. The partition is valid when left1 <= right2 AND left2 <= right1

Time Complexity: O(log(min(m, n)))
Space Complexity: O(1)

Edge Cases Handled:
1. One array is empty
2. All elements of one array are smaller than the other
3. Arrays of different sizes
4. Even/odd total length
5. Negative numbers

Example Walkthrough:
nums1 = [1,3], nums2 = [2], total = 3 (odd)
- totalLeft = (3+1)/2 = 2
- Binary search on nums1:
  - cut1 = 1, cut2 = 2-1 = 1
  - left1 = nums1[0] = 1, right1 = nums1[1] = 3
  - left2 = nums2[0] = 2, right2 = INT_MAX
  - Check: 1 <= INT_MAX ✓ and 2 <= 3 ✓
  - Median = max(1, 2) = 2
*/