bool chessBoardCellColor(std::string cell1, std::string cell2) {

    /* Given two cells on the standard chess board, determine 
     * whether they have the same color or not.

    Example

    For cell1 = "A1" and cell2 = "C3", the output should be
    chessBoardCellColor(cell1, cell2) = true.

    For cell1 = "A1" and cell2 = "H3", the output should be
    chessBoardCellColor(cell1, cell2) = false. */
    
    std::string board{"aABCDEFGH"};

    bool first{ false }, second{ false };
    
    for (int i = 1 ; i < board.size() ; ++i)
    {
        if (board[i] == cell1[0])
            if ((i + (cell1[1] - '0')) % 2 == 0)
                first = true;
        
        if (board[i] == cell2[0])
            if ((i + (cell2[1] - '0')) % 2 == 0)
                second = true;
    }
    
    return (first == second) ? true : false;
}
/*
return (a[0] + a[1]) % 2 == (b[0] + b[1]) % 2;
*/
