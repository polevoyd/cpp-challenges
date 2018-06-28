std::string reverseParentheses(std::string str) {

    /* You have a string s that consists of English 
     * letters, punctuation marks, whitespace characters, 
     * and brackets. It is guaranteed that the parentheses 
     * in s form a regular bracket sequence. Your task is 
     * to reverse the strings contained in each pair of 
     * matching parentheses, starting from the innermost 
     * pair. The results string should not contain any 
     * parentheses.

     * Example

     * For string s = "a(bc)de", the output should be
     * reverseParentheses(s) = "acbde". */
     
     /*--------------need a refactoring--------------*/
     
     /* Function cut_par finds a smaller parenthesis 
      * and return a string with reversed substring 
      * inside it without parenthesis*/
     
     /* Find out how many () we actually have in a 
      * string and do cut_par in a loop for that 
      * amount of times */
     
     int counter{};

     for (auto i : str)
          if (i == '(')
               counter++;
     for (int i = 0 ; i < counter ; i++)
          str = cut_par(str);
 
     return str;
}

std::string cut_par(std::string s)
{ 
          std::vector<int> left_index{};
          std::vector<int> right_index{};
     
          /* Find biggest left '(' and after 
           * that find closest ')' to it */
     
          int left_max{-1}, right_min{56};
     
          for (int i = 0 ; i < s.size() ; i++)
               if (s[i] == '(')
                    left_max = i;  
     
          if (left_max == -1)
               return s;
          else
               for (int i = left_max ; i < s.size() ; i++)
                    if (s[i] == ')')
                    {
                         right_min = i;
                         break;
                    }       

          /* Now we have a vectors with closest 
          * parenthasis at first elements */
     
          left_index.push_back(left_max);
          right_index.push_back(right_min);
     
          /* If vector with indexes not empty, then 
          * for index of parenthesis we cut a substring, 
          * then reverse it and put it back on same place */
