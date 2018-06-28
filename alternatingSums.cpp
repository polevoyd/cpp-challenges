std::vector<int> alternatingSums(std::vector<int> a) {

    /* Several people are standing in a row 
     * and need to be divided into two teams. 
     * The first person goes into team 1, the 
     * second goes into team 2, the third goes 
     * into team 1 again, the fourth into team 2, 
     * and so on. You are given an array of 
     * positive integers - the weights of the 
     * people. Return an array of two integers, 
     * where the first element is the total weight 
     * of team 1, and the second element is the 
     * total weight of team 2 after the division 
     * is complete. */
    
    std::vector<int> sums{a[0] , a[1]};
    
    if (a.size() % 2)
    {
        for (int i = 2 ; i < a.size() ; i+=2)
            sums[0] += a[i];
        for (int j = 3 ; j < a.size() - 1 ; j+=2)
            sums[1] += a[j];
    }
    else
    {
        for (int i = 2 ; i < a.size() - 1 ; i+=2)
            sums[0] += a[i]; 
        for (int j = 3 ; j < a.size() ; j+=2)
            sums[1] += a[j];
    }

    return sums;
}
