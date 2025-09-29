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

**Expectation of this to understand and learn the concept of DSA**
