[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/5cwW69Gl)

# EE538 Midterm Exam
## University of Southern California
## Instructor: Arash Saifhashemi

## Important:
- A lot of time and effort has been spent to design this exam for you. Please use this as a great learning opportunity and take this exam seriously.
- Please make sure you abide by the academic integrity rules and only submit your original work. All the rules described in Q1 of the Gradescope exam applies here as well.
- Make sure you use address sanitizer!
- Every time that you use a dereferencing operator (* or ->) make sure your pointer is valid!

Run your tests for each question using this command:
```
bazel test --cxxopt="-std=c++17" --config='asan' files/{question_number}/grader_test
```

Before submission, you can run all the tests for all questions using this command:

```
bazel test --cxxopt="-std=c++17" --config='asan' $(bazel query //files/... | grep grader)
```


Also note that:
- Important: Don't modify the header files. Your implementation should go in .cc files.
- Please find each question in a separate folder under [files](/files).
- For coding questions, edit the files and check them in.
- For non-coding questions write the answers in the README file (This file).
- No need to write complete student tests. Your code must pass grader tests.
- For submission, please push your answers to Github before the deadline.
  
| Question | Points |
| -------- | ------ |
| 1        | 25     |
| 2        | 25     |
| 3        | 10     |
| 4        | 25     |


- Total: 85 points. 
- Getting 100 points from the sum of the points in this repo plus the points in Gradescope exam is considered full credit. 
  - For example, if you get 80 from this repo and 25 from Gradescope, your total would be 105, which means you received full credit!


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.


#3.
arrays:
Q1:In dynamic arrays, we can't find the length of the array, so we can't find the end of the array.
Q2:The size of output is the sum of two arrays' size.

vector:
Q1:In vector, we can call the function size() to get the size of vector, so we don't need another space to provide the sizes.
Q2:This is no problem, for functions with the same name, we can make their argument types, the number of arguments or the return type different, which can achieve function overloading.

#4.
The runtime complexity of "MySet(std::vector<int>& elements)" is O(n), because the runtime complexity of vector's copy is O(n), the runtime complexity of std::sort is O(logn), so the total runtime complexity is O(n)

The runtime complexity of "MySet(const MySet& rhs)" is O(n), because the runtime complexity of vector's copy is O(n)

The runtime complexity of "insert" is: O(n), because the runtime complexity of findInsertionIndex is O(logn) and the runtime complexity of vector::insert is O(n), so the total runtime complexity is O(n)

The runtime complexity of "is_in" is: O(logn), because the runtime complexity of findInsertionIndex is O(logn)

The runtime complexity of "size" is: O(1), because the runtime complexity of vector::size is O(1)

The runtime complexity of "ConvertToStdVector" is: O(n), because the runtime complexity of vector's copy is O(n)