typedef struct _IMAGE_OPTIONAL_HEADER {
	  WORD                 Magic;
	    BYTE                 MajorLinkerVersion;
	      BYTE                 MinorLinkerVersion;
	        DWORD                SizeOfCode;
		  DWORD                SizeOfInitializedData;
		    DWORD                SizeOfUninitializedData;
		      DWORD                AddressOfEntryPoint;
		        DWORD                BaseOfCode;
			  DWORD                BaseOfData;
			    DWORD                ImageBase;
			      DWORD                SectionAlignment;
			        DWORD                FileAlignment;
				  WORD                 MajorOperatingSystemVersion;
				    WORD                 MinorOperatingSystemVersion;
				      WORD                 MajorImageVersion;
				        WORD                 MinorImageVersion;
					  WORD                 MajorSubsystemVersion;
					    WORD                 MinorSubsystemVersion;
					      DWORD                Win32VersionValue;
					        DWORD                SizeOfImage;
						  DWORD                SizeOfHeaders;
						    DWORD                CheckSum;
						      WORD                 Subsystem;
						        WORD                 DllCharacteristics;
							  DWORD                SizeOfStackReserve;
							    DWORD                SizeOfStackCommit;
							      DWORD                SizeOfHeapReserve;
							        DWORD                SizeOfHeapCommit;
								  DWORD                LoaderFlags;
								    DWORD                NumberOfRvaAndSizes;
								      IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;
