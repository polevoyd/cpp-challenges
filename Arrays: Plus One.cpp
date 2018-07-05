/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/
    vector<int> plusOne(vector<int>& digits) {

        // reversing array and adding 1 to each element
        // if element less than 9 - return array
        // if 10 - then element = 0 and move to next one
        // if element last and equal to 10 - it equal to 0
        // and push 1 to end
        // TIME: N LINEAR (size of array)
        // SPACE: 1 CONST (all done in place)
        // beats 100% of cpp solutions (yay)
        
        std::reverse(std::begin(digits), std::end(digits));
        
        for (int i = 0; i < digits.size(); i++)
        {
            digits[i]++;
            
            if (digits[i] < 10)
            {
                std::reverse(std::begin(digits), std::end(digits));
                return digits;
            }
            else
            {
                if (i == digits.size()-1)
                {
                    digits[i] = 0;
                    digits.push_back(1);
                    break;
                }
                else
                {
                    digits[i] = 0;
                } 
            }
        }

       std::reverse(std::begin(digits), std::end(digits));
        return digits;
    }
