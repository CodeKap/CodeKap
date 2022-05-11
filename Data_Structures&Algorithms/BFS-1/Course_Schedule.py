# Time Complexity: O(V+E)
# Space Complexity: O(V+E)
# Approach to solve this problem given below:
# (Used DFS approach to solve this problem by using Hashmap for adjacancy list i.e for courses and its dependent couses on it and list for storing the nodes traversed in DFS manner)

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # map each course to prererequite list
        preMap = { i:[] for i in range(numCourses)}
        for crs,pre in prerequisites:
            preMap[crs].append(pre)
                
        # visitSet = all courses according to the DFS path
        visitSet = set()
        def dfs(crs):
            if crs in visitSet:
                return False
            if preMap[crs] == [] :
                return True
            
            visitSet.add(crs)               # Add to visitSet if crs in preMap is empty and not in vS 
            for pre in preMap[crs]:
                if not dfs(pre):
                    return False
            visitSet.remove(crs)
            preMap[crs] = []
            return True
        
        for crs in range(numCourses):
            if not dfs(crs): 
                return False
        return True
        
        