cmake_minimum_required(VERSION 2.9)

set(TARGET_BUILD_PLATFORM x64)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(ARViewer)

# Add QT: 
set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.7.0/5.7/msvc2015_64/")
set(CMAKE_LIBRARY_PATH "C:/Program Files (x86)/Windows Kits/8.0/Lib/win8/um/x64")
set(QTBIN_PATH "C:/Qt/Qt5.7.0/5.7/msvc2015_64/bin/")
find_package(Qt5Widget)
find_package(Qt5Gui)
find_package(Qt5Xml)
find_package(Qt5OpenGL)

file(GLOB ARVIEWER_SRC
	./src/*.h
	./src/*.cpp
)
add_executable(ARViewer ${ARVIEWER_SRC})

if(MSVC AND OpenCV_STATIC)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
endif()

target_link_libraries(ARViewer  
	Qt5::Widgets
	Qt5::Xml
	Qt5::Core
	Qt5::Gui
	Qt5::OpenGL
)

set(BINARY_DEBUG_DIR ${PROJECT_BINARY_DIR}/Debug/)
set(BINARY_RELEASE_DIR ${PROJECT_BINARY_DIR}/Release/)
file(MAKE_DIRECTORY ${BINARY_DEBUG_DIR})
file(MAKE_DIRECTORY ${BINARY_RELEASE_DIR})

file(GLOB DLL_FILES_DEBUG
	${QTBIN_PATH}/icu*.dll
	${QTBIN_PATH}/Qt5Cored.dll
	${QTBIN_PATH}/Qt5Guid.dll
	${QTBIN_PATH}/Qt5OpenGLd.dll
	${QTBIN_PATH}/Qt5Widgetsd.dll
	${QTBIN_PATH}/Qt5Xmld.dll
)
file(GLOB DLL_FILES_RELEASE
	${QTBIN_PATH}/icu*.dll
	${QTBIN_PATH}/Qt5Core.dll
	${QTBIN_PATH}/Qt5Gui.dll
	${QTBIN_PATH}/Qt5OpenGL.dll
	${QTBIN_PATH}/Qt5Widgets.dll
	${QTBIN_PATH}/Qt5Xml.dll
)
file(COPY ${DLL_FILES_DEBUG} DESTINATION ${BINARY_DEBUG_DIR})
file(COPY ${DLL_FILES_RELEASE} DESTINATION ${BINARY_RELEASE_DIR})

file (GLOB DATA_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/data/*.*
)
file (COPY ${DATA_FILES} DESTINATION ${PROJECT_BINARY_DIR}/data/)

