

## Assignment Goals
1.	Continue practice with **linked storage** and **dynamically allocated memory**  
2.	Continue practice using **data structures** to solve problems
3.	Familiarize students with the **stack** ADT

## Problem
Design a system which reads the infix form of a ***single*** arithmetic expression, then outputs the postfix expression and resulting value.  
For example, if the user enters  
```(5 + 6) * (4 / 3)```  

The results should be  
```56+43/*```  
```14.6667```

You may assume that the infix input expression consists of 
- single-digit, non-negative integers: `0 1 2 3 4 5 6 7 8 9`
- the four basic arithmetic operators: `+ - \* /`
- parenthesis in the correct order: `( )`
## Requirements
- Provide a ***complete*** implementation for your LinkedStack data structure.   
  - The stack interface has been provided for you in this repository as ```stack.h```.
  - The node class has been provided for you in this repository as ```node.h``` and ```node.cpp```.
- Provide a **driver** which uses LinkedStack object(s) to solve the problem described above.
  - The ArrayStack data structure has been provided for you in this repository as ```arrayStack.h``` and ```arrayStack.cpp```.
    - You can use it to test your overall solution (ie, the driver functions) with a data structure that works correctly.
    - No ArrayStack objects should be included in your final version of the driver.
- Provide a working ```makefile```.
## Extra Credit
### Features will **ONLY** be considered for extra credit if the required functionality is *completely* implemented.  
Correct implementation of handling values with more than one digit will earn you an additional 5% of your original points  

