# Create a library called "epoch_timer"
# which includes the source files and include files
# The extension is already found. Any number of sources could be listed here.

# include files
set(include
  ${CMAKE_CURRENT_SOURCE_DIR}/inc/
)

# source files
file(GLOB_RECURSE source
 ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library (epoch_timer ${source})

target_include_directories (epoch_timer PUBLIC ${include})

target_link_libraries(epoch_timer PUBLIC Qt5::Core)

message("-- Epoch Timer subdir files SUCCESSFULLY linked")
