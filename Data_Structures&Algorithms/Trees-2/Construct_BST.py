# TC : O(N)
# SC : O(H)
# Approach to solve the problem:

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not postorder or not inorder:           # If Postorder and inorder is empty
            return None
        
        value = postorder[-1]                      # Value Declaration
        root = TreeNode(value)
        indx = inorder.index(value)
        
        root.left = self.buildTree(inorder[:indx], postorder[:indx])    # Lookin for left child
        root.right = self.buildTree(inorder[indx+1:], postorder[indx: -1]) # Looking for right child
         
        return root
        