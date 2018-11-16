/* 1.3.1 Comments: are they always useful?
Chris Wild

Comments are not always the best way to say something in code. Sometimes it's much better to leave some information in the code. In
the worst-case scenario, comments can lie to the user/programmer (you should never do that on purpose). It's good to use readable
variable names, and sometimes it's better to divide your code into named pieces (later we'll call these pieces functions). In some
situations, it's a good idea to write the steps of computations in a clearer way. The code below contains some of these situations. Try to
improve it (and remove the comments – removing the comments will sometimes be an improvement itself).

#include <iostream>//we included iostream
#include <iomanip>//we included iomanip
#include <string>//we included string

int main()
{
    int v=10800; // 3*60*60
    int zzz=3*60;// This is a variable to hold the value of 3 minutes in seconds
    int zzz=5*60;// This is a variable to hold the value of 6 minutes in seconds
    float siii=3.141526; //This is the value of pi
    //std::cout << "result: " << result << std::endl;
    // here we should print the v value but a programmer didn't have time to write any code
    // but he/she likes writing long comments
}
*/

#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    int result=3*60*60;
    int secPerMin = 60;   // number of seconds in minute
    int threeMin = 3 * secPerMin; // 3 minutes in seconds
    int sixMin = 6 * secPerMin;   // 6 minutes in seconds
    float pi = 3.141526;  //This is the value of pi
    std::cout << "result: " << result << std::endl;
    
    return 0;
}
