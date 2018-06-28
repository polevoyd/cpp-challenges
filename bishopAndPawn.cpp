bool bishopAndPawn(std::string bishop, std::string pawn) {

    /* Given the positions of a white bishop and a black pawn on 
     * the standard chess board, determine whether the bishop can 
     * capture the pawn in one move.

        The bishop has no restrictions in distance for each move, 
        but is limited to diagonal movement. Check out the example 
        below to see how it can move:

        Example

        For bishop = "a1" and pawn = "c3", the output should be
        bishopAndPawn(bishop, pawn) = true.

        For bishop = "h1" and pawn = "h3", the output should be
        bishopAndPawn(bishop, pawn) = false.
 */
        
        // basically, if a pawn stands at position, which
        // dots have absolute values different from bishops absolute values,
        // then return true; else return false;
        // 
        // 

        // making a board 
        std::vector<char> tmp{'a','b','c','d','e','f','g','h'};
        std::map<char, int> board{};
        for (auto i = tmp.begin() ; i != tmp.end() ; i++)
                board.insert(std::make_pair<char, int>((char)(*i), (int)(i - tmp.begin() + 1)));

        auto x_bb = board.find(bishop[0]);
        int x_b { x_bb->second};
        int y_b = bishop[1] - '0';
        
        auto x_pp = board.find(pawn[0]);
        int x_p { x_pp->second};
        int y_p = pawn[1] - '0';
        
        return (std::abs(x_b - x_p) == std::abs(y_b - y_p)) ? true : false;
        
        // or just 
        // return abs(p[0]-b[0]) == abs(p[1]-b[1]);
}
