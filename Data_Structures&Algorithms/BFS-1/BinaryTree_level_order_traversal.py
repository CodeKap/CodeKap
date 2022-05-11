# Time Complexity: O(N)
# Space Complexity: O(N)
# Approach to solve this problem:

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root == None:
            return []
        
        queue = [root]                                  # Queue will always take root
        new_queue = []                                  # Will take the node below the root
        level = []                                      # Will append the root
        result = []                                     # Will return the final result
        
        while queue != []:
            for root in queue:                          # If in root will append to level
                level.append(root.val)
                if root.left is not None:
                    new_queue.append(root.left)
                if root.right is not None:
                    new_queue.append(root.right)
            result.append(level)                        # Will append the level
            level = []                                  # Reintialize the level again
            queue = new_queue                           # Reintialize the queue again
            new_queue = []                              # Reintialize the new_queue again 
        return result