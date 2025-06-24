
<p align="center">
  <img src="https://github.com/ayogun/42-project-badges/raw/main/badges/ft_printfe.png" alt="Get Next Line Badge" width="150" height="150">
</p>

## 📖 About

"ft_printf" is a project at 42 Madrid that involves recreating the standard `printf` function from the C library. This project introduces variadic functions, format specifiers, and teaches how to handle different data types and formatting options in a systematic way.

The goal is to implement a function that mimics the behavior of `printf`, supporting various format specifiers and returning the number of characters printed.

## 🎯 Objectives

- Understanding and implementing variadic functions in C
- Learning about format specifiers and string formatting
- Managing different data types and their conversions
- Implementing a modular and extensible parsing system
- Handling edge cases and undefined behaviors

## 📋 Function Overview

<details>
<summary><strong>ft_printf</strong></summary>

### Concepts

**Description:** Formatted output function that mimics the standard printf  
**Parameters:** Format string followed by variable arguments  
**Return:** Number of characters printed, or -1 on error  

```c
int ft_printf(const char *format, ...);
```

### Use of variadic arguments
The implementation of **ft_printf** requires handling an indefinite number of arguments. For this, macros from the **`<stdarg.h>`** library are used, which allows to access and manage these arguments efficiently.

The main macros are:

- **`va_start`** ➜ Initializes the variable argument list. It must be used with a **`va_list`** and the last fixed parameter of the function must be specified.

````c
va_start(ap, n);
````

- **`va_arg`** ➜ Retrieves the next argument of the list, specifying its type.

````c
int x = va_arg(ap, int);
````

- **`va_copy`** ➜ Creates a copy of the variable argument list.

```c
va_copy(copy, ap);
````

- **`va_end`** ➜ Frees the resources used by **`va_list`** at the end of argument processing.

````c
va_end(ap);
````

These macros are essential for implementing functions such as **ft_printf**, since they allow you to manage a list of parameters that can vary in number and type.

</details>

<details>
<summary><strong>Mandatory Conversions</strong></summary>

### Supported Format Specifiers

- `%c` ➜ Prints a single character.
- `%s` ➜ Prints a string.
- `%p` ➜ Prints a pointer in hexadecimal format.
- `%d` | `%i` ➜ Prints integers in base 10.
- `%u` ➜ Prints an unsigned number in base 10.
- `%x` ➜ Prints a lowercase hexadecimal number.
- `%X` ➜ Prints an uppercase hexadecimal number.
- `%%` ➜ Prints the symbol `%`.

</details>

## 🚀 Installation & Structure

<details>
<summary><strong>📥 Download & Compilation</strong></summary>
    
<br>

```bash
# Clone the repository
git clone https://github.com/ravazque/ft_printf.git
cd ft_printf

# Compile the library
make

# Clean object files
make clean

# Clean everything including library
make fclean

# Recompile everything
make re

# Compile with your program
cc -Wall -Wextra -Werror your_program.c libftprintf.a
```

<br>

</details>

<details>
<summary><strong>📁 Project Structure</strong></summary>

<br>

```
ft_printf/
├──┬ include/
│  └── ft_printf.h                      # Header file with prototypes and definitions
├──┬ src/
│  ├── ft_printf.c                      # Main printf function implementation
│  ├── ft_printf_char.c                 # Functions for strings and characters
│  ├── ft_printf_hex.c                  # Functions for hexadecimals
│  ├── ft_printf_number.c               # Functions for numbers
│  └── ft_printf_ptr.c                  # Functions for pointers
├── Makefile                            # Compilation rules
└── README.md                           # Project documentation
```

<br>

</details>

## 💡 Key Learning Outcomes

The ft_printf project teaches advanced C programming concepts:

- **Variadic Functions**: Understanding how to create functions that accept variable arguments
- **Format String Parsing**: Learning to systematically parse and interpret format specifications
- **Type System Understanding**: Deep knowledge of C data types and their representations
- **String Manipulation**: Advanced techniques for building and formatting strings
- **Modular Design**: Creating a extensible system that can handle multiple format types
- **Edge Case Management**: Handling undefined behaviors and special cases

## ⚙️ Technical Specifications

- **Language**: C (C99 standard)
- **Compiler**: cc with flags `-Wall -Wextra -Werror`
- **Memory Management**: Dynamic allocation where necessary, proper cleanup
- **Dependencies**: Only standard C library functions for basic operations
- **Library Type**: Static library (libftprintf.a)
- **Return Value**: Number of characters printed (similar to standard printf)


---

> [!NOTE]
> This project serves as the foundation for all subsequent 42 projects and demonstrates proficiency in low-level C programming concepts.
