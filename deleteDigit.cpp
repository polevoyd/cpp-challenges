int deleteDigit(int n) {
/*
Given some integer, find the maximal number you can obtain by 
deleting exactly one digit of the given number.

Example

For n = 152, the output should be
deleteDigit(n) = 52;
For n = 1001, the output should be
deleteDigit(n) = 101.
*/
    
    std::string s = std::to_string(n);
    int r{INT_MIN};
    
    for (int i = 0; i < s.size() ; i++)
    {
        std::string temp{s};
        temp.erase(i, 1);
        
        if (std::stoi(temp) > r)
            r = std::stoi(temp);
    }

    return r;
}
