# ft_printf
The **ft_printf** project consists of the creation of a function that replicates the behavior of the standard **printf** function in C. The main objective of this project is to learn how to work with functions that accept an indefinite number of arguments by using variadic functions in C.
  
‎

## Functionality
The **ft_printf** function not only prints characters, but also returns the number of characters printed. For example, in the call:

`printf(“Hello %s”, “world”);`
It will print: `Hello world`, and return the value **10**, which is the total number of characters printed.

‎

## Supported formats
The behavior of the **ft_printf** function will depend on the format specifiers in the input string. These are the formats you will need to implement:
- `%c` ➜ Prints a single character.
- `%s` ➜ Prints a string.
- `%p` ➜ Prints a pointer in hexadecimal format.
- `%d` | `%i` ➜ Prints integers in base 10.
- `%u` ➜ Prints an unsigned number in base 10.
- `%x` ➜ Prints a lowercase hexadecimal number.
- `%X` ➜ Prints an uppercase hexadecimal number.
- `%%` ➜ Prints the symbol `%`.
These are the required formats for the mandatory version of **ft_printf**. The project can be expanded with additional functions if you decide to make the **bonus**.

‎

## Use of variadic arguments
The implementation of **ft_printf** requires handling an indefinite number of arguments. For this, macros from the **`<stdarg.h>`** library are used, which allows to access and manage these arguments efficiently.
The main macros are:
- **`va_start`** ➜ Initializes the variable argument list. It must be used with a **`va_list`** and the last fixed parameter of the function must be specified.
    ```c
    va_start(ap, n);
    ```
- **`va_arg`** ➜ Retrieves the next argument from the list, specifying its type.
    ```c
    int x = va_arg(ap, int);
    ```
- **``va_copy`** ➜ Creates a copy of the variable argument list.
    ```c
    va_copy(copy, ap);
    ```
- **`va_end`** ➜ Frees the resources used by **`va_list`** at the end of argument processing.
    ```c
    va_end(ap);
    ```
These macros are essential for implementing functions such as **ft_printf**, as they allow you to manage a list of parameters that can vary in number and type.

‎

----
> [!NOTE]
> **ft_printf** is a fundamental project to understand variadic functions in C and will help us to improve our programming skills for future more complex projects.
