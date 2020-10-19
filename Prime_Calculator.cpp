

#include <iostream>
#include <string>
using namespace std;
// function to calculate all prime numbers less than input number and to check which are palindromic and sum to an odd number
void prime_calculator(int input_num) {
    cout << "All prime numbers less than or equal to " << input_num << " are: " << "\n";
    // for loop to count all the numbers starting at 2 (since 0 and 1 are not prime) up to the input number
    for (int i = 2; i <= input_num; i++) {
        // estbalishing boolean confirm if i is prime or not
        bool is_prime = true;
        // for loop to check if i is divisable by any numbers smaller than it
        for (int n = 2; n < i; n++) {
            // if i is divisable by any numbers smaller than it it is not prime so is_prime is set to false and the loop stops
            if (i % n == 0) {
                is_prime = false;
                break;
            }
        }
        // if i is a prime number and is_prime remains true the if statement is carried
        if (is_prime) {
            cout << i;
            // converts i into a string and stores the original string as a variable and sets another variable to be reversed
            string original_prime = to_string(i);
            string palindromic = to_string(i);
            int palindromic_len = palindromic.length();
            // for loop to reverse all the characters in the string
            for (int a = 0; a < palindromic_len / 2; a++) {
                swap(palindromic[a], palindromic[palindromic_len - a - 1]);
            }
            // statement to see if a prime is palindromic by checking if the original string is the exact same as the reversed string
            if (original_prime == palindromic) {
                cout << " This prime is palindromic.";
            }
            // establishes variables to be used to calculate if the sum of the didgets of the prime number is odd 
            int sum_didgets = 0;
            int b = i;
            // while loop takes the remainder of each coloumb of the prime number and sums them together
            while (b > 0) {
                int modulo_b = b % 10;
                b = b / 10;
                sum_didgets = sum_didgets + modulo_b;
            }
            // check to see if the sum of the didigets is odd by checking the remiander divided by 2 if it is not 0 it is odd since all even numbers are divisible by 2 
            int sum_odd = sum_didgets % 2;
            if (sum_odd != 0) {
                cout << " The sum of the didgets of this prime are odd.";
            }
            cout << "\n";

        }
    }
}

int main()
{
    // gets input from user and checks to see if its greater than 1 if not it will ask for another input
    int input_num;
    cout << "Enter an integer value greater than 1." << "\n";
    cin >> input_num;
        while (input_num <= 1) {
            cout << "Incorrect number entered. Please enter an integer greater than 1." << "\n";
            cin >> input_num;
        }
        // sends user input to function
    prime_calculator(input_num);
}


