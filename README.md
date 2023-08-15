# Push_swap
This project was developed for 42 school. For comprehensive information regarding the requirements, please consult the PDF file in the subject folder of the repository. Furthermore, I have provided my notes and a concise summary below.
``` diff
+ keywords: sorting algorithm
```

## High-level Overview

This is a straightforward algorithm project: data (integers received as arguments) must be sorted, in the fastest way possible. There are two stacks: A receives the group of integers and B supports A's movements as a tmp placeholder.

1. Sort a stack using the least amount of instructions (a.k.a. **actions**);
2. `Stack A` is given a random list of unorganized numbers;
3. Sort them so that `Stack A` is organized from smallest to largest;
4. The actions are named: `sa`, `sb`, `ss`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`, `pa`, `pb`;

input `./push_swap 1337 42 -16`
output will be the list of actions

**References:** <br />
[Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a#id_token=eyJhbGciOiJSUzI1NiIsImtpZCI6ImZkNDhhNzUxMzhkOWQ0OGYwYWE2MzVlZjU2OWM0ZTE5NmY3YWU4ZDYiLCJ0eXAiOiJKV1QifQ.eyJpc3MiOiJodHRwczovL2FjY291bnRzLmdvb2dsZS5jb20iLCJhenAiOiIyMTYyOTYwMzU4MzQtazFrNnFlMDYwczJ0cDJhMmphbTRsamRjbXMwMHN0dGcuYXBwcy5nb29nbGV1c2VyY29udGVudC5jb20iLCJhdWQiOiIyMTYyOTYwMzU4MzQtazFrNnFlMDYwczJ0cDJhMmphbTRsamRjbXMwMHN0dGcuYXBwcy5nb29nbGV1c2VyY29udGVudC5jb20iLCJzdWIiOiIxMDc4NTAyMjM1MTUwMzk2OTY2NjAiLCJlbWFpbCI6InNvZmlhaGRpYXNAZ21haWwuY29tIiwiZW1haWxfdmVyaWZpZWQiOnRydWUsIm5iZiI6MTY5MTE1MDI1NCwibmFtZSI6IlNPRklBIEhJTkNLRUwiLCJwaWN0dXJlIjoiaHR0cHM6Ly9saDMuZ29vZ2xldXNlcmNvbnRlbnQuY29tL2EvQUFjSFR0Y29NbXo0VHg5VVdBTUdnVW1CaDAxQ3FSVnZVcTdzeXpwbkEtTFhHOGVQdGh3dj1zOTYtYyIsImdpdmVuX25hbWUiOiJTT0ZJQSIsImZhbWlseV9uYW1lIjoiSElOQ0tFTCIsImxvY2FsZSI6InB0LUJSIiwiaWF0IjoxNjkxMTUwNTU0LCJleHAiOjE2OTExNTQxNTQsImp0aSI6IjI5ZDk0YzUyYTU1MjVmODQzNmQxNzE3Y2IyNWI0OWI2NDU0ODg4OWIifQ.aUT3wzlK4-xnTWUfrjZosF9SPxC3r7-bs6-ktHT3Pjx-K3rSbg4MLfnq0p5j7kEnuGxtWRM9wSVIbNMVwIo5kuE4oEgV88jXe-AtmeBAWLVeXij3kTFT5xKZtyW-zczvp3CXNiJFIBnBLi9KySHdnzQrMh2Old5LJT5JthetzyjVv-9deFWh3P82-GHoWdQaqXBRv4ZnRlfxX4xSrdTyrHMyHpHqKsvSKHY1L7AMpkmViwHoXKBEheeKt82yHup03twYtSvFC9K0CiI7HtqOZxYPwWKeMW1QLUm9-blKw_tsCvvpn8FnTuQrHARmgy_yY1hG8ffPhWDR5Tm4HtzGBg) <br />
[push_swap : a performant sorting algorithm using 2 stacks (100-630 moves | 500-5470 moves)](https://www.youtube.com/watch?v=OaG81sDEpVk) <br />
[Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) <br />


## Concepts

| Task | Prototype | Description |
|:----|:-----:|:--------:|
| **`Algorithm`** | | A series of instructions that perform a task. |
| [Right-Left rule](https://riptutorial.com/c/example/18833/using-the-right-left-or-spiral-rule-to-decipher-c-declaration) | `int *p[];` `array of pointers to integers` | How to read variables in C more efficiently. |
| **`Boilerplate code`** || Code sections repeated in multiple places with little to no variation. When using languages that are considered verbose, the programmer must write a lot of boilerplate code to accomplish only minor functionality. |
| **`Insertion sort`**| | |
| **`check if the input is correct`** | `if (argc == 1 or (argc == 2 && !argv[1][0]))` | If there is only one argument or the argument is an empty string, returns an error and stops the program. |
| **`2D matrix must carry same data`** | `argv = ft_split(argv[1], 32)` | The user could write `./push_swap 1337 42 -16` or `./push_swap "1337 42 -16"` and the function must result in the same. The first example has 4 values, and the second 2 (this should be split to carry 4 as well). However, what if the user mix inputs? `1 2 3 "4 5 6" 8 9` |
| **`static function - static variable`** | | Static function is only available within the file it's in. Static variable... |
| **`ft_atoll`** | `long long	ft_atoll(const char *nptr)` | Takes a string and returns a [long long int](https://www.geeksforgeeks.org/difference-between-long-int-and-long-long-int-in-c-cpp/). |
| **`Check repetitions`** | `./pipex 42 42` | Repetitions should trow an error. |
| **`Random numbers generator`** | `add command line input` | [Calculator Soup](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php) |
| **`ANSI escape sequences`** |  | [ANSI escape sequences](https://unix.stackexchange.com/questions/124407/what-color-codes-can-i-use-in-my-bash-ps1-prompt)|

