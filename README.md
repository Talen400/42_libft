# Libft - 42 School Library

## 📚 Overview

This is my personal C library containing basic functions for my projects at 42 School. The library includes recreations of standard C library functions (with `ft_` prefix) and additional utility functions.

## 🏗️ Structure

### Part 1 - Libc Functions
Recreation of standard C library functions

#### 🔤 Character Functions
- `ft_isalpha` - Check if character is alphabetic
- `ft_isdigit` - Check if character is numeric  
- `ft_isalnum` - Check if character is alphanumeric
- `ft_isascii` - Check if character is ASCII
- `ft_isprint` - Check if character is printable
- `ft_toupper` - Convert to uppercase
- `ft_tolower` - Convert to lowercase

#### 📝 String Functions
- `ft_strlen` - Calculate string length
- `ft_strchr` - Locate character in string
- `ft_strrchr` - Locate character in string (from end)
- `ft_strncmp` - Compare strings up to n characters  
- `ft_strnstr` - Locate substring in string
- `ft_strlcpy` - Copy string with size limit
- `ft_strlcat` - Concatenate strings with size limit

#### 🧠 Memory Functions
- `ft_memset` - Fill memory with constant byte
- `ft_bzero` - Zero out memory
- `ft_memcpy` - Copy memory area
- `ft_memmove` - Copy memory area (handles overlap)
- `ft_memchr` - Scan memory for character
- `ft_memcmp` - Compare memory areas

#### 🔄 Conversion Functions
- `ft_atoi` - Convert string to integer
- `ft_calloc` - Allocate and zero memory  
- `ft_strdup` - Duplicate string

### Part 2 - Additional Functions
Original utility functions

- `ft_substr` - Extract substring
- `ft_strjoin` - Concatenate two strings
- `ft_strtrim` - Trim characters from string ends
- `ft_split` - Split string by delimiter
- `ft_itoa` - Convert integer to string
- `ft_strmapi` - Apply function to each character
- `ft_striteri` - Apply function to each character (with index)
- `ft_putchar_fd` - Output character to file descriptor
- `ft_putstr_fd` - Output string to file descriptor  
- `ft_putendl_fd` - Output string + newline to file descriptor
- `ft_putnbr_fd` - Output integer to file descriptor

### 🎁 Bonus Part - Linked Lists
Functions for manipulating linked lists

- `ft_lstnew` - Create new list element
- `ft_lstadd_front` - Add element to front of list
- `ft_lstsize` - Count elements in list  
- `ft_lstlast` - Get last element of list
- `ft_lstadd_back` - Add element to back of list
- `ft_lstdelone` - Delete single element
- `ft_lstclear` - Delete and free entire list
- `ft_lstiter` - Apply function to each element
- `ft_lstmap` - Apply function and create new list

## 🛠️ Usage

1. Clone this repository
2. Run `make` to compile the library (libft.a)
3. Include `libft.h` in your project
4. Link with `-lft -L/path/to/libft` during compilation

## 📜 License

This project is part of the 42 School curriculum. Usage may be restricted to educational purposes.
