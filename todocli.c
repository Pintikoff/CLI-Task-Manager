#include <stdio.h>
#include <string.h>

struct Todo
{
    int id;
    char content[30];
};


void helpCmd(){
    printf("THIS  IS  A  HELP  PAGE  FOR  todocli.\n\n");
    printf(" -a : Add command adds a given string to a todo list.\n");
    printf(" -l : Lists the todolist.\n");
}

void addTodo(char (*todoList)[30], int count){  
    for (int i = 0; i < count; i++){
        printf("Enter a todo for a %d. task:\n", i+1);
        fgets(todoList[i], sizeof(todoList[i]), stdin);
    }
}

void printTodo(char (*todoList)[30], int count){
    for (int i = 0; i < count; i++){;
        printf("%d. %s",i+1, todoList[i]);
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
    char todoList[5][30] = {};
    int count = sizeof(todoList) / sizeof(todoList[0]);

    genASCII();
    if(argc == 2){
        if(strcmp(argv[1], "-a") == 0){
            addTodo(todoList, count);
        }
        else if (strcmp(argv[1], "-l") == 0){
            printTodo(todoList, count);
        }
        else if (strcmp(argv[1], "-h") == 0){
            helpCmd();
        }
        else{
            printf("No such option is available. Check the -h command");
        }
    }

    return 0;
}