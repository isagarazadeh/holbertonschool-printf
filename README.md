# printf Implementation README

## Overview
This repository contains an implementation of the _printf function, which generates output based on a specified format. The function supports various format specifiers, such as %c for characters, %s for strings, %d for decimals, and %i for integers.

## Function Signature
```int _printf(const char *format, ...);```

## Execution Instructions
To execute the _printf function in your program, follow these steps:
1. Include the Header File:
Include the header file "your_header_file.h" in your source file, where you intend to use the _printf function.
```#include "your_header_file.h"```
2. Call the _printf Function:
Use the _printf function in your code with the desired format specifier and arguments. Here's an example:
```
int main(void) {
    _printf("Displaying a straightforward sentence.\n");
    return 0;
}
```
3. Compile Your Code:
Compile your source code, linking it with the implementation files. For example, if your source file is "main.c" and the implementation files are "print_char.c," "print_string.c," "print_decimal.c," and "your_header_file.h," you can compile using:
```gcc -o your_program main.c print_char.c print_string.c print_decimal.c```
4. Run Your Executable:
```./your_program```

## Usage
### Basic Example
```
#include "your_header_file.h"

int main(void) {
    _printf("Displaying a straightforward sentence.\n");
    return 0;
}
```
Output:
```Displaying a straightforward sentence.```

## Format Specifiers
- %c: Represents a character.
- %s: Represents a string.
- %d: Represents a decimal.
- %i: Represents an integer.

Example:
```
#include "your_header_file.h"

int main(void) {
    _printf("%s", "This sentence is extracted from va_args!\n");
    return 0;
}
```
Output:
```This sentence is extracted from va_args!```

## Return Value
The function returns the count of characters printed, excluding the null byte used to terminate output to strings.

## Error Handling
In the event of incorrect type usage, the function will return an error.

## Implementation Details

The implementation includes the following source files:

- _putchar.c: Contains the implementation of the _putchar function.
- print_char.c: Contains the implementation of the function to print characters (%c).
- print_string.c: Contains the implementation of the function to print strings (%s).
- print_decimal.c: Contains the implementation of the functions to print decimals (%d and %i).

## Bugs
No known bugs at the moment.

## Authors
- Isa Garazadeh
- Gunay Gasimova
