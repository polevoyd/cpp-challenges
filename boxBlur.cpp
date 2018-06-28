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
