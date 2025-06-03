#include <stdio.h>
#include <string.h>
#include <time.h>   // Required for time(NULL) and srand()
#include <stdlib.h> // Required for rand() and srand()

// Define a maximum password length to prevent buffer overflows
#define MAX_PSWD_LEN 99 // 100 - 1 for null terminator

int main()
{
    int i, pswd_len;
    // Expanded character list for more complexity
    char list[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;':\",.<>/?\\`~";
    char pswd[MAX_PSWD_LEN + 1];         // +1 for the null terminator
    char generated_pswd[MAX_PSWD_LEN + 1]; // +1 for the null terminator

    printf("\t\t\tWelcome to the password generator and authentication\n");
    printf("\n");

    // --- Password Generation ---
    while (1)
    {
        printf("Enter the desired length of the password (minimum 8 characters, maximum %d): ", MAX_PSWD_LEN);
        // Use fgets to safely read input, preventing buffer overflows for pswd_len
        char input_buffer[10]; 
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
            printf("Error reading input. Exiting.\n");
            return 1;
        }
        // Convert string to integer, handle potential non-numeric input
        if (sscanf(input_buffer, "%d", &pswd_len) != 1) {
            printf("\nInvalid input. Please enter a number.\n\n");
            continue; // Ask for input again
        }


        if (pswd_len < 8)
        {
            printf("\nThe length you entered is too short to create a strong password.\n");
            printf("Please try again!\n\n");
        }
        else if (pswd_len > MAX_PSWD_LEN)
        {
            printf("\nThe length you entered is too long. Maximum allowed length is %d.\n", MAX_PSWD_LEN);
            printf("Please try again!\n\n");
        }
        else
        {
            printf("\nGenerated password is: ");
            srand(time(NULL)); // Seed the random number generator once

            // Calculate the actual size of the 'list' array
            size_t list_size = strlen(list);

            for (i = 0; i < pswd_len; i++)
            {
                generated_pswd[i] = list[rand() % list_size];
                printf("%c", generated_pswd[i]);
            }
            generated_pswd[pswd_len] = '\0'; // Null-terminate the generated password
            printf("\n"); // Newline after printing the generated password
            break;       // Exit the generation loop
        }
    }
    printf("\n");

    // --- Password Authentication ---
    printf("Please enter your password for authentication (Note: You can enter the password for only three tries):\n");

    int attempts = 0;
    const int MAX_ATTEMPTS = 3;

    while (attempts < MAX_ATTEMPTS)
    {
        printf("Attempt %d of %d: ", attempts + 1, MAX_ATTEMPTS);
        // Use fgets to safely read the user's input password
        if (fgets(pswd, sizeof(pswd), stdin) == NULL) {
            printf("Error reading input. Exiting.\n");
            return 1;
        }
        // Remove the trailing newline character that fgets might include
        pswd[strcspn(pswd, "\n")] = '\0';

        if (strcmp(pswd, generated_pswd) == 0)
        {
            printf("\nThe password is correct. Thank you for verifying.\n");
            printf("\n\t\t\tWelcome to the system.\n");
            break; // Exit the authentication loop
        }
        else
        {
            printf("Wrong password! ");
            attempts++;
            if (attempts < MAX_ATTEMPTS)
            {
                printf("Please try again!\n\n");
            }
            else
            {
                printf("This was your third attempt.\n");
                printf("\nWrong password for the third time!!!\n");
                printf("\nTry again next time.\n");
            }
        }
    }

    return 0; // Indicate successful execution
}