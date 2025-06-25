class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countProducts(nums1, nums2, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    long long countProducts(vector<int>& nums1, vector<int>& nums2, long long target) {
        long long count = 0;
        
        for (int a : nums1) {
            count += countValidPairs(a, nums2, target);
        }
        
        return count;
    }
    
    long long countValidPairs(int a, vector<int>& nums2, long long target) {
        if (a == 0) {
            return target >= 0 ? nums2.size() : 0;
        }
        
        if (a > 0) {
            // a > 0: a * b <= target => b <= target / a
            long long threshold = floorDiv(target, a);
            return upperBound(nums2, threshold);
        } else {
            // a < 0: a * b <= target => b >= target / a (inequality flips)
            long long threshold = ceilDiv(target, a);
            return nums2.size() - lowerBound(nums2, threshold);
        }
    }
    
    // Floor division that works correctly for negative numbers
    long long floorDiv(long long a, long long b) {
        if (b > 0) {
            return a >= 0 ? a / b : (a - b + 1) / b;
        } else {
            return a <= 0 ? a / b : (a - b - 1) / b;
        }
    }
    
    // Ceiling division that works correctly for negative numbers
    long long ceilDiv(long long a, long long b) {
        if (b > 0) {
            return a >= 0 ? (a + b - 1) / b : a / b;
        } else {
            return a <= 0 ? (a + b + 1) / b : a / b;
        }
    }
    
    long long upperBound(vector<int>& arr, long long target) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    long long lowerBound(vector<int>& arr, long long target) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

/*
Key Fixes:
1. Proper floor/ceiling division functions that handle negative numbers correctly
2. Separated logic into countValidPairs for clarity
3. Correct handling of inequality direction when multiplying by negative numbers
4. Robust edge case handling for all sign combinations

Division Rules:
- Floor division: largest integer ≤ a/b
- Ceiling division: smallest integer ≥ a/b
- When b < 0, inequality direction flips in comparisons

Time Complexity: O(log(2×10^10) × n1 × log(n2))
Space Complexity: O(1)

This version should pass all test cases including edge cases with:
- Mixed positive/negative numbers
- Zero values
- Large ranges
- Boundary conditions
*/


/*Algorithm Explanation:
1. Binary search on the product value range [-1e10, 1e10]
2. For each candidate answer, count how many products are <= that value
3. Use the count to adjust binary search bounds
4. For counting, iterate through nums1 and for each element:
   - If positive: find how many nums2 elements satisfy the product constraint
   - If negative: inequality flips, handle accordingly
   - If zero: all products with this element are 0
5. Use binary search on nums2 to efficiently count valid elements
*/