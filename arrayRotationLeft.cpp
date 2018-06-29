vector<int> rotLeft(vector<int> a, int d) {
    
    //////////////////////////////////////////////////////////////////////////
    /////////SOLUTION WITH DOUBLING ARRAY AND PICK A SUBARRAY FROM IT/////////
    //////////////////////////////////////////////////////////////////////////
    
    // TIME: LINEAR N, cause assign and insert both linear in worst case
    // SPACE: LINEAR N, cause we create another array that 2N longer (N-size of array)
    
    // creating vector which is doubled input vector
    std::vector<int> v{ a };
    v.insert(v.end(), a.begin(), a.end());  
    
    // figuring out a window in which my subvector going to be
    int i{ d % a.size() };
    
    //assign a new subvector to input vector and return it
    a.assign(v.begin() + i, v.begin() + i + a.size());
    
    return a;
    
    //////////////////////////////////////////////////////////////////////////
    ////////////////SOLUTION WITH A LOOP MOVING EACH CHAR/////////////////////
    //////////////////////////////////////////////////////////////////////////
    
    /*
    // TIME: N*D, where D is amount of steps and N a size of array
    // SPACE: CONSTANT - cause no extra space needed
    // repeat whole operation d times
    for (int i = 0; i < d; i++)
    {
        // each time assign first one to temp and
        // then add it to end
        int temp{ a[0] };
        for (int k = 0; k < a.size()-1; k++)
        {
            a[k] = a[k+1];
        }   
        a[a.size()-1] = temp;
    }
    return a;
    */
    //////////////////////////////////////////////////////////////////////////
}

/*
Check out the resources on the page's right side to learn more about arrays. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.

A left rotation operation on an array shifts each of the array's elements  unit to the left. For example, if  left rotations are performed on array , then the array would become .

Given an array  of  integers and a number, , perform  left rotations on the array. Return the updated array to be printed as a single line of space-separated integers.

Function Description

Complete the function rotLeft in the editor below. It should return the resulting array of integers.

rotLeft has the following parameter(s):

An array of integers .
An integer , the number of rotations.
Input Format

The first line contains two space-separated integers  and , the size of  and the number of left rotations you must perform. 
The second line contains  space-separated integers .

Constraints

Output Format

Print a single line of  space-separated integers denoting the final state of the array after performing  left rotations.

Sample Input

5 4
1 2 3 4 5
Sample Output

5 1 2 3 4

*/
