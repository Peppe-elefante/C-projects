#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void writepass(char*);
char* readpass(char*);
char* passgen(void);

#define len  15

int main(){
    int res;
    char site[20];

    do{
        printf("would you like to read or write passwords(1 = read, 2 = write, 0 = close program): ");
        scanf("%d", &res);
        
        if(res == 1){
            printf("Insert name of site: ");
            scanf("%s", site);
            printf("The password is %s.\n", readpass(site));
        }
        if(res == 2){
            printf("Insert name of site: ");
            scanf("%s", site);
            writepass(site);
        }
    }while(res);
    return 0;
}


void writepass(char *site){
    FILE *f;
    char *pass = malloc(len * sizeof(char));
    f = fopen("password.txt", "a");
    if(!f){
        printf("file not found");
        exit(0);
    }
    strcpy(pass, passgen());
    fprintf(f, "%s:  %s\n", site, pass);
    printf("Action completed succesfully: the password for %s is %s.\n", site, pass);
    free(pass);
    fclose(f);
}


char* passgen(void){
    char *pass = malloc(len+1 *sizeof(char));
    srand(time(0));
    for(int i = 0; i <len;i++){
        pass[i] = (char)((rand() % 93)+33);
    }
    pass[len] = '\0';
    return pass;
}


char* readpass(char *site){
    FILE *f;
    char *pass = malloc(len * sizeof(char)), str[20];
    f = fopen("password.txt", "r");
    if(!f){
        printf("file not found");
        exit(0);
    }
    while(fscanf(f, "%s", str)!= EOF){
        str[strlen(str)-1]= '\0';
        if(!strcmp(site, str)){
            fscanf(f, "%s", pass);
            return pass;
        }
    }
    strcpy(pass, "not here");
    return pass;
    fclose(f);

    
}