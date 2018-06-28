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
