    /*
    Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
    */
    // TIME: N LINEAR cause go through each element
    // SPACE: LINEAR - cause using array of same size
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        
        
    int msize = (int)matrix.size();
    
    std::vector<int> emp{};
        
    if (msize == 0)
        return emp;
            
    int msize2 = (int)matrix[0].size(), msize3 = msize * msize2;
    std::vector<int> res{};
    int i = 0, j = 0, k = 0;
        
    while ( k < msize3 )
    {
        res.push_back(matrix[i][j]);
    	if ( (i + j) % 2 == 1 )
        {
            if ( i == msize - 1 ) 
                j++;
            else if (j == 0) 
                i++;
            else 
            {
                i++; j--;
            }
    	} 
        else 
        {
    		if (j == msize2 - 1) 
                i++;
            else if (i == 0) 
                j++;
            else 
            {
             i--;
             j++;   
            }
    	}
    	k++;
    }
    return res;
    }
