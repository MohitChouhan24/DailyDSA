class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        s = 0
        e = (len(matrix)*len(matrix[0]))-1
        while s <= e:
            mid = s + (e-s)//2
            element = matrix[mid//len(matrix[0])][mid%len(matrix[0])]
            if element == target:return True
            elif element < target:
                s = mid+1
            else: e = mid-1
        return False