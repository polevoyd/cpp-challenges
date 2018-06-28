char firstDigit(std::string inputString) {

    /* Find the leftmost digit that occurs in a given string.

    Example

    For inputString = "var_1__Int", the output should be
    firstDigit(inputString) = '1';
    For inputString = "q2q-q", the output should be
    firstDigit(inputString) = '2';
    For inputString = "0ss", the output should be
    firstDigit(inputString) = '0'. */
    
    std::vector<char> digits{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
        
    for (auto i : inputString)
        for (auto k : digits)
            if (i == k)
                return i;
    //for(char i : inputString) if(isdigit(i)) return i;
	
	//return inputString[inputString.find_first_of("0123456789")];
}
