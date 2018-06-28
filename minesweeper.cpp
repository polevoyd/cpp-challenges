std::vector<std::vector<int>> minesweeper(std::vector<std::vector<bool>> matrix) {
    
    /* In the popular Minesweeper game you have a board with some mines and those 
     * cells that don't contain a mine have a number in it that indicates the total 
     * number of mines in the neighboring cells. Starting off with some arrangement 
     * of mines we want to create a Minesweeper game setup.
     * 
     * Example
     * For
     *             matrix = [[true, false, false],
                            [false, true, false],
                            [false, false, false]]
                
     * the output should be
     * 
     * minesweeper(matrix) = [[1, 2, 1],
                              [2, 1, 1],
                              [1, 1, 1]]   */
    
    // creating a matrix of zeros
    std::vector<int> v(matrix[0].size() , 0);
    std::vector<std::vector<int>> matrix_to_return{matrix.size(), v };

    // For each element in a matrix
    for (int i = 0 ; i < matrix.size() ; i++)
    {
        for (int k = 0 ; k < matrix[i].size() ; k++)
        {
            // that is a bomb
            if (matrix[i][k] == true)
            {
                // decrement a bomb so it doesn't count itself
                matrix_to_return[i][k]--;
                
                // looking for elements
                for (int j = 0; j < matrix.size() ; j++)
                {
                    for (int l = 0 ; l < matrix[j].size() ; l++)
                    {
                        //  with indexes nearby
                        if ((abs(j-i) <= 1)&&(abs(l-k) <= 1))
                        {   
                            //and increment them
                            matrix_to_return[j][l]++;
                        }
                    }  
                }  
            }
        }
    }
	
    return matrix_to_return;
}
