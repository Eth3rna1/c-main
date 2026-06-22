# C-MAIN

## About
A code generation tool used to initialize a new C project

## Usage
```cmd
c-main <PROJECT NAME>
```

Running the previous command generates the following files:

```text
project_name
project_name/src
project_name/include
project_name/tests
project_name/src/main.cpp
project_name/build.py
project_name/.gitignore
```

### Building file
As of now, the generated file to build projects is a `build.py` file. Maybe not
the best decision, but can be easily replaced for a `.cmd`/`.sh`/ or `CMake` file.
