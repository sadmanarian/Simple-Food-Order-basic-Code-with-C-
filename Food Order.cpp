#include <iostream>
#include <sstream>  
#include <cstring>  
using namespace std;

int main() {
    const char* menu[] = {
        "Pizza (Large) - $12.99",
        "Burger (Deluxe) - $9.50",
        "Fries (Large) - $3.75",
        "Salad (Greek) - $7.25",
        "Drink (Soda) - $1.50"
    };
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    cout << "** Welcome to Our Delicious Menu! **\n\n";

    for (int i = 0; i < menuSize; ++i) {
        cout << i + 1 << ". " << menu[i] << endl;
    }

    cout << "\n** Enter your order by selecting item numbers (separated by spaces) or '0' to finish: **\n";

    const int MAX_ORDERS = 50;
    char order[MAX_ORDERS][50];
    int orderCount = 0;

    string input;
    getline(cin, input);

    stringstream ss(input);
    int itemNumber;

    while (ss >> itemNumber) {
        if (itemNumber == 0) {
            break;
        }
        if (itemNumber >= 1 && itemNumber <= menuSize) {
            strcpy(order[orderCount], menu[itemNumber - 1]);
            orderCount++;
        } else {
            cout << "Invalid item number: " << itemNumber << endl;
        }
    }

    if (orderCount == 0) {
        cout << "\n** You haven't ordered anything. **\n";
    } else {
        cout << "\n** Your Order: **\n";
        for (int i = 0; i < orderCount; ++i) {
            cout << "- " << order[i] << endl;
        }
    }

    return 0;
}
