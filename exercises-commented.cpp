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
/*-------------------------------------------------------------*/

std::vector<std::vector<int>> minesweeper(std::vector<std::vector<bool>> matrix) {
    
    /* In the popular Minesweeper game you have a board with some mines and those 
     * cells that don't contain a mine have a number in it that indicates the total 
     * number of mines in the neighboring cells. Starting off with some arrangement 
     * of mines we want to create a Minesweeper game setup.
     * 
     * Example
     * For
     *             matrix = [[true, false, false],
                            [false, true, false],
                            [false, false, false]]
                
     * the output should be
     * 
     * minesweeper(matrix) = [[1, 2, 1],
                              [2, 1, 1],
                              [1, 1, 1]]   */
    
    // creating a matrix of zeros
    std::vector<int> v(matrix[0].size() , 0);
    std::vector<std::vector<int>> matrix_to_return{matrix.size(), v };

    // For each element in a matrix
    for (int i = 0 ; i < matrix.size() ; i++)
    {
        for (int k = 0 ; k < matrix[i].size() ; k++)
        {
            // that is a bomb
            if (matrix[i][k] == true)
            {
                // decrement a bomb so it doesn't count itself
                matrix_to_return[i][k]--;
                
                // looking for elements
                for (int j = 0; j < matrix.size() ; j++)
                {
                    for (int l = 0 ; l < matrix[j].size() ; l++)
                    {
                        //  with indexes nearby
                        if ((abs(j-i) <= 1)&&(abs(l-k) <= 1))
                        {   
                            //and increment them
                            matrix_to_return[j][l]++;
                        }
                    }  
                }  
            }
        }
    }
	
    return matrix_to_return;
}
/*-------------------------------------------------------------*/

std::vector<int> arrayReplace(std::vector<int> &inputArray, int elemToReplace, int substitutionElem) {

    /* Given an array of integers, replace all the occurrences 
     * of elemToReplace with substitutionElem.
     * 
     * Example
     * 
     * For 
     * inputArray = [1, 2, 1], elemToReplace = 1 and substitutionElem = 3, 
     * 
     * the output should be
     * 
     * arrayReplace(inputArray, elemToReplace, substitutionElem) = [3, 2, 3]. */
    
/*
    for (int &i : inputArray)
        if (i == elemToReplace)
            i = substitutionElem;
*/  
    std::replace(inputArray.begin(), inputArray.end(), elemToReplace, substitutionElem);
    
    return inputArray;
}
/*-------------------------------------------------------------*/

bool evenDigitsOnly(int n) {

    /* Check if all digits of the given integer are even.

    Example

    For n = 248622, the output should be
    evenDigitsOnly(n) = true;
    For n = 642386, the output should be
    evenDigitsOnly(n) = false. */
    
    std::string s{ std::to_string(n) };
    
    for (char i : s)
        if ((i-'0')%2)
            return false;
    
    return true;

}

// return !~to_string(n).find_first_of("13579");
/*-------------------------------------------------------------*/

bool variableName(std::string name) {

    /* Correct variable names consist only of English letters, 
     * digits and underscores and they can't start with a digit.

    Check if the given string is a correct variable name.

    Example

    For name = &quot;var_1__Int&quot;, the output should be
    variableName(name) = true;
    For name = &quot;qq-q&quot;, the output should be
    variableName(name) = false;
    For name = &quot;2w2&quot;, the output should be
    variableName(name) = false. */
    
    for (char i : name)
    { 
        if ((name[0] > 47 && name[0] < 58) || (i < 48) || (i < 65 && i > 57) || 
            ((i < 97 && i > 90)&&(i != 95)) || (i < 127 && i > 122))
            return false;
    }

    return true;
}
/*-------------------------------------------------------------*/

