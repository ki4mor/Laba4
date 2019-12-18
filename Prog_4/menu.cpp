#include <stdio.h>
#include "Landscape.h"
#include "menu.h"
namespace menu {
	char dialog() {
		std::cout << "g - move" << std::endl;
		std::cout << "2 - Add element" << std::endl;
		std::cout << "3 - Merge alphabets" << std::endl;
		std::cout << "4 - String encoding" << std::endl;
		std::cout << "5 - String decoding" << std::endl;
		std::cout << "6 - Character search in the alphabet" << std::endl;
		std::cout << "7 - Input new alphabet" << std::endl;
		std::cout << "0 - Exit" << std::endl;
		char d = 0;
		get_char(d);
		return d;
	}

	int menu_t(char d, laba4::Landscape& L) {



		switch (d) {
		
			default: {
			std::cout << std::endl;
			std::cout << "Incorrect Data!" << std::endl << std::endl;

			}
		}
		return 0;
	}

	int get_char(char& str) {

		int r = 0;
		do {
			std::cin >> str;
			if (std::cin.eof()) {
				std::cin.clear();
				return -1;
			}
			if (!std::cin.good()) {
				std::cin.clear();
				while (std::cin.get() != '\n');
				r++;
			}
			else r = 0;
		} while (r);
		return r;
	}
}