[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/X0ofqRWp)

# HW2 EE538
## University of Southern California
## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

Important: Please use bazel with c++17:

```bash
bazel test --cxxopt="-std=c++17"  {test_target}
```

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Deadline: October 2th by 12:00 pm (noon)
- Rubrics:
  
| Question | Points |
| -------- | ------ |
| 1        | 4      |
| 2        | 32     |
| 3        | 17     |
| 4        | 8      |
| 5        | 22     |
| 6        | 27     |
| 7        | 10     |

- 100 points is considered full credit.


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.

# Write non-coding answers below
#3:
Q1:
If we want to initialize the elements vector, we shouldn't use elements[],
because elements have not be allocated any memory. we should use push_back to initialize the vector.
The variable element also didn't be used in question1.

Q2:
we didn't allocate memory for point a,if we use it and assign some value to it, it may cause undefine

Q3:
we should call the delete function to release the memory in order to avoid the memory leaks

Q4:
if we allocate memory to point a and b, we should delete them in the end.
When we use a++ or b++, we can't make sure Continuous memories are allocated
When we use a++ or b++, we will lose the address of the original allocated memory, it will cause memory leaks

Q5:
In each loop, variable will subtract 1 amd add 1, so i will not change forever, and the loop will never stop

Q6:
In this loop when *it=0,1,2,3,4 , set will insert 1,2,3,4,5 ,because they already exist, they can't be inserted in the set. when *it=5, set will insert 6, and it.end() will also change, the loop will keep going, and in the next loop, it.end() will change again, so the loop will never stop



