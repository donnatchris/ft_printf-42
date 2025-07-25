##### [🇫🇷 Version française](README.fr.md) / [🇬🇧 English version](README.md)

# PROJECT FT_PRINTF FOR 42
By chdonnat (Christophe Donnat from 42 Perpignan, France)


## AIM OF THE PROJECT
You will discover a popular and versatile C function: printf(). This exercise is a great
opportunity to improve your programming skills. It is of moderate difficulty.
You will discover variadic functions in C.
The key to a successful ft_printf is a well-structured and extensible code.

You have to recode the printf() function from libc.
The prototype of ft_printf() is:
int ft_printf(const char *, ...);
Here are the requirements:
• Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().
• You must use the command ar to create your library.
Using the libtool command is forbidden.
• Your libftprintf.a has to be created at the root of your repository

You have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadec
• %% Prints a percent sign.

## BONUS

You don’t have to do all the bonuses.
Bonus list:
• Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)

**Note:** I did not make the bonus part for thos project

## DOCUMENTATION

### variadic functions
Variadic functions are functions in programming that can accept a variable number of arguments.
This allows you to write functions that do not require you to define a fixed number of parameters in advance.
In languages like C, variadic functions are typically implemented using the stdarg.h library, which provides macros to handle the arguments.

To define a variadic function in C, you use an ellipsis (...) in the function's parameter list to indicate that the function can accept additional arguments.
For example, the standard library function printf is variadic, as it accepts a variable number of arguments depending on the format string.

Inside the function, the stdarg.h macros (va_start, va_arg, and va_end) are used to access the variable arguments.
- **va_start** initializes the argument list
- **va_arg** retrieves each argument
- **va_end** cleans up the list after processing.

Variadic functions are particularly useful when you do not know the number of arguments at compile time, making them ideal for situations like formatting output or handling user input where the number of items can vary. However, care should be taken when using them, as there's no built-in type safety or argument validation, which can lead to errors if the number of arguments doesn't match the expectations of the function.

### va_list:
This is a type that holds the information necessary to access the variable arguments.
It's essentially a pointer that will be used to traverse the list of arguments passed to the variadic function.

### va_start:
This macro initializes the va_list variable. You call va_start with two arguments:
- the va_list variable (e.g., args)
- and the last known fixed argument before the variadic arguments start.

This macro sets up the internal structure needed to access the variadic arguments.

### va_arg:
Once the va_list is initialized, you use the va_arg macro to access each individual argument.
You pass va_list as the first argument to va_arg, and you also specify the type of the argument you want to retrieve
(since the compiler doesn’t know the type of the variadic arguments). Each call to va_arg retrieves the next argument in the list.

### va_end:
After all the variadic arguments have been processed, you must call va_end to clean up.
This macro is used to perform any necessary cleanup related to the va_list. It is important to always call va_end to avoid memory or resource leaks.
