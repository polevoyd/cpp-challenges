/* URLify: Write a method to replace all spaces in a string with '%20: You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. (Note: If implementing in Java, please use a character array so that you can
perform this operation in place.)

EXAMPLE
Input: "Mr John Smith "J 13
Output: "Mr%20J ohn%20Smith"
*/

///////////////////////////////////////////////////////////////
// TIME: N LINEAR (N- size of string)
// SPACE: N LINEAR (cause we will create another array same size)
// creating empty string and adding elements one by one to it
// from initial string. If meet ' ' then adding '%20' instead
std::string urlify(std::string s){
    
    std::string rt{ };
 
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            rt += s[i];
        }
        else
        {
            rt += "%20";
        } 
    }
    return rt;
}
///////////////////////////////////////////////////////////////
