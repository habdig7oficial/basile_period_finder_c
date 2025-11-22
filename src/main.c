/*
 * Mateus Felipe da Silveira Vieira - 10723904
 * Rayana Pimentel Lopes - 10435370
 */
 
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "stdlib.h"

#include "./functions/mod.h"
#include "./tests/test.h"

int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--compress") == 0){
            printf("Compress %s\n", argv[i + 1]);

            char *compressed_str = compress(argv[i + 1], strlen(argv[i + 1]));

            printf("RESULTED = %s", compressed_str);

            free(compressed_str);
        } 
        else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--decompress") == 0){
            printf("Decompress %s\n", argv[i + 1]);

            int len = (int) strlen(argv[i + 1]);
            char *decompressed_str = decompress(argv[i + 1], len);

            printf("Descompressed: %s", decompressed_str);

            printf("\nRESULTED = %s", decompressed_str);

            free(decompressed_str);
        }
        else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--compress-legacy") == 0){
            printf("Compress W %s\n", argv[i + 1]);

            char *compressed_str = compress_legacy(argv[i + 1], strlen(argv[i + 1]));

            printf("RESULTED = %s", compressed_str);


            free(compressed_str);
        } 
        else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--test") == 0){
            printf("Loading tests Batery\n");

            bool succeded = test_all();

            if(succeded){
                printf("\n------------ All tests Ran Successfully ------------\n");
            }

        }
        
    }
    return 0;
}