#include <iostream>

int main() {
    float price_of_item;
    double mark_up;
    double sales_tax_rate;

    std::cout << "What is the initial price of the item? " << std::endl;
    std::cin >> price_of_item;
    std::cout << "What is the store's mark-up rate? " << std::endl;
    std::cin >> mark_up;
    std::cout << "What is the sale's tax? " << std::endl;
    std::cin >> sales_tax_rate;

    double store_selling_price = price_of_item + (price_of_item * mark_up);
    double sales_tax = store_selling_price * sales_tax_rate;
    double final_price = store_selling_price + sales_tax;

    std::cout << "The initial price of the item is $" << price_of_item << "." << std::endl;
    std::cout << "The mark up is " << mark_up << "%." << std::endl;
    std::cout << "The store is selling the item at $" << store_selling_price << "." << std::endl;
    std::cout << "The sale's tax rate is " << sales_tax_rate << "%." << std::endl;
    std::cout << "The sale's tax is $" << sales_tax << "." << std::endl;
    std::cout << "The final sale price is $" << final_price << "." << std::endl;

    return 0;
}
