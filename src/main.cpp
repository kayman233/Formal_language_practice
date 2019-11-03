#include <iostream>
#include <string>
#include "reg_exp.h"

int main() {
	std::string reg_exp;
	char letter;
	unsigned int k;
	std::cin >> reg_exp >> letter >> k;

	RegExpAnalyzer* analyzer = new RegExpAnalyzer(reg_exp, letter, k);

	try {
		if (analyzer->check_letter_k_times()) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	} catch (const std::runtime_error& error) {
		std::cout << "ERROR" << std::endl;
	}

	return 0;
}