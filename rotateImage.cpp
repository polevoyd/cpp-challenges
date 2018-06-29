std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
/*
Note: Try to solve this task in-place (with O(1) additional memory), since this is 
what you'll be asked to do during an interview.

You are given an n x n 2D matrix that represents an image. Rotate the image by 90 
degrees (clockwise).

Example

For

a = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
the output should be

rotateImage(a) =
    [[7, 4, 1],
     [8, 5, 2],
     [9, 6, 3]]
*/    
// transpose first (swap rows and columns)
for (int i = 0; i < a.size(); ++i)
    for (int j = 0; j < a.size(); ++j)
        //to make sure we go only through half of matrix
        //otherwise we swap 2 times back and forth
        if (i < j)
            std::swap(a[i][j], a[j][i]);
         
// reverse each row
for (auto &i : a)
    // again, we only need to do swaps on half of matrix
    for (int k = 0; k < a.size()/2; ++k)
        std::swap(i[k], i[a.size()-1-k]);
    
return a;
}
