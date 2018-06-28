int arrayMaximalAdjacentDifference(std::vector<int> inputArray) {

    /* Given an array of integers, find the maximal absolute difference 
     * between any two of its adjacent elements.
     * 
     * Example
     * 
     * For inputArray = [2, 4, 1, 0], the output should be
     * arrayMaximalAdjacentDifference(inputArray) = 3. */
    
    std::stack<int> s{};
    s.push(inputArray[0]);

    int max_difference{0};
    
    for (int i : inputArray)
    {
        if (abs(i - s.top()) > max_difference)
            max_difference = abs(i - s.top());
        s.push(i);
    }
    
    return max_difference;
}

/*   
	// another method using max()
	int ret = 0;
    
    for(int i=1; i<inputArray.size(); ++i)
        ret = max(ret,abs(inputArray[i]-inputArray[i-1]));
    
    return ret; 
	
*/
