# crapFS
An attempt at a filesystem, or at least the specs, to be implemented in OSes.


Specs start below.

# FS Specs
None of that "filesystem data goes in a boot sector" crap, the entire thing should just be a binary "blob" you load. The first 2 sectors, or 1024 bytes, of the FS contain everything, with the volume label, file names, sizes, and location. (With location being represented as an offset from where the FS was loaded.)

### Locations

Data          | Location (hex)
------------- | -------------
Volume Label  | 
File Names    | 
Terminating Char |
File Loc. |
File Size |