std::string alphabeticShift(std::string &inputString) {

    /* Given a string, replace each its character by the next 
     * one in the English alphabet (z would be replaced by a).

    Example

    For inputString = "crazy", the output should be
    alphabeticShift(inputString) = "dsbaz". */
    
    std::string alphabet{"abcdefghijklmnopqrstuvwxyz"};
    
    for (char &i : inputString)
    {
        char temp{};
        
        for (int j = 0; j < alphabet.size() - 1 ; j++)
        {
            if ((i == alphabet[j])&&(i != 'z'))
                temp = alphabet[j + 1];
            
            if (i == 'z')
                temp = 'a';
        }
        
        i = temp;
    }

    return inputString;
}
/*
    for (int i = 0; i < inputString.size(); ++i) 
	{
        inputString[i] = (inputString[i] + 1 - 'a') % 26 + 'a';
    }
*/
/*-------------------------------------------------------------*/

bool chessBoardCellColor(std::string cell1, std::string cell2) {

    /* Given two cells on the standard chess board, determine 
     * whether they have the same color or not.

    Example

    For cell1 = "A1" and cell2 = "C3", the output should be
    chessBoardCellColor(cell1, cell2) = true.

    For cell1 = "A1" and cell2 = "H3", the output should be
    chessBoardCellColor(cell1, cell2) = false. */
    
    std::string board{"aABCDEFGH"};

    bool first{ false }, second{ false };
    
    for (int i = 1 ; i < board.size() ; ++i)
    {
        if (board[i] == cell1[0])
            if ((i + (cell1[1] - '0')) % 2 == 0)
                first = true;
        
        if (board[i] == cell2[0])
            if ((i + (cell2[1] - '0')) % 2 == 0)
                second = true;
    }
    
    return (first == second) ? true : false;
}
/*
return (a[0] + a[1]) % 2 == (b[0] + b[1]) % 2;
*/
/*-------------------------------------------------------------*/

int circleOfNumbers(int n, int firstNumber) {

    /* Consider integer numbers from 0 to n - 1 written down along 
     * the circle in such a way that the distance between any two 
     * neighbouring numbers is equal (note that 0 and n - 1 are 
     * neighbouring, too).

    Given n and firstNumber, find the number which is written in the 
    radially opposite position to firstNumber.

    Example

    For n = 10 and firstNumber = 2, the output should be
    circleOfNumbers(n, firstNumber) = 7. */
    
    return (firstNumber + n/2) % n;
}
/*-------------------------------------------------------------*/

int depositProfit(int deposit, int rate, int threshold) {

    /* You have deposited a specific amount of dollars into your bank account. 
     * Each year your balance increases at the same growth rate. Find out how 
     * long it would take for your balance to pass a specific threshold with the 
     * assumption that you don't make any additional deposits.

    Example

    For deposit = 100, rate = 20 and threshold = 170, the output should be
    depositProfit(deposit, rate, threshold) = 3.

    Each year the amount of money on your account increases by 20%. It means that 
    throughout the years your balance would be:

    year 0: 100;
    year 1: 120;
    year 2: 144;
    year 3: 172,8.
    Thus, it will take 3 years for your balance to pass the threshold, which is 
    the answer. */
    
    double balance{ deposit }, years{};
    
    while ( balance < threshold )
    {
        balance += balance * rate / 100;
        years++;
    }
    
    return years;
}
/*-------------------------------------------------------------*/

int absoluteValuesSumMinimization(std::vector<int> a) {

    /* Given a sorted array of integers a, find an integer x from a 
     * such that the value of

    abs(a[0] - x) + abs(a[1] - x) + ... + abs(a[a.length - 1] - x)
    is the smallest possible (here abs denotes the absolute value).
    If there are several possible answers, output the smallest one.

    Example

    For a = [2, 4, 7], the output should be
    absoluteValuesSumMinimization(a) = 4. 
    
    */
    
    int minSum{ INT_MAX }, index{ 0 };
    
    for (std::vector<int>::iterator i = a.begin() ; i != a.end() ; i++)
    {
        int temp{ 0 };
        
        for (auto k : a)
            temp += abs(k - *i);
        
        if (temp < minSum)
        {
            minSum = temp;
            index = i - a.begin();
        }
    }

    return a[index];
    
}
// return a[(a.size() - 1) / 2];
/*-------------------------------------------------------------*/

