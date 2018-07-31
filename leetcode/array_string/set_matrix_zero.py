class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        row_len = len(matrix)
        column_len = len(matrix[0])
        zero_list = list()
        for i in range(row_len):
            for j in range(column_len):
                if (matrix[i][j] == 0):
                    zero_list.append((i, j))
        print(zero_list)
            
        for (row_num, column_num) in zero_list:
            for i in range(column_len):
                matrix[row_num][i] = 0
            for i in range(row_len):
                matrix[i][column_num] = 0
                    