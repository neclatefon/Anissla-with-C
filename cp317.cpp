#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 8
#define FILENAME "users.txt"
int main()
{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH + 1];
    char prompt;
    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 2];
    int found = 0;
    int found_username = 0;
    int found_password = 0;

    printf("Hello, Welcome to Anissla.\n");
    do{
        printf("Do you have an account? If yes, enter 'Y'. If no, enter 'N'.\n");
        scanf(" %c", &prompt);
        if (prompt == 'Y' || prompt == 'y' || prompt == 'N' || prompt == 'n') {
            break;
        }
        printf("Sorry, you have entered an invalid letter. Try again! If you have an account enter 'Y', if you don't, enter 'N'.\n");

    } while(1);
    if (prompt == 'Y' || prompt == 'y') {
        printf("Enter your username:\n");
        scanf("%s", username); 
        printf("Enter your password:\n");
        scanf("%s", password);



    // Open the file for reading
    FILE* file = fopen(FILENAME, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error: could not open file %s\n", FILENAME);
        return 1;
    }

    // Loop through each line in the file
    
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        char* stored_username = strtok(line, ",");
        char* stored_password = strtok(NULL, ",");
        if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0) {
            found = 1;
            break;
        }
    }


    // Close the file
    fclose(file);
    rewind(file);

    if (found) {
        printf("Welcome back, %s!\n", username);
    } else {
        printf("Sorry, the username and password are not in our system. Please create an account.\n");
        // Prompt the user to create a new account
        do {
            found_username = 0;
            printf("Enter a username of your choice:\n");
            scanf("%s", username);
            FILE* file = fopen(FILENAME, "r");
             if (file == NULL) {
                    printf("Error: could not open file %s\n", FILENAME);
                    return 1;
                }
                while (fgets(line, sizeof(line), file)) {
                    line[strcspn(line, "\n")] = '\0';
                    char* stored_username = strtok(line, ",");
                    if (strcmp(username, stored_username) == 0) {
                        found_username = 1;
                        printf("Sorry, that username is already taken. Please choose a different one.\n");
                        break;
                    }
                }fclose(file);


        }
        
       
        while(found_username);
            printf("Enter a password:\n");
            scanf("%s", password);



        rewind(file);

        // Open the file for appending
        FILE* file = fopen(FILENAME, "a");

        // Check if the file was opened successfully
        if (file == NULL) {
            printf("Error: could not open file %s\n", FILENAME);
            return 1;
        }

        // Write the new username and password to the file
        fprintf(file, "%s,%s\n", username, password);

        // Close the file
        fclose(file);

        printf("Account created successfully, %s!\n", username);
    }
    } else if (prompt == 'N' || prompt == 'n') {
        do{
        found_username = 0;
            printf("Enter a username of your choice:\n");
            scanf("%s", username);
            FILE* file = fopen(FILENAME, "r");
             if (file == NULL) {
                    printf("Error: could not open file %s\n", FILENAME);
                    return 1;
                }
                while (fgets(line, sizeof(line), file)) {
                    line[strcspn(line, "\n")] = '\0';
                    char* stored_username = strtok(line, ",");
                    if (strcmp(username, stored_username) == 0) {
                        found_username = 1;
                        printf("Sorry, that username is already taken. Please choose a different one.\n");
                        break;
                    }
                }fclose(file);
        
        
        } while(found_username); 
            printf("Enter a password:\n");
            scanf("%s", password); 
        
        FILE* file = fopen(FILENAME, "a");
        fprintf(file, "%s,%s\n", username, password);
        fclose(file);
        printf("Account created successfully, %s!\n", username);
    }
    else {
        printf("Sorry, you have entered an invalid letter. Try again! If you have an account enter 'Y', if you don't, enter 'N'.\n");
    }

    return 0;
}