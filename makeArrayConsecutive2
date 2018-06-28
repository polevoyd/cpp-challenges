int makeArrayConsecutive2(std::vector<int> statues) {

    
    /* Ratiorg got statues of different sizes as a present 
     * from CodeMaster for his birthday, each statue having 
     * an non-negative integer size. Since he likes to make 
     * things perfect, he wants to arrange them from smallest 
     * to largest so that each statue will be bigger than the 
     * previous one exactly by 1. He may need some additional 
     * statues to be able to accomplish that. Help him figure 
     * out the minimum number of additional statues needed.*/
    
    /* Find max number and min numbers, then return difference between count that should be between them and actual amount of numbers */
    
    int max{0}, min{20};
    for (auto i : statues)
    {
        if (i > max)
            max = i;
        if (i < min)
            min = i;
    } 
   return (max - min - 1) - (statues.size() - 2);
}
