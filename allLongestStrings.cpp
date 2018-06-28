std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {

    /* Given an array of strings, return another 
     * array containing all of its longest strings. */
    
    std::vector<std::string> longest_strings{};
    int longest_size{0};
    
    for (auto i : inputArray)
        if (i.size() > longest_size)   
            longest_size = i.size();
    
    for (auto i : inputArray)
        if (i.size() == longest_size)
            longest_strings.push_back(i);
    
    return longest_strings;
}
