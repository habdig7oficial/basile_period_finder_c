#include "stdio.h"
#include "string.h"

#include "./functions/mod.h"

int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--compress") == 0){
            printf("Compact %s\n", argv[i + 1]);

            compress(argv[i + 1]);
        } 
    }
    return 0;
}