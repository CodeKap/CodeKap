# Time Complexity: O(n)
# Space Complexity: O(1)
# Approach to solve the problem:
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        cal = 0
        i = 1
        
        
        while l < r:
            cal = max(cal, min(height[l], height[r]) * (len(height) - i))       # Getting the max between prec and curr cal
            i += 1
            #print(cal,l,r)
            
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
                
            
        return cal
        