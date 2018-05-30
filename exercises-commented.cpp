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
	
	/*-------------------------------------------------------------*/

std::vector<int> alternatingSums(std::vector<int> a) {

    /* Several people are standing in a row 
     * and need to be divided into two teams. 
     * The first person goes into team 1, the 
     * second goes into team 2, the third goes 
     * into team 1 again, the fourth into team 2, 
     * and so on. You are given an array of 
     * positive integers - the weights of the 
     * people. Return an array of two integers, 
     * where the first element is the total weight 
     * of team 1, and the second element is the 
     * total weight of team 2 after the division 
     * is complete. */
    
    std::vector<int> sums{a[0] , a[1]};
    
    if (a.size() % 2)
    {
        for (int i = 2 ; i < a.size() ; i+=2)
            sums[0] += a[i];
        for (int j = 3 ; j < a.size() - 1 ; j+=2)
            sums[1] += a[j];
    }
    else
    {
        for (int i = 2 ; i < a.size() - 1 ; i+=2)
            sums[0] += a[i]; 
        for (int j = 3 ; j < a.size() ; j+=2)
            sums[1] += a[j];
    }

    return sums;
}

/*-------------------------------------------------------------*/

std::vector<std::string> addBorder(std::vector<std::string> picture) {
/* Given a rectangular matrix of characters, 
 * add a border of asterisks(*) to it.
 * Example
 * For
 * picture = ["abc",
              "ded"]
 * the output should be
 * addBorder(picture) = ["*****",
                         "*abc*",
                         "*ded*",
                         "*****"] 
 */

 picture.insert(picture.begin(), std::string(picture[0].size(), '*'));
 picture.push_back(std::string(picture[0].size(), '*'));

 for (auto &i : picture)
    i = "*" + i + "*";

 return picture;

}

/*-------------------------------------------------------------*/

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
    
  
/*-------------------------------------------------------------*/

bool areSimilar(std::vector<int> a, std::vector<int> b) {

    /* Two arrays are called similar if one can be obtained 
     * from another by swapping at most one pair of elements 
     * in one of the arrays. Given two arrays a and b, check 
     * whether they are similar.
     * Example
     * For a = [1, 2, 3] and b = [1, 2, 3], the output should be
     * areSimilar(a, b) = true.
     * The arrays are equal, no need to swap any elements. */
    
    /* If vector are equal then return true. If not, then we 
     * swap the values of the elements pointer at after finding 
     * a mismatch one time. If after that vector not 
     * equal - return 0; */
    
    if (a == b)
        return true;
    std::iter_swap(
        std::mismatch(a.begin(), a.end(), b.begin(), b.end()).first,
        std::mismatch(a.rbegin(), a.rend(), b.rbegin(), b.rend()).first
    );
    return a == b;
}

/*-------------------------------------------------------------*/

int arrayChange(std::vector<int> inputArray) {

    /* You are given an array of integers. 
     * On each move you are allowed to increase 
     * exactly one of its element by one. 
     * Find the minimal number of moves required 
     * to obtain a strictly increasing sequence 
     * from the input. */
    
    /* Put elements on stack and while stack size 
     * smaller than vector size and check for top 
     * element be smaller than next vector element, 
     * counting steps if we need to increase it 
     * in between */
    
    std::stack<int> s{};
    s.push(inputArray[0]);
    int counter_of_steps{ 0 };

    while (s.size() < inputArray.size())
        if (s.top() >= inputArray[s.size()])
        {
            inputArray[s.size()]++;
            counter_of_steps++;
        }
        else
            s.push(inputArray[s.size()]);

    return counter_of_steps;
}

/*-------------------------------------------------------------*/

     bool palindromeRearranging(std::string inputString) {

    /* Given a string, find out if its characters 
     * can be rearranged to form a palindrome.

     * Example

     * For inputString = "aabb", the output should 
     * be palindromeRearranging(inputString) = true.

     * We can rearrange "aabb" to make "abba", which is a palindrome. */
    
    
    std::unordered_map<char, int> m;
    
    for (char c : inputString)
        m[c]++;
    
    bool single = false;
    
    for (auto i : m) 
        if (i.second % 2 == 1) 
        {
            if (inputString.size() % 2 == 0 || single)
                return false;
            single = true;
        }
    return true;
}
     

