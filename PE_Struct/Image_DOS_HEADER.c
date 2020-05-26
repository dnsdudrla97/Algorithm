typedef struct _IMAGE_DOS_HEADER {		// DOS header
	WORD 	e_magic;			// Magic number
	WORD 	e_cblp;
	WORD	e_cp;
	WORD	e_crlc;				// Relocations
						// ...
	WORD 	e_res2[10];			// Reserved words
	LONG	e-lfanew;			// File address of new exe header
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER		// winNT.h

