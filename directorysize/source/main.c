#include "searchdir.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char* argv[]) {
        struct stat buf;
        char* path = argv[1];
        if(argc == 1)
                path = ".";

        stat(path, &buf);
        if(S_ISDIR(buf.st_mode)){
                int size = searchDirectory(path);
                getFileSize((int) size);
                printf("\t%s\n", path);
        } else {
                int kbsize = getKbSize((int) buf.st_size);
                getFileSize(kbsize);
                printf("\t%s\n", path);
        }
        return 0;
}


