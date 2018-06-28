std::string buildPalindrome(std::string st) {

    /*
Given a string, find the shortest possible string which 
can be achieved by adding characters to the end of initial 
string to make it a palindrome.

Example

For st = "abcdc", the output should be
buildPalindrome(st) = "abcdcba".
    */
    
    std::string ret(st);  
    auto i = st.begin();
    std::string reversed = std::string(ret.rbegin(), ret.rend());
    while (ret != reversed) 
        ret.insert(st.size(), 1, *i++);
    return ret;

}
