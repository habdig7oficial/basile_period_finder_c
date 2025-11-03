#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include "./functions/mod.h"

int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--compress") == 0){
            printf("Compress %s\n", argv[i + 1]);

            char *compressed_str = compress(argv[i + 1], strlen(argv[i + 1]));

            free(compressed_str);
        } 
        else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--decompress") == 0){
            printf("Decompress %s\n", argv[i + 1]);

            int len = (int) strlen(argv[i + 1]);
            char *decompressed_str = decompress(argv[i + 1], len);
            printf("Descompressed: %s", decompressed_str);
            free(decompressed_str);
        }
        
    }
    return 0;
}