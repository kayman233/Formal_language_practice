#include <gtest/gtest.h>
#include <checkers.h>
#include <stdexcept>
#include <vector>

TEST(check_fail, test0) {
    ASSERT_THROW(check_correct_letter('1'), std::runtime_error);
}

TEST(check_fail, test1) {
    ASSERT_THROW(check_correct_letter('d'), std::runtime_error);
}

TEST(check_fail, test2) {
    ASSERT_THROW(check_correct_sym('d'), std::runtime_error);
}

TEST(check_fail, test3) {
    ASSERT_NO_THROW(check_correct_sym('1'));
}

TEST(check_fail, test4) {
    stack_of_vectors stack;
    std::vector<int> a(1,0);
    stack.push(a);
    std::vector<int> b(1,1);
    stack.push(b);
    //ASSERT_NO_THROW(check_stack_size(stack, 1, 1));
    ASSERT_THROW(check_stack_size(stack, 1, 1), std::runtime_error);
}

TEST(check_fail, test5) {
    stack_of_vectors stack;
    std::vector<int> a(1,0);
    stack.push(a);
    std::vector<int> b(1,1);
    stack.push(b);
    ASSERT_NO_THROW(check_stack_size(stack, 1));
}

TEST(check_fail, test6) {
    stack_of_vectors stack;
    ASSERT_THROW(check_stack_size(stack, 1), std::runtime_error);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}