#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> // For transform function to handle case insensitivity

using namespace std;

// Parallel arrays to store the data
string description[] = {
    "Mystic Hat", "Dragon Scale Armor", "Healing Potion", "Magic Wand",
    "Enchanted Boots", "Rations", "Battle Axe", "Phoenix Feather",
    "Potion of Hiding", "Thieves' Tools"
};

int quantity[] = { 3, 2, 10, 4, 1, 50, 2, 1, 3, 5 };

double price[] = { 50.0, 200.0, 10.0, 100.0, 75.0, 2.0, 150.0, 500.0, 250.0, 20.0 };

string category[] = {
    "Wearables", "Wearables", "Consumables", "Equipment",
    "Wearables", "Consumables", "Equipment", "Materials",
    "Consumables", "Equipment"
};

// Function to display all items with their details
void displayItems() {
    cout << left << setw(20) << "Description"
        << setw(10) << "Quantity"
        << setw(10) << "Price"
        << setw(15) << "Category"
        << setw(10) << "Ext Price" << endl;

    cout << "-------------------------------------------------------------" << endl;

    for (int i = 0; i < 10; ++i) {
        double extPrice = quantity[i] * price[i];
        cout << left << setw(20) << description[i]
            << setw(10) << quantity[i]
            << setw(10) << fixed << setprecision(2) << price[i]
            << setw(15) << category[i]
            << setw(10) << fixed << setprecision(2) << extPrice << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
}

// Function to filter items by category
void filterByCategory(string cat) {
    // Convert the input category to lowercase
    transform(cat.begin(), cat.end(), cat.begin(), ::tolower);

    cout << "Filtering by Category: " << cat << endl;
    bool found = false;

    for (int i = 0; i < 10; ++i) {
        string itemCategory = category[i];
        // Convert the category in the array to lowercase for comparison
        transform(itemCategory.begin(), itemCategory.end(), itemCategory.begin(), ::tolower);

        if (itemCategory == cat) {
            double extPrice = quantity[i] * price[i];
            cout << left << setw(20) << description[i]
                << setw(10) << quantity[i]
                << setw(10) << fixed << setprecision(2) << price[i]
                << setw(15) << category[i]
                << setw(10) << fixed << setprecision(2) << extPrice << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No items found for category: " << cat << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
}

// Function to filter items by description
void filterByDescription(string desc) {
    // Convert the input description to lowercase
    transform(desc.begin(), desc.end(), desc.begin(), ::tolower);

    cout << "Filtering by Description: " << desc << endl;
    bool found = false;

    for (int i = 0; i < 10; ++i) {
        string itemDescription = description[i];
        // Convert the description in the array to lowercase for comparison
        transform(itemDescription.begin(), itemDescription.end(), itemDescription.begin(), ::tolower);

        if (itemDescription == desc) {
            double extPrice = quantity[i] * price[i];
            cout << left << setw(20) << description[i]
                << setw(10) << quantity[i]
                << setw(10) << fixed << setprecision(2) << price[i]
                << setw(15) << category[i]
                << setw(10) << fixed << setprecision(2) << extPrice << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No items found with description: " << desc << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
}

// Function to display the footer with total and average prices
void displayFooter() {
    int totalQuantity = 0;
    double totalPrice = 0.0;

    for (int i = 0; i < 10; ++i) {
        totalQuantity += quantity[i];
        totalPrice += quantity[i] * price[i];
    }

    double averagePrice = totalPrice / totalQuantity;

    cout << "Total Quantity: " << totalQuantity << endl;
    cout << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
    cout << "Average Price: $" << fixed << setprecision(2) << averagePrice << endl;
}

int main() {
    string userInput;
    do {
        // Display the menu
        cout << "Hello and welcome to my wacky wares, how would you like to look at my merchandise?:" << endl;
        cout << "A. Show Full Catalog" << endl;
        cout << "B. Search by Category" << endl;
        cout << "C. Leave" << endl;
        cout << "Enter your choice (A, B, C): ";
        cin >> userInput;

        // Convert userInput to lowercase for comparison
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        if (userInput == "a") {
            displayItems();
        }
        else if (userInput == "b") {
            string categoryInput;
            cout << "What category does your mind ponder? (Enter “CL” to view list): ";
            cin >> categoryInput;

            // Convert categoryInput to lowercase
            transform(categoryInput.begin(), categoryInput.end(), categoryInput.begin(), ::tolower);

            if (categoryInput == "cl") {
                // Display category list here
                cout << "Available categories: Wearables, Equipment, Consumables, Materials, Miscellaneous" << endl;
                cout << "What category does your mind ponder? (Enter “CL” to view list): ";
                cin >> categoryInput;

                // Convert categoryInput to lowercase
                transform(categoryInput.begin(), categoryInput.end(), categoryInput.begin(), ::tolower);
            }

            filterByCategory(categoryInput);
        }
        else if (userInput == "c") {
            cout << "Good riddance." << endl;
            break;  // Exit the loop and end the program
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Continue? (Yes or No): ";
        cin >> userInput;

        // Convert userInput to lowercase
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
    } while (userInput == "yes");

    if (userInput == "no") {
        cout << "Good, now get lost." << endl;
    }

    return 0;
}
