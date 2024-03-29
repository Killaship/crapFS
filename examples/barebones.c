#include "crapfs.h" // Include the crapFS structs and data.
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// Note: remove the above later when porting to a freestanding OS.
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

void createfile(const char* name, const char* content) {
	strcpy(crapfile[entry].filename, name); // Set the name of the file.
	crapfile[entry].exists = 1; // Declare that this file exists.
	crapfile[entry].filesize = strlen(content);
	crapfile[entry].fileloc = malloc(crapfile[entry].filesize);
	strcpy(crapfile[entry].fileloc, content);
	// Use malloc, as the files should be in memory until you somehow flush the FS to a disk,
	// where the malloc'd file will be converted into some space on the disk.  
	entry++; // Increment entry counter.
}
void deletefile(char *file) {
	int i = 0;
	// TODO: Delete files.
	while((crapfile[i].null) == 0) {  // Loop through FS entries, check if they exist, normal stuff.
		if((crapfile[i].exists) != 0) { 
			if(strcmp((char*)crapfile[i].filename, (char *)file) == 0) { // Check if filename of entry is what's requested.
				crapfile[i].exists = 0;
				crapfile[i].fileloc = 0;
				strcpy(crapfile[i].filename, "");
				crapfile[i].filesize = 0;
				//free(crapfile[i].fileloc);
				break; // Close loop to avoid memory memeing. :^)
			}
		}
	}
}
void readfile(char *file, char *outbuf) {
	int i = 0;
	while(crapfile[i].null == 0) {  // Loop through FS entries, check if they exist, normal stuff.
		if(crapfile[i].exists != 0) { 
			if(strcmp(crapfile[i].filename, (char *)file) == 0) { // Check if filename of entry is what's requested.
				strcpy((char *)outbuf,(char *) crapfile[i].fileloc); // Copy file contents to output buffer.
				break; // Close loop to avoid memory memeing. :^)
			}
		}
		else {i++;}
	}
}
void listfiles() {
	int i = 0;
	while((crapfile[i].null) == 0) { 
		if((crapfile[i].exists) != 0) { // Loop through all the FS entries checking if they exist, and if so, print the filename and size/addr.
			printf(crapfile[i].filename);
			printf(" ");
			printf("%i", crapfile[i].filesize);
			printf("  ");
			printf("%p", crapfile[i].fileloc);
			printf("  ");
			printf("%x", crapfile[entry].fileloc);
			printf("  \n");
			i++;
		}
		else {i++;}
		
	}
	printf("\n");
}
int main(void) {
	printf("\n");
	initcrapfs();
	createfile("test.txt", "hello world\n");
	listfiles();
	deletefile("test.txt");
	createfile("guide.hlp", "insert guide to filesystem here");
	createfile("hello.wld", "I've lost ideas for what to put in these files.");
	listfiles();
	createfile("test.txt", "a\n");
	listfiles();
	char *buff[256];
	readfile("test.txt",(char *)buff);
	printf("%s",buff); 
	return 0;
}
