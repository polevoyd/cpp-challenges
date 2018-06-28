int firstDuplicate(std::vector<int> a) {

    /* Given an array a that contains only numbers in the range 
     * from 1 to a.length, find the first duplicate number for 
     * which the second occurrence has the minimal index. In other 
     * words, if there are more than 1 duplicated numbers, return 
     * the number for which the second occurrence has a smaller 
     * index than the second occurrence of the other number does. 
     * If there are no such elements, return -1.

        Example

        For a = [2, 1, 3, 5, 3, 2], the output should be
        firstDuplicate(a) = 3.

        There are 2 duplicates: numbers 2 and 3. The second occurrence 
        of 3 has a smaller index than the second occurrence of 2 does, 
        so the answer is 3.

        For a = [2, 4, 3, 5, 1], the output should be
        firstDuplicate(a) = -1. */
    
    // With set: inserting all the elements 
    // and if meet duplicate - return it 

    std::set<int> s{};

	for (auto i : a)
		if (s.find(i) != s.end())
			return i;
		else
			s.insert(i);
	return -1;
    
    /*

     // With arrays (slower and more code)

    int smallest_index{INT_MAX};
    
	for (std::vector<int>::iterator it = a.begin() ; it != a.end() - 1 ; it++)
        for (std::vector<int>::iterator it_2 = it + 1 ; it_2 != a.end() ; it_2++)
            if ((*it_2 == *it) && ((it_2 - a.begin()) < smallest_index))
                smallest_index = it_2 - a.begin();

    return (smallest_index != INT_MAX) ? a[smallest_index] : -1;
    
    */
}
