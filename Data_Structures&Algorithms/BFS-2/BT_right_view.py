# Time COmplexityy: O(n)
# Space Complexity: O(n) where n is the longest level order of tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = []                                 # Initialize result 
        level = []                                  # Initialize level
        queue = [root]                              # Initialize queue as root
        
        while queue != [] and root is not None:     # Termination state
            for node in queue:                         
                if node.left != None:               # If node is in left append left value
                    level.append(node.left)
                if node.right != None:              # If node is in right append right value
                    level.append(node.right)
            result.append(node.val)
            queue = level
            level = []                              # Initialize level as [] again
        return result
                