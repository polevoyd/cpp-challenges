bool sudoku(std::vector<std::vector<int>> grid) {
/*
Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 
grid with digits so that each column, each row, and each of the nine 
3 × 3 sub-grids that compose the grid contains all of the digits from 1 to 9.

This algorithm should check if the given grid of numbers represents a 
correct solution to Sudoku.

Example

For the first example below, the output should be true. For the other grid, 
the output should be false: each of the nine 3 × 3 sub-grids should contain 
all of the digits from 1 to 9.
*/
    
    for(int k = 0; k < grid.size(); k++)
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid.size(); j++)
                if(i != j && (grid[k][i] == grid[k][j] || grid[i][k] == grid[j][k]))
                    return false;    
    for(int m = 0; m < 9; m += 3)
        for(int k = 0; k < 9; k += 3) {
            int sum = 0;
            for(int i = m; i < m+3; i++)
                for(int j = k; j < k+3; j++)
                    sum += grid[i][j];
            if(sum != 45)
                return false;
        }
    return true;
}
