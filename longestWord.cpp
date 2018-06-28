std::string longestWord(std::string text) {
/* 
Define a word as a sequence of consecutive English letters. 
Find the longest word from the given string.

Example

For text = "Ready, steady, go!", the output should be
longestWord(text) = "steady".*/
 
 std::string longest{""};
 
 int i{ 0 };
 
 while (i < text.size())
 {

    if ((96 < std::tolower(text[i])) && (std::tolower(text[i]) < 123))
    {
     int begin{i}, end{};
     
     while ((96 < std::tolower(text[i])) && (std::tolower(text[i]) < 123))
      i++;
     
     std::string temp = text.substr(begin, i - begin);
     
     if (temp.size() > longest.size())
      longest = temp;
    }
     i ++;
 }

  return longest;
}
