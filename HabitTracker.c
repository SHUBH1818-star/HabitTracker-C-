#include <stdio.h>
#include <stdlib.h>

//Define a struct to hold habit information
struct Habit{
    char name [50];
    int completed;
};
int main(){
    struct Habit habits[10]; // Array to hold up to 10 habits
    int habitCount = 0; // Number of habits added
    int choice;

    // Main loop
    while(1){
        printf("Habit Tracker\n");
        printf("1. Add Habit\n");
        printf("2. VIEW HABITS\n");
        printf("3. MARK HABITS AS DONE\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        //USE fgets+sscanf to read user input
        char input[10];
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &choice);

        switch(choice){
            case 1: // Add Habit
                    printf("Enter habit name: ");
                    fgets(habits[habitCount].name, sizeof(habits[habitCount].name), stdin);
                    habits[habitCount].completed = 0; // Initialize completed to 0
                    habitCount++;
                    break;
            case 2: // List Habits
                for(int i = 0; i < habitCount; i++){
                    printf("%d. %s [%s]\n", i + 1, habits[i].name, habits[i].completed ? "DONE" : "PENDING");
                }
                break;
            case 3: // MARK Habit as Completed
                printf("ENTER HABIT NUMBER TO MARK AS COMPLETED: ");
                fgets(input, sizeof(input), stdin);
                int num;
                sscanf(input, "%d", &num);
                if(num < 1 || num > habitCount){
                    printf("Invalid habit number.\n");
                } else {
                    habits[num - 1].completed = 1; // Mark as completed
                    printf("Habit %d marked as completed.\n", habits[num - 1].name);
                }
                break;
                
            case 4: // Exit
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");    
                }        
            }       
        }      
