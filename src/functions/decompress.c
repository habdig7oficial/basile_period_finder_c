#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "ctype.h"

char *decompress(char *text, int len){
    int reapeat_num = 0;
    int num = 0 ;

    char *buffer = (char *) calloc(len, len);

    int alloc_str_build = pow(len, 2);
    char *string_builder = calloc(alloc_str_build, alloc_str_build);

    printf("entered");

    /*<= Make sure that iterates until '/0' */
    for(int c = 0; c <= len; c++){

        if(isdigit(text[c])){
            int aux = atoi(&text[c]);
            (aux > reapeat_num)? reapeat_num = aux : printf("Repeating num unchanged\n");
            printf("%d %c", reapeat_num, text[c]);
        }
        else if((text[c] != '-') && (text[c] != '\0')){
            char ct[2] = {text[c], '\0'};
            strcat(buffer, ct);
        }
        else {
            /*            for(int i = 0; *(&buffer[i]) != text[c]; i++)
                printf("%c %p %c %d\n", *(&buffer[i]), buffer, text[c], reapeat_num);*/

            for(int i = 0; i < reapeat_num; i++){
                if(strlen(string_builder) + strlen(buffer) >= alloc_str_build){
                    printf("Reallocating...");
                    alloc_str_build += (int)alloc_str_build * 0.5;
                    string_builder = realloc(string_builder, alloc_str_build);
                }
                strcat(string_builder, buffer);
            }
                

            printf("Buffer: %s", buffer);
            reapeat_num = 0;
            num = 0;
            
            int null = 0;
            memcpy(buffer, &null, len);

        }
        printf("\n");
    }


    return string_builder;
}