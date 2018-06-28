int arrayMaxConsecutiveSum(std::vector<int> inputArray, int k) {

    /* Given array of integers, find the maximal possible sum of 
     * some of its k consecutive elements.

    Example

    For inputArray = [2, 3, 5, 1, 6] and k = 2, the output should be
    arrayMaxConsecutiveSum(inputArray, k) = 8.
    All possible sums of 2 consecutive elements are:

    2 + 3 = 5;
    3 + 5 = 8;
    5 + 1 = 6;
    1 + 6 = 7.
    Thus, the answer is 8. */
    
    /*
    int max_sum{ 0 };

	for (int i = 0; i <= inputArray.size() - k ; i++)
	{
		int temp_sum{ std::accumulate(inputArray.begin() + i, inputArray.begin() + i + k, 0) };
        std::cout << temp_sum << " ";
		if (temp_sum > max_sum)
		    max_sum = temp_sum;
	}

	return max_sum;
    */
    /*
    std::set<int> s{};
    for( int i = 0 ; i <= inputArray.size() - k ; i++)
        s.insert( std::accumulate(inputArray.begin() + i, inputArray.begin() + i + k, 0) );

    return *s.rbegin();
    */

    int mx = 0;
    
    for (int i = 0 ; i < k ; i++) 
        mx += inputArray[i];
    
    int s = mx;
    
    for (int i = k ; i < inputArray.size() ; i++) 
    {
        s -= inputArray[i-k];
        s += inputArray[i];
        mx = std::max(mx, s);
    }
    
    return mx;
}
