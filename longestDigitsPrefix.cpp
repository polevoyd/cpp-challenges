std::string longestDigitsPrefix(std::string inputString) {

    /* Given a string, output its longest prefix which contains only digits.

    Example

    For inputString="123aa1", the output should be
    longestDigitsPrefix(inputString) = "123". */
    
    std::string r{};
 
    if (std::isdigit(inputString[0]))
    {
        int counter{0};
        do
        {
            r.push_back(inputString[counter]);
            counter++;
        } while (std::isdigit(inputString[counter]));
    }
    return r;
    //return inputString.substr(0, inputString.find_first_not_of("0123456789"));
}
