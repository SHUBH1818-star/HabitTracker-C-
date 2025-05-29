#include <stdio.h>
#include <string.h>

struct Habit {
    char name[50];
    int completed;
    int streak;
};

void saveHabits(struct Habit habits[], int habitCount) {
    FILE *file = fopen("habits.txt", "w");
    if (!file) return;
    
    for (int i = 0; i < habitCount; i++) {
        fprintf(file, "%s,%d,%d\n", habits[i].name, habits[i].completed, habits[i].streak);
    }
    fclose(file);
}

void loadHabits(struct Habit habits[], int *habitCount) {
    FILE *file = fopen("habits.txt", "r");
    if (!file) return;
    
    char line[100];
    *habitCount = 0;
    
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *completed = strtok(NULL, ",");
        char *streak = strtok(NULL, "\n");
        
        if (name && completed && streak) {
            strncpy(habits[*habitCount].name, name, 49);
            habits[*habitCount].completed = atoi(completed);
            habits[*habitCount].streak = atoi(streak);
            (*habitCount)++;
        }
    }
    fclose(file);
}

int main() {
    struct Habit habits[10];
    int habitCount = 0;
    
    loadHabits(habits, &habitCount);
    
    while (1) {
        printf("\nHabit Tracker\n1. Add Habits \n2. List Habits\n3. Mark Done\n4. Exit and Save to file\n> ");
        
        int choice;
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear input buffer
        
        switch (choice) {
            case 1:
                printf("Habit name: ");
                fgets(habits[habitCount].name, 50, stdin);
                habits[habitCount].name[strcspn(habits[habitCount].name, "\n")] = '\0';
                habits[habitCount].completed = 0;
                habits[habitCount].streak = 0;
                habitCount++;
                break;
                
            case 2:
                for (int i = 0; i < habitCount; i++) {
                    printf("%d. %s [%s] (Streak: %d)\n", 
                          i+1, 
                          habits[i].name,
                          habits[i].completed ? "DONE" : "Pending",
                          habits[i].streak);
                }
                break;
                
            case 3:
                printf("Habit number: ");
                int num;
                scanf("%d", &num);
                if (num > 0 && num <= habitCount) {
                    habits[num-1].completed = 1;
                    habits[num-1].streak++;
                }
                break;
                
            case 4:
                saveHabits(habits, habitCount);
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
}