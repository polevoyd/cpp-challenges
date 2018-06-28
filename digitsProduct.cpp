int digitsProduct(int product) {
/*
Given an integer product, find the smallest positive (i.e. greater than 0) 
integer the product of whose digits is equal to product. If there is no such 
integer, return -1 instead.

Example

For product = 12, the output should be
digitsProduct(product) = 26;
For product = 19, the output should be
digitsProduct(product) = -1.
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] integer product

Guaranteed constraints:
0 ≤ product ≤ 600.

[output] integer
*/

    if (product < 10)
        return product?: 10;
    
    std::string r{};
    
    for (int i = 9; i > 1; i--) 
    {
        while (product % i == 0) 
        {
            product /= i;
            r = char('0' + i) + r;
        }
    }
    
    return product == 1 ? std::stoi(r) : -1;
}
