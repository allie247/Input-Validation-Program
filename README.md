# Input Validation Program

I created a C++ program that validates all types of input in a user-friendly manner.

* My main method prompts the user for the following types of data:

| Type of input | Definition                                                        |
|---------------|-------------------------------------------------------------------|
| Character | A string of length 1                                              |
| Word | A string with no whitespace                                       |
| Sentence | A string that is read in until the user hits enter/newline        |
| Integer | A valid integer value with nothing else on the same line of input |
| Floating-Point Number | A valid floating-point number (which can be an integer, it isn't required to have a decimal part) and nothing else on the same line of input |

* The main method was written by Lisa Dion, and the following methods are my own code.
* My program validates all input, re-prompting the user when invalid input is received or no input is received. There are different reprompt messages for specific types of invalid input (see sample output below).
* My program does not have any runtime errors, no matter what the user enters.
* My program utilizes functions for each type of input to keep my code organized.

## Sample Output
The user input is in bold font.
<pre>
Enter a single character: <b>no</b>
Invalid input. Enter a single character: <b>NO</b>
Invalid input. Enter a single character: <b>but why?</b>
Invalid input. Enter a single character: <b>Ok here it is: a</b>
Invalid input. Enter a single character: <b>12345</b>
Invalid input. Enter a single character:
No input. Enter a single character: <b>1n2m3</b>
Invalid input. Enter a single character: <b>k</b>
You entered the character k
Enter a single word: <b>Here's a sentence instead</b>
Invalid input. Enter a single word:
No input. Enter a single word: <b>Ok wow</b>
Invalid input. Enter a single word: <b>butterfly</b>
You entered the word butterfly
Enter a sentence:
No input. Enter a sentence:
No input. Enter a sentence:
No input. Enter a sentence:
No input. Enter a sentence: <b>Peekaboo!</b>
You entered the sentence: Peekaboo!
Enter a number: <b>ok</b>
Invalid input. Enter a number: <b>five</b>
Invalid input. Enter a number:
No input. Enter a number: <b>123 abc</b>
Invalid input. Enter a number: <b>abc 123</b>
Invalid input. Enter a number: <b>1 1</b>
Invalid input. Enter a number: <b>-4bc</b>
Invalid input. Enter a number: <b>-4</b>
You entered the number -4
Enter a floating-point number: <b>nope</b>
Invalid input. Enter a number:
No input. Enter a number: <b>123 abc</b>
Invalid input. Enter a number: <b>3.1415926535something</b>
Invalid input. Enter a number: <b>525,600 minutes</b>
Invalid input. Enter a number: <b>10 4</b>
Invalid input. Enter a number: <b>7.8</b>
You entered the floating-point number 7.8
</pre>
