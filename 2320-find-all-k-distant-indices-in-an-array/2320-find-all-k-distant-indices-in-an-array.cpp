class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> key_indices;
    int n = nums.size();
    // Find all indices where nums[j] == key
    for (int j = 0; j < n; ++j) {
        if (nums[j] == key) {
            key_indices.push_back(j);
        }
    }
    
    unordered_set<int> result_set;
    // For each key index, mark all i in [j -k, j +k] range
    for (int j : key_indices) {
        int start = max(0, j - k);
        int end = min(n - 1, j + k);
        for (int i = start; i <= end; ++i) {
            result_set.insert(i);
        }
    }
    
    vector<int> result(result_set.begin(), result_set.end());
    sort(result.begin(), result.end());
    return result;
}
};