typedef struct _IMAGE_FILE_HEADER {
	WORD		Machine;
	WORD		NumberOfSections;
	DWORD		TimeDataStamp;
	DWORD		PointerToSymbolTable;
	WORD		SizeOptionalHeader;
	WORD		Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;
