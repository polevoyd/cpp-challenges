/* Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palin-
drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation 
is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words. 
EXAMPLE 
Input: Tact Coa 
Output: True (permutations: "taco cat". "atco cta". etc.) */

bool palindromeRearranging(std::string inputString) {

    /* Given a string, find out if its characters 
     * can be rearranged to form a palindrome.

     * Example

     * For inputString = "aabb", the output should 
     * be palindromeRearranging(inputString) = true.

     * We can rearrange "aabb" to make "abba", which is a palindrome. */
    
     // USING SET
     // TIME: N LINEAR - still going once through string
     // SPACE: N LINEAR - cause creating a set
     // creating a set of unique characters to count how many doesn't have a pair
     // while adding them to set we check if they already have a pair in a set
     // if one is already there - delete them both
     // if no - adding it cause its unique one (so far)
     // at end we have a set of unique chars that doesnt have a pair
     // if there is more than one char - it cannot be a palindrome
     std::set<char> unique_characters{};
     
     for (auto i : inputString)
     {
          // if one already there - delete it
          // if not - add
          if (unique_characters.find(i) != unique_characters.end())
          {
               unique_characters.erase(i);
          }
          else
          {
               unique_characters.insert(i);
          }
          
     }
     
     return unique_characters.size() <= 1 ? true : false;
     
     // USING HASH TABLE:
     // TIME: N + N = N LINEAR( two times run through string to create map and to count chars)
     // SPACE: N - cause we creating a map
     // Basically, the task is to know if that word can be possibly a palindrome if
     // we change characters order
     // To have palindrome we need each char be doubled and only one possible is unique
     // Create a map to count amount of chars <char, count>
     std::unordered_map<char, int> m{};
     
     // count chars
     for (auto i : inputString)
          if (m.find(i) != m.end())
               m[i]++;
          else
               m[i] = 1;

     //now making sure all chars are 2 and only one possible one
     int unique_chars{};
     for (auto i = m.begin(); i != m.end(); i++)
          if (i->second % 2 != 0)
               unique_chars++;
     
     return unique_chars < 2 ? true : false;
}

