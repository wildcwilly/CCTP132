/* 1.4.1 Parentheses
Chris Wild

Add some parentheses (none, one or two pairs) in the code below to get the expected results. Try to do this before you run the program.

#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    float v=2;
    float result = v + 1 * 2;
    std::cout << "result: " << result << " expected result : 6" << std::endl;
    result = v + 1 * v + 2 * 2;
    std::cout << "result: " << result << " expected result : 24" << std::endl;
    result = v - 1 * 2 + 2 * 2;
    std::cout << "result: " << result << " expected result : 6" << std::endl;
    result = v + v * v + v * 2;
    std::cout << "result: " << result << " expected result : 32" << std::endl;
    result = (int)v % 2 * v + 2 * 2;
    std::cout << "result: " << result << " expected result : 0" << std::endl;
}

Example input

Add parentheses

Example output

result:  6  expected result :  6
result: 24  expected result : 24
result:  6  expected result :  6
result: 32  expected result : 32
result:  0  expected result :  0
*/

#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    float v=2;
    float result = (v + 1) * 2;
    std::cout << "result: " << result << " expected result : 6" << std::endl;
    result = (v + 1) * (v + 2) * 2;
    std::cout << "result: " << result << " expected result : 24" << std::endl;
    result = (v - 1) * 2 + 2 * 2;
    std::cout << "result: " << result << " expected result : 6" << std::endl;
    result = (v + v) * (v + v) * 2;
    std::cout << "result: " << result << " expected result : 32" << std::endl;
    result = (int)v % 2 * (v + 2) * 2;
    std::cout << "result: " << result << " expected result : 0" << std::endl;
}

/* Actual output (copied from console window)

result: 6 expected result : 6
result: 24 expected result : 24
result: 6 expected result : 6
result: 32 expected result : 32
result: 0 expected result : 0
*/