/* 1.2.1 Your first program
Chris Wild

We strongly encourage you to play (yes, to play!) with your first program and make some (maybe even destructive) amendments. Feel
free to modify any part of the code, but there is one condition – learn from your mistakes and draw your own conclusions!
Try to:
    * add a greeting – let the program welcome you in a warm and pleasant way;
    * duplicate (or triplicate) the greeting to welcome more than one person;
    * insert a line saying cout << endl; between two other couts and check the effects it has; does it look interesting? You're going to
      learn more about it soon;
    * now try to insert a mysteriously-looking sequence of chars into any of the greeting: \n – there are exactly two characters: a
      backslash and lower-case n; what happens now?;
    * try to remove any of the semicolons and look carefully at the compiler's response; pay attention to where the compiler sees an
      error – is this where the error really is?
    * change the name of the main function to any other lexically correct word (e.g. Main); what happens now? Can you explain the
      result?
    * remove some of the quotes (opening and closing ones respectively); does the compiler like that? What does it think of your
      actions?

#include <iostream>

using namespace std;

int main(void)
{
    cout << "It's me, your first program.";
    return 0;
}
*/

#include <iostream>

using namespace std;

int main(void)
{
    cout << "Hello Chris.";
    cout  << endl;
    cout << "Hello Zak.\n";
    cout  << endl;
    cout << "Hello Adam.";
    cout  << endl;

    return 0;
}

/* results
* add a greeting – let the program welcome you in a warm and pleasant way;

    Hello Chris, I'm your first program.

* duplicate (or triplicate) the greeting to welcome more than one person;
    
    Hello Chris.
    Hello Zak.
    Hello Adam.

* insert a line saying cout << endl; between two other couts and check the effects it has; does it look interesting? You're going to
  learn more about it soon;

    Hello Chris.
    Hello Zak.
    Hello Adam.

* now try to insert a mysteriously-looking sequence of chars into any of the greeting: \n – there are exactly two characters: a
  backslash and lower-case n; what happens now?;

    Hello Chris.
    Hello Zak.

    Hello Adam.

* try to remove any of the semicolons and look carefully at the compiler's response; pay attention to where the compiler sees an
  error – is this where the error really is?

    compiler says error in line 40, after the line missing the ;

* change the name of the main function to any other lexically correct word (e.g. Main); what happens now? Can you explain the
  result?

    compiler gives undefined reference to 'main' error

* remove some of the quotes (opening and closing ones respectively); does the compiler like that? What does it think of your
  actions?

    IDE shows problem with missing quotes, compiler give long (multiple) error messages with missing quotes
*/