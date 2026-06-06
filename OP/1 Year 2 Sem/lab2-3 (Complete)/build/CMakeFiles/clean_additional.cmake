# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\core_logic_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\core_logic_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\lab2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\lab2_autogen.dir\\ParseCache.txt"
  "core_logic_autogen"
  "lab2_autogen"
  )
endif()