/* Given an array of equal-length strings, check if it is possible to 
     * rearrange the strings in such a way that after the rearrangement the 
     * strings at consecutive positions would differ by exactly one character.

    Example

    For inputArray = ["aba", "bbb", "bab"], the output should be
    stringsRearrangement(inputArray) = false;

    All rearrangements don't satisfy the description condition.

    For inputArray = ["ab", "bb", "aa"], the output should be
    stringsRearrangement(inputArray) = true.

    Strings can be rearranged in the following way: "aa", "ab", "bb". */
        
    
    //Transforms the range [first, last) into the next permutation from 
    //the set of all permutations that are lexicographically ordered with 
    //respect to operator< or comp. Returns true if such permutation exists, 
    //otherwise transforms the range into the first permutation 
    //(as if by std::sort(first, last)) and returns false.
    
    while(std::next_permutation(inputArray.begin(), inputArray.end())) 
    {
        bool flag{ 1 };
        
        for(int i = 0; i < inputArray.size() - 1; i++) 
        {
            int c{ 0 };
            
            for(int j = 0; j < inputArray[i].size(); j++)
                if(inputArray[i][j] != inputArray[i+1][j])
                    c++;
            if(c != 1) 
                flag = 0; 
        }
        if(flag) 
            return true;
    }
    
    return false;
}
/*-------------------------------------------------------------*/

std::vector<int> extractEachKth(std::vector<int> inputArray, int k) {
    
/* Given array of integers, remove each kth element from it.

Example

For inputArray = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] and k = 3, the output should be
extractEachKth(inputArray, k) = [1, 2, 4, 5, 7, 8, 10]. */
    
    std::vector<int> rtrn{};
    
    for (int i = 0 ; i < inputArray.size() ; i++)
        if ((i+1) % k != 0)
            rtrn.push_back(inputArray[i]);

    return rtrn;
}
/*-------------------------------------------------------------*/

