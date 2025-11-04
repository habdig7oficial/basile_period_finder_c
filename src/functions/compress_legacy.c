#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

char *compress_legacy(char *text, int len){
    size_t text_len, allocated_area;
    text_len = allocated_area = strlen(text) / 2;
    char *string_builder = (char *) malloc(text_len);

    if(string_builder == NULL){
        printf("Error could not alloc Memory!");
        return "";
    }

    for(int i = 0, counter = 1; i <= text_len; i++){
        if(text[i] == text[i + 1])
            counter++;
        else{
            char counter_size = sizeof(char)*(int)log10(counter);
            char *buffer = (char *) malloc(counter_size + sizeof(char) * 2); // + 2 because of the char &text[i]
            sprintf(buffer, "%c%d-", text[i], counter);
            printf("%c%d-", text[i], counter);

            if(counter_size + strlen(string_builder) > allocated_area){
                allocated_area += allocated_area * 0.5;
                string_builder = realloc(string_builder, allocated_area);
                printf("Reallocing...\n%zu Bytes total", allocated_area);
            }

            counter = 1;
        }
    }

    string_builder[strlen(string_builder) - 1] = '\0';

    return string_builder;
}

