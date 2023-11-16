[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/r8O3eZrR)

# HW3 EE538
## University of Southern California
## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

## Important:
- Use address sanitizer!
- Every time that you use a dereferencing operator (* or ->) make sure your pointer is valid!

Also note that:
- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Rubrics:
  
| Question | Points |
| -------- | ------ |
| 1        | 16     |
| 2        | 15     |
| 3        | 15     |
| 4        | 20     |
| 5        | 15     |
| 6        | 15     |
| 7        | 15     |


- 100 points is considered full credit.


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.

#1
Q1:
MyClass o1 use the non-parameterized constructor,so it call the function 'MyClass()' and print 'Non-parameterized constructor'
Then call the function o1.v_.size(), there is no elements in o1.v_, so the size is 0
When all programs are finished running in Q1, it will call the function '~MyClass()' to destroy the o1, and this function will print 'Destructor'

Q2:
MyClass o1 use the non-parameterized constructor,so it call the function 'MyClass()' and print 'Non-parameterized constructor'
MyClass o2(1,3) use the parameterized constructor,so it call the function 'MyClass(int a,int b)' and print 'Parameterized constructor'
MyClass o3 = o1 use the copy constructor,so it call the function 'MyClass(const MyClass &rhs)' and print 'Copy constructor'
When all programs are finished running in Q2, it will call the function '~MyClass()' to destroy all the objects, and this function will print 'Destructor' 3 times.

Q3:
MyClass o use the non-parameterized constructor,so it call the function 'MyClass()' and print 'Non-parameterized constructor'
In 'DoSomething1(o)',it will call the function 'DoSomething1(MyClass o)'. In this function, it will also create another 'MyClass o' to receive the parameter, so it will call the function 'MyClass(const MyClass &rhs)' and print 'Copy constructor'
Then in function 'DoSomething1', it will print 'Something 1'
When the programs are finished running in function 'DoSomething1', it will call the function '~MyClass()' to destroy the copy objects, and this function will print 'Destructor'.
Then when all programs are finished running in Q3, it will call the function '~MyClass()' to destroy object o, and this function will print 'Destructor'.

Q4:
MyClass o use the non-parameterized constructor,so it call the function 'MyClass()' and print 'Non-parameterized constructor'
In 'DoSomething2(o)',it will call the function 'DoSomething2(MyClass &o)'. In this function, it will not create another 'MyClass o' to receive the parameter, it just pass the address of o, so it will not call the constructor and just print 'Something 2'
Then when all programs are finished running in Q4, it will call the function '~MyClass()' to destroy object o, and this function will print 'Destructor'.

Q5:
In Q5, it is the same with the Q4, and the only difference is that in function 'DoSomething3', it print 'Something 3'

Q6:
MyClass o use the non-parameterized constructor,so it call the function 'MyClass()' and print 'Non-parameterized constructor'
In 'DoSomething4(o)',it will call the function 'DoSomething4(MyClass &o)'. In this function, it pass the address of o to another object o as a parameter in function 'DoSomething4.And in this function, it will create another object o2 = o using the copy constructor,so it call the function 'MyClass(const MyClass &rhs)' and print 'Copy constructor'
Then in function 'DoSomething4', it will print 'Something 4'
When the programs are finished running in function 'DoSomething4', it will call the function '~MyClass()' to destroy the object o2, and this function will print 'Destructor'.
Then when all programs are finished running in Q6, it will call the function '~MyClass()' to destroy object o, and this function will print 'Destructor'.

Q7:
Firstly,MyClass(1,2) will call the function 'MyClass(int a,int b)' and print 'Parameterized constructor'
Then in pair<MyClass, int> p1, it will create another object 'MyClass' by using copy constructor to copy the data of MyClass(1,2), it call the function 'MyClass(const MyClass &rhs)' and print 'Copy constructor'
After the object of MyClass in pair copy the data of MyClass(1,2),MyClass(1,2) will call the function '~MyClass()' to destroy this object, and this function will print 'Destructor'
Then program call the function p1.first.v_.size(), p1.first's type is MyClass, there is no elements in p1.first.v_, so the size is 0
In the last step, in {MyClass(1, 2),0}, it assign 0 to p1.second,so program print p1.second which value is 0;
Then in pair<MyClass, int> p2, it will create another object 'MyClass' by using copy constructor to copy the MyClass object in p1, it call the function 'MyClass(const MyClass &rhs)' and print 'Copy constructor'
Then program call the function p2.first.v_.size(), the value of p2.first.v_ is the same as p1.first.v_, so the size is also 0
Then program print the function p2.second, the value of p2.second is the same as p1.second, so value is also 0
Then when all programs are finished running in Q7, it will call the function '~MyClass()' to destroy MyClass object in p2 firstly, and this function will print 'Destructor'.
And then it will call the function '~MyClass()' to destroy MyClass object in p1, and this function will also print 'Destructor'.

Q8:
At the beginning of the for loop, MyClass(1,2) will call the function 'MyClass(int a,int b)' and print 'Parameterized constructor'
Then in pair<MyClass, int> p, it will create another object 'MyClass' by using copy constructor to copy the data of MyClass(1,2), it call the function 'MyClass(const MyClass &rhs)' and print 'Copy constructor'
After the object of MyClass in pair copy the data of MyClass(1,2),MyClass(1,2) will call the function '~MyClass()' to destroy this object, and this function will print 'Destructor'
In the for loop, p.second is assigned a value of 0 at firs, and in each loop, it will add 1. After 3 cycles, the value of p will change to 3, thus exiting the loop. In each cycles, it will call the function 'DoSomething2'. In function 'DoSomething2', because it will pass the address, it won't create any other object. So it will just print 'Something2' 3 times.
After finish looping, it will call the function '~MyClass()' to destroy the object in pair, and this function will print 'Destructor'.

