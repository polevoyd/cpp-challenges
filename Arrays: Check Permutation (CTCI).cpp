/* Check Permutation: Given two strings, write a method to decide if one is a permutation of the
other. */

bool checkPermutation(std::string s1, std::string s2){

    // TIME: N+M LINEAR (N,M -sizes of strings)
    // SPACE: N LINEAR - cause we creating maps???
    // create a map with char: amount
    // that hold frequency of characters in string
    std::unordered_map<char, int> m1{};
    for (char i : s1)
    {
        bool exist = m1.find(i) != m1.end();

        if (exist)
            m1[i]++;
        else
            m1[i] = 1;
    }

    // check if another string has same amounts
    std::unordered_map<char, int> m2{};
    for (char i : s2)
    {
        bool exist = m2.find(i) != m2.end();

        if (exist)
            m2[i]++;
        else
            m2[i] = 1;
    }

    //see if maps are equal
    return m1 == m2 ? true : false;
}
