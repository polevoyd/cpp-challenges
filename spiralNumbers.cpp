std::vector<std::vector<int>> spiralNumbers(int n) {

    /*
    Construct a square matrix with a size N × N containing 
    integers from 1 to N * N in a spiral order, starting from 
    top-left and in clockwise direction.

    Example

    For n = 3, the output should be

    spiralNumbers(n) = [[1, 2, 3],
                        [8, 9, 4],
                        [7, 6, 5]]
    */
    
    // create an empty vector of N elements
	std::vector<std::vector<int>> A(n);
    
    // make each element a vector of N elements
    for (int i = 0; i < n; i++)
    {
        std::vector<int> j(n);
        A[i] = j;
    }

	int length = n, k = 1, p = 0;   
									
    while(k <= n*n)                      
	{
		for(int i = p ; i < length ; i++)      
		{
			A[p][i] = k++;
		}
        
		for(int i = p+1 ; i < length ; i++)      
		{
			A[i][length - 1] = k++;
		}
        
		for(int i = length - 2 ; i >= p ; i--)     
		{
			A[length-1][i] = k++;
		}
        
		for(int i = length-2 ; i > p ; i--)      
		{
			A[i][p] = k++;
		}
        
		p++;
        length = length-1;
	}
    
	if(!n%2)                      
	{
		A[(n+1)/2][(n+1)/2]=n*n; 
	}

	return A;
}
