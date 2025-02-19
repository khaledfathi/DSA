cmake_minimum_required(VERSION 3.10)  # Or higher if needed
project(DSA)  # Replace with your project name

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the executable
add_executable(run_dsa# Replace with your executable name
    main.cpp
    src/exceptions/dsa_exceptions.cpp
)

# Optional: Add compiler flags (e.g., warnings)
# target_compile_options(YourExecutableName PRIVATE -Wall -Wextra)

# Optional: Set output directory for the executable
# set_target_properties(YourExecutableName PROPERTIES OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Optional: Install target (for packaging)
# install(TARGETS YourExecutableName DESTINATION bin)