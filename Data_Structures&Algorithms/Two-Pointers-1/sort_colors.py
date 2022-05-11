# Time Complexity: O(n)
# Space Complexity: O(1)
# Approach to solve the problem: 

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = 0
        curr = 0
        r = len(nums)-1
        
        while curr <= r:                                      # Termination state
            if nums[curr] == 2:                               
                nums[curr], nums[r] = nums[r], nums[curr]     # Exchanging value with right if curr is 2 
                r -= 1
                
            elif nums[curr] == 0:                        
                nums[curr], nums[l] = nums[l], nums[curr]     # Exchanging value with left if curr is 0 
                curr += 1
                l += 1
            else:
                curr += 1
                
        return nums
                    
                