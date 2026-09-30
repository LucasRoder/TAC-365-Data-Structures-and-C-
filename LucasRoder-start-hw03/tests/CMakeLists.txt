# Require CMAKE 3.12 or higher
cmake_minimum_required(VERSION 3.12)

# If you create new headers/cpp files, add them to these list!
set(HEADER_FILES
    catch.hpp
    catch_reporter_github.hpp
)

set(SOURCE_FILES
    Catch.cpp
	StudentTests.cpp
    GradedTests.cpp
)

# Don't change this
add_executable(tests ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(tests src)
