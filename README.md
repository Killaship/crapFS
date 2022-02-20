# crapFS
An attempt at a filesystem, or at least the specs, to be implemented in OSes.
## TODO
- [ ] Finish specs
- [ ] Add example code
- [ ] Make blob generator
- [ ] FUSE driver?
- [ ] Working Implementation
- [ ] Port to OS projects

Specs start below.

# FS Specs
None of that "filesystem data goes in a boot sector" crap, the entire thing should just be a binary "blob" you load. The first 8 sectors, or 4096 bytes, of the FS contain everything, with the volume label, file names, sizes, and location. (With location being represented as an offset from where the FS was loaded.)

## Locations and data type

Data          | Location (hex) | Data Type/Size |
------------- | -------------- | -------------- |
Volume Label  |    `0x0004`    | 10 byte char   |
Filenames     |    `0x000F`    | 1024 byte char array of 4 char long filenames. |
File Loc.     |    `0x040F`    | 1024 byte int array of 32 bit ints, half this if in Real Mode. |
File Size     |    `0x080F`    | 1024 byte int array of 32 bit ints, half this if in Real Mode. |
Other         |Any remaining room| Any kind of data can go here, this is room for un-added features. |
Data          | `0x1000` onward | Data for files. |

## Details
### Volume Label
This is an array of 10 characters, including a null character, so in reality, it's more like 9.
### Filename Array
Due to crappy design choices, the filenames are only 4 characters long, including a null char, and without any extensions. This means there can be 26^4 filenames, but only 256 files are supported in one filesystem. (Crappy design at work! Don't you just love the waste?)
### File Location Array
An array of 256 file pointers, to the start of a file, but it can be 512 pointers if you are in real mode, where you'd use 16 bit locations. You could also use this for calculating the size of files, by finding the difference between one pointer and the next, but preferably, the implementation of the FS on its own would include this in the file size array.
### File Size Array
This is the same thing as the file location array, but every entry in this array corresponds to one in the other, so for every file 
### Other/Unimplemented


