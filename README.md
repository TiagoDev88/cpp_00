# CPPs - C++ Learning Journey at 42

This repository contains my solutions for the C++ modules at 42 school. Each module focuses on different aspects of C++ programming, helping to build a strong foundation in object-oriented programming.

## 📚 Modules Overview

### CPP 00 - Introduction to C++
**Topics**: Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and basic concepts

**Exercises**:
- **ex00**: Megaphone - Basic string manipulation and I/O operations
- **ex01**: PhoneBook - First class implementation with member functions and data encapsulation
- **ex02**: Account - Working with timestamps, static members, and logging

### CPP 01 - Memory Allocation
**Topics**: Memory allocation, pointers to members, references, switch statements

**Exercises**:
- **ex00**: BraiiiiiiinnnzzzZ - Stack vs heap allocation
- **ex01**: Moar brainz! - Dynamic array allocation (zombie horde)
- **ex02**: HI THIS IS BRAIN - Understanding pointers and references
- **ex03**: Unnecessary violence - References and object composition
- **ex04**: Sed is for losers - File manipulation and string replacement
- **ex05**: Harl 2.0 - Member function pointers
- **ex06**: Harl filter - Switch statements and filtering

### CPP 02 - Ad-hoc Polymorphism & Orthodox Canonical Form
**Topics**: Ad-hoc polymorphism, operator overloading, Orthodox Canonical class form

**Exercises**:
- **ex00**: My First Class in Orthodox Canonical Form - Fixed-point number class basics
- **ex01**: Towards a more useful fixed-point number class - Conversion and output operators
- **ex02**: Now we're talking - Arithmetic and comparison operators
- **ex03**: BSP - Binary Space Partitioning (point in triangle algorithm)

### CPP 03 - Inheritance
**Topics**: Inheritance, derived classes, access specifiers

**Exercises**:
- **ex00**: Aaaaand... OPEN! - Base class ClapTrap
- **ex01**: Serena, my love! - ScavTrap derived from ClapTrap
- **ex02**: Repetitive work - FragTrap inheritance
- **ex03**: Now it's weird! - DiamondTrap and multiple inheritance

### CPP 04 - Subtype Polymorphism & Abstract Classes
**Topics**: Subtype polymorphism, abstract classes, interfaces, virtual functions

**Exercises**:
- **ex00**: Polymorphism - Base Animal class with Dog and Cat
- **ex01**: I don't want to set the world on fire - Deep copy and Brain class
- **ex02**: Abstract class - Making Animal an abstract class
- **ex03**: Interface & recap - Materia system with interfaces

## 🛠️ How to Use

Each exercise has its own Makefile. Navigate to the specific exercise directory to compile:

```bash
# Navigate to the desired exercise
cd cpp00/ex00

# Clean previous builds (recommended)
make fclean

# Compile
make

# Run the program
./program_name
```

### Common Make Targets
- `make` or `make all` - Compile the program
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Rebuild everything from scratch

## Author

- TiagoDev88

## License

This project is part of the 42 school curriculum. Please refer to their policies regarding code usage and distribution.