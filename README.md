# UMBC 341 Almes Spring 2018
The provided code is intended for reference for students currently enrolled in 
UMBC's CMSC 341 Data Structures class.

These data structures (and test cases) are not necessarily complete nor optimized for production use.

# Downloading Code
## Option 1 (Preferred) 
Using the git tool.
1. Install '[git](https://git-scm.com/)'
2. Clone this repository via

`git clone https://github.com/almes1/341sp18.git`

## Option 2
From this webpage, select 'Clone or download' -> Download ZIP

# Compiling Code on Gl
1. Copy these files to the linux server
2. ssh into the server via terminal / putty / etc
3. From the directory containing the desired source code run:

`g++ -g *.h *.cpp -o a.out`

This lazy compilation method will grab all h and cpp files in a directory and create an
executable called a.out. To run: `a.out` or `gdb a.out` 

# Running Examples (Linux + CMAKE)
If using a linux machine with [CMAKE](https://cmake.org) installed:
 
```
cd < directory containing this readme >
mkdir build
cd build
cmake ..
make -j4
ArrayList/arrayList
```
## Step by step
1. Move to the directory containing the files that will be used to build the executable.
2. Create a directory to store the binary files (not source files)
3. Move to that directory
4. Initialize the build directory using CMake. CMake is a tool for generating make files and resolving code dependencies 
for multi platform development. It will automatically create makefiles and properly setup targets.
5. run make, but do it fast! This will run make using up to 4 threads.
6. Run the executable. For the arrayList test, it will be in build/ArrayList/. Alternatively
you could run gdb ArrayList/arrayList