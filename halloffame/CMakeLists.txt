cmake_minimum_required (VERSION 3.1.0)

project (halloffame)

# Find includes in corresponding build directories
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON) 
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++0x")

FILE(GLOB SRC_FILES "src/*.cpp" "src/*.cc") 
FILE(GLOB HEAD_FILES "include/*.h") 
FILE(GLOB UI_FILES "widget.ui")

find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Widgets)
find_package(Qt5Sql)
find_package(Qt5Network)
find_package(Protobuf REQUIRED)

qt5_wrap_ui(WRAP_FILES ${UI_FILES})
add_executable (${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES} ${WRAP_FILES} )

include_directories (include /usr/local/include /usr/local/protobuf/include /usr/local/mycpp/include)
link_directories (/usr/local/protobuf/lib)
target_link_libraries (${PROJECT_NAME} Qt5::Core Qt5::Widgets Qt5::Sql Qt5::Network ${PROTOBUF_LIBRARIES} /usr/local/mycpp/libmycpp.so rt uuid pthread ssl odbc jsoncpp )


# Install section
install (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION /opt/lynx/${PROJECT_NAME})
install (FILES "${PROJECT_SOURCE_DIR}/bin/configuration.json" DESTINATION /opt/lynx/${PROJECT_NAME})
install (DIRECTORY "${PROJECT_SOURCE_DIR}/bin/ui" DESTINATION /opt/lynx/${PROJECT_NAME})
#install (FILES "${PROJECT_SOURCE_DIR}/${PROJECT_NAME}.service" DESTINATION /etc/systemd/system)
install (FILES "${PROJECT_SOURCE_DIR}/${PROJECT_NAME}.desktop" DESTINATION /usr/share/applications/)
install (FILES "${PROJECT_SOURCE_DIR}/bin/ui/jinyuan.png" DESTINATION /usr/share/pixmaps/)
install (FILES "${PROJECT_SOURCE_DIR}/${PROJECT_NAME}.desktop" DESTINATION /etc/xdg/autostart/)

# Packaging section
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_NAME}")
set(CPACK_PACKAGE_DESCRIPTION "Hall Of Fame")

set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "lynx@lynxattractions.com")
set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS 1)
#set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/debian/postinst;${CMAKE_CURRENT_SOURCE_DIR}/debian/prerm;${CMAKE_CURRENT_SOURCE_DIR}/debian/conffiles")

include(CPack)
