#include <stdio.h>
int getKbSize(int byte){
        double size = byte/1024.0;
        if(size <1)
                return 1;
        size+=0.9999;
        size = (int)(size*1000);
        size = size/1000;
        return (int)size;
}


