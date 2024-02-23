// Product, Item, Cart
#include <string>
#include <unordered_map>

// Forward Declarations
class Item;
class Cart;

class Product {
    int id {};
    std::string name;
    int price {};

public:
    Product() {
    }

    Product(int id, std::string name, int price)
        : id { id }
        , name { name }
        , price { price } {
    }

    std::string getDisplayName() const {
        return name + " : Rs " + std::to_string(price) + "\n";
    }

    std::string getShortName() const {
        return name.substr(0, 1);
    }

    friend class Item;
    friend class Cart;
};

class Item {
    Product product {};
    int quantity {};

public:
    Item() {
    }

    Item(Product product, int quantity)
        : product(product)
        , quantity(quantity) {
    }

    int getItemPrice() const {
        return quantity * product.price;
    }

    std::string getItemInfo() const {
        return std::to_string(quantity) + " x " + product.name + " Rs. " + std::to_string(quantity * product.price) + "\n";
    }

    friend class Cart;
};

class Cart {
    std::unordered_map<int, Item> items;

public:
    void addProduct(Product product) {
        if (items.count(product.id) == 0) {
            Item newItem(product, 1);
            items[product.id] = newItem;
        } else {
            items[product.id].quantity += 1;
        }
    }

    int getTotal() const {
        // Todo
        int total {};
        for (auto itemPair : items) {
            auto item = itemPair.second;
            total += item.getItemPrice();
        }
        return total;
    }

    std::string viewCart() const {
        if (items.empty()) {
            return "Cart is empty";
        }

        std::string itemizedList;
        int cart_total = getTotal();

        for (auto itemPair : items) {
            auto item = itemPair.second;
            itemizedList.append(item.getItemInfo());
        }
        return itemizedList + "\n Total Amount : Rs. " + std::to_string(cart_total);
    }

    bool isEmpty() const {
        return items.empty();
    }
};