bool evenDigitsOnly(int n) {

    /* Check if all digits of the given integer are even.

    Example

    For n = 248622, the output should be
    evenDigitsOnly(n) = true;
    For n = 642386, the output should be
    evenDigitsOnly(n) = false. */
    
    std::string s{ std::to_string(n) };
    
    for (char i : s)
        if ((i-'0')%2)
            return false;
    
    return true;

}

// return !~to_string(n).find_first_of("13579");
