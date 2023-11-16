[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/gxXY5D76)

# HW1 EE538
## University of Southern California
## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc.
  We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Rubrics:
  
| Question | Points |
| -------- | ------ |
| 1        | 18     |
| 2        | 18     |
| 3        | 18     |
| 4        | 18     |
| 5        | 18     |
| 6        | 18     |
| 7        | 18     |

- Total: 126 points. 100 points is considered full credit.


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.

# Question
- Please refer to [files](/files).
- For each question, implement and test it in the [files](/files).
- Write the runtime complexity of each question in this README file.

# Answers
[TODO: Should be filled out with runtime complexity of each question with justification.]

1. runtime complexity of "Reverse" is O(n).
The operations within the for loop have a time complexity of O(1), and the loop runs n/2 times. Therefore, the overall time complexity is O(n).

    runtime complexity of "PlusOne" is O(n).
The operations within the for loop have a time complexity of O(1), and the loop runs n times. Therefore, the overall time complexity is O(n).   

2. runtime complexity of "IsPrime" is O(n^(1/2)).
The time complexity of the operations performed in the preceding statements is O(1). The for loop runs n^(1/2) times. Therefore, the overall time complexity is O(n^(1/2)).

3. runtime complexity of "CountNumberOfSpaces" is O(n).
The for loop runs n times. Therefore, the overall time complexity is O(n).

4. runtime complexity of "Flatten3DVector" is O(n^3).
There are a total of 3 nested for loops, where each layer's iteration count depends on the input, averaging n elements per layer. So the time complexity for each layer is O(n). The overall time complexity is O(n^3).

5. runtime complexity of "ClimbStairs" is O(3^n).
In this problem, a recursive algorithm is used. The time complexity for each recursive call is O(1), and on average, each recursive call will further invoke the function three times, resembling a ternary tree structure with an average depth of n.So the overall time complexity is O(3^n).

6. runtime complexity of "Calculator" is O(1).
The functions consist of basic operations.So the overall time complexity is O(1).

7. runtime complexity of "CanBecome" is O(n).
The operations in the function have a time complexity of O(1), but the "sting.find()" function have a time complexity of O(n). Therefore, the overall time complexity is O(n).