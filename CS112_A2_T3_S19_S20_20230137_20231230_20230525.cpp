// File:  CS112_A2_T3_S19_S20_20230137_20231230_20230525.cpp
// Purpose: rational Number Calculator
// 20230525:  input handling and menu by Ahmed Ali somida (a.semeda4@gmail.com)
// 20230137:  two functions for division and multiplication by Rahma Salah Eldiin (rahmasalah072@gmail.com)
// 20231230:  two functions for addition and subtraction by Demiana Farid Michael (demianafarid88@gmail.com)


// algorithm
// 1. Function Definitions:
//    - Define functions for various arithmetic operations: addition, subtraction, multiplication, and division.
//    - Each function should take numerator and denominator pairs as input and perform the corresponding operation.

// 2. Input Validation Function:
//    - Define a function validateInput to validate user input for rational number operations.
//    - Use regular expressions to validate the input format.
//    - Ensure that denominators are not zero.

// 3. Main Function:
//    - Declare variables for menu and operation choices.
//    - Use a while loop to display the main menu and process user input until the user chooses to exit.
//    - Within the loop:
//      - Display the main menu options.
//      - Prompt the user to choose an option.
//      - If the user chooses to perform an operation:
//        - Prompt the user to enter the operation.
//        - Validate the user input using the validateInput function.
//        - Extract operands, denominators, and the operator from the validated input.
//        - Perform the appropriate operation based on the operator using a switch statement.
//      - If the user chooses to exit, display a farewell message and break out of the loop.
//      - If the user provides an invalid choice, display an error message.

// 4. Operation Processing:
//    - Depending on the operation chosen by the user, perform the corresponding operation using the provided functions.
//    - Display the result of the operation along with the type of operation performed.

// 5. End of Program:
//    - Upon choosing to exit, display a closing message and terminate the program.

#include <iostream>
#include <regex>
#include <string>
#include <stdexcept>

using namespace std;

// Function for division of rational number
void divide(double&  denom1, double& num1,double&  denom2, double& num2) {
  if(num2==0){
    cout<<"Error: can not divide by zero"<<endl;
    return;
  }
  double dem , num ;
  dem = denom1 * num2;
  num = num1 * denom2;
  cout <<"Result = " <<num << "/" << dem<<endl;
}
// Function for multiplication of rational numbers
void mult(double&  denom1, double& num1,double&  denom2, double& num2) {
    double dem , num ;
    dem = denom1 * denom2;
    num = num1 * num2;
    cout <<"Result = " <<num << "/" << dem<<endl;
}
// Function for addition of rational numbers
void sum(double num1, double num2, double denom1, double denom2) {
    double r_num = num1 * denom2 + num2 * denom1;
    double r_denom = denom1 * denom2;
    cout << "Result = " << r_num << "/" << r_denom<<endl;
}
// Function for subtraction of rational number
void sub(double num1, double num2, double denom1, double denom2) {
    double res_num = num1 * denom2 - num2 * denom1;
    double res_denom = denom1 * denom2;
    cout <<"Result = " << res_num << "/" << res_denom<<endl;
}

// Function to validate user input for a rational number operation
bool validateInput(const string& userInput) {
    // regular expression pattern to match the expected input format
    regex pattern(R"(^(-?)(\d+)(?:/(-?)(\d+))? ([+\-*\/]) (-?)(\d+)(?:/(-?)(\d+))?$)");

    // Check if the user input matches the defined pattern
    if (!regex_match(userInput, pattern)) {
        // Display an error message if the input format is invalid
        cout << "Error: Invalid input format. Please enter a valid rational number operation.\n";
        return false; // Return false to indicate validation failure
    }

    // Extract operands, denominators, and operator from the validated input
    smatch match;
    regex_match(userInput, match, pattern);

    // Extract denominators and for validation
    double denom1 = match[4].matched ? stod(match[4]) : 1;
    double denom2 = match[9].matched ? stod(match[9]) : 1;

    // Check if denominators are not zero
    if (denom1 == 0 || denom2 == 0) {
        // Display an error message for zero denominators
        cout << "Error: Zero denominators are not allowed.\n";
        return false; // Return false for validation failure
    }

    // Input validation successful
    return true; // Return true to indicate validation success
}

int main() {
    double dem , num ;
    string Menu_choice, Operation_choice;

    // Main loop for the menu-driven program
    while (true) {
        // Display the main menu options
        cout << "Menu\n" << "A) Do operation\n" << "B) Exit\n";
        getline(cin, Menu_choice); // Get user's menu choice

        // Process user's choice based on menu options
        if (Menu_choice == "A" || Menu_choice == "a") {
            // Prompt the user to enter the operation
            cout << "Enter the operation you want to perform (First_operand operator Second_operand): \n";

            // Inner loop to repeatedly ask for a valid operation until provided
            while (true) {
                getline(cin, Operation_choice); // Get user's operation input
                if (validateInput(Operation_choice)) {
                    break; // Exit the inner loop if input is valid
                } else {
                    continue; // Continue asking for input if validation fails
                }
            }

            // Process the validated operation here
            smatch match;
            regex_match(Operation_choice, match, regex(R"(^(-?)(\d+)(?:/(-?)(\d+))? ([+\-*\/]) (-?)(\d+)(?:/(-?)(\d+))?$)"));

            // Extract operands, denominators, and operator from the validated input
            double num1 = stod(match[2]);
            double denom1 = match[4].matched ? stod(match[4]) : 1;
            char op = match[5].str()[0];
            double num2 = stod(match[7]);
            double denom2 = match[9].matched ? stod(match[9]) : 1;
            //dealing with negative sign if present
            if (!match[1].str().empty()) {
                num1 = -num1;
            }
            if (!match[6].str().empty()) {
                num2 = -num2;
            }
            if (!match[3].str().empty()) {
                denom1 = -denom1;
            }
            if (!match[8].str().empty()) {
                denom2 = -denom2;
            }

            // switch case to Perform the appropriate operation based on the operator
            switch (op) {
                case '+':
                    cout << "\nOperation: Addition\n";

                    sum(num1, num2, denom1, denom2);

                    break;
                case '-':
                    cout << "\nOperation: Subtraction\n";

                    sub(num1, num2, denom1, denom2);

                    break;
                case '*':
                    cout << "\nOperation: Multiplication\n";

                    mult(denom1, num1, denom2, num2 );

                    break;
                case '/':
                    cout << "\nOperation: Division\n";

                    divide(denom1,num1, denom2, num2);

                    break;
                }

        } else if (Menu_choice == "B" || Menu_choice == "b") {
            // Exit the program if the user chooses to exit
            cout << "Thank you for using the program\n" << "Ending the program...\n";
            break; // Exit the main loop
        } else {
            // Display an error message for invalid menu choice
            cout << "Choose correctly from the menu.\n";
        }
    }

    return 0;
}
