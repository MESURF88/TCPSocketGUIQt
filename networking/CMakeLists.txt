# Create a library called "networking"
# which includes the source files and include files
# The extension is already found. Any number of sources could be listed here.

# include files
set(include
  ${CMAKE_CURRENT_SOURCE_DIR}/inc/
)

# source files
set(source
 ${CMAKE_CURRENT_SOURCE_DIR}/src/UDPClient_Support.cpp
 ${CMAKE_CURRENT_SOURCE_DIR}/src/UDPClient.cpp
)

add_library (networking ${source})

target_include_directories (networking PUBLIC ${include})

target_link_libraries(networking PUBLIC Qt5::Network)

message("-- All subdir files SUCCESSFULLY linked")
