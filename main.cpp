#include<stdio.h>
#include "json.hpp"
#include<fstream>
#include "dictionary.h"

using namespace std;

using json = nlohmann::json;

void mainMenu(){

    int choice;

    fstream f("dictionary.json");
    json j;
    f >> j;

    while(true){
        printf("\n\nSelect a choice: \n\n");
        printf("1. Search word in dictionary\n");
        printf("2. Play Quiz\n");
        printf("3. Exit\n");
        printf("Choice: ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            searchWord(j);
            break;
        case 2:
            playQuiz(j);
            break;
        case 3:
            return;
            break;
        default:
            printf("Enter a valid choice.");
            break;
        }
    }

}

int main(){
    
    mainMenu();

    return 0;
}
