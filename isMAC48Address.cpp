bool isMAC48Address(std::string inputString) {
/*
A media access control address (MAC address) is a unique identifier 
assigned to network interfaces for communications on the physical 
network segment.

The standard (IEEE 802) format for printing MAC-48 addresses in 
human-friendly form is six groups of two hexadecimal digits (0 to 9 or A to F), 
separated by hyphens (e.g. 01-23-45-67-89-AB).

Your task is to check by given string inputString whether it corresponds 
to MAC-48 address or not.

Example

For inputString = "00-1B-63-84-45-E6", the output should be
isMAC48Address(inputString) = true;
For inputString = "Z1-1B-63-84-45-E6", the output should be
isMAC48Address(inputString) = false;
For inputString = "not a MAC-48 address", the output should be
isMAC48Address(inputString) = false.
*/

std::set<int> allowed{'A', 'B', 'C', 'D', 'E', 'F', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-'};
           
for (int i = 0 ; i < inputString.size() ; i++)
{
        auto search = allowed.find(inputString[i]);
        
        if (search == allowed.end())
                return false;
        else if (((i == 2)||(i == 5)||(i == 8)||(i == 11)||(i == 14)) && (inputString[i] != '-'))
                return false;
        else if (inputString.size() != 17)
                return false;
        else if (((i != 2)&&(i != 5)&&(i != 8)&&(i != 11)&&(i != 14)) && (inputString[i] == '-'))
                return false;
}
return true;
 
/* regex solution    
regex r("[0-9a-fA-F]{2}(-[0-9a-fA-F]{2}){5}");
return regex_match(inputString,r);
*/   
}
