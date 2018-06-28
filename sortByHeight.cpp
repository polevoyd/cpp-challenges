std::vector<int> sortByHeight(std::vector<int> a) {

    /* Some people are standing in a row in a park. 
     * There are trees between them which cannot be moved. 
     * Your task is to rearrange the people by their heights 
     * in a non-descending order without moving the trees.

     * Example

     * For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
     * sortByHeight(a) = [-1, 150, 160, 170, -1, -1, 180, 190] */
    
    for (int i = 0 ; i < a.size() ; i++)
         for (int j = i ; j < a.size() ; j++)
              /* If its = -1 - we don't touch it */
              if ( (a[j] < a[i]) && (a[i] != -1) && (a[j] != -1) ) 
              {
                int temp{ a[i] };
                a[i] = a[j];
                a[j] = temp;
              }
    return a;
}
