bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
/*
A cryptarithm is a mathematical puzzle for which the goal is to find the correspondence between letters and digits, such that the given arithmetic equation consisting of letters holds true when the letters are converted to digits.

You have an array of strings crypt, the cryptarithm, and an an array containing the mapping of letters and digits, solution. The array crypt will contain three non-empty strings that follow the structure: [word1, word2, word3], which should be interpreted as the word1 + word2 = word3 cryptarithm.

If crypt, when it is decoded by replacing all of the letters in the cryptarithm with digits using the mapping in solution, becomes a valid arithmetic equation containing no numbers with leading zeroes, the answer is true. If it does not become a valid arithmetic solution, the answer is false.

Example

For crypt = ["SEND", "MORE", "MONEY"] and

solution = [['O', '0'],
            ['M', '1'],
            ['Y', '2'],
            ['E', '5'],
            ['N', '6'],
            ['D', '7'],
            ['R', '8'],
            ['S', '9']]
the output should be
isCryptSolution(crypt, solution) = true.

When you decrypt "SEND", "MORE", and "MONEY" using the mapping given in crypt, you get 9567 + 1085 = 10652 which is correct and a valid arithmetic equation.

For crypt = ["TEN", "TWO", "ONE"] and

solution = [['O', '1'],
            ['T', '0'],
            ['W', '9'],
            ['E', '5'],
            ['N', '4']]
the output should be
isCryptSolution(crypt, solution) = false.

Even though 054 + 091 = 145, 054 and 091 both contain leading zeroes, meaning that this is not a valid solution.
*/
    //transfer solution into a map instead of arrays
    std::unordered_map<char, int> solution_map{};
    for (auto i : solution)
        solution_map[i[0]] = i[1]; 

    // array with out numbers from crypt
    std::vector<long long> numbers{};
    std::vector<std::string> numbers_string{};

    for (auto i : crypt)
    {
        std::string num{};
        for (auto k : i)
            num += solution_map[k]; 

        numbers_string.push_back(num);
        numbers.push_back(std::stol(num));
    }
    
    //check if amount of digits is same
    //as size of string to make sure
    //it doesn't starts with 0
    for (int i = 0; i < numbers.size(); i++)
    {
        // amount of digits in a number
        int size = ((int)log10(numbers[i]) < 0) ? 1 : (int)log10(numbers[i]) + 1;
  
        if ((numbers_string[i].size() != size) || (numbers[0] + numbers[1] != numbers[2]))
            return false;
    }

    return true;
}
