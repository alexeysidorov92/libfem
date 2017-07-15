function(get_project_files PROJECT_FILES)
	set(SOURCE_FILES)
	file(GLOB_RECURSE SOURCE_FILES 
		${CMAKE_CURRENT_SOURCE_DIR}/*.h	
		${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/*.inl
	)
	
	foreach(SOURCE_FILE IN ITEMS ${SOURCE_FILES})
		if (IS_ABSOLUTE "${SOURCE_FILE}")
			file(RELATIVE_PATH RELATIVE_FILE_PATH "${CMAKE_CURRENT_SOURCE_DIR}" "${SOURCE_FILE}")
		else()
			set(RELATIVE_FILE_PATH "${SOURCE_FILE}")
		endif()
		get_filename_component(SOURCE_FILE_PATH "${RELATIVE_FILE_PATH}" PATH)
		string(REPLACE "/" "\\" SOURCE_FILE_GROUP "${SOURCE_FILE_PATH}")
		source_group("${SOURCE_FILE_GROUP}" FILES "${SOURCE_FILE}")
	endforeach()
	
	set(${PROJECT_FILES} ${SOURCE_FILES} PARENT_SCOPE)
endfunction(get_project_files)