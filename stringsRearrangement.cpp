/* Given an array of equal-length strings, check if it is possible to 
     * rearrange the strings in such a way that after the rearrangement the 
     * strings at consecutive positions would differ by exactly one character.

    Example

    For inputArray = ["aba", "bbb", "bab"], the output should be
    stringsRearrangement(inputArray) = false;

    All rearrangements don't satisfy the description condition.

    For inputArray = ["ab", "bb", "aa"], the output should be
    stringsRearrangement(inputArray) = true.

    Strings can be rearranged in the following way: "aa", "ab", "bb". */
        
    
    //Transforms the range [first, last) into the next permutation from 
    //the set of all permutations that are lexicographically ordered with 
    //respect to operator< or comp. Returns true if such permutation exists, 
    //otherwise transforms the range into the first permutation 
    //(as if by std::sort(first, last)) and returns false.
    
    while(std::next_permutation(inputArray.begin(), inputArray.end())) 
    {
        bool flag{ 1 };
        
        for(int i = 0; i < inputArray.size() - 1; i++) 
        {
            int c{ 0 };
            
            for(int j = 0; j < inputArray[i].size(); j++)
                if(inputArray[i][j] != inputArray[i+1][j])
                    c++;
            if(c != 1) 
                flag = 0; 
        }
        if(flag) 
            return true;
    }
    
    return false;
}
