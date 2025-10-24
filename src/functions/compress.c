#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

char *find_period(char *text, int len, int *counter, int *buffer_size){
    char *hello = (char *) malloc(len);

    for(int i = 0; i < len / 2 + 1; i++){

    }

    *counter = *buffer_size = 1;

    return &text[0];
}

char *compress(char *text, int len){
    size_t text_len, allocated_area;
    text_len = allocated_area = strlen(text);
    char *string_builder = (char *) malloc(text_len);

    if(string_builder == NULL){
        printf("Error could not alloc Memory!");
        return "";
    }


    for(int i = 0, counter = 0, buffer_size = 0; i < text_len; i += counter * buffer_size){
        char *new_slice = find_period(&text[i], len - i, &counter, &buffer_size);

        char *buffer_size_str = malloc(sizeof(char)*(int)log10(10));
        sprintf(buffer_size_str, "%d", buffer_size);

        int needed = strlen(string_builder) + counter * buffer_size;
        if(needed >= allocated_area){
            printf("\n Allocated: %zu, Needed: %d, ", allocated_area, needed);
            allocated_area += needed;
            string_builder = realloc(string_builder, allocated_area);
            printf("Realloc: %zu \n", allocated_area);
        }

        strcat(string_builder, new_slice);
        strcat(string_builder, buffer_size_str);
        strcat(string_builder, "-");


       printf("\nSlice: %d %s %lu\n", i, string_builder, strlen(string_builder));
    }

    printf("Slice: %s\n",string_builder);

    return string_builder;
}