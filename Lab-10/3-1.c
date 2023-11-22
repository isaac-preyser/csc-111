#include <stdio.h>
#include <string.h>

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char customer_name[1000]; //Name of the customer placing the order
    int order_number; //The order number
    Date order_date; //The date on which the order was placed
    float total_price;
} Order;

/* print_order(the_order)
   Given an Order object, print the order's details in the same format
   described in the section above.
*/
void print_order(Order the_order){
    /* Your code here */
    printf("Order %3d: Placed by %s on %2d/%2d/%4d (price: $%.02f)\n",
    the_order.order_number,
    the_order.customer_name,
    the_order.order_date.day, the_order.order_date.month, the_order.order_date.year,
    the_order.total_price);
}
/* create_order(order_number, year, month, day, customer_name, price)
   Create and return an Order object which has been pre-filled with the
   provided parameters.
*/
Order create_order( int order_number, int year, int month, int day, char customer_name[], float price ){
    /* Your code here */
    Order new_order;
    strcpy(new_order.customer_name, customer_name);
    new_order.order_number = order_number;
    new_order.order_date.day = day;
    new_order.order_date.month = month;
    new_order.order_date.year = year;
    new_order.total_price = price;
    return new_order;
}

/* change_price(order_ptr, new_price)
   Given an pointer to an Order object and a new total price, set
   the total_price component of the provided Order to the new price.

   You may want to use the arrow operator (written ->),
   but you are not required to do so (the combination of * and . also works).
*/
void change_price(Order* order_ptr, float new_price){
    /* Your code here */
    order_ptr->total_price = new_price; 
}

/* change_date(order_ptr, new_year, new_month, new_day)
   Given an pointer to an Order object and a new date, set
   the date of the provided order to the new values.

   You may want to use the arrow operator (written ->),
   but you are not required to do so (the combination of * and . also works).
*/
void change_date(Order* order_ptr, int new_year, int new_month, int new_day){
    /* Your code here */
    order_ptr->order_date.year = new_year;
    order_ptr->order_date.month = new_month;
    order_ptr->order_date.day = new_day; 
}


int main(){

    Order orderA = create_order(111, 2023, 11, 25, "Rebecca Raspberry", 6.10);
    Order orderB = create_order(116, 2023, 11, 29, "Fiona Framboise", 17.0);

    //Print each order
    print_order(orderA);
    print_order(orderB);

    //Now reassign orderB to have different details (notice that an initializer could not be used here)
    orderB = create_order(225, 2019, 10, 6, "Neal Naranja", 18.7);
    //Print the new order
    print_order(orderB);

    //Change the price of orderA to be $11.1
    change_price(&orderA, 11.1);

    //Change the date of orderB to be March 12th, 2018
    change_date(&orderB, 2018, 3, 12);

    //Print each order
    print_order(orderA);
    print_order(orderB);

    return 0;
}