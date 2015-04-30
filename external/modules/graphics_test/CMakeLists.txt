set ( SOURCES 
	"src/interface.cpp"
	"src/graphics_test.cpp"
)

set (HEADERS
	"include/graphics_test.h"
)

include_directories("include")

add_library (graphics_test MODULE ${SOURCES} ${HEADERS})
target_link_libraries(graphics_test PRIVATE lms imaging)
