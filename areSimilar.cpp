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
