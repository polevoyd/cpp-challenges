std::vector<std::string> addBorder(std::vector<std::string> picture) {
/* Given a rectangular matrix of characters, 
 * add a border of asterisks(*) to it.
 * Example
 * For
 * picture = ["abc",
              "ded"]
 * the output should be
 * addBorder(picture) = ["*****",
                         "*abc*",
                         "*ded*",
                         "*****"] 
 */

 picture.insert(picture.begin(), std::string(picture[0].size(), '*'));
 picture.push_back(std::string(picture[0].size(), '*'));

 for (auto &i : picture)
    i = "*" + i + "*";

 return picture;
}