char firstDigit(std::string inputString) {

    /* Find the leftmost digit that occurs in a given string.

    Example

    For inputString = "var_1__Int", the output should be
    firstDigit(inputString) = '1';
    For inputString = "q2q-q", the output should be
    firstDigit(inputString) = '2';
    For inputString = "0ss", the output should be
    firstDigit(inputString) = '0'. */
    
    std::vector<char> digits{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
        
    for (auto i : inputString)
        for (auto k : digits)
            if (i == k)
                return i;
    //for(char i : inputString) if(isdigit(i)) return i;
	
	//return inputString[inputString.find_first_of("0123456789")];
}
/*-------------------------------------------------------------*/

int differentSymbolsNaive(std::string s) {

    /*Given a string, find the number of different characters in it.

    Example

    For s = &quot;cabca&quot;, the output should be
    differentSymbolsNaive(s) = 3.

    There are 3 different characters a, b and c.*/
    
    std::list<char> l{};
    
    for (auto i : s)
        l.push_back(i); 

    l.sort();
    l.unique(); 

    return l.size();
    
    //return std::set<char>(s.begin(), s.end()).size();
}
/*-------------------------------------------------------------*/
int arrayMaxConsecutiveSum(std::vector<int> inputArray, int k) {

    /* Given array of integers, find the maximal possible sum of 
     * some of its k consecutive elements.

    Example

    For inputArray = [2, 3, 5, 1, 6] and k = 2, the output should be
    arrayMaxConsecutiveSum(inputArray, k) = 8.
    All possible sums of 2 consecutive elements are:

    2 + 3 = 5;
    3 + 5 = 8;
    5 + 1 = 6;
    1 + 6 = 7.
    Thus, the answer is 8. */
    
    /*
    int max_sum{ 0 };

	for (int i = 0; i <= inputArray.size() - k ; i++)
	{
		int temp_sum{ std::accumulate(inputArray.begin() + i, inputArray.begin() + i + k, 0) };
        std::cout << temp_sum << " ";
		if (temp_sum > max_sum)
		    max_sum = temp_sum;
	}

	return max_sum;
    */
    /*
    std::set<int> s{};
    for( int i = 0 ; i <= inputArray.size() - k ; i++)
        s.insert( std::accumulate(inputArray.begin() + i, inputArray.begin() + i + k, 0) );

    return *s.rbegin();
    */

    int mx = 0;
    
    for (int i = 0 ; i < k ; i++) 
        mx += inputArray[i];
    
    int s = mx;
    
    for (int i = k ; i < inputArray.size() ; i++) 
    {
        s -= inputArray[i-k];
        s += inputArray[i];
        mx = std::max(mx, s);
    }
    
    return mx;
}
/*-------------------------------------------------------------*/

int growingPlant(int upSpeed, int downSpeed, int desiredHeight) {
    /*
    Each day a plant is growing by upSpeed meters. Each night that 
    plant's height decreases by downSpeed meters due to the lack of sun 
    heat. Initially, plant is 0 meters tall. We plant the seed at the 
    beginning of a day. We want to know when the height of the plant will 
    reach a certain level.

    Example

    For upSpeed = 100, downSpeed = 10 and desiredHeight = 910, the output should be
    growingPlant(upSpeed, downSpeed, desiredHeight) = 10.
    */
    
    int current_height{ 0 }, days{ 0 };
    
    while (current_height < desiredHeight)
    {
        current_height += upSpeed;
        if (current_height >= desiredHeight)
            return days + 1;
        current_height -= downSpeed;
        days++;
    }
     return days - 1;
}
/*-------------------------------------------------------------*/

int knapsackLight(int value1, int weight1, int value2, int weight2, int maxW) {

    /* You found two items in a treasure chest! The first item weighs weight1 and is 
     * worth value1, and the second item weighs weight2 and is worth value2. What is the 
     * total maximum value of the items you can take with you, assuming that your max 
     * weight capacity is maxW and you can't come back for the items later?

    Note that there are only two items and you can't bring more than one item of each type, 
    i.e. you can't take two first items or two second items.

    Example

    For value1 = 10, weight1 = 5, value2 = 6, weight2 = 4 and maxW = 8, the output should be
    knapsackLight(value1, weight1, value2, weight2, maxW) = 10.

    You can only carry the first item.

    For value1 = 10, weight1 = 5, value2 = 6, weight2 = 4 and maxW = 9, the output should be
    knapsackLight(value1, weight1, value2, weight2, maxW) = 16.

    You're strong enough to take both of the items with you.

    For value1 = 5, weight1 = 3, value2 = 7, weight2 = 4 and maxW = 6, the output should be
    knapsackLight(value1, weight1, value2, weight2, maxW) = 7.

    You can't take both items, but you can take any of them. */
           
    if ((maxW == weight1) && (value1 * maxW / weight1 > value2 * maxW / weight2))
        return value1;
    if ((maxW == weight2) && (value1 * maxW / weight1 < value2 * maxW / weight2))
        return value2;
    if (maxW >= weight1 + weight2)
            return value1 + value2;
    if (maxW < std::min(weight1, weight2))
        return 0;
    else
        return std::max(value1, value2); 
}
/*-------------------------------------------------------------*/

std::string longestDigitsPrefix(std::string inputString) {

    /* Given a string, output its longest prefix which contains only digits.

    Example

    For inputString="123aa1", the output should be
    longestDigitsPrefix(inputString) = "123". */
    
    std::string r{};
 
    if (std::isdigit(inputString[0]))
    {
        int counter{0};
        do
        {
            r.push_back(inputString[counter]);
            counter++;
        } while (std::isdigit(inputString[counter]));
    }
    return r;
    //return inputString.substr(0, inputString.find_first_not_of("0123456789"));
}
/*-------------------------------------------------------------*/

int binarySearch(std::vector<int> v, int e)
{
	/* binary search in a vector */
	int v_size{ (int)v.size() };
	int left{ 0 }, right{ v_size - 1 };
	int pivot{ v_size / 2 };

	while (pivot != e)
	{
		if (v[pivot] == e)
			return pivot;
		else if (v[pivot] > e)
		{
			right = pivot;
			pivot /= 2;
		}
		else
		{
			left = pivot;
			pivot += pivot / 2;
		}
	}
	return pivot;
}
/*-------------------------------------------------------------*/

int digitDegree(int n) {

    /* Let's define digit degree of some positive integer as the number 
     * of times we need to replace this number with the sum of its digits 
     * until we get to a one digit number.

    Given an integer, find its digit degree.

    Example

    For n = 5, the output should be
    digitDegree(n) = 0;
    For n = 100, the output should be
    digitDegree(n) = 1.
    1 + 0 + 0 = 1.
    For n = 91, the output should be
    digitDegree(n) = 2.
    9 + 1 = 10 -> 1 + 0 = 1. */
    
    int count{ 0 };
    std::string s{ std::to_string(n) };
    
    while (s.size() > 1)
    {
        count++;
        int temp{};

        for(auto i : s)
            temp += (i - '0');

        s = std::to_string(temp);
    }
    
    return count;
}
/*-------------------------------------------------------------*/

bool bishopAndPawn(std::string bishop, std::string pawn) {

    /* Given the positions of a white bishop and a black pawn on 
     * the standard chess board, determine whether the bishop can 
     * capture the pawn in one move.

        The bishop has no restrictions in distance for each move, 
        but is limited to diagonal movement. Check out the example 
        below to see how it can move:

        Example

        For bishop = "a1" and pawn = "c3", the output should be
        bishopAndPawn(bishop, pawn) = true.

        For bishop = "h1" and pawn = "h3", the output should be
        bishopAndPawn(bishop, pawn) = false.
 */
        
        // basically, if a pawn stands at position, which
        // dots have absolute values different from bishops absolute values,
        // then return true; else return false;
        // 
        // 

        // making a board 
        std::vector<char> tmp{'a','b','c','d','e','f','g','h'};
        std::map<char, int> board{};
        for (auto i = tmp.begin() ; i != tmp.end() ; i++)
                board.insert(std::make_pair<char, int>((char)(*i), (int)(i - tmp.begin() + 1)));

        auto x_bb = board.find(bishop[0]);
        int x_b { x_bb->second};
        int y_b = bishop[1] - '0';
        
        auto x_pp = board.find(pawn[0]);
        int x_p { x_pp->second};
        int y_p = pawn[1] - '0';
        
        return (std::abs(x_b - x_p) == std::abs(y_b - y_p)) ? true : false;
        
        // or just 
        // return abs(p[0]-b[0]) == abs(p[1]-b[1]);
}
/*-------------------------------------------------------------*/
/*
Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;  
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
 /* 	preorder traversal 	*/ 
 /* 	root - left - right	*/
 /* 
 since we doing recursion, we can't create vector inside of recursion
and have to split function to two functions: one accepting a root and vector
and doing traversal and another one takes root, creates empty vector and
applying first function to it 
*/
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) 
    {
		std::vector<int> rt{};
        calculateAndReturn(root, rt);
        return rt;
    }
    
    void calculateAndReturn(TreeNode *root, std::vector<int> &v)
    {
        if ( root != NULL )                     // if node is not empty, cause otherwise nothing to add
        { 
            v.push_back(root->val);             // adding value to a vector
            calculateAndReturn( root->left, v);  // going to left child and repeat previous steps 
            calculateAndReturn( root->right, v); // going to right child and repeat previous steps 
        }
    }
};
/* 
BUT we can also do that just using a static variable 
and add values directly to it 
*/
static std::vector<int> v{};
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) 
    {
        if ( root != NULL )                  // if node is not empty, cause otherwise nothing to add
        { 
            v.push_back(root->val);          // adding current |root| value to a vector
            preorderTraversal( root->left);  // going to |left| child and repeat previous steps 
            preorderTraversal( root->right); // going to |right| child and repeat previous steps 
        }
        return v;
    }
};
/* same thing but without recursion (iteratively) */
class Solution {
public:
    std::vector<int> v{};
    std::vector<int> preorderTraversal(TreeNode* root) 
    {
        std::vector<int> v{};
        std::stack<TreeNode*> s{};
        if (root == NULL)   // if input empty
            return v;       // then return vector
        else
        {
            s.push(root);       // adding this root to stack
            while(!s.empty())   // while stack is not empty
            {
                TreeNode *tmp = s.top();     //temp node that will be a link to top one
                v.push_back(tmp->val);       // push the root's value into a vector
                s.pop();                     //pop the temp node from stack
                                            // since stack is FILO
                if(tmp->right != NULL)      // if right node not empty
                    s.push(tmp->right); // then push it to stack
                if(tmp->left != NULL)       // if left node not empty
                    s.push(tmp->left);  // then push it to stack too
            }
        return v;
        }
    }
};

