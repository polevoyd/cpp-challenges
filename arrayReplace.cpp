std::vector<int> arrayReplace(std::vector<int> &inputArray, int elemToReplace, int substitutionElem) {

    /* Given an array of integers, replace all the occurrences 
     * of elemToReplace with substitutionElem.
     * 
     * Example
     * 
     * For 
     * inputArray = [1, 2, 1], elemToReplace = 1 and substitutionElem = 3, 
     * 
     * the output should be
     * 
     * arrayReplace(inputArray, elemToReplace, substitutionElem) = [3, 2, 3]. */
    
/*
    for (int &i : inputArray)
        if (i == elemToReplace)
            i = substitutionElem;
*/  
    std::replace(inputArray.begin(), inputArray.end(), elemToReplace, substitutionElem);
    
    return inputArray;
}
