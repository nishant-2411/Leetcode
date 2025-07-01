class Solution {
    public int maxSubstrings(String word) {
        int n = word.length();
        List<List<Integer>> mpp = new ArrayList<>();
        for (int i = 0; i < 26; i++) mpp.add(new ArrayList<>());
        for (int i = 0; i < n; i++) {
            mpp.get(word.charAt(i) - 'a').add(i);
        }
        List<int[]> intervals = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            List<Integer> curr = mpp.get(i);
            for (int j = 0; j < curr.size(); j++) {
                int idx = Collections.binarySearch(curr, curr.get(j) + 3);
                if (idx < 0) idx = -idx - 1;
                if (idx < curr.size()) {
                    intervals.add(new int[]{curr.get(idx), curr.get(j)});
                }
            }
        }
        Collections.sort(intervals, Comparator.comparingInt(a -> a[0]));
        int count = 0, last = -1;
        for (int[] p : intervals) {
            if (p[1] > last) {
                count++;
                last = p[0];
            }
        }
        return count;
    }
}