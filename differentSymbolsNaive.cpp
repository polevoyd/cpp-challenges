int differentSymbolsNaive(std::string s) {

    /*Given a string, find the number of different characters in it.

    Example

    For s = &quot;cabca&quot;, the output should be
    differentSymbolsNaive(s) = 3.

    There are 3 different characters a, b and c.*/
    
    std::list<char> l{};
    
    for (auto i : s)
        l.push_back(i); 

    l.sort();
    l.unique(); 

    return l.size();
    
    //return std::set<char>(s.begin(), s.end()).size();
}
