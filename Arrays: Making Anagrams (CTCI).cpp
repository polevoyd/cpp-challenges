int makeAnagram(string a, string b) {
    
    // BRUTE FORCE:
    // for each element in first array check equal element in second and
    // cross it. At end count amount elements that not crossed
    // TIME: N*M where (N,M - sizes)
    // SPACE: 1 CONST
    int counter{};
    
    for (char &i : a)
        for (char &k : b)
            if (i == k)
            {
                i = '0';
                k = '0';
                break;
            }
    
    for (auto i : a)
        if (i != '0')
            counter++;
    
    for (auto i : b)
        if (i != '0')
            counter++;

    return counter;
}

/*
Check out the resources on the page's right side to learn more about strings. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.

Alice is taking a cryptography class and finding anagrams to be very useful. We consider two strings to be anagrams of each other if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

Alice decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. Can you help her find this number?

Given two strings,  and , that may or may not be of the same length, determine the minimum number of character deletions required to make  and  anagrams. Any characters can be deleted from either of the strings.

Function Description

Complete the makeAnagram function in the editor below. It must return an integer representing the minimum total characters that must be deleted to make the strings anagrams.

makeAnagram has the following parameter(s):

a: a string
b: a string
Input Format

The first line contains a single string, . 
The second line contains a single string, .

Constraints

The strings  and  consist of lowercase English alphabetic letters ascii[a-z].
Output Format

Print a single integer denoting the number of characters you must delete to make the two strings anagrams of each other.

Sample Input

cde
abc
Sample Output

4
Explanation

We delete the following characters from our two strings to turn them into anagrams of each other:

Remove d and e from cde to get c.
Remove a and b from abc to get c.
We must delete  characters to make both strings anagrams, so we print  on a new line.
*/
