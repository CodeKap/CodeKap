# Time Complexity: O(nlogn)
# Spave Complexity: O(1)
# Approach to solve the problem : 
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []                                              # Output result enmpty list
        nums.sort()                                              # Sort
        
        for i, a in enumerate(nums):                             # Index and value
            if i > 0 and a == nums[i-1]:
                continue
                
            l, r = i+1, len(nums)-1
            while l < r:                                        # termination state
                threeSum = a + nums[l] + nums[r]                 # Formula to calculate threesum
                if threeSum > 0:
                    r-=1
                elif threeSum < 0:
                    l+=1
                else:
                    result.append([a, nums[l], nums[r]])          # Append 
                    l += 1
                    while nums[l] == nums[l-1] and l < r:
                        l += 1
                        
        return result
        