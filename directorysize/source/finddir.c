#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int searchDirectory(char* dirname){
        struct dirent *dit;
        struct stat st;
        DIR *dir;
        double totalSize = 0;
        double size = 0;
        double dirsize = 0;
        char path[256];

        if((dir = opendir(dirname))==NULL) {
                perror("Error");
                exit(1);
        }
        while((dit = readdir(dir))!=NULL) {
                sprintf(path, "%s/%s", dirname, dit->d_name);
                if(lstat(path, &st)<0)
                        continue;
                if(strcmp(dit->d_name, ".") == 0 || strcmp(dit->d_name, "..")==0)
                        continue;
                else
                        size = getKbSize((int)st.st_size);

                if(S_ISDIR(st.st_mode)) {
                        dirsize = searchDirectory(path);
                        getFileSize((int) dirsize);
                        printf("\t%s\n", path);
                        totalSize +=dirsize;
                } else {
                        totalSize += size;
                }
        }
        return totalSize+1;

}

