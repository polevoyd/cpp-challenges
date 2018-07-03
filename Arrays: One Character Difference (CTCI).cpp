/* 
One Away: There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.
EXAMPLE
pale, pIe -> true
pales. pale -> true
pale. bale -> true
pale. bake -> false
*/

bool isOneAway(std::string s1, std::string s2){
	
  // a- longest string, b - shortest
  std::string a,b;
	a = s1.size() >= s2.size() ? s1 : s2;
	b = s1.size() < s2.size() ? s1 : s2;
  
  // if difference of strings more than 1 char its false
  if (std::abs(a.size() - b.size()) > 1)
		return false;
  
	bool flag = false;
	
  for(int i = 0, j = 0; i < a.size() && j < b.size(); )
  {
		if( a[i] != b[j])
    {
			if(flag)
				return false;
      
			flag = true;
			
      if(a.size() == b.size())
				i++,j++;
			else
				i++;
		}
		else
			i++,j++;
	}
	return true;
}
