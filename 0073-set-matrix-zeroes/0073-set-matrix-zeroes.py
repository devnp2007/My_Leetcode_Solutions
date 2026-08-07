class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        rows = len(matrix)
        cols = len(matrix[0])


        first_row_has_zero = False
        first_col_has_zero = False

        #check if the first row contains 
        for c in range(cols):
            if matrix[0][c] == 0:
                first_row_has_zero = True
                break
            
        #check if first column contains zero
        for r in range(rows):
            if matrix[r][0] == 0:
                first_col_has_zero = True
                break
        
        #use the first row and column as note
        for r in range(1,rows):
            for c in range(1,cols):
                if matrix[r][c] == 0:
                    matrix[r][0] = 0
                    matrix[0][c] = 0

        # set the marked rows to zero 
        for r in range(1,rows):
            if matrix[r][0] == 0:
                for c in range(1,cols):
                    matrix[r][c] = 0

        # set the marked cols to zero
        for c in range(1,cols):
            if matrix[0][c] == 0:
                for r in range(1,rows):
                    matrix[r][c] = 0

        # check if first row needs to be marked zero
        if first_row_has_zero:
            for c in range(cols):
                matrix[0][c] = 0

        #check if the first coloumn needs to be marked zero
        if first_col_has_zero:
            for r in range(rows):
                matrix[r][0] = 0
        
        return matrix