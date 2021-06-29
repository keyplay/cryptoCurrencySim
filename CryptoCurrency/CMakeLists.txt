# CMakeList.txt : CMake project for CryptoCurrency, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(CryptoCurrency)

find_package(cryptopp CONFIG REQUIRED)

# Add source to this project's executable.
file(GLOB SOURCES "src/*.cpp")
add_executable (${PROJECT_NAME} ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

# link against libraries
target_link_libraries(CryptoCurrency PRIVATE cryptopp-static)
# TODO: Add tests and install targets if needed.