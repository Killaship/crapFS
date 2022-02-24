#include "crapfs.h" // Include the crapFS structs and data.
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// Note: remove the 2 later when porting to a freestanding OS.


struct crapFS crapfile[256]; // Initialize the filesystem to 256 files. (Including the blank one marking the end of the filesystem.)
int entry = 0; // Current file entry. This is where the next new file will be put. 
// It's expected that the FS will be defragmented to avoid memes resulting from the entry counter going too high.
void initcrapfs() {
crapfile->null = 0; // Null should already be zeroed out, but let's just do this to be safe.
crapfile[255].null = 1; // This sets the end of the filesystem at the 256th file.
crapfile->exists = 0; 
// This will set all of the "exist" fields in the files to 0, to not mark 
// as the end of the filesystem, but rather a file that's deleted or absent. 
}

void defrag_entries() {
    // TODO: defragment file entries
}

void createfile(const char* name, const char* content) {
    strcpy(crapfile[entry].filename, name); // Set the name of the file.
    crapfile[entry].exists = 1; // Declare that this file exists.
    crapfile[entry].fileloc = (long*)malloc(my_sizeof(content));
    crapfile[entry].filesize = my_sizeof(content);
    // Use malloc, as the files should be in memory until you somehow flush the FS to a disk,
    // where the malloc'd file will be converted into some space on the disk.  
    entry++; // Increment entry counter.
}

void deletefile() {
    // TODO: Delete files.
}

void listfiles() {
    int i = 0;
    while((crapfile[i].null) == 0) { // Poor man's for loop here.
        if((crapfile[i].exists) != 0) { // Loop through all the FS entries checking if they exist, and if so, print the filename and size/addr.
            printf(crapfile[i].filename);
            printf(" ");
            printf("%i", crapfile[i].filesize);
            printf("  ");
            printf("%p", crapfile[i].fileloc);
            printf("  \n");
            i++;
            
        }
        else {i++;}

         
    }
}
int main(void) {
    printf("\n");
    initcrapfs();
    createfile("test.txt", "hello world");
    createfile("guide.hlp", "insert guide to filesystem here");
    createfile("hello.wld", "I've lost ideas for what to put in these files.");
    printf((char*)crapfile[0].fileloc);
    printf((char*)crapfile[1].fileloc);
    printf((char*)crapfile[2].fileloc);
    listfiles();
    printf("\n");
    return 0;
}
