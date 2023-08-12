This repository is designed to house computer programs that either simulate or solve problems that one might encounter in a Chemistry, Physics, Engineering or Mathematics textbook.

# INSTALL

- Clone this repository.
- To build this project you will need to have CMake installed. If you have brew you can just use the command `brew install cmake` to install it.
- You will also need gflw installed so just  use the command `brew install glfw`.
- Once that is completed create a build directory with `mkdir build` while in the main science folder and navigate to it with `cd build`.
- Then do `cmake .` and finally `make`.
- You can then run the main application with `./science-main` or the test's with `./science-test`.