/*-------------------------------------------------------------*/

bool areEquallyStrong(int yourLeft, int yourRight, int friendsLeft, int friendsRight) {

    /* Call two arms equally strong if the heaviest weights they each are able to lift are equal.
     * Call two people equally strong if their strongest arms are equally strong (the strongest 
     * arm can be both the right and the left), and so are their weakest arms.
     * Given your and your friend's arms' lifting capabilities find out if you two are equally strong.
     * 
     * Example
     * 
     * For yourLeft = 10, yourRight = 15, friendsLeft = 15 and friendsRight = 10, the output should be
     * areEquallyStrong(yourLeft, yourRight, friendsLeft, friendsRight) = true;
     * For yourLeft = 15, yourRight = 10, friendsLeft = 15 and friendsRight = 10, the output should be
     * areEquallyStrong(yourLeft, yourRight, friendsLeft, friendsRight) = true;
     * For yourLeft = 15, yourRight = 10, friendsLeft = 15 and friendsRight = 9, the output should be
     * areEquallyStrong(yourLeft, yourRight, friendsLeft, friendsRight) = false. */
    
    int your_strongest = (yourLeft >=yourRight) ? yourLeft : yourRight;
    int friend_strongest = (friendsLeft >= friendsRight) ? friendsLeft : friendsRight;
    int your_weakest = (yourLeft >=yourRight) ? yourRight : yourLeft;
    int friend_weakest = (friendsLeft >= friendsRight) ? friendsRight : friendsLeft;
    
    return (your_strongest == friend_strongest) && (your_weakest == friend_weakest);
}

/*-------------------------------------------------------------*/

int arrayMaximalAdjacentDifference(std::vector<int> inputArray) {

    /* Given an array of integers, find the maximal absolute difference 
     * between any two of its adjacent elements.
     * 
     * Example
     * 
     * For inputArray = [2, 4, 1, 0], the output should be
     * arrayMaximalAdjacentDifference(inputArray) = 3. */
    
    std::stack<int> s{};
    s.push(inputArray[0]);

    int max_difference{0};
    
    for (int i : inputArray)
    {
        if (abs(i - s.top()) > max_difference)
            max_difference = abs(i - s.top());
        s.push(i);
    }
    
    return max_difference;
}

/*   
	// another method using max()
	int ret = 0;
    
    for(int i=1; i<inputArray.size(); ++i)
        ret = max(ret,abs(inputArray[i]-inputArray[i-1]));
    
    return ret; 
	
*/

/*-------------------------------------------------------------*/

bool isIPv4Address(std::string inputString) {

    /* An IP address is a numerical label assigned to each device (e.g., computer, printer) 
     * participating in a computer network that uses the Internet Protocol for communication. 
     * There are two versions of the Internet protocol, and thus two versions of addresses. 
     * One of them is the IPv4 address.
     * 
     * IPv4 addresses are represented in dot-decimal notation, which consists of four decimal 
     * numbers, each ranging from 0 to 255 inclusive, separated by dots, e.g., 172.16.254.1.
     * 
     * Given a string, find out if it satisfies the IPv4 address naming rules.
     * 
     * Example
     * 
     * For inputString = "172.16.254.1", the output should be
     * isIPv4Address(inputString) = true;
     * 
     * For inputString = "172.316.254.1", the output should be
     * isIPv4Address(inputString) = false.
     * 316 is not in range [0, 255].
     * 
     * For inputString = ".254.255.0", the output should be
     * isIPv4Address(inputString) = false.
     * There is no first number. */
    
        regex ipv4("^((25[0-5]|2[0-4][0-9]|[1][0-9][0-9]|[0-9]{1,2})\\.){3}(25[0-5]|2[0-4][0-9]|[1][0-9][0-9]|[0-9]{1,2})$");
    
        return regex_match( inputString, ipv4 ) ;

}
     
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

 /*-------------------------------------------------------------*/

