  bool palindromeRearranging(std::string inputString) {

    /* Given a string, find out if its characters 
     * can be rearranged to form a palindrome.

     * Example

     * For inputString = "aabb", the output should 
     * be palindromeRearranging(inputString) = true.

     * We can rearrange "aabb" to make "abba", which is a palindrome. */
    
    
    std::unordered_map<char, int> m;
    
    for (char c : inputString)
        m[c]++;
    
    bool single = false;
    
    for (auto i : m) 
        if (i.second % 2 == 1) 
        {
            if (inputString.size() % 2 == 0 || single)
                return false;
            single = true;
        }
    return true;
}