Q9:
When call the 'new MyClass(1, 2)', it will call the function 'MyClass(int a,int b)' and print 'Parameterized constructor'
Because it use new to create an object in the heap memory, and didn't call the delete, it won't call the function '~MyClass()' to destroy it

Q10:
When call the 'new MyClass(1, 2)', it will call the function 'MyClass(int a,int b)' and print 'Parameterized constructor'
Then it call the delete, it will call the function '~MyClass()' to destroy it, and this function will print 'Destructor'.

Q11:
At first, MyClass() will call the function 'MyClass()' and print 'Non-parameterized constructor'
And then it will create a pair<int,MyClass> to copy the data of {0, MyClass()}, it will call the function 'MyClass(const MyClass &rhs)' and print 'Copy constructor'
MyClass(1, 2) will call the function 'MyClass(int a,int b)' and print 'Parameterized constructor'
And then it will also create a pair<int,MyClass> to copy the data of {3, MyClass(1, 2)}, it will call the function 'MyClass(const MyClass &rhs)' and print 'Copy constructor'
For the {5, MyClass(3, 4)}, it is the same as the above description
Then in the map<int, MyClass> my_map, it will create 3 MyClass to copy 3 pairs,it will call the function 'MyClass(const MyClass &rhs)' and print 'Copy constructor' 3 times
Then for the pair({5, MyClass(3, 4)}), it will call the function '~MyClass()' to destroy MyClass(3, 4) firstly, and then destroy pair<int,MyClass>,so it will print 'Destructor' 2 times.
The same as pair({5, MyClass(3, 4)}), pair({3, MyClass(1, 2)}) and pair({0, MyClass()}) each will print 'Destructor' 2 times.
Then in the loop, each e will create a MyClass object and copy the data in the map, and then call the function '~MyClass()' to destroy it before next cycle.So it will print 'Copy constructor' and 'Destructor' 3 times.
Then when all programs are finished running in Q11, it will call the function '~MyClass()' to destroy MyClass object in map, and it will print 'Destructor' 3 times.

Q12:
About map<int, MyClass> my_map, it is the same as Q11.
But in the for loop, it didn't copy the data of map to e, it pass the each pair's address to e, so it won't create any MyClass object.
Then when all programs are finished running in Q12, it will call the function '~MyClass()' to destroy MyClass object in map, and it will print 'Destructor' 3 times.

Q13:
When call the 'new MyClass(1, 2)', it will call the function 'MyClass(int a,int b)' and print 'Parameterized constructor'
Then it call the delete, it will call the function '~MyClass()' to destroy it, and this function will print 'Destructor'.

Q14:
MyClass o(100000000) use the parameterized constructor,so it call the function 'MyClass(int size)' and print 'Parameterized constructor'
PrintAndGetDuration() print the time of the creation of MyClass o(100000000)
In the first cycle, MyClass o2 call the function 'MyClass(const MyClass &rhs)' and print 'Copy constructor'
In DoSomething1(o2), it create another object o to copy o2, so it call the function 'MyClass(const MyClass &rhs)' and print 'Copy constructor'
Then in this function, it print 'Something 1.'
When the function ending, it will call the function '~MyClass()' to destroy object o in function 'DoSomething1', and this function will print 'Destructor'.
Then it will print o2.v_'s size which is the same as o.v_'s size
When the cycle ending, it will call the function '~MyClass()' to destroy object o2, and this function will print 'Destructor'.
Then the next cycle is the same as the first cycle.
After looping,it will print the cost time by calling PrintAndGetDuration();
When we create object o,we need to assign 100000000 space to o.v_,it cost a lot of time.But when we use copy constructor,it is a shallow copy constructor,we don't need a lot of time to assign a lot of space,so even it copy two object,the time cost is still smaller than time cost of object o

Q15:
It is the same as Q14,but in the function 'DoSomething2',it just pass the address of object, it didn't create another MyClass to copy it.
Because it just pass the address and didn't create object to copy, it save more time compare to Q14

Q16:
About vector<MyClass> my_vector, it is similar to Q14,from MyClass(10000000) to MyClass(70000000), it will call the function 'MyClass(int size)' and print 'Parameterized constructor' for 7 times.
Then in vector<MyClass> my_vector, it need to create a MyClass object to copy these 7 objects, it will call the function 'MyClass(const MyClass &rhs)' and print 'Copy constructor' for 7 times.
After copying them, these 7 objects will be destroy, it will call the function '~MyClass()' to destroy it, and this function will print 'Destructor' for 7 times.
And PrintAndGetDuration() will print the during time
Then in the first loop, for each cycle, it need to create a object e to copy the data in my_vector and print e.v_'s size and at the ending of each cycle, it will destroy the object e.So each cycles, it will print 'Copy constructor', e.v_.size() and 'Destructor'.
And PrintAndGetDuration() will print the during time
In the second loop,it just pass the MyClass object's address to e, it didn't create any object. So it just print e.v.size() for 7 times.
And PrintAndGetDuration() will print the during time
Then when all programs are finished running in Q16, it will call the function '~MyClass()' to destroy all the MyClass object in vector, and it will print 'Destructor' 7 times.
In the first during time, it need to create 7 new object and assign a lot of space to them and 7 shallow copy, it cost a lot of time. In the second during time, it create 7 shallow copy, it cost a short time. In the third during time, it only pass the address to the point, it takes almost no time.
