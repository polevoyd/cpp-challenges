std::vector<char> reverseVowels(std::vector<char> v) {
	
	/* 	reverse vowels in a string.	*/
	/* 	vowels are: a, e, i, o, u 	*/
	
	int i = 0;
	int j = v.size() - 1;
	while (i < j) 
	{
		while (i < j && (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')) 
		{
			i++;
		}
		while (i < j && (v[j] == 'a' || v[j] == 'e' || v[j] == 'i' || v[j] == 'o' || v[j] == 'u'))
		{
			j--;
		}
		std::swap(v[i++], v[j--]); // need to #include <algorithm>
	}
	return v;
}
