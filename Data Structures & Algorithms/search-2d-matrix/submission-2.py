class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m=len(matrix)
        n=len(matrix[0])
        x=0
        y=m-1
        mid=(x+y)//2
        while x<=y:
            mid=(x+y)//2
            if matrix[mid][0]<=target and matrix[mid][n-1]>=target:
                break
            elif matrix[mid][0]>target:
                y=mid-1
            elif matrix[mid][n-1]<target:
                x=mid+1
        l=0
        r=n-1
        md=(l+r)//2
        while l<=r:
            md=(l+r)//2
            if matrix[mid][md]==target :
                return True
            elif matrix[mid][md]>target:
                r=md-1
            elif matrix[mid][md]<target:
                l=md+1
        return False