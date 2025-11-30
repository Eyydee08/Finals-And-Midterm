#include <iostream>
using namespace std;

int main() {
   
    double total_price = 0.0;
    int choice;
    int quantity;
    bool keep_ordering = true;



    //grilling Text image =======================================================

const string RESET_COLOR = "\033[0m";
const string RED = "\033[31m";
const string YELLOW = "\033[33m";
const string ORANGE = "\033[38;5;208m"; 
const string SMOKE_GRAY = "\033[90m";
const string BOLD = "\033[1m";


    cout << SMOKE_GRAY;
    cout << "         (   )      (   ) " << endl;
    cout << "          ) (        ) (  " << endl;
    cout << "         (   )      (   ) " << endl;
    cout << RESET_COLOR;
    cout << "      ____________________ " << endl;
    cout << "     /                    \\" << endl;
    cout << "    |" << BOLD << RED << " Eyydee's Lit & Grill" << RESET_COLOR << " |" << endl;
    cout << "    |  ||||||||||||||||    |" << endl;
    cout << "     \\____________________/" << endl;
    cout << RED << "       ( ) ( ) ( ) ( )" << RESET_COLOR << endl;
    cout << YELLOW << "      ( ) ( ) ( ) ( ) " << RESET_COLOR << endl;
    cout << "         |        |    " << endl;
    cout << "        /          \\   " << endl;
    // =========================================================================


    cout << "Welcome to Eyydee's Lit & Grill" << endl;
    cout << "What Are We Rolling Today?" << endl;
    cout << "1. Pork BBQ - P15.00" << endl;
    cout << "2. Isaw - P10.00" << endl;
    cout << "3. Dugo - P10.00" << endl;
    cout << "4. Bulaklak - P12.00" << endl;
    cout << "5. Hotdog - P11.00" << endl;
    cout << "0. Exit and checkout" << endl;
   
    while (keep_ordering == true) {
        cout << "Please enter the number of the item you want to order: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "How many Pork bbq are we grilling today?";
            cin >> quantity;
            total_price = total_price + (quantity * 15.00);
            cout << "Added " << quantity << " Pork Babyquoh to your order." << endl;
        } else if (choice == 2) {
            cout << "How many Isaw are we grilling today? ";
            cin >> quantity;
            total_price = total_price + (quantity * 10.00);
            cout << "Added " << quantity << " Isaw(s) to your order" << endl;
        } else if (choice == 3) {
            cout << "How many Dugo are we grilling today? ";
            cin >> quantity;
            total_price = total_price + (quantity * 10.00);
            cout << "Added " << quantity << " Dugo to your order." << endl;
        } else if (choice == 4) {
            cout << "How many Bulaklak are we grilling today? ";
            cin >> quantity;
            total_price = total_price + (quantity * 12.00);
            cout << "Added " << quantity << " Hotdog to your order" << endl;
        } else if (choice == 5) {
            cout << "How many Hotdog are we grilling today? ";
            cin >> quantity;
            total_price = total_price + (quantity * 11.00);
            cout << "Added " << quantity << " Hotdog to your order" << endl;
        } else if (choice == 0) {
            keep_ordering = false;
        } else {
            cout << "That is not a valid choice. Please try again." << endl;
        }
        
        cout << "Your current total is: $" << total_price << endl;
    }
    
    cout << "Thanks for being our best bud! Your final total is: P" << total_price << endl;
    cout << "Stay lit! <3" << endl;
    
    return 0;
}
