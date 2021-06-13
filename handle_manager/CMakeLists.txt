# Create a library called "handle_manager"
# which includes the source files and include files
# The extension is already found. Any number of sources could be listed here.

# include files
set(include
  ${CMAKE_CURRENT_SOURCE_DIR}/inc/
)

# source files
set(source
 ${CMAKE_CURRENT_SOURCE_DIR}/src/handle_manager.cpp
)

add_library (handle_manager ${source})

target_include_directories (handle_manager PUBLIC ${include})

target_link_libraries(handle_manager PUBLIC Qt5::Core)

message("-- Handle Manager subdir files SUCCESSFULLY linked")
