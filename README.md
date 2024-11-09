# Sem07-ProgrammingLanguages

### Course Overview
This repository contains assignments and projects from the **Programming Languages** course taken in my seventh semester. The course introduced concepts around programming language theory, including **compiler design** and **language specialization**. While previous coursework primarily focused on object-oriented languages, this course introduced **functional programming** with **Haskell** and explored how compilers work internally through simulation projects in C++.

### Learning Outcomes
Key skills and concepts developed in this course include:
- Building foundational skills in functional programming, using Haskell to implement various algorithms and exercises.
- Understanding how compilers interpret and process code, including lexical analysis and parsing.
- Implementing components of a compiler in C++ to simulate syntax checking and token recognition.

### Repository Structure

#### 1. Haskell
This directory contains assignments focused on learning the functional programming paradigm using Haskell. Each file demonstrates different aspects of Haskell programming.

   - **Exercises.hs**: Contains various Haskell exercises, including implementing basic modules, creating a custom `gcd` function, and other functional programming concepts.
   - **Fib.hs**: Implements the Fibonacci sequence in Haskell, showcasing recursion and functional style.

#### 2. Codes
This directory contains projects written in C++ to simulate compiler functionalities, focusing on lexical and syntactic analysis.

   - **if-check**:
     - **Description**: A C++ program that simulates an `if` statement parser. This code reads a string representing an `if` statement and interprets it, checking for syntactic correctness.
     - **Usage**: Run the compiled executable, and input a string simulating an `if` statement for the code to parse and check.

   - **scanner**:
     - **Description**: A lexical scanner implemented in C++ that reads and interprets an input file (`input.txt`). The scanner identifies tokens in the code, such as keywords (`if`, `bucle`, `num`, `text`), arithmetic and logical operators, delimiters, and assignments.
     - **File Structure**:
       - `input.txt`: Provides example code for the scanner to process.
       - `Scanner.cpp`: Implements the scanner functionality, reading `input.txt` and interpreting tokens while providing feedback on syntax.
     - **Usage**:
       1. Prepare `input.txt` with the desired code to scan.
       2. Compile `Scanner.cpp`:
          ```bash
          g++ -o scanner Scanner.cpp
          ```
       3. Run the scanner:
          ```bash
          ./scanner
          ```

### Usage Instructions for Haskell and C++ Projects
Each `.hs` and `.cpp` file can be compiled and executed individually:
1. **Haskell Files**:
   - Open a terminal in the `Haskell` directory.
   - Run using GHC (Glasgow Haskell Compiler):
     ```bash
     ghci Exercises.hs  # Loads the file in GHCi for interactive testing
     ghci Fib.hs        # Loads and tests Fibonacci implementation
     ```

2. **C++ Files**:
   - Navigate to the `Codes` directory, then into the subdirectories (`if-check` or `scanner`).
   - Compile the `.cpp` file with a C++ compiler:
     ```bash
     g++ -o output_file_name file_name.cpp
     ```
   - Run the compiled executable:
     ```bash
     ./output_file_name
     ```
