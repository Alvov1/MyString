#include "pch.h"
#include "CppUnitTest.h"
#include "..\UnitTest\MyString.h"
#include "..\UnitTest\MyString.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
    TEST_CLASS(Testing)
    {
    public:

        TEST_METHOD(Consructor_one_test) {
            MyString test;
            Assert::IsTrue(test.size() == 0);
            Assert::IsTrue(test.capacity() == 0);
            Assert::IsTrue(test.c_str() == nullptr);
        }

        TEST_METHOD(Constructor_two_test1) {
            const char* ptr = "Hello world!";
            MyString test(ptr);
            Assert::IsTrue(test.size() == 12);
            Assert::IsTrue(test.capacity() == 13);
            Assert::IsTrue(strcmp(test.c_str(), "Hello world!") == 0);
        }
        TEST_METHOD(Constructor_two_test2) {
            try {
                const char* ptr = "";
                MyString test(ptr);
            }
            catch (std::invalid_argument& e) {
                Assert::IsTrue(1 == 1);
            }
            catch (...) {
                Assert::IsFalse(1 == 1);
            }
        }

        TEST_METHOD(Constructor_three_test1) {
            MyString test({ 'h', 'e', 'l', 'l', 'o' });

            Assert::IsTrue(test.size() == 5);
            Assert::IsTrue(test.capacity() == 6);
            Assert::IsTrue(strcmp(test.c_str(), "hello") == 0);
        }
        TEST_METHOD(Constructor_three_test2) {
            try {
                MyString test({});
            }
            catch (std::invalid_argument& e) {
                Assert::IsTrue(1 == 1);
            }
            catch (...) {
                Assert::IsFalse(1 == 1);
            }
        }

        TEST_METHOD(Constructor_four_test1) {
            const std::string str("hello");
            MyString test(str);

            Assert::IsTrue(test.size() == 5);
            Assert::IsTrue(test.capacity() == 6);
            Assert::IsTrue(strcmp(test.c_str(), "hello") == 0);
        }
        TEST_METHOD(Constructor_four_test2) {
            try {
                const std::string str;
                MyString test(str);
            }
            catch (std::invalid_argument& e) {
                Assert::IsTrue(1 == 1);
            }
            catch (...) {
                Assert::IsFalse(1 == 1);
            }
        }

        TEST_METHOD(Constructor_five_test1) {
            const char* ptr = "hello";
            MyString test(ptr, 4);

            Assert::IsTrue(test.size() == 4);
            Assert::IsTrue(test.capacity() == 5);
            Assert::IsTrue(strcmp(test.c_str(), "hell") == 0);
        }
        TEST_METHOD(Constructor_five_test2) {
            try {
                const char* ptr = "hello";
                MyString test(ptr, 10);
            }
            catch (std::invalid_argument& e) {
                Assert::IsTrue(1 == 1);
            }
            catch (...) {
                Assert::IsFalse(1 == 1);
            }
        }

        TEST_METHOD(Constructor_six_test1) {
            MyString test(5, '!');

            Assert::IsTrue(test.size() == 5);
            Assert::IsTrue(test.capacity() == 6);
            Assert::IsTrue(strcmp(test.c_str(), "!!!!!") == 0);
        }
        TEST_METHOD(Constructor_six_test2) {
            try {
                MyString test(5, static_cast<char>(0));
            }
            catch (std::invalid_argument& e) {
                Assert::IsTrue(1 == 1);
            }
            catch (...) {
                Assert::IsFalse(1 == 1);
            }
        }

        TEST_METHOD(Constructor_seven_test1) {
            MyString a("hello");
            MyString test(a);

            Assert::IsTrue(test.size() == 5);
            Assert::IsTrue(test.capacity() == 6);
            Assert::IsTrue(strcmp(test.c_str(), "hello") == 0);
        }
        TEST_METHOD(Constructor_seven_test2) {
            try {
                MyString a;
                MyString test(a);
            }
            catch (std::invalid_argument& e) {
                Assert::IsTrue(1 == 1);
            }
            catch (...) {
                Assert::IsFalse(1 == 1);
            }
        }

        TEST_METHOD(Addition_operator_one_test1) {
            MyString left("123");
            MyString right("456");

            auto result = left + right;

            Assert::IsTrue(result.size() == 6);
            Assert::IsTrue(result.capacity() == 7);
            Assert::IsTrue(strcmp(result.c_str(), "123456") == 0);
        }
        TEST_METHOD(Addition_operator_one_test2) {
            MyString left("123");
            MyString right;

            auto result = left + right;

            Assert::IsTrue(result.size() == 3);
            Assert::IsTrue(result.capacity() == 4);
            Assert::IsTrue(strcmp(result.c_str(), "123") == 0);
        }
        TEST_METHOD(Addition_operator_one_test3) {
            MyString left;
            MyString right("456");

            auto result = left + right;

            Assert::IsTrue(result.size() == 3);
            Assert::IsTrue(result.capacity() == 4);
            Assert::IsTrue(strcmp(result.c_str(), "456") == 0);
        }

        TEST_METHOD(Addition_operator_two_test1) {
            MyString left("123");
            const char* right = "456";

            auto result = left + right;
            Assert::IsTrue(result.size() == 6);
            Assert::IsTrue(result.capacity() == 7);
            Assert::IsTrue(strcmp(result.c_str(), "123456") == 0);
        }
        TEST_METHOD(Addition_operator_two_test2) {
            MyString left("123");
            const char* right = nullptr;

            auto result = left + right;
            Assert::IsTrue(result.size() == 3);
            Assert::IsTrue(result.capacity() == 4);
            Assert::IsTrue(strcmp(result.c_str(), "123") == 0);
        }
        TEST_METHOD(Addition_operator_two_test3) {
            MyString left;
            const char* right = "456";

            auto result = left + right;
            Assert::IsTrue(result.size() == 3);
            Assert::IsTrue(result.capacity() == 4);
            Assert::IsTrue(strcmp(result.c_str(), "456") == 0);
        }

        TEST_METHOD(Addition_operator_three_test1) {
            MyString left("123");
            const std::string right("456");

            auto result = left + right;

            Assert::IsTrue(result.size() == 6);
            Assert::IsTrue(result.capacity() == 7);
            Assert::IsTrue(strcmp(result.c_str(), "123456") == 0);
        }
        TEST_METHOD(Addition_operator_three_test2) {
            MyString left;
            const std::string right("456");

            auto result = left + right;

            Assert::IsTrue(result.size() == 3);
            Assert::IsTrue(result.capacity() == 4);
            Assert::IsTrue(strcmp(result.c_str(), "456") == 0);
        }
        TEST_METHOD(Addition_operator_three_test3) {
            MyString left("123");
            const std::string right;

            auto result = left + right;

            Assert::IsTrue(result.size() == 3);
            Assert::IsTrue(result.capacity() == 4);
            Assert::IsTrue(strcmp(result.c_str(), "123") == 0);
        }

        TEST_METHOD(Addition_and_assignment_operator_one_test1) {
            MyString left("123");
            const std::string right("456");

            left += right;

            Assert::IsTrue(left.size() == 6);
            Assert::IsTrue(left.capacity() == 7);
            Assert::IsTrue(strcmp(left.c_str(), "123456") == 0);
        }
        TEST_METHOD(Addition_and_assignment_operator_one_test2) {
            MyString left("123");
            const std::string right;

            left += right;

            Assert::IsTrue(left.size() == 3);
            Assert::IsTrue(left.capacity() == 4);
            Assert::IsTrue(strcmp(left.c_str(), "123") == 0);
        }
        TEST_METHOD(Addition_and_assignment_operator_one_capacity) {
            MyString left("12345");
            left.clear();
            const std::string right("12");;

            left += right;

            Assert::IsTrue(left.size() == 2);
            Assert::IsTrue(left.capacity() == 6);
            Assert::IsTrue(strcmp(left.c_str(), "12") == 0);
        }

        TEST_METHOD(Addition_and_assignment_operator_two_test1) {
            MyString left("123");
            const char* right = "456";

            left += right;
            Assert::IsTrue(left.size() == 6);
            Assert::IsTrue(left.capacity() == 7);
            Assert::IsTrue(strcmp(left.c_str(), "123456") == 0);
        }
        TEST_METHOD(Addition_and_assignment_operator_two_test2) {
            MyString left("123");
            const char* right = nullptr;

            left += right;
            Assert::IsTrue(left.size() == 3);
            Assert::IsTrue(left.capacity() == 4);
            Assert::IsTrue(strcmp(left.c_str(), "123") == 0);
        }
        TEST_METHOD(Addition_and_assignment_operator_two_capacity) {
            MyString left("12345");
            left.clear();
            const char* insert = "12";

            left += insert;
            Assert::IsTrue(left.size() == 2);
            Assert::IsTrue(left.capacity() == 6);
            Assert::IsTrue(strcmp(left.c_str(), "12") == 0);
        }

        TEST_METHOD(Assignment_operator_one_test1) {
            MyString result;
            const char* ptr = "123456";

            result = ptr;

            Assert::IsTrue(result.size() == 6);
            Assert::IsTrue(result.capacity() == 7);
            Assert::IsTrue(strcmp(result.c_str(), "123456") == 0);
        }
        TEST_METHOD(Assignment_operator_one_test2) {
            MyString result;
            const char* ptr = nullptr;

            result = ptr;

            Assert::IsTrue(result.size() == 0);
            Assert::IsTrue(result.capacity() == 0);
            Assert::IsTrue(result.c_str() == nullptr);
        }
        TEST_METHOD(Assignment_operator_one_capacity) {
            MyString result("12345");
            result.clear();
            const char* ptr = "12";

            result = ptr;

            Assert::IsTrue(result.size() == 2);
            Assert::IsTrue(result.capacity() == 6);
            Assert::IsTrue(strcmp(result.c_str(), "12") == 0);
        }

        TEST_METHOD(Assignment_operator_two_test1) {
            MyString result;
            const std::string str("123456");

            result = str;

            Assert::IsTrue(result.size() == 6);
            Assert::IsTrue(result.capacity() == 7);
            Assert::IsTrue(strcmp(result.c_str(), "123456") == 0);
        }
        TEST_METHOD(Assignment_operator_two_test2) {
            MyString result;
            const std::string str;

            result = str;

            Assert::IsTrue(result.size() == 0);
            Assert::IsTrue(result.capacity() == 0);
            Assert::IsTrue(result.c_str() == nullptr);
        }
        TEST_METHOD(Assignment_operator_two_capacity) {
            MyString result("12345");
            result.clear();
            const std::string str("12");

            result = str;

            Assert::IsTrue(result.size() == 2);
            Assert::IsTrue(result.capacity() == 6);
            Assert::IsTrue(strcmp(result.c_str(), "12") == 0);
        }

        TEST_METHOD(Assignment_operator_three_test1) {
            MyString result;
            const char c = '@';

            result = c;

            Assert::IsTrue(result.size() == 1);
            Assert::IsTrue(result.capacity() == 2);
            Assert::IsTrue(strcmp(result.c_str(), "@") == 0);
        }
        TEST_METHOD(Assignment_operator_three_test2) {
            MyString result;
            const char c = static_cast<char>(0);

            result = c;

            Assert::IsTrue(result.size() == 0);
            Assert::IsTrue(result.capacity() == 0);
            Assert::IsTrue(result.c_str() == nullptr);
        }
        TEST_METHOD(Assignment_operator_three_capacity) {
            MyString result("12345");
            result.clear();
            const char c = static_cast<char>('@');

            result = c;

            Assert::IsTrue(result.size() == 1);
            Assert::IsTrue(result.capacity() == 6);
            Assert::IsTrue(strcmp(result.c_str(), "@") == 0);
        }

        TEST_METHOD(Indexing_operator_test1) {
            const std::string comparator("123456");
            MyString test("123456");

            for (auto i = 0; i < 6; ++i)
                Assert::IsTrue(comparator[i] == test[i]);
        }
        TEST_METHOD(Indexing_operator_test2) {
            MyString test;

            try {
                for (auto i = 0; i < 10; ++i)
                    char temp = test[i];
            }
            catch (...) {
                /* If something goes wrong at this point,
                   and program throws any exceptions then test is uncompleted */
                Assert::IsFalse(true);
            }
        }

        TEST_METHOD(More_operator_test1) {
            MyString left(1, '2');
            MyString right(1, '1');

            Assert::IsTrue(left > right);
        }
        TEST_METHOD(More_operator_test2) {
            MyString left(1, '2');
            MyString right;

            /* Empty string is less than non-empty string. */
            Assert::IsTrue(left > right);
        }
        TEST_METHOD(More_operator_test3) {
            MyString left;
            MyString right(1, '1');

            Assert::IsFalse(left > right);
        }

        TEST_METHOD(Less_operator_test1) {
            MyString left(1, '2');
            MyString right(1, '1');

            Assert::IsFalse(left < right);
        }
        TEST_METHOD(Less_operator_test2) {
            MyString left(1, '2');
            MyString right;

            Assert::IsFalse(left < right);
        }
        TEST_METHOD(Less_operator_test3) {
            MyString left;
            MyString right(1, '1');

            Assert::IsTrue(left < right);
        }

        TEST_METHOD(More_or_equall_operator_test1) {
            MyString first(1, '2');
            MyString second(1, '1');
            MyString third(1, '2');

            Assert::IsTrue(first >= second);
            Assert::IsTrue(first >= third);
            Assert::IsFalse(second >= third);
        }
        TEST_METHOD(More_or_equall_operator_test2) {
            MyString first(1, '2');
            MyString second;
            MyString third;

            Assert::IsTrue(first >= second);
            Assert::IsTrue(first >= third);
            Assert::IsTrue(second >= third);
        }

        TEST_METHOD(Less_or_equall_operator_test1) {
            MyString first(1, '2');
            MyString second(1, '1');
            MyString third(1, '2');

            Assert::IsFalse(first <= second);
            Assert::IsTrue(first <= third);
            Assert::IsTrue(second <= third);
        }
        TEST_METHOD(Less_or_equall_operator_test2) {
            MyString first(1, '2');
            MyString second;
            MyString third;

            Assert::IsFalse(first <= second);
            Assert::IsFalse(first <= third);
            Assert::IsTrue(second <= third);
        }

        TEST_METHOD(Not_equall_operator_test1) {
            MyString left(1, '2');
            MyString right(1, '1');

            Assert::IsTrue(left != right);
        }
        TEST_METHOD(Not_equall_operator_test2) {
            MyString left(1, '2');
            MyString right;

            Assert::IsTrue(left != right);
        }
        TEST_METHOD(Not_equall_operator_test3) {
            MyString left;
            MyString right(1, '2');

            Assert::IsTrue(left != right);
        }

        TEST_METHOD(C_str_and_data_methods_test1) {
            MyString first("123456");
            MyString second("123456");

            Assert::IsTrue(first.c_str() != nullptr);
            Assert::IsTrue(first.data() != nullptr);
            Assert::IsTrue(strcmp(first.data(), second.c_str()) == 0);
        }
        TEST_METHOD(C_str_and_data_methods_test2) {
            MyString first;
            MyString second;

            Assert::IsTrue(first.c_str() == nullptr);
            Assert::IsTrue(first.data() == nullptr);
        }

        TEST_METHOD(Len_and_size_methods_test1) {
            MyString first("123456");
            MyString second("123456");

            Assert::IsTrue(first.size() == 6);
            Assert::IsTrue(first.length() == 6);
            Assert::IsTrue(first.size() == second.length());
        }
        TEST_METHOD(Len_and_size_methods_test2) {
            MyString first;
            MyString second;

            Assert::IsTrue(first.size() == 0);
            Assert::IsTrue(first.length() == 0);
            Assert::IsTrue(first.size() == second.length());
        }

        TEST_METHOD(Empty_method_test1) {
            MyString empty;
            MyString not_empty("123456");

            Assert::IsTrue(empty.empty());
            Assert::IsFalse(not_empty.empty());
        }
        TEST_METHOD(Empty_method_test2) {
            MyString empty;

            Assert::IsTrue(empty.empty());

            empty.append(1, '!"');
            Assert::IsFalse(empty.empty());
        }

        TEST_METHOD(Capacity_test1) {
            MyString test("123456");

            Assert::IsTrue(test.capacity() == 7);
        }
        TEST_METHOD(Capacity_test2) {
            MyString test;

            Assert::IsTrue(test.capacity() == 0);
        }

        TEST_METHOD(Clear_method_test1) {
            MyString test("123456");

            Assert::IsTrue(strlen(test.c_str()) == 6);

            test.clear();

            Assert::IsTrue(strlen(test.c_str()) == 0);
            Assert::IsTrue(test.capacity() == 7);
            Assert::IsTrue(test.size() == 0);
        }
        TEST_METHOD(Clear_method_test2) {
            try {
                MyString test;
                test.clear();
            }
            catch (...) {
                Assert::IsTrue(false);
            }
        }

        TEST_METHOD(Shrink_to_fit_method_test1) {
            MyString test("123456");
            test.clear();

            Assert::IsTrue(test.capacity() == 7);
            test.shrink_to_fit();

            Assert::IsTrue(test.capacity() == 1);
        }
        TEST_METHOD(Shrink_to_fit_method_test2) {
            try {
                MyString test("123456");

                Assert::IsTrue(test.capacity() == 7);
                test.shrink_to_fit();

                Assert::IsTrue(test.capacity() == 7);
            }
            catch (...) {
                Assert::IsTrue(false);
            }
        }

        TEST_METHOD(Insert_method_one_test1) {
            MyString test("__");
            test.insert(1, 4, '1');

            Assert::IsTrue(strcmp(test.c_str(), "_1111_") == 0);
        }
        TEST_METHOD(Insert_method_one_test2) {
            try {
                MyString test;
                test.insert(10, 4, '1');
            } /* With wrong start index should be thrown out_of_range exception and nothing more */
            catch (std::out_of_range& e) {
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::IsTrue(false);
            }
        }
        TEST_METHOD(Insert_method_one_capacity) {
            MyString test("12345");
            test.erase(1, 4);
            test.insert(1, 1, '@');

            Assert::IsTrue(test.size() == 2);
            Assert::IsTrue(test.capacity() == 6);
            Assert::IsTrue(strcmp(test.c_str(), "1@") == 0);
        }

        TEST_METHOD(Insert_method_two_test1) {
            MyString test("__");
            const char* insertion = "1111";
            test.insert(1, insertion);

            Assert::IsTrue(strcmp(test.c_str(), "_1111_") == 0);
        }
        TEST_METHOD(Insert_method_two_test2) {
            try {
                MyString test("__");
                const char* insertion = "1111";
                test.insert(10, insertion);

                Assert::IsTrue(strcmp(test.c_str(), "_1111_") == 0);
            }
            catch (std::out_of_range& e) {
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::IsTrue(false);
            }
        }
        TEST_METHOD(Insert_method_two_capacity) {
            MyString test("12345");
            test.erase(1, 4);
            const char* insertion = "@@";
            test.insert(1, insertion);

            Assert::IsTrue(strcmp(test.c_str(), "1@@") == 0);
            Assert::IsTrue(test.size() == 3);
            Assert::IsTrue(test.capacity() == 6);
        }

        TEST_METHOD(Insert_method_three_test1) {
            MyString test("__");
            test.erase(1, 1);
            test.insert(1, "1111nonono", 1);

            Assert::IsTrue(strcmp(test.c_str(), "_1") == 0);
        }
        TEST_METHOD(Insert_method_three_test2) {
            try {
                MyString test("__");
                test.insert(1, "1111nonono", 4);

                Assert::IsTrue(strcmp(test.c_str(), "_1111_") == 0);
            }
            catch (std::out_of_range& e) {
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::IsTrue(false);
            }
        }
        TEST_METHOD(Insert_method_three_capacity) {
            MyString test("12345");
            test.erase(1, 4);
            test.insert(1, "@@nonono", 2);

            Assert::IsTrue(strcmp(test.c_str(), "1@@") == 0);
            Assert::IsTrue(test.size() == 3);
            Assert::IsTrue(test.capacity() == 6);
        }

        TEST_METHOD(Insert_method_four_test1) {
            MyString test("__");
            const std::string insertion("1111");
            test.insert(1, insertion);

            Assert::IsTrue(strcmp(test.c_str(), "_1111_") == 0);
        }
        TEST_METHOD(Insert_method_four_test2) {
            try {
                MyString test("__");
                const std::string insertion("1111");
                test.insert(10, insertion);

                Assert::IsTrue(strcmp(test.c_str(), "_1111_") == 0);
            }
            catch (std::out_of_range& e) {
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::IsTrue(false);
            }

        }
        TEST_METHOD(Insert_method_four_capacity) {
            MyString test("12345");
            test.erase(1, 4);
            const std::string insertion("@@");
            test.insert(1, insertion);

            Assert::IsTrue(strcmp(test.c_str(), "1@@") == 0);
            Assert::IsTrue(test.size() == 3);
            Assert::IsTrue(test.capacity() == 6);
        }

        TEST_METHOD(Insert_method_five_test1) {
            MyString test("__");
            const std::string insertion("1111nonono");
            test.insert(1, insertion, 4);

            Assert::IsTrue(strcmp(test.c_str(), "_1111_") == 0);
        }
        TEST_METHOD(Insert_method_five_test2) {
            try {
                MyString test("__");
                const std::string insertion("1111nonono");
                test.insert(100, insertion, 4);

                Assert::IsTrue(strcmp(test.c_str(), "_1111_") == 0);
            }
            catch (std::out_of_range& e) {
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::IsTrue(false);
            }
        }
        TEST_METHOD(Insert_method_five_capacity) {
            MyString test("12345");
            test.erase(1, 4);
            const std::string insertion("@@nonono");
            test.insert(1, insertion, 2);

            Assert::IsTrue(strcmp(test.c_str(), "1@@") == 0);
            Assert::IsTrue(test.size() == 3);
            Assert::IsTrue(test.capacity() == 6);
        }

        TEST_METHOD(Erase_method_test1) {
            MyString test("Do not erase me - Erase me");
            test.erase(15, 11);
            
            Assert::IsTrue(test.size() == 15);
            Assert::IsTrue(test.capacity() == 27);
            Assert::IsTrue(strcmp(test.c_str(), "Do not erase me") == 0);
        }
        TEST_METHOD(Erase_method_test2) {
            try {
                MyString test("Do not erase me - Erase me");
                test.erase(100, 11);
            }
            catch (std::out_of_range& e) {
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::IsTrue(false);
            }
        }

        TEST_METHOD(Append_method_one_test1) {
            MyString append("Hello, ");

            append.append(4, '@');

            Assert::IsTrue(strcmp(append.c_str(), "Hello, @@@@") == 0);
        }
        TEST_METHOD(Append_method_one_test2) {
            MyString append("Hello, ");

            append.append(4, static_cast<char>(0));

            Assert::IsTrue(strcmp(append.c_str(), "Hello, ") == 0);
        }
        TEST_METHOD(Append_method_one_capacity) {
            MyString append("12345");
            append.erase(1, 4);

            append.append(2, static_cast<char>('@'));

            Assert::IsTrue(append.size() == 3);
            Assert::IsTrue(append.capacity() == 6);
            Assert::IsTrue(strcmp(append.c_str(), "1@@") == 0);
        }

        TEST_METHOD(Append_method_two_test1) {
            MyString append("Hello, ");
            const char* addition = "World!";

            append.append(addition);

            Assert::IsTrue(strcmp(append.c_str(), "Hello, World!") == 0);
        }
        TEST_METHOD(Append_method_two_test2) {
            MyString append("Hello, ");
            const char* addition = nullptr;

            append.append(addition);

            Assert::IsTrue(strcmp(append.c_str(), "Hello, ") == 0);
        }
        TEST_METHOD(Append_method_two_capacity) {
            MyString append("12345");
            append.erase(1, 4);
            const char* addition = "@@";

            append.append(addition);

            Assert::IsTrue(append.size() == 3);
            Assert::IsTrue(append.capacity() == 6);
            Assert::IsTrue(strcmp(append.c_str(), "1@@") == 0);
        }

        TEST_METHOD(Append_method_three_test1) {
            MyString append("Hello, ");
            const char* addition = "World! nonono";

            append.append(addition, 0, 6);

            Assert::IsTrue(strcmp(append.c_str(), "Hello, World!") == 0);
        }
        TEST_METHOD(Append_method_three_test2) {
            MyString append("Hello, ");
            const char* addition = "World!";

            append.append(addition, 0, 100);

            Assert::IsTrue(strcmp(append.c_str(), "Hello, World!") == 0);
        }
        TEST_METHOD(Append_method_three_capacity) {
            MyString append("12345");
            append.erase(1, 4);
            const char* addition = "@@nonono";

            append.append(addition, 0, 2);

            Assert::IsTrue(append.size() == 3);
            Assert::IsTrue(append.capacity() == 6);
            Assert::IsTrue(strcmp(append.c_str(), "1@@") == 0);
        }

        TEST_METHOD(Append_method_four_test1) {
            MyString append("Hello, ");
            const std::string addition("World!");

            append.append(addition);

            Assert::IsTrue(strcmp(append.c_str(), "Hello, World!") == 0);

        }
        TEST_METHOD(Append_method_four_test2) {
            MyString append("Hello, ");
            const std::string addition;

            append.append(addition);

            Assert::IsTrue(strcmp(append.c_str(), "Hello, ") == 0);
        }
        TEST_METHOD(Append_method_four_capacity) {
            MyString append("12345");
            append.erase(1, 4);
            const std::string addition("@@");

            append.append(addition);

            Assert::IsTrue(append.size() == 3);
            Assert::IsTrue(append.capacity() == 6);
            Assert::IsTrue(strcmp(append.c_str(), "1@@") == 0);

        }

        TEST_METHOD(Append_method_five_test1) {
            MyString append("Hello, ");
            const std::string addition("World! nonono");

            append.append(addition, 0, 6);

            Assert::IsTrue(strcmp(append.c_str(), "Hello, World!") == 0);
        }
        TEST_METHOD(Append_method_five_test2) {
            MyString append("Hello, ");
            const std::string addition("World!");

            append.append(addition, 0, 100);

            Assert::IsTrue(strcmp(append.c_str(), "Hello, World!") == 0);
        }
        TEST_METHOD(Append_method_five_capacity) {
            MyString append("12345");
            append.erase(1, 4);
            const std::string addition("@@nonono");

            append.append(addition, 0, 2);

            Assert::IsTrue(append.size() == 3);
            Assert::IsTrue(append.capacity() == 6);
            Assert::IsTrue(strcmp(append.c_str(), "1@@") == 0);
        }

        TEST_METHOD(Replace_method_one_test1) {
            MyString replace("White yellow green");
            const char* replacement = "orange";
            replace.replace(13, 5, replacement);

            Assert::IsTrue(replace.size() == 19);
            Assert::IsTrue(replace.capacity() == 20);
            Assert::IsTrue(strcmp(replace.c_str(), "White yellow orange") == 0);
        }
        TEST_METHOD(Replace_method_one_test2) {
            try {
                MyString replace("White yellow green");
                const char* replacement = "orange";
                replace.replace(100, 5, replacement);

                Assert::IsTrue(strcmp(replace.c_str(), "White yellow orange") == 0);
            }
            catch (std::out_of_range& e) {
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::IsTrue(false);
            }
        }
        TEST_METHOD(Replace_method_one_capacity) {
            MyString test("12345");
            test.erase(2, 3);
            test.replace(0, 2, "!!!!");

            Assert::IsTrue(test.size() == 4);
            Assert::IsTrue(test.capacity() == 6);
            Assert::IsTrue(strcmp(test.c_str(), "!!!!") == 0);
        }

        TEST_METHOD(Replace_method_two_test1) {
            MyString replace("White yellow green");
            const std::string replacement("orange");
            replace.replace(13, 5, replacement);

            Assert::IsTrue(replace.size() == 19);
            Assert::IsTrue(replace.capacity() == 20);
            Assert::IsTrue(strcmp(replace.c_str(), "White yellow orange") == 0);            
        }
        TEST_METHOD(Replace_method_two_test2) {
            try {
                MyString replace("White yellow green");
                const std::string replacement("orange");
                replace.replace(100, 5, replacement);

                Assert::IsTrue(strcmp(replace.c_str(), "White yellow orange") == 0);
            }
            catch (std::out_of_range& e) {
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::IsTrue(false);
            }
        }
        TEST_METHOD(Replace_method_two_capacity) {
            MyString replace("12345");
            replace.erase(2, 3);
            const std::string replacement("!!!!");
            replace.replace(0, 2, replacement);

            Assert::IsTrue(replace.size() == 4);
            Assert::IsTrue(replace.capacity() == 6);
            Assert::IsTrue(strcmp(replace.c_str(), "!!!!") == 0);
        }

        TEST_METHOD(Substr_method_one_test1) {
            MyString test("My name is Sasha");
            MyString substr = test.substr(11);

            Assert::IsTrue(strcmp(substr.c_str(), "Sasha") == 0);
        }
        TEST_METHOD(Substr_method_one_test2) {
            try {
                MyString test("My name is Sasha");
                MyString substr = test.substr(100);

                Assert::IsTrue(strcmp(substr.c_str(), "Sasha") == 0);
            }
            catch (std::out_of_range& e) {
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::IsTrue(false);
            }
        }

        TEST_METHOD(Substr_method_two_test1) {
            MyString test("Bear is an animal");
            MyString substr = test.substr(8, 9);

            Assert::IsTrue(strcmp(substr.c_str(), "an animal") == 0);
        }
        TEST_METHOD(Substr_method_two_test2) {
            try {
                MyString test("Bear is an animal");
                MyString substr = test.substr(100, 9);

                Assert::IsTrue(strcmp(substr.c_str(), "an animal") == 0);
            }
            catch (std::out_of_range& e) {
                Assert::IsTrue(true);
            }
            catch (...) {
                Assert::IsTrue(false);
            }
        }

        TEST_METHOD(Find_method_one_test1) {
            MyString find("Red yellow blue white orange purple green blue");
            auto founded = find.find("blue");

            Assert::IsTrue(founded == 11);
        }
        TEST_METHOD(Find_method_one_test2) {
            MyString find("Red yellow blue white orange purple green blue");
            auto founded = find.find("hello");

            Assert::IsTrue(founded == -1);
        }
        TEST_METHOD(Find_method_one_test3) {
            MyString find("Red yellow blue white orange purple green blue");
            auto founded = find.find(nullptr);

            Assert::IsTrue(founded == -1);
        }

        TEST_METHOD(Find_method_two_test1) {
            MyString find("Red yellow blue white orange purple green blue");
            auto founded = find.find("blue", 12);

            Assert::IsTrue(founded == 42);
        }
        TEST_METHOD(Find_method_two_test2) {
            MyString find("Red yellow blue white orange purple green blue");
            auto founded = find.find("hello", 12);

            Assert::IsTrue(founded == -1);
        }
        TEST_METHOD(Find_method_two_test3) {
            MyString find("Red yellow blue white orange purple green blue");
            int founded = find.find(static_cast<const char*>(nullptr), 12);

            Assert::IsTrue(founded == -1);
        }

        TEST_METHOD(Find_method_three_test1) {
            MyString find("Red yellow blue white orange purple green blue");
            const std::string text("blue");
            auto founded = find.find(text);

            Assert::IsTrue(founded == 11);
        }
        TEST_METHOD(Find_method_three_test2) {
            MyString find("Red yellow blue white orange purple green blue");
            const std::string text("hello");
            auto founded = find.find(text);

            Assert::IsTrue(founded == -1);
        }
        TEST_METHOD(Find_method_three_test3) {
            MyString find("Red yellow blue white orange purple green blue");
            const std::string text;
            int founded = find.find(text);

            Assert::IsTrue(founded == -1);
        }

        TEST_METHOD(Find_method_four_test1) {
            MyString find("Red yellow blue white orange purple green blue");
            const std::string text("blue");
            auto founded = find.find(text, 12);

            Assert::IsTrue(founded == 42);
        }
        TEST_METHOD(Find_method_four_test2) {
            MyString find("Red yellow blue white orange purple green blue");
            const std::string text("hello");
            auto founded = find.find(text, 12);

            Assert::IsTrue(founded == -1);
        }
        TEST_METHOD(Find_method_four_test3) {
            MyString find("Red yellow blue white orange purple green blue");
            const std::string text;
            auto founded = find.find(text, 12);

            Assert::IsTrue(founded == -1);
        }
    };
}
