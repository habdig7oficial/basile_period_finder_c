#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

char *find_period(char *text, int len, int *counter, int *buffer_size){
    *counter = *buffer_size = 0;
    for(int i = 1; i < len / 2 + 1; i++){
        char *left = (char *) malloc(i);
        char *right = (char *) malloc(i);

        memcpy(left, &text[0], i);
        memcpy(right, &text[i], i);

        if(strcmp(left, right) == 0){
            *buffer_size = i;

            char *period_left = (char *) malloc(i);
            memcpy(period_left, &text[0], i);

            printf("Left: %s, Right: %s %d\n", left, right, strcmp(left, right));
            for(int j = 0; j + i <= len; (*counter)++, j += i){

                char *period_right = (char *) malloc(i);

                memcpy(period_right, &text[j], i);

                printf("\tPeriod Left: %s, Period Right: %s, Counter: %d, Bf: %d\n", period_left, period_right, *counter, *buffer_size);
                
                if(strcmp(period_left, period_right) != 0)
                    break;
                
            } 
            printf("Return: %d %d", *counter, *buffer_size);
            return left;
        }
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

        printf("buf %d |", counter);

        char counter_size = sizeof(char)*(int)log10(counter);
        char *counter_str = malloc(counter_size);
        sprintf(counter_str, "%d", counter);

        int needed = counter_size + strlen(string_builder) + counter * buffer_size;
        if(needed >= allocated_area){
            printf("\n Allocated: %zu, Needed: %d, ", allocated_area, needed);
            allocated_area += needed;
            string_builder = realloc(string_builder, allocated_area);
            printf("Realloc: %zu \n", allocated_area);
        }

        strcat(string_builder, new_slice);
        strcat(string_builder, counter_str);
        strcat(string_builder, "-");

        printf("%d %d", buffer_size, counter);
        printf("\nSlice: %d %s %lu %lu %d\n", i, string_builder, strlen(string_builder), allocated_area, needed);
    }

    printf("Slice: %s\n",string_builder);

    return string_builder;
}