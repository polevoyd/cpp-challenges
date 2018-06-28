void print_PI_num()
{
	/* Find PI to the Nth Digit - Enter a number and have the program generate PI up to 
	that many decimal places. Keep a limit to how far the program will go. */

	std::cout << "Enter a number to show PI: ";

	unsigned int nth{};
	std::cin >> nth;
	std::cout << std::endl;
	double PI_to_show = 22.0 / 7.0;

	std::cout << std::fixed << std::setprecision(nth) << PI_to_show;
}
