#include "crapfs.h" // Include the crapFS structs and data.
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

struct crapFS crapfile[256]; // Initialize the filesystem to 256 files. (Including the blank one marking the end of the filesystem.)
void initcrapfs() {
crapfile->null = 0; // Null should already be zeroed out, but let's just do this to be safe.
crapfile[255].null = 1; // This sets the end of the filesystem at the 256th file.
crapfile->exists = 0; 
// This will set all of the "exist" fields in the files to 0, to not mark 
// as the end of the filesystem, but rather a file that's deleted or absent. 
}


void createfile(const char name, const char content, const int entry) {
    crapfile[entry].filename = name; // Set the name of the file.
    crapfile[entry].exists = 1; // Declare that this file exists.
    crapfile[entry]->fileloc = (malloc(my_sizeof(content)));
    crapfile[entry].filesize = my_sizeof(content);
    // Use malloc, as the files should be in memory until you somehow flush the FS to a disk,
    // where the malloc'd file will be converted into some space on the disk.    
}


int main(void) {
    initcrapfs();
    createfile("test.txt", "hello world", 1);
}
