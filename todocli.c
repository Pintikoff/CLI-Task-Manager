#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Todo
{
    int id;
    char content[30];
};


void helpCmd(){
    printf("THIS  IS  A  HELP  PAGE  FOR  todocli.\n\n");
    printf(" -a [id]: Add command adds a given string to a todo list.\n");
    printf(" -l : Lists the todolist.\n");
}

void addTodo(struct Todo *todoList, char *idString, char *content){  
    int id = atoi(idString);
    strcpy(todoList[id-1].content, content);
    todoList[id-1].id = id;

    printf("%d %s", todoList[0].id, todoList[0].content);
}

void printTodo(struct Todo *todoList){
    for (int i = 0; i < 5; i++){;
        printf("%d. ID: %d - %s.",i+1, todoList[i].id, todoList[i].content);
    }
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

int main(int argc, char* argv[]){
    struct Todo todoList[5] = {0};

    //genASCII();
    if(argc >= 2){
        if(strcmp(argv[1], "-a") == 0 && argv[2] && argv[3]){
                addTodo(todoList, argv[2], argv[3]);  
        }
        else if (strcmp(argv[1], "-l") == 0){
            printTodo(todoList);
        }
        else if (strcmp(argv[1], "-h") == 0){
            genASCII();
            helpCmd();
        }
        else{
            printf("No such option is available. Check the -h command");
        }
    }

    return 0;
}