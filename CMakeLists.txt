#
#  Copyright
#

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(PROJECT_NAME sot-core)
project(${PROJECT_NAME})

SET(PROJECT_VERSION 1.0.0)

SET(CMAKE_VERBOSE_MAKEFILE true)

IF(WIN32)
  SET(LIBDIR_KW "/LIBPATH:")
  SET(LIBINCL_KW "")
  SET(LIB_EXT ".lib")
ENDIF(WIN32)

IF(UNIX)
  SET(LIBDIR_KW "-L")
  SET(LIBINCL_KW "-l")
  SET(LIB_EXT "")
ENDIF(UNIX)

#
# Look for dependencies
#

# Load Pkgconfig macros
INCLUDE(FindPkgConfig)
SET(PACKAGE_REQUIREMENTS "")

#
#  Dependency to package MatrixAbstractLayer
#
SET(MATRIXABSTRACTLAYER_FOUND 0)
SET(MATRIXABSTRACTLAYER_REQUIRED "MatrixAbstractLayer >= 1.8.0")
PKG_CHECK_MODULES(MATRIXABSTRACTLAYER REQUIRED ${MATRIXABSTRACTLAYER_REQUIRED})
EXEC_PROGRAM(${PKG_CONFIG_EXECUTABLE} ARGS  --variable=docdir MatrixAbstractLayer
  OUTPUT_VARIABLE MATRIXABSTRACTLAYER_DOCDIR)
MESSAGE(STATUS "pkg-config: ${PKG_CONFIG_EXECUTABLE}")
MESSAGE(STATUS "MATRIXABSTRACTLAYER_DOCDIR=${MATRIXABSTRACTLAYER_DOCDIR}")
SET(MATRIXABSTRACTLAYER_FOUND 1)

IF(NOT ${MATRIXABSTRACTLAYER_FOUND})
  MESSAGE(FATAL_ERROR "Check that package MatrixAbstractLayer is installed in a directory pointed out by PKG_CONFIG_PATH.")
ENDIF(NOT ${MATRIXABSTRACTLAYER_FOUND})
  
IF(PACKAGE_REQUIREMENTS STREQUAL "")
  SET(PACKAGE_REQUIREMENTS ${MATRIXABSTRACTLAYER_REQUIRED})
ELSE(PACKAGE_REQUIREMENTS STREQUAL "")
  SET(PACKAGE_REQUIREMENTS "${PACKAGE_REQUIREMENTS}, ${MATRIXABSTRACTLAYER_REQUIRED}")
ENDIF(PACKAGE_REQUIREMENTS STREQUAL "")


#
#  Dependency to package dynamicsJRLJapan
#
SET(DYNAMICSJRLJAPAN_FOUND 0)
SET(DYNAMICSJRLJAPAN_REQUIRED "dynamicsJRLJapan >= 1.16.1")
PKG_CHECK_MODULES(DYNAMICSJRLJAPAN REQUIRED ${DYNAMICSJRLJAPAN_REQUIRED})
EXEC_PROGRAM(${PKG_CONFIG_EXECUTABLE} ARGS  --variable=docdir dynamicsJRLJapan
  OUTPUT_VARIABLE DYNAMICSJRLJAPAN_DOCDIR)
MESSAGE(STATUS "pkg-config: ${PKG_CONFIG_EXECUTABLE}")
MESSAGE(STATUS "DYNAMICSJRLJAPAN_DOCDIR=${DYNAMICSJRLJAPAN_DOCDIR}")
SET(DYNAMICSJRLJAPAN_FOUND 1)

IF(NOT ${DYNAMICSJRLJAPAN_FOUND})
  MESSAGE(FATAL_ERROR "Check that package dynamicsJRLJapan is installed in a directory pointed out by PKG_CONFIG_PATH.")
ENDIF(NOT ${DYNAMICSJRLJAPAN_FOUND})
  
IF(PACKAGE_REQUIREMENTS STREQUAL "")
  SET(PACKAGE_REQUIREMENTS ${DYNAMICSJRLJAPAN_REQUIRED})
ELSE(PACKAGE_REQUIREMENTS STREQUAL "")
  SET(PACKAGE_REQUIREMENTS "${PACKAGE_REQUIREMENTS}, ${DYNAMICSJRLJAPAN_REQUIRED}")
ENDIF(PACKAGE_REQUIREMENTS STREQUAL "")


#
#  Dependency to package hrp2Dynamics
#
SET(HRP2DYNAMICS_FOUND 0)
SET(HRP2DYNAMICS_REQUIRED "hrp2Dynamics >= 1.3.0")
PKG_CHECK_MODULES(HRP2DYNAMICS REQUIRED ${HRP2DYNAMICS_REQUIRED})
EXEC_PROGRAM(${PKG_CONFIG_EXECUTABLE} ARGS  --variable=docdir hrp2Dynamics
  OUTPUT_VARIABLE HRP2DYNAMICS_DOCDIR)
MESSAGE(STATUS "pkg-config: ${PKG_CONFIG_EXECUTABLE}")
MESSAGE(STATUS "HRP2DYNAMICS_DOCDIR=${HRP2DYNAMICS_DOCDIR}")
SET(HRP2DYNAMICS_FOUND 1)

