bool sudoku2(std::vector<std::vector<char>> grid) {
/*

Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with numbers in such a way that each column, each row, and each of the nine 3 × 3 sub-grids that compose the grid all contain all of the numbers from 1 to 9 one time.

Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle according to the layout rules described above. Note that the puzzle represented by grid does not have to be solvable.

Example

For

grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
        ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
        ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
        ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
        ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
        ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
        ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
the output should be
sudoku2(grid) = true;

For

grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
        ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
        ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
        ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
        ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
        ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
        ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
        ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
the output should be
sudoku2(grid) = false.

The given grid is not correct because there are two 1s in the second column. Each column, each row, and each 3 × 3 subgrid can only contain the numbers 1 through 9 one time.

*/
        for (auto i : grid)
        {       
                //making each subarray into a unique set 
                //and compare amount of elements
                std::unordered_set<char> rows{};
                int counter{ 0 };
                
                for (auto k : i)
                {
                        if (std::isdigit(k))
                        {
                                rows.insert(k);
                                counter++;
                        }    
                }
                
                if (rows.size() != counter)
                        return false;      
        }

        //checking for columns
        for (int i = 0; i < grid[i].size(); i++)
        {
                std::unordered_set<char> columns{};
                int counter{ 0 };
                
                for (int k = 0; k < grid.size(); k++)
                {
                        if (std::isdigit(grid[k][i]))
                        {
                                columns.insert(grid[k][i]);
                                counter++;
                        }
                }
                
                if (columns.size() != counter)
                        return false;
        }
        
        //checking a squares inside
        for (int i = 0; i < grid.size() ; i+=3)
        {
                for (int k = 0; k < grid.size(); k+=3)
                {
                        // at this point we are picking upper left
                        // point for each 3x3 square and going 
                        // through small submatrix 3x3 using set
                        // of digits to see if there any duplicates
                        //   
                        //   x . .
                        //   . . . 
                        //   . . .
                        //  
                        
                        std::unordered_set<char> sub_matrix{};
                        int counter{ 0 };
                        
                        for (int m = i; m < i+3; m++)
                        {
                                for (int n = k; n < k+3; n++)
                                {
                                       if (std::isdigit(grid[m][n]))
                                       {
                                               sub_matrix.insert(grid[m][n]);
                                               counter++;
                                       }
                                }
                        }
                        
                        if (sub_matrix.size() != counter)
                                return false;     
                }
        }
        
        // if we passed all that tests then its TRUE sudoku
        return true;
}
