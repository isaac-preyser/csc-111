#include <stdio.h>
#include <string.h>


typedef struct {
    char name[100];
    float price;
} Product;

typedef struct {
    char customer_name[1000]; //Name of the customer placing the order
    int order_number; //The order number
    int num_contents; //Number of products present in the order
    Product contents[100]; //Array of products in the order (the first num_contents elements are valid)
} Order;

/* create_empty_order( customer_name, order_number)
   Create and return an Order object containing the provided
   name and order number, with the number of contents set to
   zero.
*/
Order create_empty_order( char customer_name[], int order_number ){
    Order new_order;
    strcpy(new_order.customer_name,customer_name);
    new_order.order_number = order_number;
    new_order.num_contents = 0;
    return new_order;
}

/* print_order( order_ptr )
   Given a pointer to an order, print the order in the format shown in the previous section.
*/
void print_order(Order* order_ptr){
    /* Your code here */
    printf("Order %d: Placed by %s\n", order_ptr->order_number, order_ptr->customer_name);
    for (int i = 0; i < order_ptr->num_contents; i++){
        printf("\tProduct %s: $%.02f\n", order_ptr->contents[i].name, order_ptr->contents[i].price );
    }
}

/* get_order_cost( order_ptr )
   Given a pointer to an order, return the total cost of the order (by adding up the cost
   of each product in the order)
*/
float get_order_cost(Order* order_ptr){
    /* Your code here */
    float sum = 0;
    for (int i = 0; i < order_ptr->num_contents; i++){
        sum += order_ptr->contents[i].price;
    }
    return sum;
}

Product create_product(char product_name[100], float product_price){
    Product new_product;
    strcpy(new_product.name, product_name);
    new_product.price = product_price; 
    return new_product; 
}


/* add_item_to_order( order_ptr, product_name, product_price )
   Given a pointer to an order, the name of a product and the price
   of that product, add the product to the order at the end of the
   contents array (after the last valid item). Don't forget to update
   the num_contents variable.
*/
void add_item_to_order(Order* order_ptr, char product_name[100], float product_price ){
    /* Your code here */
    order_ptr->contents[order_ptr->num_contents] = create_product(product_name, product_price); //come back to me! 
    //does this work? no strcpy used, so editing wont work. however, every time we create a product we instantiate a new copy of the class, so like it should probably work (memory issue though?)
    order_ptr->num_contents++;
    return; 
}
int main(){

    //Create an order with order number 111, containing two products.
    Order orderA = create_empty_order("Fiona Framboise", 111);

    add_item_to_order(&orderA, "Pear", 1.50);
    add_item_to_order(&orderA, "Raspberries", 6.10);


    //Create an order with order number 116, containing three products.
    Order orderB = create_empty_order("Hannah Hindbaer", 116);

    add_item_to_order(&orderB, "Pineapple", 0.60);
    add_item_to_order(&orderB, "Grapefruit", 1.06);
    add_item_to_order(&orderB, "Pear", 1.25);


    //Print orderA (including all of its contents)
    print_order(&orderA);


    //Print orderB (including all of its contents)
    print_order(&orderB);


    printf("Cost of order %d: $%.2f\n", orderA.order_number, get_order_cost(&orderA));
    printf("Cost of order %d: $%.2f\n", orderB.order_number, get_order_cost(&orderB));


    return 0;
}