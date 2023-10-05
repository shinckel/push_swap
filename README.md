# Push_swap
This project was developed for 42 school. For comprehensive information regarding the requirements, please consult the PDF file in the subject folder of the repository. Furthermore, I have provided my notes and a concise summary below.
``` diff
+ keywords: sorting algorithm
+ linked list
```
_Mindmaps (shinckel, 2023)_
![mind-map_push-swap1](https://github.com/shinckel/push_swap/assets/115558344/e5dfc007-2728-4b16-91dc-832ae223dcf1)

![mind-map_push-swap2](https://github.com/shinckel/push_swap/assets/115558344/3f59a37d-4ea0-456d-8588-2073daaa4929)


## High-level Overview

This is a straightforward algorithm project: data (integers received as arguments) must be sorted, in the fastest way possible. There are two stacks: `A` receives the group of integers and `B` supports `A`'s movements as a tmp placeholder.

1. Sort a stack using the least amount of instructions (a.k.a. **actions**);
2. `Stack A` is given a random list of unorganized numbers;
3. Sort them so that `Stack A` is organized from smallest to largest, in ascending order;
4. The actions are named: `sa`, `sb`, `ss`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`, `pa`, `pb`;

input `./push_swap 1337 42 -16`
output will be the list of actions

**References:** <br />
[Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a#id_token=eyJhbGciOiJSUzI1NiIsImtpZCI6ImZkNDhhNzUxMzhkOWQ0OGYwYWE2MzVlZjU2OWM0ZTE5NmY3YWU4ZDYiLCJ0eXAiOiJKV1QifQ.eyJpc3MiOiJodHRwczovL2FjY291bnRzLmdvb2dsZS5jb20iLCJhenAiOiIyMTYyOTYwMzU4MzQtazFrNnFlMDYwczJ0cDJhMmphbTRsamRjbXMwMHN0dGcuYXBwcy5nb29nbGV1c2VyY29udGVudC5jb20iLCJhdWQiOiIyMTYyOTYwMzU4MzQtazFrNnFlMDYwczJ0cDJhMmphbTRsamRjbXMwMHN0dGcuYXBwcy5nb29nbGV1c2VyY29udGVudC5jb20iLCJzdWIiOiIxMDc4NTAyMjM1MTUwMzk2OTY2NjAiLCJlbWFpbCI6InNvZmlhaGRpYXNAZ21haWwuY29tIiwiZW1haWxfdmVyaWZpZWQiOnRydWUsIm5iZiI6MTY5MTE1MDI1NCwibmFtZSI6IlNPRklBIEhJTkNLRUwiLCJwaWN0dXJlIjoiaHR0cHM6Ly9saDMuZ29vZ2xldXNlcmNvbnRlbnQuY29tL2EvQUFjSFR0Y29NbXo0VHg5VVdBTUdnVW1CaDAxQ3FSVnZVcTdzeXpwbkEtTFhHOGVQdGh3dj1zOTYtYyIsImdpdmVuX25hbWUiOiJTT0ZJQSIsImZhbWlseV9uYW1lIjoiSElOQ0tFTCIsImxvY2FsZSI6InB0LUJSIiwiaWF0IjoxNjkxMTUwNTU0LCJleHAiOjE2OTExNTQxNTQsImp0aSI6IjI5ZDk0YzUyYTU1MjVmODQzNmQxNzE3Y2IyNWI0OWI2NDU0ODg4OWIifQ.aUT3wzlK4-xnTWUfrjZosF9SPxC3r7-bs6-ktHT3Pjx-K3rSbg4MLfnq0p5j7kEnuGxtWRM9wSVIbNMVwIo5kuE4oEgV88jXe-AtmeBAWLVeXij3kTFT5xKZtyW-zczvp3CXNiJFIBnBLi9KySHdnzQrMh2Old5LJT5JthetzyjVv-9deFWh3P82-GHoWdQaqXBRv4ZnRlfxX4xSrdTyrHMyHpHqKsvSKHY1L7AMpkmViwHoXKBEheeKt82yHup03twYtSvFC9K0CiI7HtqOZxYPwWKeMW1QLUm9-blKw_tsCvvpn8FnTuQrHARmgy_yY1hG8ffPhWDR5Tm4HtzGBg) <br />
[push_swap : a performant sorting algorithm using 2 stacks (100-630 moves | 500-5470 moves)](https://www.youtube.com/watch?v=OaG81sDEpVk) <br />
[Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) <br />
[Doubly Linked List (in C)](https://www.youtube.com/watch?v=KFbm6lkMhgw) <br />
[Doubly-Linked Lists - CS50 Shorts](https://www.youtube.com/watch?v=FHMPswJDCvU) <br />
[LinkedList 12 Double Linked Lists](https://www.youtube.com/watch?v=v8xyoI11PsU) <br />

## Concepts

| Task | Prototype | Description |
|:----|:-----:|:--------:|
| **`Algorithm`** | | A series of instructions that perform a task. |
| [Right-Left rule](https://riptutorial.com/c/example/18833/using-the-right-left-or-spiral-rule-to-decipher-c-declaration) | `int *p[];` `array of pointers to integers` | How to read variables in C more efficiently. |
| **`Boilerplate code`** || Code sections repeated in multiple places with little to no variation. When using languages that are considered verbose, the programmer must write a lot of boilerplate code to accomplish only minor functionality. |
| **`Insertion sort`**| | |
| **`check if the input is correct`** | `if (argc == 1 or (argc == 2 && !argv[1][0]))` | If there is only one argument or the argument is an empty string, returns an error and stops the program. |
| **`2D matrix must carry same data`** | `argv = ft_split(argv[1], 32)` | The user could write `./push_swap 1337 42 -16` or `./push_swap "1337 42 -16"` and the function must result in the same. The first example has 4 values, and the second 2 (this should be split to carry 4 as well). However, what if the user mixes inputs? `1 2 3 "4 5 6" 8 9` |
| **`static function - static variable`** | | Static function is only available within the file it's in. Static variable... |
| **`ft_atoll`** | `long long	ft_atoll(const char *nptr)` | Takes a string and returns a [long long int](https://www.geeksforgeeks.org/difference-between-long-int-and-long-long-int-in-c-cpp/). |
| **`Check repetitions`** | `./pipex 42 42` | Repetitions should trow an error. |
| **`Random numbers generator`** | `add command line input` | [Calculator Soup](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php) |
| **`ANSI escape sequences`** |  | [ANSI escape sequences](https://unix.stackexchange.com/questions/124407/what-color-codes-can-i-use-in-my-bash-ps1-prompt)|
| **`tiny_sort`** | `trivial sorting, 3 numbers` | In the worst scenario, a maximum of two moves. Is the first node the biggest value? Yes, rotate `a`. No, check if the second node is the biggest, ensuring it is in the bottom position. |
| **`More than three`**| `push_swap(&a, &b)` | Push the nodes to `b` until only three nodes remain in `a` for `tiny_sort(a)`. Perform a precise insertion of the node from `b` to `a`. For it, you need a strategy: every node in `b` will have a `target_node` in `a`. The target will be the next value in `a`, which is one node bigger than `b` itself. If the value is already the biggest, it should point to the smallest value in the stack `a` (a.k.a. cheapest). In addition, set the current position and the price (`b->current_position + target_node->current_position`), what is the cost of each node to bring to the top of the stack? |
| **`cost`** | `How many moves to bring to the top?` | Because the start and the end of the list have a distance of only one move, it is not possible to calculate the distance to the top only through the natural list order. It is necessary to divide the stack in two: everything in the middle of the stack is the most expensive. The first node has cost zero because it is already in the ideal position. Therefore, the cost is proportional to the position and the length of the stack. What is the cost of pushing node and target node? Because both need to be in the first position, for then applying the action `pa` in putting them into order. This is a continuous calculation, done in each iteration. |
| **`move nodes`** | | In every configuration I get one cheapest node, with the smallest cost. This function will return me a pointer to the cheapest: you are the cheapest and I want to move you. If both node and target are above the median, rotate both (two moves simultaneously, reduce the cost in half). |
| **`Stack size`** | `metadata ` | What is the complexity? `O(n)` You have to count it every time! [Look here the Time complexity chart](https://www.freecodecamp.org/news/big-o-cheat-sheet-time-complexity-chart/). On the other hand, storing metadata, complexity is 1. In the case of `push_swap`, we do it a lot. |
| [Linked List Problems](http://cslibrary.stanford.edu/105/LinkedListProblems.pdf) By Nick Parlante | x | Changing a Pointer Using a Reference Pointer (pass a pointer to the head pointer. i.e. pass a pointer to the "value of interest" that needs to be changed). Therefore, t is o change a struct node*, pass a struct node** |
| **`Doubly Linked List`** | `*prev` `data` `*next` | [Programiz content](https://www.programiz.com/dsa/doubly-linked-list#google_vignette). Self-referential structure. Each node consists of three components: address of the previous node, data item, address of the next node. Meaning: you can access information in both directions! In other words, you have a list that can be traversed from “front-to-back” using next pointers, and one that can be traversed "back-to-front" using `prev` pointers. It is particularly interesting to use this technique in problems as push swap (e.g. rotate action). Tradeoff: extra bites of memory and operations get more complex, e.g. adding to the middle of the list, you will have to deal with four pointers (moving a lot of `prev` and `next`). Benefit: constant time removal of the tail of the list. |
| **`Doubly Linked List - insert/delete node`** | `node->next->prev->prev` | Constant-algorithm, meaning: time is not related with the size of iteration-linear-time (actually, it can solve the problem with 3 or 4 operations). Assuming all of the next and prev pointers are pointing at valid list elements, `node->next->prev->prev` will end up returning the same node as `node->prev`, as `node->next->prev` is just node. If the element is `NULL`, you will get a segmentation fault. |
| **`5 linked lists rules`** | x | empty list, single element list, working at the beggining, working at the end, working at the middle. Always check! |
| **`Binary Search Algorithm`** | `O(n)` | [Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm#:~:text=Binary%20search%20compares%20the%20target,the%20target%20value%20is%20found.) / [Computational Complexity Theory](https://plato.stanford.edu/entries/computational-complexity/) / [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation#Orders_of_common_functions) ![1_KfZYFUT2OKfjekJlCeYvuQ](https://github.com/shinckel/push_swap/assets/115558344/e9888ce5-24dc-454e-98ad-36a9f8a0fff1)|
| **`Big O`** |  | A way of generalizing code, comparing solutions and its performances, how can I determine which one is the best? **It is a system for classifying code, puts things into context = numeric representation of the performance of code.** Tell me the big O of this algorithm? Rather then counting seconds, let’s count the number of simple operations the computer has to perform. It allows us to talk formally about how the runtime of an algorithm grows as the inputs grow. |
| **`...as an input grows`** | $f(n) = n$  $f(n) = n^2$  $f(n) = 1$ | A function with an argument n, returns an output n. Relationship of the input and the runtime. Nested loops would be $f(n) = n^2$ <img width="645" alt="Screenshot 2023-10-03 at 09 24 15" src="https://github.com/shinckel/push_swap/assets/115558344/714b817e-48df-4c60-b334-630c4bf813e6"> <img width="929" alt="Screenshot 2023-10-03 at 09 23 31" src="https://github.com/shinckel/push_swap/assets/115558344/7efa039f-006b-4c0c-bd5b-a2c1231d353c"> |

# [Push_swap Visualizer](https://push-swap-visualizer.vercel.app/)
