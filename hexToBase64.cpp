std::string hexToBase64(std::string str)
{
	/////////////////////////////////////////////////
	/* Function that encode a Hex string to Base64 */
	/////////////////////////////////////////////////
	
	// 1. Converting hexadecimal string to numerical binary
	std::string s{};
	for (char i : str)
	{
		switch (i)
		{
		case '0': s.append("0000"); break;
		case '1': s.append("0001"); break;
		case '2': s.append("0010"); break;
		case '3': s.append("0011"); break;
		case '4': s.append("0100"); break;
		case '5': s.append("0101"); break;
		case '6': s.append("0110"); break;
		case '7': s.append("0111"); break;
		case '8': s.append("1000"); break;
		case '9': s.append("1001"); break;
		case 'a': s.append("1010"); break;
		case 'b': s.append("1011"); break;
		case 'c': s.append("1100"); break;
		case 'd': s.append("1101"); break;
		case 'e': s.append("1110"); break;
		case 'f': s.append("1111"); break;
		default: break;
		}
	}

	// 2. Pad at the end as necessary with zeros (to divide by 6)
	while (s.size() % 6 != 0)
		s += '0';

	// 3. Divide binary string into words of 6 bits
	std::vector<std::string> vs{};
	for (int i = 0; i < s.size(); i += 6)
	{
		std::string temp(s, i, 6);
		vs.push_back(temp);
	}

	// 4. Convert 6 - bit words to decimal then decimal to ASCII
	std::vector<int> vi{};
	for (std::string &i : vs)
	{
		std::bitset<6> tmp{ i };
		vi.push_back(tmp.to_ulong());
	}

	const std::vector<char> base64_c{
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V',
		'W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','0','p','q','r',
		's','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/' };

	std::string rt{};

	for (int &i : vi)
		rt += base64_c[i];

	// 5. Pad the string with "=" as necessary
	while (rt.size() % 4 != 0)
		rt += '=';

	return rt;
}
