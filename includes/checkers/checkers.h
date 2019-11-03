#pragma once
#include "constants.h"
#include <stack>
#include <vector>

typedef std::stack<std::vector<int>> stack_of_vectors;

void check_correct_letter(char letter);
void check_correct_sym(char symbol);
void check_stack_size(const stack_of_vectors& stack, size_t size, bool equality = 0);