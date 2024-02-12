#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

//atm transaction simulation
int in, out, avail = 10000;
// int pin[100] = {1200, 3189, 1234, 4709};

// Timeout handler function
void timeout(int sig) {
    printf("\nSession timed out.\n");
    // You can add additional cleanup or handling code here if needed
    exit(1);
}

// can use struct for ease 
void withdrawal(){
	printf("Enter the amount to withdraw\n>_ ");
	scanf("%d", &out);
	if(out>avail || (out >= 'a' && out <= 'z') || (out >= 'A' && out <= 'Z')){
		withdrawal();
	}
	else{
		avail -= out;
		printf("Amount withdrawn = %d\nAvailable Balance = %d\n",out,avail);
	}

}

void transfer(){
	printf("Enter amout to transfer\n>_ ");
	scanf("%d", &out);
	if(out>avail || ((out >= 'a' && out <= 'z') || (out >= 'A' && out <= 'Z'))){
		transfer();
	}
	else{
		avail -= out;
		printf("\n\\\\Transaction Summary\n\nAmount Transferred = %d\nAvailable Balance = %d\n",out,avail);
	}
}

void enquiry(){
	printf("Available balance = %d\n", avail);
}


// Function to authenticate user
int authenticate(char username[], char password[]) {
    // Hardcoded username and password for demonstration purposes
    char correct_username[] = "u";
    char correct_password[] = "p";

    // Compare the input username and password with the correct ones
    if (strcmp(username, correct_username) == 0 && strcmp(password, correct_password) == 0) {
        return 1; // Return 1 if authentication successful
    } else {
        return 0; // Return 0 if authentication failed
    }
}


int main(){
	// int p;
	// print("Enter PIN\n");
	// scanf("%d",&p);
	// for (int i = 0; i<len(pin); i++){
	// 	if (p == pin[i]){	return 1;}
	// 	else{	main();}
	// }
	char username[50];
    char password[50];

    printf("=== Login Page ===\n");

    // Input username
    printf("Enter username\n>_ ");
    scanf("%s", username);
	
    // Input password
    printf("Enter password\n>_ ");
    scanf("%s", password);


	signal(SIGALRM, timeout);
	alarm(10);


    // Authenticate user
    if (authenticate(username, password)) {
        printf("Login successful. Welcome, %s!\n", username);

		// printf("Welcome to the ATM!\nEnter your choice\n");
		printf("1. Withdrawal\n");
		printf("2. Transfer\n");
		printf("3. Balance Enquiry\n>_ ");
		int c;
		scanf("%d", &c);
		switch(c){
			case 1: withdrawal();
					printf("\n");
					return 1;
			case 2: transfer();
					return 1;
			case 3: enquiry();
					return 1;
		}
    } else {
        printf("Login failed. Invalid username or password.\n");
    }
	return 0;
}

	
