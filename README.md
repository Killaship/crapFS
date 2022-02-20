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
in progress.
For now, see examples/crapfs.h for some documentation.
# the below is obsolete as I'm putting everything in structs instead of at offsets.
The structs would be a "header" to each file and there would be a magic number aligned to a certain amount of bytes, to tell where each file is.
The filesystem, for now, is also read-only, as I don't wanna mess around with fragmentation or any of that. The filenames will be 8.3 instead of 4 chars. (yay)


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
Due to crappy design choices, the filenames are only 4 characters long, including a null char, and without any extensions. This means there can be a ton of filenames (how many?), but only 256 files are supported in one filesystem. (Crappy design at work! Don't you just love the waste?)
### File Location Array
An array of 256 file pointers, to the start of a file, but it can be 512 pointers if you are in real mode, where you'd use 16 bit locations. You could also use this for calculating the size of files, by finding the difference between one pointer and the next, but preferably, the implementation of the FS on its own would include this in the file size array.
### File Size Array
This is the same thing as the file location array, but every entry in this array corresponds to one in the other, so for every file 
### Other/Unimplemented


