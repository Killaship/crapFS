#define VOL_LABEL "CRAPFS  "
#include <stdbool.h>
struct filedata {
  char filename[12]; // 8.3 filename including null char
  int null; // if null is marked as one, then this will be treated as the end of the filesystem
  bool exists;
  long* fileloc; // pointer to file location
  long filesize; // file size, implementation must round to nearest 512 bytes or memes might occur
  char perms; // file permissions, see documentation "mega-comment" lower down
} 
  
/*
File permissions are stored in an 8 bit char, in the header of the file. The system this uses takes some inspiration from standard UNIX permissions.
The first 4 bits are for what the owner or root user can do, and the last 4 bits are for what everyone else can do.
Each nibble (4 bits) represents the normal rwx, but with a "system" bit at the end, which, if it is active (a one,) only the system can touch that file.
(System as in kernel, not just the root user.) (Also, this is in terms of OSDev, so we're not talking about the Linux or NT kernel.)
*/

