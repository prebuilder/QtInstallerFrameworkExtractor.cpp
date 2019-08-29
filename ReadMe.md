Qt Installer Framework extractor
================================

Helps you to extract installers created with [Qt Installer Framework](https://github.com/qtproject/installer-framework).

How to use
----------

### CarvFS mode

CarvFS is a FUSE FS mapping parts of files to paths within its root. In this mode this tool generates a shell file that creates symlinks to the paths within CarvFS, corresponding to archives. Then you can extract the archives using the archiver you like, i.e. `7z`.

1. Build and install [carvFS](https://github.com/DNPA/carvfs).
2. Obtain an installer binary.
3. Create 2 dirs.
    a. A dir where carvfs will be mounted
    b. A dir where symlinks will be.
4. Mount carvfs into the first dir.
5. Execute the tool, giving it paths to the dirs and to the file. Redirect its output into a shell file.
6. Examine the shell file.

### `dd` mode

The similar, but instead of generating commands generating symlinks generates commands copying pieces of file using dd.
