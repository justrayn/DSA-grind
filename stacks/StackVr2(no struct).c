#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    int date;
    int month;
    int year;
} Date;

typedef struct {
    int prodID;
    char prodName[20];
    Date prodExp;
    float prodPrice;
    int prodQty;
} Product;

// Stack type: stack[0].prodID = current size
typedef Product ProductStk[MAX];

// --- Function prototypes ---
Product createProduct(int id, char name[], Date dexp, float price, int qty);
Date createDate(int date, int month, int year);
void populateStack(ProductStk s);
void push(ProductStk s, Product p);
Product pop(ProductStk s);
Product peek(ProductStk s);
int isEmpty(ProductStk s);
int isFull(ProductStk s);

// --- MAIN ---
int main() {
    ProductStk prodStk;
    populateStack(prodStk);

    // Print all products in stack (LIFO order)
    while (!isEmpty(prodStk)) {
        Product p = pop(prodStk);
        printf("%d - %s (%.2f)\n", p.prodID, p.prodName, p.prodPrice);
    }

    return 0;
}

// --- Functions ---
Product createProduct(int id, char name[], Date dexp, float price, int qty) {
    Product p;
    p.prodID = id;
    strcpy(p.prodName, name);
    p.prodExp = dexp;
    p.prodPrice = price;
    p.prodQty = qty;
    return p;
}

Date createDate(int date, int month, int year) {
    Date d = {date, month, year};
    return d;
}

void populateStack(ProductStk s) {
    s[0].prodID = 0;  // size = 0

    push(s, createProduct(1005, "Binangkal", createDate(15, 6, 2026), 12.50, 40));
    push(s, createProduct(1010, "Bingka", createDate(12, 7, 2027), 20.00, 5));
    push(s, createProduct(1020, "Budbud", createDate(12, 7, 2027), 20.00, 5));
}

void push(ProductStk s, Product p) {
    if (!isFull(s)) {
        int top = ++s[0].prodID; // increment size
        s[top] = p;
    }
}

Product pop(ProductStk s) {
    if (!isEmpty(s)) {
        int top = s[0].prodID--;
        return s[top];
    }
    Product empty = {0, "", {0,0,0}, 0.0, 0};
    return empty;
}

Product peek(ProductStk s) {
    if (!isEmpty(s)) {
        return s[s[0].prodID];
    }
    Product empty = {0, "", {0,0,0}, 0.0, 0};
    return empty;
}

int isEmpty(ProductStk s) {
    return s[0].prodID == 0;
}

int isFull(ProductStk s) {
    return s[0].prodID == MAX - 1;
}
