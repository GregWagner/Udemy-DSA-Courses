/*
 * Features:
 * 1) View produts
 * 2) Add product
 * 3) Checkout / Total
 *
 * Product			Item		Cart
 * 		ID			Product		Items
 * 		Name		Quantity	Total
 * 		Price		Price
 */
#include "datamodel.h"
#include <iostream>
#include <vector>

std::vector<Product> allProducts = {
    Product(1, "apple", 26),
    Product(3, "mango", 16),
    Product(2, "guava", 36),
    Product(5, "banana", 56),
    Product(4, "strawberry", 29),
    Product(6, "pineapple", 20),
};

Product* chooseProduct() {
    // Display the list of products
    std::string productList;
    std::cout << "Available Products\n";

    for (auto product : allProducts) {
        productList.append(product.getDisplayName());
    }
    std::cout << productList << '\n';

    std::cout << "----------------\n";
    std::string choice;
    std::cin >> choice;

    for (int i = 0; i < allProducts.size(); i++) {
        if (allProducts[i].getShortName() == choice) {
            return &allProducts[i];
        }
    }
    std::cout << "Product not found!\n";
    return nullptr;
}

bool checkout(Cart& cart) {
    if (cart.isEmpty()) {
        return false;
    }

    int total = cart.getTotal();
    std::cout << "Pay in Cash";

    int paid;
    std::cin >> paid;

    if (paid >= total) {
        std::cout << "Change " << paid - total << '\n';
        std::cout << "Thank you for shopping!\n";
        return true;
    } else {
        std::cout << "Not enough cash!\n";
        return false;
    }
}

int main() {
    char action;
    Cart cart;

    while (true) {
        std::cout << "Select an action -  (a)dd item, (v)iew cart, (c)heckout" << '\n';
        std::cin >> action;

        if (action == 'a') {
            // Add item to cart
            Product* product = chooseProduct();
            if (product != nullptr) {
                std::cout << "Added to the Cart " << product->getDisplayName() << '\n';
                cart.addProduct(*product);
            }
        } else if (action == 'v') {
            // View the Cart
            std::cout << "------------------\n";
            std::cout << cart.viewCart() << '\n';
            std::cout << "------------------\n";
        } else {
            // Checkout
            cart.viewCart();
            if (checkout(cart)) {
                break;
            }
        }
    }
}