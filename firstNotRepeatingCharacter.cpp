char firstNotRepeatingCharacter(std::string s) {
/*
Note: Write a solution that only iterates over the string once and 
uses O(1) additional memory, since this is what you would be asked 
to do during a real interview.

Given a string s, find and return the first instance of a non-repeating 
character in it. If there is no such character, return '_'.

Example

For s = "abacabad", the output should be
firstNotRepeatingCharacter(s) = 'c'.

There are 2 non-repeating characters in the string: 'c' and 'd'. Return c 
since it appears in the string first.

For s = "abacabaabacaba", the output should be
firstNotRepeatingCharacter(s) = '_'.

There are no characters in this string that do not repeat.
*/
    /* We creating only a map that not allows for a duplicates,
    which means maximum amount of elements limited by alphabet.
    That gives a O(1) constant space 
    
    Then we loop through string to fill and count characters into map,
    which is O(n) time (n - size of string) and then loop again to check
    each character in a string in map to find one with "1" value - it will
    be another O(n)
    
    Total Time: O(n) + O(n) = O(n);
    Total Space: O(1);
    
    */

    // creating a map <character, counter>
    std::unordered_map<char, int> m{};
    
    // filling a map
    for(char c : s)
        m[c]++;
    
    //checking for a char with value '1' in a map
    for(auto c: s)
        if(m[c] == 1)
            return c;

    return '_';
}
