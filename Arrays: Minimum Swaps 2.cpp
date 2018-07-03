
int minimumSwaps(vector<int> arr) {
    // TIME: N*N SQUARED (N - size of array)
    // SPACE: 1 CONSTANT
    // since number going to be consecutive,
    // we can check if each number on its ideal
    // sorted position (index + 1)
    // and if not - we will move variable temp
    // until find it in array and then swap
    // thus, in each step we have one number that sorted
    int steps {};
    // for rach element
    for (int i = 0; i < arr.size(); i++)
    {
        // see if its equal to index (sorted or not)
        if (arr[i] != (i+1))
        {
            // if not, go until meet ideal element
            // for that position
            int temp = i;
            while (arr[temp] != (i+1))
            {
                temp++;
            }
            // then swap and add step to counter
            std::swap(arr[temp], arr[i]);
            steps++;
        }
    }
    return steps;
}

/*
You are given an unordered array consisting of consecutive integers  [1, 2, 3, ..., n] without any duplicates. You are allowed to swap any two elements. You need to find the minimum number of swaps required to sort the array in ascending order.

For example, given the array  we perform the following steps:

i   arr                         swap (indices)
0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
5   [1, 2, 3, 4, 5, 6, 7]
It took  swaps to sort the array.

Function Description

Complete the function minimumSwaps in the editor below. It must return an integer representing the minimum number of swaps to sort the array.

minimumSwaps has the following parameter(s):

arr: an unordered array of integers
Input Format

The first line contains an integer, , the size of . 
The second line contains  space-separated integers .

Constraints

Output Format

Return the minimum number of swaps to sort the given array.

Sample Input 0

4
4 3 1 2
Sample Output 0

3
Explanation 0

Given array  
After swapping  we get  
After swapping  we get  
After swapping  we get  
So, we need a minimum of  swaps to sort the array in ascending order.

Sample Input 1

5
2 3 4 1 5
Sample Output 1

3
Explanation 1

Given array  
After swapping  we get  
After swapping  we get  
After swapping  we get  
So, we need a minimum of  swaps to sort the array in ascending order.
*/
