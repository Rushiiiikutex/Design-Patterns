#include <iostream>
#include <string>
using namespace std;

class AuthService {
public:
    bool authenticate(string token) {
        return token == "valid_token";
    }
};

class ProductService {
public:
    void getProducts() {
        cout << "Products fetched successfully.\n";
    }
};

class APIGateway {
    AuthService auth;
    ProductService product;
public:
    void handleRequest(string token) {
        if (auth.authenticate(token)) {
            product.getProducts();
        } else {
            cout << "Unauthorized access!\n";
        }
    }
};

int main() {
    APIGateway gateway;
    gateway.handleRequest("valid_token");
    return 0;
}
