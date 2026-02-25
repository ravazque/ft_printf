
# ft_printf

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

- **Description:** Formatted output function that mimics the standard printf
- **Parameters:** Format string followed by variable arguments
- **Return:** Number of characters printed, or -1 on error
- **Files:** `ft_printf.c`, `ft_printf.h`
- **Buffer optimization:** Uses a 1024-byte buffer (`BUFFER_SIZE`) to minimize system calls and improve performance
- **Flags support:** Implements various formatting flags (-, 0, ., #, space, +) and width/precision modifiers

<br>

```c
int ft_printf(const char *format, ...);
```

### Use of variadic arguments
The implementation of **ft_printf** requires handling an indefinite number of arguments. For this, macros from the **`<stdarg.h>`** library are used, which allows to access and manage these arguments efficiently.

The main macros are:

- **`va_start`** ➜ Initializes the variable argument list. It must be used with a **`va_list`** and the last fixed parameter of the function must be specified.

````c
va_start(ap, format);
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

### Buffer Management

The implementation uses an internal buffer structure to optimize output operations:

```c
typedef struct s_buffer
{
    char    data[BUFFER_SIZE];  // 1024-byte buffer
    int     index;              // Current position in buffer
    int     total;              // Total characters written
}   t_buffer;
```

This approach significantly reduces the number of `write()` system calls, improving overall performance.

</details>

<details>
<summary><strong>Format Specifiers</strong></summary>

### Supported Conversions

- `%c` ➜ Prints a single character.
- `%s` ➜ Prints a string.
- `%p` ➜ Prints a pointer in hexadecimal format (with 0x prefix).
- `%d` | `%i` ➜ Prints integers in base 10.
- `%u` ➜ Prints an unsigned number in base 10.
- `%x` ➜ Prints a lowercase hexadecimal number.
- `%X` ➜ Prints an uppercase hexadecimal number.
- `%%` ➜ Prints the symbol `%`.

</details>

<details>
<summary><strong>Formatting Flags</strong></summary>

### Supported Flags

The implementation supports various formatting flags that modify the output:

```c
typedef struct s_flags
{
    int minus;      // Left-justify (-)
    int zero;       // Zero-padding (0)
    int dot;        // Precision specified (.)
    int hash;       // Alternative form (#)
    int space;      // Space before positive numbers
    int plus;       // Show sign for numbers (+)
    int width;      // Minimum field width
    int precision;  // Precision for numbers/strings
}   t_flags;
```

**Flag Behaviors:**
- `-` (minus) ➜ Left-justify within the given field width
- `0` (zero) ➜ Pad with zeros instead of spaces
- `.` (dot) ➜ Specify precision for numbers or maximum width for strings
- `#` (hash) ➜ Use alternative form (0x for hex, 0X for HEX)
- ` ` (space) ➜ Print a space before positive numbers
- `+` (plus) ➜ Always print sign (+ or -) for numbers

**Examples:**
```c
ft_printf("%5d", 42);      // "   42" (width 5, right-justified)
ft_printf("%-5d", 42);     // "42   " (width 5, left-justified)
ft_printf("%05d", 42);     // "00042" (width 5, zero-padded)
ft_printf("%+d", 42);      // "+42" (show sign)
ft_printf("% d", 42);      // " 42" (space before positive)
ft_printf("%#x", 42);      // "0x2a" (hex with prefix)
ft_printf("%.5d", 42);     // "00042" (precision 5)
ft_printf("%10.5d", 42);   // "     00042" (width 10, precision 5)
```

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
│  ├── ft_printf.h                      # Mandatory header
│  └── ft_printf_bonus.h                # Bonus header with t_flags and t_buffer
├──┬ src/
│  ├── buffer.c                         # Mandatory: buffer management
│  ├── ft_printf.c                      # Mandatory: main printf function
│  ├── print_char.c                     # Mandatory: character and string printing
│  ├── print_hex.c                      # Mandatory: hexadecimal printing
│  ├── print_number.c                   # Mandatory: signed/unsigned number printing
│  ├── print_ptr.c                      # Mandatory: pointer printing
│  ├── buffer_bonus.c                   # Bonus: buffer management
│  ├── flags_bonus.c                    # Bonus: flag parsing
│  ├── format_helpers_bonus.c           # Bonus: padding and sign helpers
│  ├── ft_printf_bonus.c                # Bonus: main printf with flag dispatch
│  ├── print_char_bonus.c               # Bonus: char/string/percent with flags
│  ├── print_hex_bonus.c                # Bonus: hex with flags and # prefix
│  ├── print_number_bonus.c             # Bonus: signed number with flags
│  ├── print_ptr_bonus.c                # Bonus: pointer with width flag
│  ├── print_unsigned_bonus.c           # Bonus: unsigned number with flags
│  └── utils_bonus.c                    # Bonus: utility functions
├── Makefile                            # Compilation rules (all, bonus, clean, fclean, re)
└── README.md                           # Project documentation
```

<br>

</details>

## 💡 Key Learning Outcomes

The ft_printf project teaches advanced C programming concepts:

- **Variadic Functions**: Understanding how to create functions that accept variable arguments using `<stdarg.h>`
- **Format String Parsing**: Learning to systematically parse and interpret format specifications with flags
- **Type System Understanding**: Deep knowledge of C data types and their representations in memory
- **Buffer Optimization**: Implementing efficient I/O operations by minimizing system calls
- **Modular Design**: Creating an extensible system that can handle multiple format types
- **Flag Processing**: Implementing width, precision, and various formatting flags (-, 0, ., #, space, +)
- **Edge Case Management**: Handling undefined behaviors, null pointers, and special cases

## ⚙️ Technical Specifications

- **Language**: C (C90 standard)
- **Compiler**: cc with flags `-Wall -Wextra -Werror`
- **Library Type**: Static library (libftprintf.a)
- **Buffer Size**: 1024 bytes (`BUFFER_SIZE`) for optimized I/O operations
- **Memory Management**: Stack-based buffer with minimal dynamic allocation
- **Dependencies**: Only standard C library functions (`write`, `malloc`, `free`)
- **Return Value**: Number of characters printed, or -1 on error
- **Features**: Supports format flags (-, 0, ., #, space, +), width, and precision modifiers


---

> [!NOTE]
> This project serves as the foundation for all subsequent 42 projects and demonstrates proficiency in low-level C programming concepts.
