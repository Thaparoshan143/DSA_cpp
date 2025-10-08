## This repo contains the DSA implementation in CPP

## Current Progress

### Sorting
| Name | Complexity | Requirement/Limitations/Preference |
| :--- | :---: | ---: |
| Bubble    | $$n^2$$           | All numeric val |
| Counting  | $$n+k$$           | Small range, only integral |
| Insertion | $$n^2$$           | All numeric val |
| Merge     | $$n.log_2(n)$$    | All numeric val |
| Quick     | $$n.log_2(n)$$    | All numeric val |
| Radix     | $$n.k$$           | Non-negative integral |
| Selection | $$n^2$$           | All numeric val |

#Note: For more detailes look into respective source code comment.

<hr />

### Searching
- **Linear:** good when, element access is less *(i.e. when sorting overhead is not worth for later access, eg: array of size 10000, to access 5 element position only)*, also array is dynamic in nature.. (not compulsive)
- **Binary:** good when, element access is frequent *(i.e sorting overhead is worth it, eg: array of size 10000, to access 5000 element position)*, also array is static in nature.. (prefered, not compulsive). **Important Note:** Must be sorted to utilize its potential.

<hr />

### Linked List
- **Linear:** One way chain (only forward)
- **Doubly:** Two way chain (both forward and backward) **
- **Circular:** One way but loop (forward) **

** Left to be completed, partially done (Implementation for Doubly and Circular only contains the basic bare bone.. i.e the operation are not included, only the linear linked list basic operation are done implemented)

<hr />

### Stack & Queue 
- **Stack:** First-In-Last-Out order based container (implementation is dynamic, i.e size is changed to accomodate the added elements)
- **Queue:** First-In-First-Out order based container (implementation is static/fixed in nature, i.e size should be known in initialization)

<hr />

### Hash **
- **Tabular:** Simple, without collision remedy, (currently in override mode, i.e. old value is replaced with new value, if hash collide)

**#Importatn Note:** Hash (or Hashing) is not completed as per expectation (collision remedies, multiple hash, other hashing functions..., etc), still looking for few stuffs.. will be updated later..

<hr />

#Warning: Logging is missing in most of the implementation to reduce the overall source code so, for debugging or more detailed interaction (either add the log from /utils/Utils.cpp or make own implementations, **Wondering what log means here?** eg: node added with x element, cannot delete element, stack already empty, queue is full, etc..)

**Expectation of this to understand and learn the concept of DSA**
