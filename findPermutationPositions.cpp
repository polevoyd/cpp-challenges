std::vector<int> findPermutationPositions(std::string whatToLookFor, std::string whereToLookFor);
std::map<char, int> makePattern(std::string subString);

int main()
{
    std::string a { "baca" };
    std::string b { "abacbcabacbbcacbaccabca" };
    
    std::vector<int> v = findPermutationPositions(a, b);
    
    for (auto i : v)
        std::cout << i << ", ";

  return 0;
}

std::vector<int> findPermutationPositions(std::string whatToLookFor, std::string whereToLookFor)
{
    /* find all possible permutations of whatToLookFor in whereToLookFor */
    std::vector<int> v{};
    
    for (int i = 0 ; i < (int)whereToLookFor.size() - (int)whatToLookFor.size() + 1 ; i++)
    {
        std::string temp = whereToLookFor.substr(i, whatToLookFor.size());
        std::map<char, int> temp2 = makePattern(whatToLookFor);
        
        if (temp2 == makePattern(temp))
            v.push_back(i);
    }
    return v;
}

std::map<char, int> makePattern(std::string subString)
{
    std::map<char, int> m{};
    
    for (auto i : subString)
    {
        auto search = m.find(i);
        if (search == m.end())
            m.insert(std::make_pair(i, 1));
        else
            m[i]++;
    }
    return m;
}
