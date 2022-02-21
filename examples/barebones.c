#include "crapfs.h" // Include the crapFS structs and data.



filedata crapfile[256]; // Initialize the filesystem to 256 files. (Including the blank one marking the end of the filesystem.)

crapfile[255].null = 1; // This sets the end of the filesystem at the 256th file.

crapfile.exists = {false}; 
// This will set all of the "exist" fields in the files to 0, to not mark 
// as the end of the filesystem, but rather a file that's deleted or absent. 
