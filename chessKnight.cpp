int chessKnight(std::string cell) {
/*
Given a position of a knight on the standard chessboard, find the number 
of different moves the knight can perform.

The knight can move to a square that is two squares horizontally and one 
square vertically, or two squares vertically and one square horizontally 
away from it. The complete move therefore looks like the letter L. Check 
out the image below to see all valid moves for a knight piece that is placed 
on one of the central squares.

Example

For cell = "a1", the output should be
chessKnight(cell) = 2.

For cell = "c2", the output should be
chessKnight(cell) = 6.
*/
    // by default we have an 8 options
    int counter{8};

    // creating a map with key-value as x-y position of possible dots
    std::multimap<char, int> m{};
    
    // left part
    m.insert(std::make_pair(cell[0] - 2, (cell[1] - '0') + 1));
    m.insert(std::make_pair(cell[0] - 2, (cell[1] - '0') - 1));
    m.insert(std::make_pair(cell[0] - 1, (cell[1] - '0') + 2));
    m.insert(std::make_pair(cell[0] - 1, (cell[1] - '0') - 2));
    
    // right part
    m.insert(std::make_pair(cell[0] + 1, (cell[1] - '0') + 2));
    m.insert(std::make_pair(cell[0] + 1, (cell[1] - '0') - 2));
    m.insert(std::make_pair(cell[0] + 2, (cell[1] - '0') + 1));
    m.insert(std::make_pair(cell[0] + 2, (cell[1] - '0') - 1));    
    
    //going through and decrement counter for invalid positions
    for (auto i = m.begin() ; i != m.end() ; i++)
        if (((*i).first > 104) || ((*i).first < 97) || ((*i).second > 8) || ((*i).second < 1))
            counter--;
    
    return counter;
}
