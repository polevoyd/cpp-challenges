int commonCharacterCount(std::string s1, std::string s2) {

    /* Given two strings, find the number of common 
     * characters between them. */
 
    /* Sorting both of strings */
  sort(begin(s1), end(s1));
  sort(begin(s2), end(s2));
    
  /* Setting up a string to put all matches 
   * there and return size of that string */
  std::string intersection;
  std::set_intersection(begin(s1), end(s1), begin(s2), end(s2), back_inserter(intersection));
  
  return intersection.size();
}
