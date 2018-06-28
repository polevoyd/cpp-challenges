bool variableName(std::string name) {

    /* Correct variable names consist only of English letters, 
     * digits and underscores and they can't start with a digit.

    Check if the given string is a correct variable name.

    Example

    For name = &quot;var_1__Int&quot;, the output should be
    variableName(name) = true;
    For name = &quot;qq-q&quot;, the output should be
    variableName(name) = false;
    For name = &quot;2w2&quot;, the output should be
    variableName(name) = false. */
    
    for (char i : name)
    { 
        if ((name[0] > 47 && name[0] < 58) || (i < 48) || (i < 65 && i > 57) || 
            ((i < 97 && i > 90)&&(i != 95)) || (i < 127 && i > 122))
            return false;
    }

    return true;
}
