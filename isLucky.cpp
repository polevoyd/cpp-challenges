bool isLucky(int n) {

    /* Ticket numbers usually consist of an 
     * even number of digits. A ticket number 
     * is considered lucky if the sum of the 
     * first half of the digits is equal to the 
     * sum of the second half. Given a ticket 
     * number n, determine if it's lucky or not. */
    
    std::string s = std::to_string(n);
    int sum1{}, sum2{}; 
   
    for (int i = 0, j = s.size()/2 ; i < s.size()/2, j < s.size() ; i++, j++)
    {
        sum1 += s[i] - '0';
        sum2 += s[j] - '0';
    }
    
    return (sum1 == sum2) ? true : false;
}
