bool almostIncreasingSequence(std::vector<int> sequence) {

    /* Given a sequence of integers as an array, 
     * determine whether it is possible to obtain 
     * a strictly increasing sequence by removing 
     * no more than one element from the array. */
    
    int removes_needed {0};
    
    int max{-100000};
    int second_max{-100000};
    
    for (int i = 0; i < sequence.size(); i++) 
    {
        if (sequence[i] > max) 
        {
            second_max = max;
            max = sequence[i];
        } 
        else if (sequence[i] > second_max) 
        {
            max = sequence[i];
            removes_needed++;
        } 
        else 
        {
            removes_needed++;
        }
    }
    
    return removes_needed < 2;  
}
