#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PAIRS 100

struct keyValuePair {
    char key[21];
    char value[21];
};

struct keyValuePair keyValueDb[MAX_PAIRS];
int pairCount = 0;

int getIndex(const char *key){
    for(int i= 0; i< pairCount; i++){
        if(strcmp(keyValueDb[i].key, key)== 0){
            return i;
        }
    }
    return -1;
}

void setValue(char *key, char *value){
    if(strlen(key)> 20 || strlen(value)> 20){
        printf("ERROR: Key and value should be not more than 20 characters. \n");
        return;
    }

    int index= getIndex(key);

    if(index!= -1){
        strcpy(keyValueDb[index].value, value);
    }
    else{
        if(pairCount>= MAX_PAIRS){
            printf("ERROR: Maximum limit reached. \n");
            return;
        }

        strcpy(keyValueDb[pairCount].key, key);
        strcpy(keyValueDb[pairCount].value, value);

        pairCount++;
    }
}

void getValue(char *key){
    int index= getIndex(key);
    if(index== -1){
        printf("(%s, (null))\n", key);
    }
    else{
        printf("(%s, %s)\n", keyValueDb[index].key, keyValueDb[index].value);
    }
}


void deleteValue(char *key) {
    int index= getIndex(key);
    if (index== -1) return;

    // After deleting an element, we left rotate the array by 1.
    for (int i= index; i< pairCount; i++) {
        keyValueDb[i]= keyValueDb[i+ 1];
    }
    pairCount--;
}


int main(){

    char input[202];
    char action[21], key[21], value[21];

    printf("The following actions are allowed: SET, GET, DELETE. To exit, enter EXIT.\n");
    while(1){
        printf("> ");
        if (!fgets(input, sizeof(input), stdin)) break;

        // Verifying that there is no more than 200 bytes after reading
        if (strlen(input)> 200) {
            printf("ERROR: Input line is exceeding 200 bytes. Kindly shorten it.\n");

            // to clear the buffer
            if (input[strlen(input)- 1]!= '\n') {
                int c;
                while ((c= getchar())!= '\n'&& c!= EOF);
            }
            continue;
        }

        int arguments= sscanf(input, "%s %s %s", action, key, value);
        if (arguments< 1) continue;

        if (strcmp(action, "EXIT")== 0) break;
        
        if (strcmp(action, "SET") == 0 && arguments== 3) {
            setValue(key, value);
        } else if (strcmp(action, "GET")== 0 && arguments>= 2) {
            getValue(key);
        } else if (strcmp(action, "DELETE")== 0 && arguments>= 2) {
            deleteValue(key);
        }
        else{
            printf("ERROR: Invalid action requested.\n");
        }
    }

    return 0;
}