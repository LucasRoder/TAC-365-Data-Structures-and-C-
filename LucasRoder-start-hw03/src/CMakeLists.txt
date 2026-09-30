# If you create new headers/cpp files, add them to these list!
set(HEADER_FILES
	money.h
	stock.h
	portfolio.h
	driver.h
	strlib.h
)

set(SOURCE_FILES
	money.cpp
	stock.cpp
	portfolio.cpp
	driver.cpp
	strlib.cpp
)

# Don't change this
add_library(src ${SOURCE_FILES} ${HEADER_FILES})
