#include <iostream>
#include <vector>
#include <string>

struct Item {
    std::string name;
    int quantity;
    double price;
};

int main() {
    std::vector<Item> inventory;
    int choice;
    bool running = true;

    while (running) {
        std::cout << "\nInventory Management System\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Remove Item\n";
        std::cout << "3. Update Item\n";
        std::cout << "4. Display Inventory\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            // adding things
            Item newItem;
            std::cout << "Enter item name: ";
            std::cin.ignore(); 
            std::getline(std::cin, newItem.name);
            std::cout << "Enter quantity: ";
            std::cin >> newItem.quantity;
            std::cout << "Enter price: ";
            std::cin >> newItem.price;
            inventory.push_back(newItem);
            std::cout << "Item added successfully.\n";
        } else if (choice == 2) {
            // Remove Item
            std::string itemName;
            std::cout << "Enter item name to remove: ";
            std::cin.ignore();
            std::getline(std::cin, itemName);
            bool found = false;
            for (size_t i = 0; i < inventory.size(); ++i) {
                if (inventory[i].name == itemName) {
                    inventory.erase(inventory.begin() + i);
                    found = true;
                    std::cout << "Item removed successfully.\n";
                    break;
                }
            }
            if (!found) {
                std::cout << "Item not found.\n";
            }
        } else if (choice == 3) {
            // update items
            std::string itemName;
            std::cout << "Enter item name to update: ";
            std::cin.ignore();
            std::getline(std::cin, itemName);
            bool found = false;
            for (size_t i = 0; i < inventory.size(); ++i) {
                if (inventory[i].name == itemName) {
                    std::cout << "Enter new quantity: ";
                    std::cin >> inventory[i].quantity;
                    std::cout << "Enter new price: ";
                    std::cin >> inventory[i].price;
                    found = true;
                    std::cout << "Item updated successfully.\n";
                    break;
                }
            }
            if (!found) {
                std::cout << "Item not found.\n";
            }
        } else if (choice == 4) {
            // display storage
            if (inventory.empty()) {
                std::cout << "Inventory is empty.\n";
            } else {
                std::cout << "Current Inventory:\n";
                for (size_t i = 0; i < inventory.size(); ++i) {
                    std::cout << "Name: " << inventory[i].name 
                              << ", Quantity: " << inventory[i].quantity 
                              << ", Price: $" << inventory[i].price << "\n";
                }
            }
        } else if (choice == 5) {
            // Exit
            running = false;
            std::cout << "Exiting program.\n";
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
