
#include "Image.cpp"
#include "Image_bool.cpp"
#include "Image_char.cpp"

int main() {

	Image<char> first(10, 10, 'a');

	std::cout << "Images Output\n";
	std::cout << first << "\n";
	Image<char> second(10, 10, 'b');
	std::cout << second;

	std::cout << "Adding images\n";
	std::cout << "\n" << first + second << "\n" << first * second << "\n";
	char value = 'c';

	std::cout << "Addition with a variable\n";
	std::cout << "\n" << first + value << "\n" << first * value << "\n" << value + first << "\n" << value * first << "\n";



	//first.creating_rectangle(4, 4, 8, 8);
	//std::cout << first << "\n";

}