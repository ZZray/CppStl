project(array)
message("Source code:" ${SRCS})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(${PROJECT_NAME} main.cc)
# visual studio
#add_compile_options("/sdl")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /sdl")
target_compile_options(array PRIVATE "/sdl")