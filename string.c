#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int search(char* word, char* name_of_file);
int search(char* word, char* name_of_file){
    char *temp = NULL;
    char *string = NULL;
    char scn_tmp[512];
    FILE* input;
    FILE* count;
    int min, temp_len,avg_len, number_of_strings = 0, len_index = 0;
    int flag = 0;
    char check[53] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
    char count_tmp[2]="a";
    temp_len = 0;
    avg_len = 0;
    input = fopen(name_of_file,"r");
    count = fopen(name_of_file,"r");
    if (!input || !count){
        printf("Error: cannot open file\n");
        exit(2);
    }
    min = INT_MAX;
    temp = (char*)malloc(temp_len*sizeof(char));
    if (temp == NULL){
        printf("Error: cannot allocate memory\n");
        exit(3);
    }
    while(fgets(scn_tmp, sizeof(scn_tmp), count) != NULL){
        number_of_strings++;
    }
    while (fscanf(count, "%c",&count_tmp)==1){
        avg_len++;
    }
    for (int x = 0; x < number_of_strings; x++){
        avg_len = 0;
        len_index = 0;
        string = fgets(scn_tmp, sizeof(scn_tmp), input);
        while (string[len_index] != '\0'){
            avg_len++;
            len_index++;
        }
        for (int j = 0; j < avg_len; j++){
            if ((string[j] != ' ')&&(string[j] != ',')&&(string[j] != '.')){
                temp_len++;
                temp = (char*)realloc(temp, temp_len*sizeof(char));
                temp[temp_len - 1] = string[j];
            }
            if ((string[j] == ' ')||(string[j] == ',')||(string[j] == '.')||(j == (avg_len -1))){
                if (temp[0]=='A'){
                    for (int k=0; k < temp_len; k++){
                        for (int u=0; u<52; u++){
                            if (temp[k] == check[u]){
                                flag++;
                            }
                        }
                    }
                    if (flag == temp_len){
                        if (temp_len <= min){
                            min = temp_len;
                            word = (char*)realloc(word, (temp_len+1)*sizeof(char));
                            for (int g=0; g< temp_len; g++){
                                word[g] = temp[g];
                            }
                            word[temp_len] = '\0';
                        }
                    }
                }
                flag = 0;
                temp_len = 0;
                temp = (char*)realloc(temp, 0*sizeof(char));
            }
        }
    }
    free(temp);
    fclose(input);
    fclose(count);
    return 0;
}
int Autotest(void);
int Autotest(void){
    char *test;
    char name_of_testfile[50] = "C:\\Users\\mihai\\Desktop\\progy\\test.txt";
    test = (char*)malloc(0*sizeof(char));
    test[0] = 't';
    search(test, name_of_testfile);
    if (test[0] == 't'){
        printf("Autotest not passed\n");
        exit(-1);
    }
    if (test[0] == 'A'){
        printf("Autotest passed successfully\n");
    }
    return 0;
}
int main(void){
    char *word = NULL;
    char name_of_file[60] = "C:\\Users\\mihai\\Desktop\\progy\\text.txt";
    word = (char*)malloc(0*sizeof(char));
    word[0] = 't';
    Autotest();
    search(word, name_of_file);
    if (word[0] == 't'){
        printf("No such words\n");
    }
    else{
        printf("Answer is %s\n",word);
    }
    free(word);
    return 0;
}
