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
Filenames     |    `0x000F`    | 1024 byte char array of 8.3 filenames |
File Loc.     |    `0x040F`    | 1024 byte int array of 32 bit ints, half this if in Real Mode. |
File Size     |    `0x0583`    | 1024 byte int array of 32 bit ints, half this if in Real Mode. |
Other         |Any remaining room| Any kind of data can go here, this is room for un-added features. |
Data          | `0x1000` onward | Data for files. |

## Details

### Volume Label
### Filename Array

### File Location Array
An array of 256 file pointers, to the start of a file, 
### File Size Array
### Other/Unimplemented


