int adjacentElementsProduct(std::vector<int> inputArray) {

    /* Given an array of integers, find the pair 
     * of adjacent elements that has the largest 
     * product and return that product. */
    
    int max_product{inputArray[0] * inputArray[1]};
    
    for (int i = 0; i < inputArray.size() - 1 ; i++)
        if (inputArray[i] * inputArray[i + 1] > max_product)
            max_product = inputArray[i] * inputArray[i + 1];
    
    return max_product;
}


/*-------------------------------------------------------------*/

 
int shapeArea(int n) {

    /* Your task is to find the area of a polygon 
     * for a given n. A 1-interesting polygon is 
     * just a square with a side of length 1. 
     * An n-interesting polygon is obtained by 
     * taking the n - 1-interesting polygon and 
     * appending 1-interesting polygons to its rim, 
     * side by side. */
    
    return n*n + (n-1)*(n-1);

}


/*-------------------------------------------------------------*/

 

int makeArrayConsecutive2(std::vector<int> statues) {

    
    /* Ratiorg got statues of different sizes as a present 
     * from CodeMaster for his birthday, each statue having 
     * an non-negative integer size. Since he likes to make 
     * things perfect, he wants to arrange them from smallest 
     * to largest so that each statue will be bigger than the 
     * previous one exactly by 1. He may need some additional 
     * statues to be able to accomplish that. Help him figure 
     * out the minimum number of additional statues needed.*/
    

    /* Find max number and min numbers, then return difference between count that should be between them and actual amount of numbers */
    
    int max{0}, min{20};

    for (auto i : statues)
    {
        if (i > max)
            max = i;
        if (i < min)
            min = i;
    }
    
   return (max - min - 1) - (statues.size() - 2);

}


/*-------------------------------------------------------------*/

 

bool almostIncreasingSequence(std::vector<int> sequence) {

    /* Given a sequence of integers as an array, 
     * determine whether it is possible to obtain 
     * a strictly increasing sequence by removing 
     * no more than one element from the array. */
    
    int removes_needed {0};
    
    int max{-100000};
    int second_max{-100000};
    
    for (int i = 0; i < sequence.size(); i++) 
    {
        if (sequence[i] > max) 
        {
            second_max = max;
            max = sequence[i];
        } 
        else if (sequence[i] > second_max) 
        {
            max = sequence[i];
            removes_needed++;
        } 
        else 
        {
            removes_needed++;
        }
    }
    
    return removes_needed < 2;  
}


/*-------------------------------------------------------------*/

 
int matrixElementsSum(std::vector<std::vector<int>> matrix) {

    /* After they became famous, the CodeBots all decided 
     * to move to a new building and live together. The 
     * building is represented by a rectangular matrix of 
     * rooms. Each cell in the matrix contains an integer 
     * that represents the price of the room. Some rooms 
     * are free (their cost is 0), but that's probably 
     * because they are haunted, so all the bots are afraid 
     * of them. That is why any room that is free or is 
     * located anywhere below a free room in the same column 
     * is not considered suitable for the bots to live in.

     *  Help the bots calculate the total price of all the 
     *  rooms that are suitable for them. */
     
     int sum{0};
     
     for (int i = 0 ; i < matrix.size() ; i++)
     {
          for (int j = 0 ; j < matrix[i].size() ; j++)
          {
               if (matrix[i][j] != 0)
               {
                    sum += matrix[i][j];
               } 
               else
               {
                    /* After meet 0 making all rooms 
                     * below equal to 0 as well */
                    
                    for (int k = i; k < matrix.size() ; k++)
                    {
                         matrix[k][j] = 0;
                    }
               }                   
          }
     }
     
     return sum;

}


/*-------------------------------------------------------------*/

 
void quickSort(std::vector<int> &input_array, int left, int right) 
{
	/* setting up indexes at the beginning and end, a pivot 	point in a 	middle*/
	int i{ left }, j{ right }, pivot{ input_array[(left + right) 	/ 2] };

	/* stepping through an array in between i and j */
	while (i <= j)
	{
		/* if left indexes elements smaller and right one 	bigger than a pivot than step over them, hey are already in 	order*/
		while (input_array[i] < pivot)
			i++;
		while (input_array[j] > pivot)
			j--;

		/* after meet element not in order - swap it and step 	further */
		if (i <= j)
		{
			int temp{ input_array[i] };
			input_array[i] = input_array[j];
			input_array[j] = temp;
			i++;
			j--;
		}
	}

	/* recursion */
	/* if i didnt reach a end (right) or j didnt reach a 	beginning (left), 	then repeat function */
	if (left < j)
		quickSort(input_array, left, j);
	if (i < right)
		quickSort(input_array, i, right);
}


/*-------------------------------------------------------------*/

 
std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {

    /* Given an array of strings, return another 
     * array containing all of its longest strings. */
    
    std::vector<std::string> longest_strings{};
    int longest_size{0};
    
    for (auto i : inputArray)
        if (i.size() > longest_size)   
            longest_size = i.size();
    
    for (auto i : inputArray)
        if (i.size() == longest_size)
            longest_strings.push_back(i);
    
    return longest_strings;
}


/*-------------------------------------------------------------*/

 
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


/*-------------------------------------------------------------*/

 
bool isLucky(int n) {

    /* Ticket numbers usually consist of an 
     * even number of digits. A ticket number 
     * is considered lucky if the sum of the 
     * first half of the digits is equal to the 
     * sum of the second half. Given a ticket 
     * number n, determine if it's lucky or not. */
    
    std::string s = std::to_string(n);
    int sum1{}, sum2{}; 
   
    for (int i = 0, j = s.size()/2 ; i < s.size()/2, j < s.size() ; i++, j++)
    {
        sum1 += s[i] - '0';
        sum2 += s[j] - '0';
    }
    
    return (sum1 == sum2) ? true : false;
}


/*-------------------------------------------------------------*/

 
std::vector<int> sortByHeight(std::vector<int> a) {

    /* Some people are standing in a row in a park. 
     * There are trees between them which cannot be moved. 
     * Your task is to rearrange the people by their heights 
     * in a non-descending order without moving the trees.

     * Example

     * For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
     * sortByHeight(a) = [-1, 150, 160, 170, -1, -1, 180, 190] */
    
    for (int i = 0 ; i < a.size() ; i++)
         for (int j = i ; j < a.size() ; j++)
              /* If its = -1 - we don't touch it */
              if ( (a[j] < a[i]) && (a[i] != -1) && (a[j] != -1) ) 
              {
                int temp{ a[i] };
                a[i] = a[j];
                a[j] = temp;
              }

    return a;
}


/*-------------------------------------------------------------*/

 
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
     
          if (!left_index.empty())
          {
               std::string temp{ s.substr(left_index[0] + 1, right_index[0] - left_index[0] - 1) };  
               std::reverse(std::begin(temp), std::end(temp));   
               s.replace(left_index[0] + 1, temp.size(), temp);
     
               /* Removing parenthesis */
               s.erase(left_max,1);
               s.erase(right_min - 1,1);
          }
          
          return s;
}


/*-------------------------------------------------------------*/

 
