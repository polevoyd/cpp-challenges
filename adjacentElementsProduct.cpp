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
