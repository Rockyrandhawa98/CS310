#include <iostream>

int main() {
    float price_of_item;
    double mark_up;
    double sales_tax_rate;

    std::cout << "What is the initial price of the item? " << std::endl;
    std::cin >> price_of_item;
    std::cout << "What is the store's mark-up rate? \n(Please enter as a decimal; For instance, if the mark-up is 15%, enter 0.15.) " << std::endl;
    std::cin >> mark_up;
    std::cout << "What is the sales tax? \n(Please enter as a decimal; For instance, if the sales tax is 15%, enter 0.15.) " << std::endl;
    std::cin >> sales_tax_rate;

    double store_selling_price = price_of_item + (price_of_item * mark_up);
    double sales_tax = store_selling_price * sales_tax_rate;
    double final_price = store_selling_price + sales_tax;

    std::cout << "The initial price of the item is $" << price_of_item << "." << std::endl;
    std::cout << "The mark up is " << mark_up * 100 << "%." << std::endl;
    std::cout << "The store is selling the item at $" << store_selling_price << "." << std::endl;
    std::cout << "The sales tax rate is " << sales_tax_rate * 100 << "%." << std::endl;
    std::cout << "The sales tax is $" << sales_tax << "." << std::endl;
    std::cout << "The final sale price is $" << final_price << "." << std::endl;
    return 0;
}
