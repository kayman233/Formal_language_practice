#include <iostream>
#include "reg_exp.h"

bool RegExpAnalyzer::check_letter_k_times() {

	check_correct_letter(letter);

	for (char current_symbol : reg_exp) {
	    check_correct_sym(current_symbol);

		add_to_stack(current_symbol);
	}

	check_stack_size(count_stack, 1, true);

	std::vector<int> last = count_stack.top();
    return last[k] != 0;
}

void RegExpAnalyzer::add_to_stack(char current_symbol) {
	std::vector<int> new_word(k + 1, 0);

	if (alphabet.find(current_symbol) != alphabet.end()) {
		add_symbol(current_symbol, new_word);
	} else {
		make_operation(current_symbol, new_word);
	}

	count_stack.push(new_word);
}

void RegExpAnalyzer::add_symbol(char current_symbol, std::vector<int>& new_word) {
	if (current_symbol == letter) {
		if (k > 0) {
			new_word[1] = 1;
		}
	} else {
		new_word[0] = 1;
	}
}
void RegExpAnalyzer::make_operation(char operation, std::vector<int>& new_word) {
	if (operation == '*') {
		check_stack_size(count_stack, 1);
		std::vector<int> last = count_stack.top();
		count_stack.pop();
		new_word[0] = 1;
		for (unsigned int j = 1; j < k + 1; ++j) {
			if (last[j]) {
                unsigned int step = j;
                unsigned int index = j;
				while (index < k + 1) {
					new_word[index] = 1;
					index += step;
				}
			}
		}
	} else {
		check_stack_size(count_stack, 2);

		std::vector<int> last = count_stack.top();
		count_stack.pop();
		std::vector<int> second_to_last = count_stack.top();
		count_stack.pop();

		if (operation == '.') {
			for (unsigned int j = 0; j < k + 1; ++j) {
				for (unsigned int t = 0; t < k + 1; ++t) {
					if ((j + t < k + 1) && (last[j] && second_to_last[t])) {
						new_word[j + t] = 1;
					}
				}
			}
		} else { // operation == '+'
			for (unsigned int j = 0; j < k + 1; ++j) {
				new_word[j] = (last[j] + second_to_last[j]) ? 1 : 0;
			}
		}
	}
}