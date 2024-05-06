cmake_minimum_required(VERSION 3.10)
project(StaffDemo)

set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")
set(header ${header_path}/Interfaces.h ${header_path}/Employee.h ${header_path}/Personal.h ${header_path}/Engineer.h ${header_path}/Factory.h)
set(src src/Employee.cpp src/Personal.cpp src/Engineer.cpp src/Factory.cpp
		include/Project.h
		src/Project.cpp)

add_library(${PROJECT_NAME} SHARED
		${header}
		${src})
target_include_directories(${PROJECT_NAME}
		PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
		${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME})

add_executable(${PROJECT_NAME}_exe src/main.cpp)
target_include_directories(${PROJECT_NAME}_exe
		PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
		${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}_exe
		${PROJECT_NAME})

set(lib_dest "lib")
set(tool_dest "bin")
set(include_dest "include")

install(TARGETS ${PROJECT_NAME}
		LIBRARY DESTINATION "${lib_dest}"
		ARCHIVE DESTINATION "${lib_dest}"
		COMPONENT library)
install(TARGETS ${PROJECT_NAME}_exe
		RUNTIME DESTINATION "${tool_dest}"
		COMPONENT library)
install(FILES ${header} DESTINATION "${include_dest}")