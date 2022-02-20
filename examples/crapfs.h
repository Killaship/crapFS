#define VOL_LABEL "CRAPFS  "

struct filedata {
  char filename[12]; // 8.3 filename including null char
  int null; // if null is marked as one, then this will be treated as the end of the filesystem
  long* fileloc; // pointer to file location
  long filesize; // file size, implementation must round to nearest 512 bytes or memes might occur
  short perms; // file permissions, see documentation "mega-comment" lower down
}
  
