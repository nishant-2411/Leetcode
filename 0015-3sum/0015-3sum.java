import java.util.AbstractList;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        return new AbstractList<List<Integer>>() {

            List<List<Integer>> ans;

            @Override
            public int size() {
                if (ans == null)
                    ans = createList(nums);
                return ans.size();
            }

            @Override
            public List<Integer> get(int index) {
                if (ans == null)
                    ans = createList(nums);
                return ans.get(index);
            }
        };
    }
    public static List<List<Integer>> createList(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        int i = 0;
        int n = nums.length;
        while (i < n - 2) {
            if (i != 0 && nums[i] == nums[i - 1])
                i++;
            else {
                int j = i + 1, k = n - 1;
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0) {
                        ans.add(Arrays.asList(nums[i], nums[j], nums[k]));
                        j++;
                        while (j < k && nums[j] == nums[j - 1])
                            j++;
                    } else if (sum < 0)
                        j++;
                    else
                        k--;
                }
                i++;
            }
        }

        return ans;
    }
}