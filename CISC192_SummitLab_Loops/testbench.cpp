//
// Don't modify code in this file, with the exception
// of adding test cases.
//
#include <iostream>
#include <sstream>
#include "student_code.h"

using namespace std;

#define TEST_FUNC_PTR void (*test_func)(stringstream&, stringstream&)
void test(TEST_FUNC_PTR, const string& input, const string& expected)
{
    stringstream in_stream(input);
    stringstream out_stream;
    test_func(in_stream, out_stream);

    if (expected == out_stream.str())
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "With input \"" << input << "\" expected output \"" << expected
            << "\", received \"" << out_stream.str() << "\"" << endl;
    }
}

int main()
{
    // username_list tests
    test(username_list,
        "john_smith anna22 coolcoder STOP",
        "john_smith;anna22;coolcoder;");

    test(username_list,
        "admin STOP",
        "admin;");


    // grocery_total tests
    test(grocery_total,
        "5.50 3.25 25 12 0",
        "Expensive item!\nTotal grocery cost $45.75");

    test(grocery_total,
        "4 6 8 2 0",
        "Total grocery cost $20.00");


    // average_daily_steps tests
    test(average_daily_steps,
        "5000 6000 7000 8000 9000 10000 11000",
        "Average daily steps: 8000\n");

    test(average_daily_steps,
        "12000 11000 15000 14000 13000 16000 17000",
        "Average daily steps: 14000\nGreat job staying active!");


    // triangle_pattern tests
    test(triangle_pattern,
        "3 *",
        "* \n* * \n* * * \n");

    test(triangle_pattern,
        "5 X",
        "X \nX X \nX X X \nX X X X \nX X X X X \n");

    return 0;
}