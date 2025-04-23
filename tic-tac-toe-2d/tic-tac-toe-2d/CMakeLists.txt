# CMakeList.txt : CMake project for tic-tac-toe-2d, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (tic-tac-toe-2d "tic-tac-toe-2d.cpp" "tic-tac-toe-2d.h" "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET tic-tac-toe-2d PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
