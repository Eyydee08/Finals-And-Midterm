#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Item {
    string name;
    double price;
    int quantity;
};

struct CartItem {
    string name;
    double price;
    int quantity;
};

vector<Item> inventory;
vector<CartItem> cart;

// Initialize inventory
void initializeInventory() {
    inventory.push_back({"Barbeque", 20.00, 50});
    inventory.push_back({"Isaw", 10.00, 40});
    inventory.push_back({"Dugo", 10.00, 30});
    inventory.push_back({"Bulaklak", 15.00, 35});
    inventory.push_back({"Hotdog", 10.00, 60});
    inventory.push_back({"Tenga", 15.00, 25});
    inventory.push_back({"Liempo", 90.00, 20});
}

// Display with numbers


void displayInventory() {

    
    cout << "\n=============== MENU ================\n";
    for (size_t i = 0; i < inventory.size(); i++) {
        cout << i + 1 << ". " << inventory[i].name
             << " - P" << fixed << setprecision(2) << inventory[i].price
             << " (Qty: " << inventory[i].quantity << ")\n";

     
             
    }
    cout << "\n=====================================\n";   
}

// Display cart
void displayCart() {

    cout << "           " << endl;
    cout << "              *                   " << endl;
    cout << "   *    ===|        *           *    " << endl;
    cout << "          _|_________________     *" << endl;
    cout << "          \\                 /      *" << endl;
    cout << "        *  \\               /  *" << endl;
    cout << "            \\_____________/      *" << endl;
    cout << "    *        /                         " << endl;
    cout << "            /______________         *" << endl;
    cout << "             O            O             " << endl;



    cout << "\n====================================\n";

    if (cart.empty()) {
        cout << "Your cart is empty.\n";
        return;
    }

    double total = 0;
    for (size_t i = 0; i < cart.size(); i++) {
        double subtotal = cart[i].price * cart[i].quantity;

        cout << i + 1 << ". " << cart[i].name
             << " - P" << cart[i].price
             << " x " << cart[i].quantity
             << " = P" << fixed << setprecision(2) << subtotal << endl;

        total += subtotal;
    }
    cout << "Total: P" << total << "\n";
}

// Add to cart using item number
void addToCart() {
    while (true) {
        displayInventory();

        int choice, qty;
        cout << "\nEnter item number: ";
        cin >> choice;
        cout << "Enter quantity: ";
        cin >> qty;

        if (choice < 1 || choice > inventory.size()) {
            cout << "X Invalid item number. Try again.\n";
            continue;
        }

        Item &selected = inventory[choice - 1];

        if (qty <= 0 || qty > selected.quantity) {
            cout << "X Invalid quantity or not enough stock.\n";
            continue;
        }

        // Check if item already in cart
        bool exists = false;
        for (auto &c : cart) {
            if (c.name == selected.name) {
                c.quantity += qty;
                exists = true;
                break;
            }
        }

        if (!exists) {
            cart.push_back({selected.name, selected.price, qty});
        }

        selected.quantity -= qty;

        cout << " \n=========================\n";
            cout << "||    Cart updated!     ||";
             cout << " \n=========================\n";
        return;
    }
}

// Modify cart with number selection
void modifyCart() {



    if (cart.empty()) {
        cout << "||                                      ||\n";
        cout << "||                                      ||\n";
        cout << "||            Cart is empty.            ||\n";
        cout << "||                                      ||\n";
        cout << "||                                      ||\n";
        return;
    }

    displayCart();

    int choice, newQty;
    cout << "\nEnter cart item number to modify: ";
    cin >> choice;

    if (choice < 1 || choice > cart.size()) {
        cout << "X Invalid choice.\n";
        return;
    }

    CartItem &selected = cart[choice - 1];

    cout << "Enter new quantity (0 to remove): ";
    cin >> newQty;

    // Restore inventory stock before modifying
    for (auto &inv : inventory) {
        if (inv.name == selected.name) {
            inv.quantity += selected.quantity;
            break;
        }
    }

    if (newQty == 0) {
        cart.erase(cart.begin() + choice - 1);
        cout << "/ Item removed.\n";
        return;
    }

    // Validate stock
    for (auto &inv : inventory) {
        if (inv.name == selected.name) {
            if (newQty > inv.quantity) {
                cout << "X Not enough stock.\n";
                return;
            }

            inv.quantity -= newQty;
            selected.quantity = newQty;
            cout << " ========================n";
            cout << " ||    Cart updated!     ||\n";
             cout << " ========================n";
            return;
        }
    }
}

// Checkout
void checkout() {
    if (cart.empty()) {
        cout << "Cart is empty. Enjoy your day!.\n";
        std::exit(1);
        return;
    }

    string name;
    cout << "\nEnter customer name: ";
    cin >> name;

    displayCart();

    double total = 0;
    for (auto &c : cart) total += c.price * c.quantity;

    double tax = total * 0.20;
    double grandTotal = total;

    cout << "\n      Tax (20%): P" << fixed << setprecision(2) << tax << "      ";
    cout << "\n     Grand Total: P" << grandTotal << "      " << endl;
    cout << "\n  \n";
    cout << "\n  \n";
    cout << "\n  \n";
    cout << "\n  \n";
    cout << "      Thank you for being lit!, " << name << "    ";
    cout << "\n Your smoked grilled inihaw is done.\n";
    cout << "\n This is brought to you by AD Corp \n";
    cout << "\n         Aim High Butterfly        \n";


    cart.clear();
}

int main() {
    initializeInventory();

    int choice;
    do {

        
    //grilling Text image =======================================================

const string RESET_COLOR = "\033[0m";
const string RED = "\033[31m";
const string YELLOW = "\033[33m";
const string ORANGE = "\033[38;5;208m"; 
const string SMOKE_GRAY = "\033[90m";
const string BOLD = "\033[1m";


    cout << "\n ";
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
    cout << RED << "          ( ) ( ) ( ) ( )" << RESET_COLOR << endl;
    cout << YELLOW << "       ( ) ( ) ( ) ( ) ( ) " << RESET_COLOR << endl;
    cout << "           |         |    " << endl;
    cout << "          /           \\   " << endl;
    // =========================================================================




        displayInventory();


        cout << "\n============ OPTIONS ================\n"
             << " \n"
             << "1. Add Item to Cart\n"
             << "2. Add or Remove Item(s) in Cart\n"
             << "3. Display Cart\n"
             << "4. Exit & Checkout\n"
             << "\n=====================================\n"
             << "Enter choice: ";
             
        cin >> choice;

        switch (choice) {
            case 1: addToCart(); break;
            case 2: modifyCart(); break;
            case 3: displayCart(); break;
            case 4: checkout(); break;
            default: cout << "X Invalid choice.\n";
                     cout << "--------------------------------\n";
        }
    } while (choice != 4);

    return 0;
}
