#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


//first 
int get_dates(char text[], int* arr[]){
    char* tokenPtr;
    int counter = 0;
    tokenPtr = strtok(text, " ");
    int x = 0;
    

    while(tokenPtr != NULL){
        
        if(tokenPtr[0] == '1' || tokenPtr[0] == '2'){
            if (strlen(tokenPtr) == 4 || strlen(tokenPtr) == 5){
                if (strlen(tokenPtr) == 5 && (tokenPtr[4] == '.' || tokenPtr[4] == ',' || tokenPtr[4] == '\n')){
                    tokenPtr[4] = '\0';
                    x = atoi(tokenPtr);
                    //printf("arr[%d] = %s\n", counter, arr[counter]);
                    printf("%s, ", tokenPtr);
                    arr[counter] = &x;
                    //printf("arr[%d] = %d\n", counter, *arr[counter]);
                    counter++;

                }
                else{
                    x = atoi(tokenPtr);
                    arr[counter] = &x;
                    //printf("arr[%d] = %s\n", counter, arr[counter]);
                    printf("%s, ", tokenPtr);
                    counter++;


                }
                                    

            }
        }




        tokenPtr = strtok(NULL, " ");
    
    }
    printf("\n");
    return counter;
}



void cancel_newline(char arr[]){
    arr[strlen(arr)-1] = '\0';
}


int word_freq(char text[1500], char keyword[]){

    int n = 0;
    int m = 0;
    int times = 0;
    int word_len = strlen(keyword);

    while(text[n] != '\0'){
        if (text[n] == keyword[m]){
            while(text[n] == keyword[m] && text[n] != '\0'){
                n++;
                m++;
            }
            
        
            if (m == word_len && text[n] != '\0'){
                times++;
            }

        }
        else{
            n++;
            m = 0;
        }
        
    }
    printf("num of %s: %d\n", keyword, times);
    return times;
    
}

void max(int arr[], int size){
    int i, location = 0;

    for (i = 1; i < size; i++)
        if (arr[i] > arr[location])
        location = i;

    printf("paragraph %d has the most number of sentences: %d\n", location+1, arr[location]);
}

int sentence_ferq(char* array)
{
    int counter = 0;
    for (int i = 0; i < strlen(array); i++){
        if (array[i] == '.')
            counter++;
    }
    return counter;
}

int main(void){

    FILE * p_file;
    char file_name[50];
    char str[3000];
    char buffer[3000];
    int paragraphs_number = 0;
    int sentences_number = 0;
    int sentence_num_arr[50] = {0};
    int arr_size = 0;


    printf("Enter file name eg: example.txt\n");
    fgets(file_name, 50, stdin);
    cancel_newline(file_name);

    p_file = fopen(file_name, "r");

    if (p_file == NULL)
        perror("error opening file");

    else{
        while(fgets(str, 1000,p_file) != NULL){

            sentences_number = sentence_ferq(str);

            sentence_num_arr[paragraphs_number] = sentences_number;            


            printf("num of sentences in this paragraph: %d\n", sentences_number);

            strcat(buffer, str);
            paragraphs_number++;
        }

    
            arr_size = paragraphs_number;

            // max sentence number and it's paragraph
            max(sentence_num_arr, arr_size);

            printf("\n\n");

            char name[100];
            char author[100];
            char protagonist[100];
            char keywords_freq[100];

            printf("Enter the book's name:\n");
            fgets(name, 100, stdin);

            printf("Enter author's author: \n");
            fgets(author, 100, stdin);

            printf("Enter author's protagonist: \n");
            fgets(protagonist, 100, stdin);

            cancel_newline(name);
            cancel_newline(author);
            cancel_newline(protagonist);
            
            // Fahrenheit 451, Ray Bradbury,Guy Montag

            keywords_freq[0] = word_freq(buffer, name);
            keywords_freq[1] = word_freq(buffer, author);
            keywords_freq[2] = word_freq(buffer, protagonist);

        
            int* dates_arr[1000];
            char tokenize_text[3000];
            int size_dates_arr = 0;
            strcpy(tokenize_text, buffer);

            size_dates_arr = get_dates(tokenize_text, dates_arr);

            
    
    
    }



}

