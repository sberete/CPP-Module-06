# CPP-Module-06

This project is part of the 42 school C++ curriculum. It focuses on C++ casts and how to convert between types safely.

## Exercises

- **ex00** — Implements a `ScalarConverter` that converts a literal representing a `char`, `int`, `float`, or `double` into each of the other types, correctly handling edge cases (overflow, `nan`, `inf`, non-displayable characters).
- **ex01** — Implements a `Serializer` that converts a pointer to an integer type (`uintptr_t`) and back, demonstrating pointer-to-integer serialization/deserialization without any loss of data.
- **ex02** — Implements a simplified Run-Time Type Identification mechanism with a `Base` class and derived classes `A`, `B`, and `C`, using `dynamic_cast` to identify the real type of an object at runtime (both with pointers and references).

- ## Build

- Each exercise has its own Makefile:
- ```
  cd ex00 && make   # builds the ex00 executable
  ```
  Repeat inside `ex01` and `ex02` as needed. Use `make clean`, `make fclean`, or `make re` to clean/rebuild.

  ## Constraints

  - Follows the 42 Norm
  - Compiles without errors or warnings (`-Wall -Wextra -Werror`)
  - Written in C++98
