/* Is Unique: Implement an algorithm to determine if a string has all unique characters. 
What if you cannot use additional data structures? */

#include <set>
#include <algorithm>

bool hasUniqueChars(std::string s) {
  
  // TIME: N*LOG(N) (N - size of string)
  // SPACE: 1 (in place, don't need extra space
  // sorting an array and checking neighbors elements
  
  std::sort(s.begin(), s.end());
  for (int i = 0; i < s.size(); i++)
      if (s[i] == s[i+1])
          return false;
          
  return true;
  
  /////////////////////////////////////////////////////////////////////////////////////////////////
  // creating set and put all values there 
  // to compare sizes after 
  // TIME: N (N = size of string)
  // SPACE: N
  /*
  std::set<char> st{};
  for (auto i : s)
      st.insert(i);
  return (s.size() == st.size()) ? true : false;
  */
  
  /////////////////////////////////////////////////////////////////////////////////////////////////
  // two loops with checking for duplicates
  // TIME: N squared, where N - size of string
  // SPACE: CONSTANT
  /*
  for (int i = 0; i < s.size(); i++)
      for (int k = 0; k < s.size(); k++)
          if ((s[i] == s[k]) && (i != k))
              return false;
  
  return true;
  */
}
