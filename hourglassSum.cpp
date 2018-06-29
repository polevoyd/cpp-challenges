int hourglassSum(vector<vector<int>> arr) {

    // we need to find all possible hourglasses:
    //      x x x
    //        x
    //      x x x
    // calculate sum of each
    // and return biggest sum
    
    // TIME : N*M, where n and m are dimentions of matrix 
    // SPACE : CONSTANT
    
    int biggest_sum{ INT_MIN };
    for (int i = 0; i < arr.size()-2; i++)
    {
        for (int k = 0; k < arr[i].size()-2; k++)
        {
            // arr[i][k] is upper left point 
            // for each dumbell
            // calc a dumbell sum and put it in set of sums
            int current_sum{};

            current_sum += arr[i][k] + arr[i][k+1]   + arr[i][k+2]
                                     + arr[i+1][k+1]
                       + arr[i+2][k] + arr[i+2][k+1] + arr[i+2][k+2];

            if (current_sum > biggest_sum)
                biggest_sum = current_sum;              
        }
    }
    return biggest_sum;
