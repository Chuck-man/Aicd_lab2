#include "Image.cpp"
#include "Image_bool.cpp"
#include "Image_char.cpp"

int main() {

	bool exit1 = false;

	while (!exit1) {
		bool exit = false;
		int sw1;
		std::cout << "Choose:\n1. Bool\n2. Short\n3. Float\n4. Char\n5. Exit\n";
		std::cin >> sw1;
		switch (sw1) {
		case(1):
		{
			while (!exit) {
				bool mean = 0;
				int length = 0, width = 0;
				int sw;
				std::cout << "\nChoose:\n1. Create the Image\n2. Operations with Images\n3. Operations with Image and value\n4. Image inversion\n5. Calculate the occupancy rate\n6. Draw rectangle\n7. Reading/writing an element\n8. Exit\n";
				std::cin >> sw;
				switch (sw) {
				case(1):
				{
					std::cout << "Create the Image\n\n" << "Enter the length and width of the Images: ";
					std::cin >> length;
					std::cin >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean;
					try {
						Image<bool> picture(length, width, mean);
						std::cout << picture << "\n\n";
					}
					catch (std::logic_error& err) {
						std::cerr << err.what() << std::endl;
					}
					break;
				}
				case(2):
				{
					bool exit2 = false;
					bool mean2, mean1;
					std::cout << "Enter the length and width of the Images: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the first Image: ";
					std::cin >> mean1;
					std::cout << "Enter the value for the second Image: ";
					std::cin >> mean2;
					Image<bool> picture1(length, width, mean1);
					Image<bool> picture2(length, width, mean2);
					while (!exit2) {
						int sw2;
						std::cout << "Choose:\n1. Adding pictures \n2. Multiplication of Images \n3. Exit\n\n";
						std::cin >> sw2;

						switch (sw2) {
						case(1):
						{
							std::cout << picture1 << "\n\n" << picture2 << "\n\n";
							std::cout << picture1 + picture2;
							break;
						}
						case(2):
						{
							std::cout << picture1 << "\n\n" << picture2 << "\n\n";
							std::cout << picture1 * picture2;
							break;
						}
						case(3):
						{
							exit2 = true;
							break;
						}
						}
					}
					break;
				}
				case(3):
				{
					bool value;
					std::cout << "The meaning of the variable (0 or 1): ";
					std::cin >> value;
					bool exit3 = false;
					if (value == 0) value = false;
					else value = true;
					bool mean3;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean3;
					Image<bool> picture3(length, width, mean3);
					while (!exit3) {
						int sw3;
						std::cout << "Choose:\n1. Adding a picture and a variable \n2. Multiplication a picture and a variable \n3. Adding a variable and a picture \n4. Multiplication a variable and a picture \n5. Exit\n\n";
						std::cin >> sw3;
						switch (sw3) {
						case(1):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << picture3 + value;
							break;
						}
						case(2):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << picture3 * value;
							break;
						}
						case(3):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << value + picture3;
							break;
						}
						case(4):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << value * picture3;
							break;
						}
						case(5):
						{
							exit3 = true;
							break;
						}
						}
					}
					break;
				}
				case(4):
				{
					bool mean0;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean0;
					Image<bool> picture0(length, width, mean0);
					std::cout << "Original\n" << picture0 << "\nInversion\n" << !picture0;
					break;
				}
				case(5):
				{
					bool mean0 = 0;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					Image<bool> picture0(length, width, mean0);
					int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
					std::cout << "Enter the upper left and lower right coordinates of the rectangle: ";
					std::cin >> x1 >> y1 >> x2 >> y2;
					picture0.creating_rectangle(x1, y1, x2, y2);
					double ratio = 0;
					ratio = fullness(picture0);
					std::cout << "Occupancy rate  = " << ratio << "\n" << picture0;
					break;
				}
				case(6):
				{
					bool mean0 = 0;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					Image<bool> picture0(length, width, mean0);
					int x1, y1, x2, y2;
					std::cout << "Enter the coordinates of the upper left and lower right vertices of the rectangle: \n";
					std::cin >> x1 >> y1 >> x2 >> y2;
					try {
						picture0.creating_rectangle(x1, y1, x2, y2);
						std::cout << picture0;
					}
					catch (std::logic_error& err) {
						std::cerr << err.what() << std::endl;
					}
					break;
				}
				case(7):
				{
					bool value, element;
					int x = 0, y = 0;
					std::cout << "Enter the length and width of the Images: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean;
					Image<bool> picture(length, width, mean);
					std::cout << picture << "\n\n";
					std::cout << "Enter the coordinates of the cell: ";
					std::cin >> x >> y;
					try {
						element = picture(x, y);
						std::cout << element << "\n\n";
						std::cout << "Enter the value to the cell: ";
						std::cin >> value;
						picture(x, y) = value;
						std::cout << picture(x, y) << "\n\n";
						std::cout << picture << "\n\n";
					}
					catch (std::logic_error& err) {
						std::cerr << err.what() << std::endl;
					}
					break;
				}
				case(8):
				{
					exit = true;
					break;
				}
				}
			}
		}
		case(2):
		{
			while (!exit) {
				short mean = 0;
				int length = 0, width = 0;
				int sw;
				std::cout << "\nChoose:\n1. Create the Image\n2. Operations with Images\n3. Operations with Image and value\n4. Image inversion\n5. Calculate the occupancy rate\n6. Draw rectangle\n7. Reading/writing an element\n8. Exit\n";
				std::cin >> sw;
				switch (sw) {
				case(1):
				{
					std::cout << "Create the Image<bool>\n\n" << "Enter the length and width of the Images: ";
					std::cin >> length;
					std::cin >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean;
					try {
						Image<short> picture(length, width, mean);
						std::cout << picture << "\n\n";
					}
					catch (std::logic_error& err) {
						std::cerr << err.what() << std::endl;
					}
					break;
				}
				case(2):
				{
					bool exit2 = false;
					short mean2, mean1;
					std::cout << "Enter the length and width of the Images: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the first Image: ";
					std::cin >> mean1;
					std::cout << "Enter the value for the second Image: ";
					std::cin >> mean2;
					Image<short> picture1(length, width, mean1);
					Image<short> picture2(length, width, mean2);
					while (!exit2) {
						int sw2;
						std::cout << "Choose:\n1. Adding pictures \n2. Multiplication of Images \n3. Exit\n\n";
						std::cin >> sw2;

						switch (sw2) {
						case(1):
						{
							std::cout << picture1 << "\n\n" << picture2 << "\n\n";
							std::cout << picture1 + picture2;
							break;
						}
						case(2):
						{
							std::cout << picture1 << "\n\n" << picture2 << "\n\n";
							std::cout << picture1 * picture2;
							break;
						}
						case(3):
						{
							exit2 = true;
							break;
						}
						}
					}
					break;
				}
				case(3):
				{
					short value;
					std::cout << "The meaning of the variable (0 or 1): ";
					std::cin >> value;
					bool exit3 = false;
					short mean3;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean3;
					Image<short> picture3(length, width, mean3);
					while (!exit3) {
						int sw3;
						std::cout << "Choose:\n1. Adding a picture and a variable \n2. Multiplication a picture and a variable \n3. Adding a variable and a picture \n4. Multiplication a variable and a picture \n5. Exit\n\n";
						std::cin >> sw3;
						switch (sw3) {
						case(1):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << picture3 + value;
							break;
						}
						case(2):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << picture3 * value;
							break;
						}
						case(3):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << value + picture3;
							break;
						}
						case(4):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << value * picture3;
							break;
						}
						case(5):
						{
							exit3 = true;
							break;
						}
						}
					}
					break;
				}
				case(4):
				{
					short mean0;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean0;
					Image<short> picture0(length, width, mean0);
					std::cout << "Original\n" << picture0 << "\nInversion\n" << !picture0;
					break;
				}
				case(5):
				{
					short mean0 = 0;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					Image<short> picture0(length, width, mean0);
					int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
					std::cout << "Enter the upper left and lower right coordinates of the rectangle: ";
					std::cin >> x1 >> y1 >> x2 >> y2;
					picture0.creating_rectangle(x1, y1, x2, y2);
					double ratio = 0;
					ratio = fullness(picture0);
					std::cout << "Occupancy rate  = " << ratio << "\n" << picture0;
					break;
				}
				case(6):
				{
					short mean0 = 0;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					Image<short> picture0(length, width, mean0);
					int x1, y1, x2, y2;
					std::cout << "Enter the coordinates of the upper left and lower right vertices of the rectangle: \n";
					std::cin >> x1 >> y1 >> x2 >> y2;
					try {
						picture0.creating_rectangle(x1, y1, x2, y2);
						std::cout << picture0;
					}
					catch (std::logic_error& err) {
						std::cerr << err.what() << std::endl;
					}
					break;
				}
				case(7):
				{
					short value, element;
					int x = 0, y = 0;
					std::cout << "Enter the length and width of the Images: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean;
					Image<short> picture(length, width, mean);
					std::cout << picture << "\n\n";
					std::cout << "Enter the coordinates of the cell: ";
					std::cin >> x >> y;
					try {
						element = picture(x, y);
						std::cout << element << "\n\n";
						std::cout << "Enter the value to the cell: ";
						std::cin >> value;
						picture(x, y) = value;
						std::cout << picture(x, y) << "\n\n";
						std::cout << picture << "\n\n";
					}
					catch (std::logic_error& err) {
						std::cerr << err.what() << std::endl;
					}
					break;
				}
				case(8):
				{
					exit = true;
					break;
				}
				}
			}
		}
		case(3):
		{
			while (!exit) {
				float mean = 0;
				int length = 0, width = 0;
				int sw;
				std::cout << "\nChoose:\n1. Create the Image\n2. Operations with Images\n3. Operations with Image and value\n4. Image inversion\n5. Calculate the occupancy rate\n6. Draw rectangle\n7. Reading/writing an element\n8. Exit\n";
				std::cin >> sw;
				switch (sw) {
				case(1):
				{
					std::cout << "Create the Image<bool>\n\n" << "Enter the length and width of the Images: ";
					std::cin >> length;
					std::cin >> width;
					std::cout << "Enter the value for the Image<bool>: ";
					std::cin >> mean;
					try {
						Image<float> picture(length, width, mean);
						std::cout << picture << "\n\n";
					}
					catch (std::logic_error& err) {
						std::cerr << err.what() << std::endl;
					}
					break;
				}
				case(2):
				{
					bool exit2 = false;
					float mean2, mean1;
					std::cout << "Enter the length and width of the Images: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the first Image: ";
					std::cin >> mean1;
					std::cout << "Enter the value for the second Image: ";
					std::cin >> mean2;
					Image<float> picture1(length, width, mean1);
					Image<float> picture2(length, width, mean2);
					while (!exit2) {
						int sw2;
						std::cout << "Choose:\n1. Adding pictures \n2. Multiplication of Image<bool>s \n3. Exit\n\n";
						std::cin >> sw2;

						switch (sw2) {
						case(1):
						{
							std::cout << picture1 << "\n\n" << picture2 << "\n\n";
							std::cout << picture1 + picture2;
							break;
						}
						case(2):
						{
							std::cout << picture1 << "\n\n" << picture2 << "\n\n";
							std::cout << picture1 * picture2;
							break;
						}
						case(3):
						{
							exit2 = true;
							break;
						}
						}
					}
					break;
				}
				case(3):
				{
					float value;
					std::cout << "The meaning of the variable (0 or 1): ";
					std::cin >> value;
					bool exit3 = false;
					float mean3;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean3;
					Image<float> picture3(length, width, mean3);
					while (!exit3) {
						int sw3;
						std::cout << "Choose:\n1. Adding a picture and a variable \n2. Multiplication a picture and a variable \n3. Adding a variable and a picture \n4. Multiplication a variable and a picture \n5. Exit\n\n";
						std::cin >> sw3;
						switch (sw3) {
						case(1):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << picture3 + value;
							break;
						}
						case(2):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << picture3 * value;
							break;
						}
						case(3):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << value + picture3;
							break;
						}
						case(4):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << value * picture3;
							break;
						}
						case(5):
						{
							exit3 = true;
							break;
						}
						}
					}
					break;
				}
				case(4):
				{
					float mean0;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean0;
					Image<float> picture0(length, width, mean0);
					std::cout << "Original\n" << picture0 << "\nInversion\n" << !picture0;
					break;
				}
				case(5):
				{
					float mean0 = 0;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					Image<float> picture0(length, width, mean0);
					int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
					std::cout << "Enter the upper left and lower right coordinates of the rectangle: ";
					std::cin >> x1 >> y1 >> x2 >> y2;
					picture0.creating_rectangle(x1, y1, x2, y2);
					double ratio = 0;
					ratio = fullness(picture0);
					std::cout << "Occupancy rate  = " << ratio << "\n" << picture0;
					break;
				}
				case(6):
				{
					float mean0 = 0;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					Image<float> picture0(length, width, mean0);
					int x1, y1, x2, y2;
					std::cout << "Enter the coordinates of the upper left and lower right vertices of the rectangle: \n";
					std::cin >> x1 >> y1 >> x2 >> y2;
					try {
						picture0.creating_rectangle(x1, y1, x2, y2);
						std::cout << picture0;
					}
					catch (std::logic_error& err) {
						std::cerr << err.what() << std::endl;
					}
					break;
				}
				case(7):
				{
					float value, element;
					int x = 0, y = 0;
					std::cout << "Enter the length and width of the Images: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean;
					Image<float> picture(length, width, mean);
					std::cout << picture << "\n\n";
					std::cout << "Enter the coordinates of the cell: ";
					std::cin >> x >> y;
					try {
						element = picture(x, y);
						std::cout << element << "\n\n";
						std::cout << "Enter the value to the cell: ";
						std::cin >> value;
						picture(x, y) = value;
						std::cout << picture(x, y) << "\n\n";
						std::cout << picture << "\n\n";
					}
					catch (std::logic_error& err) {
						std::cerr << err.what() << std::endl;
					}
					break;
				}
				case(8):
				{
					exit = true;
					break;
				}
				}
			}
		}
		case(4):
		{
			while (!exit) {
				char mean = 0;
				int length = 0, width = 0;
				int sw;
				std::cout << "\nChoose:\n1. Create the Image\n2. Operations with Images\n3. Operations with Image and value\n4. Image inversion\n5. Calculate the occupancy rate\n6. Draw rectangle\n7. Reading/writing an element\n8. Exit\n";
				std::cin >> sw;
				switch (sw) {
				case(1):
				{
					std::cout << "Create the Image\n\n" << "Enter the length and width of the Images: ";
					std::cin >> length;
					std::cin >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean;
					try {
						Image<char> picture(length, width, mean);
						std::cout << picture << "\n\n";
					}
					catch (std::logic_error& err) {
						std::cerr << err.what() << std::endl;
					}
					break;
				}
				case(2):
				{
					bool exit2 = false;
					char mean2, mean1;
					std::cout << "Enter the length and width of the Images: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the first Image: ";
					std::cin >> mean1;
					std::cout << "Enter the value for the second Image: ";
					std::cin >> mean2;
					Image<char> picture1(length, width, mean1);
					Image<char> picture2(length, width, mean2);
					while (!exit2) {
						int sw2;
						std::cout << "Choose:\n1. Adding pictures \n2. Multiplication of Images \n3. Exit\n\n";
						std::cin >> sw2;

						switch (sw2) {
						case(1):
						{
							std::cout << picture1 << "\n\n" << picture2 << "\n\n";
							std::cout << picture1 + picture2;
							break;
						}
						case(2):
						{
							std::cout << picture1 << "\n\n" << picture2 << "\n\n";
							std::cout << picture1 * picture2;
							break;
						}
						case(3):
						{
							exit2 = true;
							break;
						}
						}
					}
					break;
				}
				case(3):
				{
					char value;
					std::cout << "The meaning of the variable (0 or 1): ";
					std::cin >> value;
					bool exit3 = false;
					char mean3;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean3;
					Image<char> picture3(length, width, mean3);
					while (!exit3) {
						int sw3;
						std::cout << "Choose:\n1. Adding a picture and a variable \n2. Multiplication a picture and a variable \n3. Adding a variable and a picture \n4. Multiplication a variable and a picture \n5. Exit\n\n";
						std::cin >> sw3;
						switch (sw3) {
						case(1):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << picture3 + value;
							break;
						}
						case(2):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << picture3 * value;
							break;
						}
						case(3):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << value + picture3;
							break;
						}
						case(4):
						{
							std::cout << "value = " << value << "\n" << picture3 << "\n\n";
							std::cout << value * picture3;
							break;
						}
						case(5):
						{
							exit3 = true;
							break;
						}
						}
					}
					break;
				}
				case(4):
				{
					char mean0;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean0;
					Image<char> picture0(length, width, mean0);
					std::cout << "Original\n" << picture0 << "\nInversion\n" << !picture0;
					break;
				}
				case(5):
				{
					char mean0 = 0;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					Image<char> picture0(length, width, mean0);
					int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
					std::cout << "Enter the upper left and lower right coordinates of the rectangle: ";
					std::cin >> x1 >> y1 >> x2 >> y2;
					picture0.creating_rectangle(x1, y1, x2, y2);
					double ratio = 0;
					ratio = fullness(picture0);
					std::cout << "Occupancy rate  = " << ratio << "\n" << picture0;
					break;
				}
				case(6):
				{
					char mean0 = 0;
					std::cout << "Enter the length and width of the Image: ";
					std::cin >> length >> width;
					Image<char> picture0(length, width, mean0);
					int x1, y1, x2, y2;
					std::cout << "Enter the coordinates of the upper left and lower right vertices of the rectangle: \n";
					std::cin >> x1 >> y1 >> x2 >> y2;
					try {
						picture0.creating_rectangle(x1, y1, x2, y2);
						std::cout << picture0;
					}
					catch (std::logic_error& err) {
						std::cerr << err.what() << std::endl;
					}
					break;
				}
				case(7):
				{
					char value, element;
					int x = 0, y = 0;
					std::cout << "Enter the length and width of the Images: ";
					std::cin >> length >> width;
					std::cout << "Enter the value for the Image: ";
					std::cin >> mean;
					Image<char> picture(length, width, mean);
					std::cout << picture << "\n\n";
					std::cout << "Enter the coordinates of the cell: ";
					std::cin >> x >> y;
					try {
						element = picture(x, y);
						std::cout << element << "\n\n";
						std::cout << "Enter the value to the cell: ";
						std::cin >> value;
						picture(x, y) = value;
						std::cout << picture(x, y) << "\n\n";
						std::cout << picture << "\n\n";
					}
					catch (std::logic_error& err) {
						std::cerr << err.what() << std::endl;
					}
					break;
				}
				case(8):
				{
					exit = true;
					break;
				}
				}
			}
		}
		case(5):
		{
			exit1 = true;
			break;
		}
		}
		
	}

	return 0;
}