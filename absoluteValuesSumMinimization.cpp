int absoluteValuesSumMinimization(std::vector<int> a) {

    /* Given a sorted array of integers a, find an integer x from a 
     * such that the value of

    abs(a[0] - x) + abs(a[1] - x) + ... + abs(a[a.length - 1] - x)
    is the smallest possible (here abs denotes the absolute value).
    If there are several possible answers, output the smallest one.

    Example

    For a = [2, 4, 7], the output should be
    absoluteValuesSumMinimization(a) = 4. 
    
    */
    
    int minSum{ INT_MAX }, index{ 0 };
    
    for (std::vector<int>::iterator i = a.begin() ; i != a.end() ; i++)
    {
        int temp{ 0 };
        
        for (auto k : a)
            temp += abs(k - *i);
        
        if (temp < minSum)
        {
            minSum = temp;
            index = i - a.begin();
        }
    }

    return a[index];
    
}
// return a[(a.size() - 1) / 2];
