# exercise 1: intro to c `[24 + 3 / 15]`

# running programs

a makefile is provided. run `make run p=[part number]` to build and run individual parts. you are expected to verify your own test cases for this exercise.

# exercises

## conventions `[2]`

some points will be considered based on adherence to convention. while a small part of the overall grade, these are helpful to know.

 - all function and variable names must be in snake case. this means rather than `DoSomething` or `doSomething`, they should be called `do_something`.
 - function and variable names should be descriptive. `i`/`j`/`k`, `buf`, and `tmp`/`temp` are common shorthands for index, buffers, and temporary variables, but other intentions should be explicitly declared through the name.
 - pointer stars should be declared next to the variable name, not the type
 - brackets start on the same line as their context. there are 3 major ways of styling brackets, but this is the most common in c programming.
 - a line should not exceed 78 characters. use backslashes to separate tokens that must go on the same line, if necessary.
 - one statement per line.

these are not hard rules and will be enforced fairly loosely, but consistently bad formatting will result in docking of points.

## part 1: simple loops and strings `[4 + 1]`

string manipulation is different in c compared to other languages as it provides fewer high-level interfaces to do so. a string is essentially an array of bytes (or characters), terminated with the `\0` byte. they can be created and manipulated manually or via functions in [`string.h` <img src="resources/link.png" width="12" height="12">](https://man7.org/linux/man-pages/man0/string.h.0p.html), and the `%s` format specifier can be used to print them out via [`printf` <img src="resources/link.png" width="12" height="12">](https://man7.org/linux/man-pages/man3/printf.3.html).

the provided template will print out a "hello world" message with the [process id <img src="resources/link.png" width="12" height="12">](https://man7.org/linux/man-pages/man2/getpid.2.html) of the running program. your task is to transform this into a simple "fizzbuzz" program. it must conform to the follow specification:

 - it must print out each number from 1 to 100. `[1]`
 - every multiple of 3 must have the word "fizz" to its right, and every multiple of 5 must have the word "buzz" to its right. `[1]`
 - multiples of both must have "fizzbuzz" to their right. `[1]`
 - extra credit: a particularly concise or unique solution. `[1]`

example program output:

```
1
2
3 fizz
4
5 buzz
6 fizz
7
8
9 fizz
10 buzz
11
12 fizz
13
14
15 fizzbuzz
```

## part 2: file i/o `[5 + 1]`

file i/o in c follows roughly the same flow as in other languages: open a file buffer, read or write, and close the buffer. programmatically, this follows the order of opening using the [`fopen` <img src="resources/link.png" width="12" height="12">](https://man7.org/linux/man-pages/man3/fopen.3.html), reading with [`fgets` <img src="resources/link.png" width="12" height="12">](https://man7.org/linux/man-pages/man3/fgets.3p.html) or writing with [`fprintf` <img src="resources/link.png" width="12" height="12">](https://man7.org/linux/man-pages/man3/fprintf.3p.html), then closing with [`fclose` <img src="resources/link.png" width="12" height="12">](https://man7.org/linux/man-pages/man3/fclose.3.html). 

the provided template reads from `README.md` (this file), prints out the number of lines to standard output, and writes each character's numeric to `out.md`, overwriting the original file if it exists. your task is to transform this into a word-reversal program that reads `README.md` and processes its content, outputting to `out.md`. it must conform to the following specification:
 - `out.md` must have the same number of characters as `README.md`. `[1]`
 - every word (group of alphabetical characters) in `out.md` must be reversed. numbers, spaces, and special characters do not count. overall order of words must be preserved. `[3]`
 - file handles need to be properly closed. `[1]`
 - extra credit: source file is 25 lines of code or less (excluding whitespace, function headers, brackets) `[1]`

first line of an example `out.md`:
```
# esicrexe 1: ortni ot c `[11 + 3]`
```

## part 3: user cli input `[6 + 1]`

in order to get the user input from the standard input, it is important to note that in the context of linux, the standard input/output/errors are considered file streams. any file with an open [buffer <img src="resources/link.png" width="12" height="12">](https://tldp.org/LDP/sag/html/buffer-cache.html) is considered a file stream and may be read from or written to depending on the associated read/write permissions. this is all to say that reading from `stdin` in c is essentially the same as reading from a file, and `stdout`/`stderr` are writable. this means you can also use `fgets` to read from the standard input, and `fprintf` to write to the standard output and error (in fact, `printf` is just a shorthand for it).

the provided template takes a user input and [echoes <img src="resources/link.png" width="12" height="12">](https://man7.org/linux/man-pages/man1/echo.1.html) it back to the user. your task is to transform this into a fizzbuzz program whose output is dependent on user input. you are free to reuse code from part 1, and you may use `string.h`. in addition to the previous fizzbuzz specs, it must conform to the follow specification:

 - it must accept 3 user inputs: any number of loops (greater than 1), a "fizz", and a "buzz". `[2]`
 - there should be sanity checking for the loop input; the program should either exit or reprompt if it is not a positive integer. `[1]`
 - the program should print out every number from 1 to the number of loops. `[1]`
 - the "fizz" input will replace the existing printed "fizz", and likewise for the "buzz". `[2]`
 - extra credit: no use of `string.h`. `[1]`

example program output:

```
loops: 10
fizz: a
buzz: b
1
2
3 a
4
5 b
6 a
7
8
9 a
10 b
```

## part 4: simple pointers and dynamic memory allocation on the heap `[8]`

as mentioned previously, strings are just arrays of characters, and in the same vein, arrays are just references to blocks of memory. this introduces several problems in c; there is no inherent length attribute associated with arrays, and you can't pass all of the data in an array as an argument to a function.

c does, however, have the concept of [pointers <img src="resources/link.png" width="12" height="12">](https://www.cs.yale.edu/homes/aspnes/pinewiki/C%282f%29Pointers.html), which are just memory addresses *pointing* to a location in memory. what you see as an array is itself just a pointer to the start of a section of program memory, meaning an array of integers is functionally equivalent to an integer pointer. this allows us to pass arrays to functions. the following is a code example of pointer creation and usage:

```c
int x = 0;         // create a local int variable x
int* y = 0;        // create a pointer from x
*y = 1;            // set the referenced value of y to 1
(*y)++;            // increment the referenced value of y
printf("%d\n", x)  // print the value of x, which at this point is 2
```

in speaking of program memory, it is important to understand the memory layout of a c program. this diagram from [uiuc's cs 225 program](https://courses.grainger.illinois.edu/cs225/fa2023/resources/stack-heap/) illustrates the basic idea:

<img src="resources/uiuc_memory_layout.png" width="358" height="368">

the text section (`.text`, or the [code segment <img src="resources/link.png" width="12" height="12">](https://en.wikipedia.org/wiki/Code_segment)) is a read-only part of the program that contains its executable instructions. the initialized data (`.data`, or the [data segment <img src="resources/link.png" width="12" height="12">](https://en.wikipedia.org/wiki/Data_segment)) contains all global and static variables (read-write) that have been initialized, including string literals (read-only). the uninitialized data (`.bss`, or [block starting symbol <img src="resources/link.png" width="12" height="12">](https://en.wikipedia.org/wiki/.bss)) holds global or static variables that have *not* been initialized, including variables with an implicit value of 0. the stack (or the [call stack <img src="resources/link.png" width="12" height="12">](https://en.wikipedia.org/wiki/Call_stack)) stores information about functions, including local variables. its current location is kept track of via the [stack pointer <img src="resources/link.png" width="12" height="12">](https://en.wikipedia.org/wiki/Stack_register). the stack typically has a limited amount of memory, and the stack pointer leaving the bounds of the stack is an error typically called a [stack overflow <img src="resources/link.png" width="12" height="12">](https://stackoverflow.com/). the remaining portion of memory is the heap. memory accesses and writes to the heap are generally much slower than the stack and data segments, but the heap also typically has significantly more memory than the stack, so managed memory is delegated to the heap.

c provides reasonably simple interfaces for memory management in [`stdlib.h` <img src="resources/link.png" width="12" height="12">](https://man7.org/linux/man-pages/man0/stdlib.h.0p.html): [malloc <img src="resources/link.png" width="12" height="12">](https://man7.org/linux/man-pages/man3/malloc.3.html) and [free  <img src="resources/link.png" width="12" height="12">](https://man7.org/linux/man-pages/man1/free.1.html). `malloc` reserves the specified number of bytes on the heap and returns a pointer to it, and `free` will return that memory to the heap. keep in mind that old memory may be reused and that memory is not implicitly reset. example usage shown below:

```c
int* arr = (int*) malloc(512 * sizeof(int)) // allocate a 500 x 4 byte memory block, or a 500-length integer array
for (int i = 0; i < 500; ++i) {
    arr[i] = 2 * i;                         // assign each index of the array with its index times 2
}
for (int i = 499; i >= 0; --i) {
    printf("%d ", arr[i]);                  // print out even numbers from 0-999, in reverse order
}
printf("\n");
free(arr);                                  // return arr's memory allocation to the heap
```

up until now you have likely been using mostly stack memory with memory allocations hidden from you, but for more dynamic tasks these functions will be required. this assignment will effectively force you to use dynamic memory. the provided template contains a mostly main function with a single helper function that verifies numeric ordering of an array. your task is to create a program that generates a random 10000000 (10 million) integer array and sort it in ascending order. you may choose to use any sorting algorithm you wish, but don't bother with a complex one. it must conform to the following specification:

 - complete the `generate_array` function, which generates a randomized array of positive integers of the specified length. `[3]`
 - complete the `sort_array` function, which must sort the array in ascending order. a point is lost by default for using a selection-based sort. `[4]`
 - any heap memory used must be freed. you can use [valgrind <img src="resources/link.png" width="12" height="12">](https://valgrind.org/) to find memory leaks. `[1]`

## challenge 1: heapsort `[6]`

heapsort is a sorting algorithm that utilizes a trick with how data is organized to achieve faster sort times (on average) than insertion or selection sorts. heapsort follows the following procedure:

1. create a heap out of the input array, and keep track of its `size`. this is an implicit data structure where, assuming 0-indexing, a value at index `i` is always greater than its child values at indices `2i + 1` and `2i + 2`, meaning the first element is always the largest element in the array.
2. swap the first and last elements of the array, and decrease the considered `size` of the heap by 1.
3. sift the new first element of the array down, swapping with the larger of its two children until it is greater than both of its child values.
4. repeat from step 2 until `size` is 1.

the big-O [time complexity <img src="resources/link.png" width="12" height="12">](https://en.wikipedia.org/wiki/Time_complexity) of heapsort is O(n log n). time complexity describes the amount of time an algorithm would be expected to take. it counts the number of "basic" or elementary operations which are assumed to take a fixed amount of time, and extrapolates it to an input of a particular size, usually `n`. it is effectively expected time as a function of input size, although time complexity is not the end-all be-all of performance.

the provided template is nearly identical to the one in p4, with the exceptions of the `sift_down` and `heapify` functions that you must implement. you may copy your `generate_array` over from p4. it must conform to the follow specification:

 - the `heapify` function must convert the input array into a heap, where any value with index `i` is always greater than its child values at indices `2i + 1` and `2i + 2`. this must run in `O(n)` time. `[2]`
 - the `sift_down` function must take the current first element of the heap, and move it down the heap until the heap property is satisfied again. because the *depth* of a heap is bounded logarithmically, this must run in `O(n log n)` time. `[2]`
 - the output array must be sorted. `[1]`
 - any heap memory used must be freed. `[1]`