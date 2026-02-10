if (NOT POCO_UNBUNDLED)
	add_subdirectory(pcre2)
	add_subdirectory(v8_double_conversion)
	add_subdirectory(utf8proc)
	
	if (ENABLE_JSON)
		add_subdirectory(pdjson)
	endif()
	
	if (NOT POCO_SQLITE_UNBUNDLED AND ENABLE_DATA_SQLITE)
		add_subdirectory(sqlite3)
	endif()
	
	if (ENABLE_XML)
		add_subdirectory(expat)
	endif()
	
	if (ENABLE_SEVENZIP)
		add_subdirectory(7zip)
	endif()
	
	if(WIN32)
		add_subdirectory(wepoll)
	endif()
	
	if (ENABLE_PDF OR ENABLE_ZIP)
		add_subdirectory(zlib)
	endif()
	
	if (ENABLE_PDF)
		add_subdirectory(png)
		add_subdirectory(hpdf)
	endif()
	
	if(ENABLE_FASTLOGGER)
		add_subdirectory(quill)
	endif()
endif()