/*-------------------------------------------------------------*/
/* Binary Tree Inorder Traversal */
/*
Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode *left;   
TreeNode *right;  
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
class Solution {
public:
    void calculateIntoVector(TreeNode* root, std::vector<int> &v)
    {
        if (root != NULL)
        {
            calculateIntoVector(root->left, v);
            v.push_back(root->val);
            calculateIntoVector(root->right, v);
        }
    }
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> r{};
        calculateIntoVector(root, r);
        return r;
    }
};

/*---------------inorder iteratively------------------*/

    std::vector<int> inorderTraversal(TreeNode* root) {
        
        std::vector<int> r{};
        // if root is null then just return empty vector
        if (root == NULL) return r;
        //if not, we are creating an empty stack
        std::stack<TreeNode*> st{};
        TreeNode* current = root;
        // while current not empty or stack not empty
        while (current || !st.empty()) 
        {
            //specifically, while current not empty
            //we pushing it to stack and moving to left
            while (current) 
            {
                st.push(current);
                current = current->left;
            }
            //okay, now current is NULL
            // so we making current pack to
            //previous one (top of stack)
            current = st.top();
            //and pop it from stack
            st.pop();
            //adding current value to vector
            r.push_back(current->val);
            //and moving to right
            current = current->right;
        }
        return r;
    }
