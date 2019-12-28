#include <stdio.h>
void getFileSize(int kb){
        int count = 0;
        double size = kb;
        char* unit;
        int temp;
        while(size>=1024){
                size/=1024;
                count++;
        }
        switch(count) {
                case 0: unit = "K"; break;
                case 1: unit = "M"; break;
                case 2: unit = "G"; break;
                case 3: unit = "T"; break;
                default : unit = "byte"; break;
        }

        if (count>0){
                size+=0.09;
                size = (int)(size*1000);
                size = size/1000;
                temp = size *10;
                printf("%5.1f%s", temp/10.0, unit);
        } else
                printf("%5d%s", (int)size, unit);
}

