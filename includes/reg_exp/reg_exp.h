#pragma once
#include <stack>
#include <vector>
#include <string>
#include "checkers.h"

class RegExpAnalyzer {
public:
	RegExpAnalyzer(const std::string& reg_exp, char letter, unsigned int k) :
		reg_exp(reg_exp), letter(letter), k(k), count_stack() {}

	bool check_letter_k_times();

	void add_to_stack(char current_symbol);
	void add_symbol(char current_symbol, std::vector<int>& new_word);
	void make_operation(char operation, std::vector<int>& new_word);
private:
	char letter;
	unsigned int k;
	std::string reg_exp;

	stack_of_vectors count_stack;
};
