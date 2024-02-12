#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <signal.h>
#include <unistd.h>

// Function prototypes
int authenticate(char username[], char password[]);
void timeout_handler(int sig);

int main() {
    char username[50];
    char password[50];

    printf("=== Login Page ===\n");

    // Input username
    printf("Enter username: ");
    scanf("%s", username);

    // Input password
    printf("Enter password: ");
    scanf("%s", password);

    // Set up alarm for timeout
    signal(SIGALRM, timeout_handler);
    alarm(5); // Set alarm for 1 second

    // Authenticate user
    if (authenticate(username, password)) {
        printf("Login successful. Welcome, %s!\n", username);
    } else {
        printf("Login failed. Invalid username or password.\n");
    }

    return 0;
}

// Function to authenticate user
int authenticate(char username[], char password[]) {
    // Hardcoded username and password for demonstration purposes
    char correct_username[] = "user123";
    char correct_password[] = "pass123";

    // Compare the input username and password with the correct ones
    if (strcmp(username, correct_username) == 0 && strcmp(password, correct_password) == 0) {
        return 1; // Return 1 if authentication successful
    } else {
        return 0; // Return 0 if authentication failed
    }
}

// Timeout handler function
void timeout_handler(int sig) {
    printf("\nLogin attempt timed out.\n");
    // You can add additional cleanup or handling code here if needed
    exit(1);
}