/*-------------------------------------------------------------*/

/*
Binary Tree Postorder Traversal

Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
-------------Recursive way-------------
*/
class Solution {
public:
    void traversePost(TreeNode* root, std::vector<int> &v)
    {
        if (root != NULL)
        {
            /*root - right - left*/
            traversePost(root->left, v);
            traversePost(root->right, v);
            v.push_back(root->val);
        }
    }
    
    std::vector<int> postorderTraversal(TreeNode* root) 
    {        
        std::vector<int> v{};
        traversePost(root, v);
        return v;
    }
};

/*-----------iterative way-----------*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> r;
        stack<TreeNode*> s;
        TreeNode* _current_node = root;
        TreeNode* _last_node = NULL;
        
        while(_current_node || !s.empty())
        {
            if(_current_node)
            {
                s.push(_current_node);
                _current_node = _current_node->left;
            }
            else
            {
                TreeNode* _top_node = s.top();
                if(_top_node->right && _top_node->right != _last_node)
                {
                    _current_node = _top_node->right;
                }
                else
                {
                    r.push_back(_top_node->val);
                    _last_node = _top_node;
                    s.pop();
                }
            }
        }
    return r;
    }
};
/*-------------------------------------------------------------*/
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

/*-------------------------------------------------------------*/

bool isBeautifulString(std::string in) {

    /* A string is said to be beautiful if b occurs in it 
     * no more times than a; c occurs in it no more times than b; 
     * etc.

    Given a string, check whether it is beautiful.

    Example

    For inputString = "bbbaacdafe", the output should be
    isBeautifulString(inputString) = true;
    For inputString = "aabbb", the output should be
    isBeautifulString(inputString) = false;
    For inputString = "bbc", the output should be
    isBeautifulString(inputString) = false. */
    
    std::map<char, int> m{};
    std::vector<char> vc{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for (auto i : vc)
        m[i] = 0;
    for (auto i : in)
            m[i]++;

    /*----------------------------------------------------------------*/
    /*     we have a map with all characters and their occurencies    */
    /*----------------------------------------------------------------*/
    
    for (auto i = m.begin() ; i != std::prev(m.end(),1) ; i++)
        if (i->second < std::next(i,1)->second)
            return false;
    return true;
}

/*-------------------------------------------------------------*/

std::string findEmailDomain(std::string address) {

/* An email address such as "John.Smith@example.com" is 
made up of a local part ("John.Smith"), an "@" symbol, 
then a domain part ("example.com").

The domain name part of an email address may only consist of 
letters, digits, hyphens and dots. The local part, however, 
also allows a lot of different special characters. Here you 
can look at several examples of correct and incorrect email 
addresses.

Given a valid email address, find its domain part.

Example

For address = "prettyandsimple@example.com", the output should be
findEmailDomain(address) = "example.com";
For address = "<>[]:,;@\"!#$%&*+-/=?^_{}| ~.a\"@example.org", the output should be
findEmailDomain(address) = "example.org". */
    
    char at { '@' };
    for (auto i = address.size() - 1 ; i > 0 ; i--)
        if (address[i] == at) 
            return address.substr(i + 1);
}

/*-------------------------------------------------------------*/

std::string buildPalindrome(std::string st) {

    /*
Given a string, find the shortest possible string which 
can be achieved by adding characters to the end of initial 
string to make it a palindrome.

Example

For st = "abcdc", the output should be
buildPalindrome(st) = "abcdcba".
    */
    
    std::string ret(st);  
    auto i = st.begin();
    std::string reversed = std::string(ret.rbegin(), ret.rend());
    while (ret != reversed) 
        ret.insert(st.size(), 1, *i++);
    return ret;

}

/*------------------------------------------*/
/*		check for palindrome        */
/*------------------------------------------*/

bool isPalindrome(std::string s)
{
    for (int i = 0 ; i < s.size()/2 ; i++)
        if (s[i] != s[s.size() - 1 - i])
            return false;
    return true;
}

/*-------------------------------------------------------------*/

int electionsWinners(std::vector<int> votes, int k) {
/*
Elections are in progress!

Given an array of the numbers of votes given to each of the candidates so far, 
and an integer k equal to the number of voters who haven't cast their vote yet, 
find the number of candidates who still have a chance to win the election.

The winner of the election must secure strictly more votes than any other candidate. 
If two or more candidates receive the same (maximum) number of votes, assume there 
is no winner at all.

Example

For votes = [2, 3, 5, 2] and k = 3, the output should be
electionsWinners(votes, k) = 2.

The first candidate got 2 votes. Even if all of the remaining 3 candidates vote for 
him, he will still have only 5 votes, i.e. the same number as the third candidate, 
so there will be no winner.
The second candidate can win if all the remaining candidates vote for him (3 + 3 = 6 > 5).
The third candidate can win even if none of the remaining candidates vote for him. 
For example, if each of the remaining voters cast their votes for each of his opponents, 
he will still be the winner (the votes array will thus be [3, 4, 5, 3]).
The last candidate can't win no matter what (for the same reason as the first candidate).
Thus, only 2 candidates can win (the second and the third), which is the answer.
*/

// if there are duplicates - then return 0


//[1, 1, 1, 3, 3] k = 0

    int max{INT_MIN};
    int numberOfMax{0};
    
    for(int candidate : votes) 
    {
        if(candidate > max)
            max = candidate;
    }
    
    int count{0};
    
    for(int candidate : votes) 
    {
        if(candidate == max) 
            numberOfMax++;
        else if (candidate + k > max) 
            count++;
    }
    
    if (k == 0 && numberOfMax > 1) 
        return 0; 
    return numberOfMax+count;
}

/*-------------------------------------------------------------*/

bool isMAC48Address(std::string inputString) {
/*
A media access control address (MAC address) is a unique identifier 
assigned to network interfaces for communications on the physical 
network segment.

The standard (IEEE 802) format for printing MAC-48 addresses in 
human-friendly form is six groups of two hexadecimal digits (0 to 9 or A to F), 
separated by hyphens (e.g. 01-23-45-67-89-AB).

Your task is to check by given string inputString whether it corresponds 
to MAC-48 address or not.

Example

For inputString = "00-1B-63-84-45-E6", the output should be
isMAC48Address(inputString) = true;
For inputString = "Z1-1B-63-84-45-E6", the output should be
isMAC48Address(inputString) = false;
For inputString = "not a MAC-48 address", the output should be
isMAC48Address(inputString) = false.
*/

std::set<int> allowed{'A', 'B', 'C', 'D', 'E', 'F', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-'};
           
for (int i = 0 ; i < inputString.size() ; i++)
{
        auto search = allowed.find(inputString[i]);
        
        if (search == allowed.end())
                return false;
        else if (((i == 2)||(i == 5)||(i == 8)||(i == 11)||(i == 14)) && (inputString[i] != '-'))
                return false;
        else if (inputString.size() != 17)
                return false;
        else if (((i != 2)&&(i != 5)&&(i != 8)&&(i != 11)&&(i != 14)) && (inputString[i] == '-'))
                return false;
}
return true;
 
/* regex solution    
regex r("[0-9a-fA-F]{2}(-[0-9a-fA-F]{2}){5}");
return regex_match(inputString,r);
*/   
}

/*-------------------------------------------------------------*/

bool isDigit(char symbol) {
/* Determine if the given character is a digit or not. */
return std::isdigit(symbol);
}

/*-------------------------------------------------------------*/

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

/*-------------------------------------------------------------*/
int chessKnight(std::string cell) {
/*
Given a position of a knight on the standard chessboard, find the number 
of different moves the knight can perform.

The knight can move to a square that is two squares horizontally and one 
square vertically, or two squares vertically and one square horizontally 
away from it. The complete move therefore looks like the letter L. Check 
out the image below to see all valid moves for a knight piece that is placed 
on one of the central squares.

Example

For cell = "a1", the output should be
chessKnight(cell) = 2.

For cell = "c2", the output should be
chessKnight(cell) = 6.
*/
    // by default we have an 8 options
    int counter{8};

    // creating a map with key-value as x-y position of possible dots
    std::multimap<char, int> m{};
    
    // left part
    m.insert(std::make_pair(cell[0] - 2, (cell[1] - '0') + 1));
    m.insert(std::make_pair(cell[0] - 2, (cell[1] - '0') - 1));
    m.insert(std::make_pair(cell[0] - 1, (cell[1] - '0') + 2));
    m.insert(std::make_pair(cell[0] - 1, (cell[1] - '0') - 2));
    
    // right part
    m.insert(std::make_pair(cell[0] + 1, (cell[1] - '0') + 2));
    m.insert(std::make_pair(cell[0] + 1, (cell[1] - '0') - 2));
    m.insert(std::make_pair(cell[0] + 2, (cell[1] - '0') + 1));
    m.insert(std::make_pair(cell[0] + 2, (cell[1] - '0') - 1));    
    
    //going through and decrement counter for invalid positions
    for (auto i = m.begin() ; i != m.end() ; i++)
        if (((*i).first > 104) || ((*i).first < 97) || ((*i).second > 8) || ((*i).second < 1))
            counter--;
    
    return counter;
}
/*-------------------------------------------------------------*/

