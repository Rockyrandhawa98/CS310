#include <iostream>

int price_of_item = 15;
double mark_up = .15;
double store_selling_price = price_of_item + (price_of_item * mark_up);
double sales_tax_rate = .08;
double sales_tax = store_selling_price * sales_tax_rate;
double final_price = store_selling_price + sales_tax;

int main() {
    
    std::cout << "The initial price of the item is $" << price_of_item << "." << std::endl;
    std::cout << "The mark up is " << mark_up << "%." << std::endl;
    std::cout << "The store is selling the item at $" << store_selling_price << "." << std::endl;
    std::cout << "The sale's tax rate is " << sales_tax_rate << "%." << std::endl;
    std::cout << "The sale's tax is $" << sales_tax << "." << std::endl;
    std::cout << "The final sale price is $" << final_price << "." << std::endl;

    return 0;
}
