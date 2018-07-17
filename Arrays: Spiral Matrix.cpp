/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/




class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        
        std::vector<int> rt{};
        
        
        if (matrix.size() == 0)
        {
            return rt;
        }
        
        
        int row_up = 0;
        int col_right = (int)matrix[0].size()-1;
        int row_down = (int)matrix.size()-1;
        int col_left = 0;
        
        int total_size = (int)(matrix.size() * matrix[0].size());
        int counter = 0;
        
        while (rt.size() < total_size)
        {
            
            // row up
            for (int i = col_left; i < col_right+1; i++)
            {
                    rt.push_back(matrix[row_up][i]);
            }
            row_up++;

            //  column right
            for (int i = row_up; i < row_down+1; i++)
            {
                    rt.push_back(matrix[i][col_right]); 
            }
            col_right--;

            // row down
            for (int i = col_right; i >= col_left; i--)
            {
                    rt.push_back(matrix[row_down][i]);
            }
            row_down--;

            // column left
            for (int i = row_down; i >= row_up; i--)
            {
                    rt.push_back(matrix[i][col_left]);  
            }
            col_left++;
            
            
            
        }

        return rt;
    }
};
