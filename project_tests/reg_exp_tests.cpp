#include <gtest/gtest.h>
#include <reg_exp.h>

class TestAnalyser : public ::testing::Test {
protected:
    void SetUp() {
        analyzer = new RegExpAnalyzer("ab+c.*", 'c', 5);
    }
    void TearDown() {
        delete analyzer;
    }
    RegExpAnalyzer* analyzer;
};

TEST_F(TestAnalyser, test1) {
    std::vector<int> new_word(5 + 1, 0);
    analyzer->add_symbol('a', new_word);
    std::vector<int> check_word(5 + 1, 0);
    check_word[0] = 1;
    ASSERT_EQ(new_word, check_word);
}

TEST_F(TestAnalyser, test2) {
    std::vector<int> new_word(5 + 1, 0);
    analyzer->add_symbol('c', new_word);
    std::vector<int> check_word(5 + 1, 0);
    check_word[1] = 1;
    ASSERT_EQ(new_word, check_word);
}

TEST_F(TestAnalyser, test3) {
    analyzer->add_to_stack('a');
    analyzer->add_to_stack('b');
    ASSERT_NO_THROW(analyzer->add_to_stack('+'));
}

TEST_F(TestAnalyser, test4) {
    analyzer->add_to_stack('a');
    ASSERT_THROW(analyzer->add_to_stack('+'), std::runtime_error);
}

TEST_F(TestAnalyser, test5) {
    analyzer->add_to_stack('a');
    ASSERT_THROW(analyzer->add_to_stack('.'), std::runtime_error);
}

TEST_F(TestAnalyser, test6) {
    analyzer->add_to_stack('a');
    ASSERT_NO_THROW(analyzer->add_to_stack('*'));
}

TEST_F(TestAnalyser, test7) {
    std::vector<int> new_word(5 + 1, 0);
    analyzer->add_to_stack('c');
    analyzer->add_to_stack('c');
    analyzer->make_operation('.', new_word);
    std::vector<int> check_word(5 + 1, 0);
    check_word[2] = 1;
    ASSERT_EQ(new_word, check_word);
}

TEST_F(TestAnalyser, test8) {
    std::vector<int> new_word(5 + 1, 0);
    analyzer->add_to_stack('c');
    analyzer->make_operation('*', new_word);
    std::vector<int> check_word(5 + 1, 1);
    ASSERT_EQ(new_word, check_word);
}

TEST_F(TestAnalyser, test9) {
    std::vector<int> new_word(5 + 1, 0);
    analyzer->add_to_stack('c');
    analyzer->add_to_stack('c');
    analyzer->add_to_stack('.');
    analyzer->add_to_stack('c');

    analyzer->make_operation('+', new_word);
    std::vector<int> check_word(5 + 1, 0);
    check_word[1] = 1;
    check_word[2] = 1;
    ASSERT_EQ(new_word, check_word);
}

TEST_F(TestAnalyser, test10) {
    EXPECT_TRUE(analyzer->check_letter_k_times());
}

TEST(TestInput, test1) {
    RegExpAnalyzer* analyzer = new RegExpAnalyzer("ab", 'c', 5);
    ASSERT_THROW(analyzer->check_letter_k_times(), std::runtime_error);
}

TEST(TestInput, test2) {
    RegExpAnalyzer* analyzer = new RegExpAnalyzer("ab+.", 'c', 5);
    ASSERT_THROW(analyzer->check_letter_k_times(), std::runtime_error);
}
TEST(TestInput, test3) {
    RegExpAnalyzer* analyzer = new RegExpAnalyzer("ab+", '2', 5);
    ASSERT_THROW(analyzer->check_letter_k_times(), std::runtime_error);
}

TEST(TestInput, test4) {
    RegExpAnalyzer* analyzer = new RegExpAnalyzer("ad+", 'a', 5);
    ASSERT_THROW(analyzer->check_letter_k_times(), std::runtime_error);
}

TEST(UsualTests, test1) {
    RegExpAnalyzer* analyzer = new RegExpAnalyzer("ab+c.aba.*.bac.+.+*", 'a', 2);
    EXPECT_TRUE(analyzer->check_letter_k_times());
}
TEST(UsualTests, test2) {
    RegExpAnalyzer* analyzer = new RegExpAnalyzer("acb..bab.c.*.ab.ba.+.+*", 'a', 0);
    EXPECT_TRUE(analyzer->check_letter_k_times());
}

TEST(UsualTests, test3) {
    RegExpAnalyzer* analyzer = new RegExpAnalyzer("cc.*c.caacc....*.acc...", 'c', 4);
    EXPECT_FALSE(analyzer->check_letter_k_times());
}