std::string hexToBase64(std::string str)
{
	/////////////////////////////////////////////////
	/* Function that encode a Hex string to Base64 */
	/////////////////////////////////////////////////
	
	// 1. Converting hexadecimal string to numerical binary
	std::string s{};
	for (char i : str)
	{
		switch (i)
		{
		case '0': s.append("0000"); break;
		case '1': s.append("0001"); break;
		case '2': s.append("0010"); break;
		case '3': s.append("0011"); break;
		case '4': s.append("0100"); break;
		case '5': s.append("0101"); break;
		case '6': s.append("0110"); break;
		case '7': s.append("0111"); break;
		case '8': s.append("1000"); break;
		case '9': s.append("1001"); break;
		case 'a': s.append("1010"); break;
		case 'b': s.append("1011"); break;
		case 'c': s.append("1100"); break;
		case 'd': s.append("1101"); break;
		case 'e': s.append("1110"); break;
		case 'f': s.append("1111"); break;
		default: break;
		}
	}

	// 2. Pad at the end as necessary with zeros (to divide by 6)
	while (s.size() % 6 != 0)
		s += '0';

	// 3. Divide binary string into words of 6 bits
	std::vector<std::string> vs{};
	for (int i = 0; i < s.size(); i += 6)
	{
		std::string temp(s, i, 6);
		vs.push_back(temp);
	}

	// 4. Convert 6 - bit words to decimal then decimal to ASCII
	std::vector<int> vi{};
	for (std::string &i : vs)
	{
		std::bitset<6> tmp{ i };
		vi.push_back(tmp.to_ulong());
	}

	const std::vector<char> base64_c{
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V',
		'W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','0','p','q','r',
		's','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/' };

	std::string rt{};

	for (int &i : vi)
		rt += base64_c[i];

	// 5. Pad the string with "=" as necessary
	while (rt.size() % 4 != 0)
		rt += '=';

	return rt;
}

/*-------------------------------------------------------------*/

std::vector<std::vector<int>> boxBlur(std::vector<std::vector<int>> image) {

    /* The pixels in the input image are represented as integers. The algorithm 
     * distorts the input image in the following way: Every pixel x in the output 
     * image has a value equal to the average value of the pixel values from the 
     * 3 × 3 square that has its center at x, including x itself. All the pixels 
     * on the border of x are then removed.
     * 
     * Return the blurred image as an integer, with the fractions rounded down. */
    
    
    std::vector<std::vector<int>> vector_return{};

    for (int i = 1 ; i < image.size() - 1 ; i++)
    {
        std::vector<int> vector_row{};  
        for (int k = 1; k < image[i].size() - 1 ; k++)
        {   
            int sum{};
            sum +=  image[i-1][k-1] + image[i-1][k] + image[i-1][k+1] + 
                    image[i][k-1]   + image[i][k]   + image[i][k+1]   + 
                    image[i+1][k-1] + image[i+1][k] + image[i+1][k+1];
                
            vector_row.push_back(sum / 9);
        }

        vector_return.push_back(vector_row);
    }

    return vector_return;
}

/*-------------------------------------------------------------*/

int avoidObstacles(std::vector<int> inputArray) {

    /* You are given an array of integers representing coordinates of obstacles 
     * situated on a straight line. Assume that you are jumping from the point 
     * with coordinate 0 to the right. You are allowed only to make jumps of the 
     * same length represented by some integer. Find the minimal length of the 
     * jump enough to avoid all the obstacles. 
     * 
     * Example
     * 
     * For inputArray = [5, 3, 6, 7, 9], the output should be 
     * 
     * avoidObstacles(inputArray) = 4 */


    int step = 1;
     
    while(true)
    { 
      bool found = true;

      for(int i = 0; i < inputArray.size() ; i++)
        if(inputArray[i] % step == 0) 
        {
          found = false;
          break;
        }
        
      if(found == true)
        return step;
       
      step++;
    }  
}

/*-------------------------------------------------------------*/

void print_PI_num()
{
	/* Find PI to the Nth Digit - Enter a number and have the program generate PI up to 
	that many decimal places. Keep a limit to how far the program will go. */

	std::cout << "Enter a number to show PI: ";

	unsigned int nth{};
	std::cin >> nth;
	std::cout << std::endl;
	double PI_to_show = 22.0 / 7.0;

	std::cout << std::fixed << std::setprecision(nth) << PI_to_show;
}
