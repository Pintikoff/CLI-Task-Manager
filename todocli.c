#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Todo
{
    int id;
    char content[30];
};

//adds todos from a file to a struct
int readTodo(struct Todo **todoList){
    FILE *ftpr;
    ftpr = fopen("todocli.txt","r");

    int count = 0;
    char lineContent[100];

    while (fgets(lineContent, sizeof(lineContent), ftpr))
    {
        count ++;
    }

    *todoList = malloc(sizeof(struct Todo) * (count+1));
    if (todoList == NULL){
        printf("error");
        return 0;
    }

    rewind(ftpr);

    int i = 0;
    while (fgets(lineContent, sizeof(lineContent), ftpr))
    {
        int trash;
        char content[30];

        sscanf(lineContent, "%d: %s", &trash, content);
        (*todoList)[i].id = i+1;
        strcpy((*todoList)[i].content, content);
        i++;
    }

    return count;
}

void updateFile(struct Todo *todoList, int count){
    FILE *delete;
    delete = fopen("todocli.txt", "w");

    FILE *ftpr;
    ftpr = fopen("todocli.txt","a");
    fprintf(delete, "");
    for(int i = 0; i < count; i++){
        fprintf(ftpr, "%d: %s \n", todoList[i].id, todoList[i].content);
    }
    fclose(ftpr);
}

void genASCII(){
    printf("   ___       ___       ___       ___            ___       ___       ___   \n");
    printf("  /\\  \\     /\\  \\     /\\  \\     /\\  \\          /\\  \\     /\\  \\     /\\  \\  \n");
    printf("  \\:\\  \\   /::\\  \\   /::\\  \\   /::\\  \\        /::\\  \\   /::\\  \\   /::\\  \\ \n");
    printf("  /: \\__\\ /:/\\:\\__\\ /:/\\:\\__\\ /:/\\:\\__\\      /::\\:\\__\\ /::\\:\\__\\ /::\\:\\__\\ \n");
    printf(" /:/\\/__/ \\:\\/:/  / \\:\\/:/  / \\:\\/:/  /      \\/\\::/  / \\/\\::/  / \\/\\::/  /\n");
    printf(" \\/__/     \\::/  /   \\::/  /   \\::/  /         /:/  /     \\/__/     \\/__/ \n");
    printf("            \\/__/     \\/__/     \\/__/          \\/__/                      \n");
}

void addTodo(struct Todo *todoList, char *content, int count){
    todoList[count].id = count+1;
    strcpy(todoList[count].content, content);

    printf("Task added succesfully (ID: %d): %s\n", todoList[count].id, todoList[count].content);

    updateFile(todoList, count+1);
}

void listTodo(struct Todo *todoList,int count){
    for(int i = 0; i < count; i++){
        printf("%d: %s.\n", todoList[i].id, todoList[i].content);
    }
}

void deleteTodo(struct Todo *todoList, char *argv, int *count){
    int givenId = atoi(argv);
    if (givenId <= 0 || givenId > *count){
        return;
    }
    int wantedInd = givenId - 1;
    for(int i = wantedInd; i < *count; i++){
        todoList[i] = todoList[i+1];
        todoList[i-1].id = i;
    }
    
    (*count) --;
    updateFile(todoList, *count);
}

void clearTodo(){
    FILE *ftpr;
    ftpr = fopen("todocli.txt","w");
    fprintf(ftpr, "");
}

void helpTodo(){
    printf("\n");
    printf("THIS  IS  A  HELP  PAGE  FOR  todocli.\n\n");
    printf("   -a   : Add command adds a given string to a todo list.\n");
    printf("   -l   : Lists the todolist.\n");
    printf(" -d [id]: Deletes a chosen task.\n");
    printf(" -u [id]: Update a chosen task.\n");
    printf(" -clear : deletes WHOLE todo-todo list (clears whole data).\n");
    printf("   -h   : Displays this help command.\n\n");
}

int main(int argc, char* argv[]){
    struct Todo *todoList = NULL;
    int count = readTodo(&todoList);
    if (todoList == NULL){
        printf("error");
        return 1;
    }

    //genASCII();
    if(argc >= 2){
        if(strcmp(argv[1], "-a") == 0 && argv[2]){
            addTodo(todoList, argv[2], count);  
        }
        else if (strcmp(argv[1], "-l") == 0){
            listTodo(todoList,count);
        }
        else if (strcmp(argv[1], "-d") == 0 && argv[2]){
            deleteTodo(todoList, argv[2], &count);
        }
        else if (strcmp(argv[1], "-clear") == 0){
            clearTodo();
        }
        else if (strcmp(argv[1], "-h") == 0){
            genASCII();
            helpTodo();
        }
        else{
            printf("No such option is available. Check the -h command");
        }
    }
    else{
        genASCII();
        helpTodo();
    }
    free(todoList);
    return 0;
}