IF(NOT ${HRP2DYNAMICS_FOUND})
  MESSAGE(FATAL_ERROR "Check that package hrp2Dynamics is installed in a directory pointed out by PKG_CONFIG_PATH.")
ENDIF(NOT ${HRP2DYNAMICS_FOUND})
  
IF(PACKAGE_REQUIREMENTS STREQUAL "")
  SET(PACKAGE_REQUIREMENTS ${HRP2DYNAMICS_REQUIRED})
ELSE(PACKAGE_REQUIREMENTS STREQUAL "")
  SET(PACKAGE_REQUIREMENTS "${PACKAGE_REQUIREMENTS}, ${HRP2DYNAMICS_REQUIRED}")
ENDIF(PACKAGE_REQUIREMENTS STREQUAL "")


#
#  Dependency to package walkGenJrl
#
SET(WALKGENJRL_FOUND 0)
SET(WALKGENJRL_REQUIRED "walkGenJrl >= 3.0.0")
PKG_CHECK_MODULES(WALKGENJRL REQUIRED ${WALKGENJRL_REQUIRED})
EXEC_PROGRAM(${PKG_CONFIG_EXECUTABLE} ARGS  --variable=docdir walkGenJrl
  OUTPUT_VARIABLE WALKGENJRL_DOCDIR)
MESSAGE(STATUS "pkg-config: ${PKG_CONFIG_EXECUTABLE}")
MESSAGE(STATUS "WALKGENJRL_DOCDIR=${WALKGENJRL_DOCDIR}")
SET(WALKGENJRL_FOUND 1)

IF(NOT ${WALKGENJRL_FOUND})
  MESSAGE(FATAL_ERROR "Check that package walkGenJrl is installed in a directory pointed out by PKG_CONFIG_PATH.")
ENDIF(NOT ${WALKGENJRL_FOUND})
  
IF(PACKAGE_REQUIREMENTS STREQUAL "")
  SET(PACKAGE_REQUIREMENTS ${WALKGENJRL_REQUIRED})
ELSE(PACKAGE_REQUIREMENTS STREQUAL "")
  SET(PACKAGE_REQUIREMENTS "${PACKAGE_REQUIREMENTS}, ${WALKGENJRL_REQUIRED}")
ENDIF(PACKAGE_REQUIREMENTS STREQUAL "")


#
#  Dependency to package dynamic-graph
#
SET(DYNAMIC_GRAPH_FOUND 0)
SET(DYNAMIC_GRAPH_REQUIRED "dynamic-graph >= 1.0.0")
PKG_CHECK_MODULES(DYNAMIC_GRAPH REQUIRED ${DYNAMIC_GRAPH_REQUIRED})
EXEC_PROGRAM(${PKG_CONFIG_EXECUTABLE} ARGS  --variable=docdir dynamic-graph
  OUTPUT_VARIABLE DYNAMIC_GRAPH_DOCDIR)
MESSAGE(STATUS "pkg-config: ${PKG_CONFIG_EXECUTABLE}")
MESSAGE(STATUS "DYNAMIC_GRAPH_DOCDIR=${DYNAMIC_GRAPH_DOCDIR}")
SET(DYNAMIC_GRAPH_FOUND 1)

IF(NOT ${DYNAMIC_GRAPH_FOUND})
  MESSAGE(FATAL_ERROR "Check that package dynamic-graph is installed in a directory pointed out by PKG_CONFIG_PATH.")
ENDIF(NOT ${DYNAMIC_GRAPH_FOUND})
  
IF(PACKAGE_REQUIREMENTS STREQUAL "")
  SET(PACKAGE_REQUIREMENTS ${DYNAMIC_GRAPH_REQUIRED})
ELSE(PACKAGE_REQUIREMENTS STREQUAL "")
  SET(PACKAGE_REQUIREMENTS "${PACKAGE_REQUIREMENTS}, ${DYNAMIC_GRAPH_REQUIRED}")
ENDIF(PACKAGE_REQUIREMENTS STREQUAL "")

#
# Boost
#
FIND_PACKAGE(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
set(LIBS ${LIBS} ${Boost_LIBRARIES})


#
# pkg-config file
#

SET(install_pkg_prefix "\${prefix}")
SET(install_pkg_exec_prefix "\${exec_prefix}")
SET(install_pkg_libdir "\${libdir}")
SET(install_pkg_datarootdir "\${datarootdir}")
SET(install_pkg_include_dir "\${includedir}")

IF(UNIX)
  SET (${PROJECT_NAME}_LDFLAGS "-Wl,-R${install_pkg_libdir} ${LIBINCL_KW}${PROJECT_NAME}${LIB_EXT} ${${PROJECT_NAME}_LDFLAGS}")
ENDIF(UNIX)

IF(WIN32)
  SET (${PROJECT_NAME}_LDFLAGS "${LIBINCL_KW}${PROJECT_NAME}${LIB_EXT} ${${PROJECT_NAME}_LDFLAGS}")
ENDIF(WIN32)

# Install the file in the appropriate place.
SET(install_libdir_pkgconfig ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.pc.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc
  DESTINATION ${install_libdir_pkgconfig}	
  PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE)

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(unitTesting)

#
# Documentation produced by doxygen
#
INCLUDE(FindDoxygen)
IF(DOXYGEN_FOUND)
  add_subdirectory(doc)
ENDIF(DOXYGEN_FOUND)