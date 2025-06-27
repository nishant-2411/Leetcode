class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        N = len(nums)
        pointer_visit = set()
        ans = []
        for i in range(N):
            for k in range(i+1, N):
                pointer1 = nums[i]
                pointer2 = nums[k]

                if (nums[i], nums[k]) not in pointer_visit:
                    pointer_visit.add((nums[i], nums[k]))
                else:
                    continue
                    
                hehehehaw = target - pointer1 - pointer2
                mp = {}
                for j in range(k + 1, N): # indices?
                    if hehehehaw - nums[j] in mp:
                        ans.append([pointer1, pointer2, nums[j], hehehehaw-nums[j]]) # appends all the numbers into a list
                    if nums[j] not in mp:
                        mp[nums[j]] = j # adds entry into list
        
        ans_set = set()
        for i in range(len(ans)):
            if tuple(sorted(ans[i])) not in ans_set:
                ans_set.add(tuple(sorted(ans[i])))
                    
        return list(ans_set)    