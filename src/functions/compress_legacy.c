#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

char *compress_legacy(char *text, int len){
    size_t text_len, allocated_area;
    text_len = allocated_area = strlen(text);
    char *string_builder = (char *) malloc(text_len);

    if(string_builder == NULL){
        printf("Error could not alloc Memory!");
        return "";
    }

    for(int i = 0, counter = 1; i <= text_len; i++){
        if(text[i] == text[i + 1])
            counter++;
        else{
            printf("%c%d-", text[i], counter);
            counter = 1;
        }
    }

    string_builder[strlen(string_builder) - 1] = '\0';

    return string_builder;
}

