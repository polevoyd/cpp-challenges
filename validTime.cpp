bool validTime(std::string time) {
/*
Check if the given string is a correct time representation of the 24-hour clock.

Example

For time = "13:58", the output should be
validTime(time) = true;
For time = "25:51", the output should be
validTime(time) = false;
For time = "02:76", the output should be
validTime(time) = false.
*/
   return (time[2] == ':' && 
           std::isdigit(time[0]) && 
           std::isdigit(time[1]) && 
           std::isdigit(time[3]) && 
           std::isdigit(time[4]) && 
           
           std::stoi(time.substr(0, 2)) < 24 &&
           std::stoi(time.substr(3, 2)) < 60
          ) ? true : false; 
}
