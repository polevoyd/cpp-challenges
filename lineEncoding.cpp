std::string lineEncoding(std::string s) {
/*
 Given a string, return its encoding defined as follows:

First, the string is divided into the least possible number 
of disjoint substrings consisting of identical characters
for example, "aabbbc" is divided into ["aa", "bbb", "c"]
Next, each substring with length greater than one is replaced 
with a concatenation of its length and the repeating character
for example, substring "bbb" is replaced by "3b"
Finally, all the new strings are concatenated together in the 
same order and a new string is returned.
Example

For s = "aabbbc", the output should be
lineEncoding(s) = "2a3bc".
 */
 
 std::string ret{};
 int temp{1};
 
 for (int i = 0; i < s.size() ; i++)
 {
       if (s[i] == s[i+1])
              temp++;
       else if (s[i] != s[i+1])
       {
             if (temp > 1)
                   ret.push_back(temp+'0');
   
             ret.push_back(s[i]);
             temp = 1;
       }
       else
       {
             if (i == s.size()-2)
             {
                   ret.push_back(s[i+1]);
             }
       }
 }
 return ret;
}
