std::string alphabeticShift(std::string &inputString) {

    /* Given a string, replace each its character by the next 
     * one in the English alphabet (z would be replaced by a).

    Example

    For inputString = "crazy", the output should be
    alphabeticShift(inputString) = "dsbaz". */
    
    std::string alphabet{"abcdefghijklmnopqrstuvwxyz"};
    
    for (char &i : inputString)
    {
        char temp{};
        
        for (int j = 0; j < alphabet.size() - 1 ; j++)
        {
            if ((i == alphabet[j])&&(i != 'z'))
                temp = alphabet[j + 1];
            
            if (i == 'z')
                temp = 'a';
        }
        
        i = temp;
    }

    return inputString;
}
/*
    for (int i = 0; i < inputString.size(); ++i) 
	{
        inputString[i] = (inputString[i] + 1 - 'a') % 26 + 'a';
    }
*/
