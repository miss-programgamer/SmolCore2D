# Project settings
cmake_minimum_required(VERSION 3.29.0)
project(SmolCore2D VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

# Project cache variables
set(SMOL_CORE2D_BUILD_TESTS FALSE CACHE BOOL "Whether unit tests should be built")

# Define main project source files
set(SMOL_CORE2D_SOURCES
	"source/smol/core2d/vec2.hpp"
	"source/smol/core2d/size.hpp"
	"source/smol/core2d/rect.hpp"
	"source/smol/core2d.hpp"
)

# Add main library target
add_library(SmolCore2D INTERFACE)
target_sources(SmolCore2D INTERFACE FILE_SET HEADERS BASE_DIRS "source" FILES ${SMOL_CORE2D_SOURCES})
target_include_directories(SmolCore2D INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/source>")
target_include_directories(SmolCore2D INTERFACE "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

# Unit tests
if (SMOL_CORE2D_BUILD_TESTS)
	# Find our testing framework
	find_package(Catch2 3 REQUIRED)
	include(Catch)
	
	# Add test target and discover tests
	add_executable(SmolCore2DTests "tests/tests.cpp")
	target_link_libraries(SmolCore2DTests PRIVATE Catch2::Catch2WithMain SmolCore2D)
	catch_discover_tests(SmolCore2DTests)
	
	# Enable testing
	include(CTest)
	enable_testing()
endif()

# Packaging settings
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Generate CMake integration scripts
include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

configure_package_config_file("cmake/Config.cmake.in"
	"${CMAKE_CURRENT_BINARY_DIR}/SmolCore2DConfig.cmake"
	INSTALL_DESTINATION "lib/cmake/SmolCore2D"
)

write_basic_package_version_file(SmolCore2DConfigVersion.cmake
	VERSION ${CMAKE_PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
)

# Install targets & scripts
install(TARGETS SmolCore2D EXPORT SmolCore2DTargets LIBRARY DESTINATION ${CMAKE_CURRENT_BINARY_DIR} FILE_SET HEADERS)
install(EXPORT SmolCore2DTargets FILE SmolCore2DTargets.cmake NAMESPACE Smol:: DESTINATION "lib/cmake/SmolCore2D")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/SmolCore2DConfigVersion.cmake" DESTINATION "lib/cmake/SmolCore2D")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/SmolCore2DConfig.cmake" DESTINATION "lib/cmake/SmolCore2D")