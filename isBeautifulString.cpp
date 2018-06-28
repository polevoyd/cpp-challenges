bool isBeautifulString(std::string in) {

    /* A string is said to be beautiful if b occurs in it 
     * no more times than a; c occurs in it no more times than b; 
     * etc.

    Given a string, check whether it is beautiful.

    Example

    For inputString = "bbbaacdafe", the output should be
    isBeautifulString(inputString) = true;
    For inputString = "aabbb", the output should be
    isBeautifulString(inputString) = false;
    For inputString = "bbc", the output should be
    isBeautifulString(inputString) = false. */
    
    std::map<char, int> m{};
    std::vector<char> vc{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for (auto i : vc)
        m[i] = 0;
    for (auto i : in)
            m[i]++;

    /*----------------------------------------------------------------*/
    /*     we have a map with all characters and their occurencies    */
    /*----------------------------------------------------------------*/
    
    for (auto i = m.begin() ; i != std::prev(m.end(),1) ; i++)
        if (i->second < std::next(i,1)->second)
            return false;
    return true;
}
