#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
    char name[100];
    float price; 
} MenuItem;

//define new_menu_item

MenuItem new_menu_item ( char item_name[], float item_price ){
    MenuItem newItem; 
    strcpy(newItem.name, item_name);
    newItem.price = item_price;
    return newItem; 
}

void print_menu( int number_of_items, MenuItem all_items[number_of_items]){
    for (int i = 0; i < number_of_items; i++){
        printf("%s -\t$%.02f\n", all_items[i].name, all_items[i].price);
    }
    return;
}

int main(){
    MenuItem menu[2];

    menu[0] = new_menu_item("Caesar Salad", 6.10);
    menu[1] = new_menu_item("Fruit Loops", 14.30);

    print_menu(2, menu);
    return 0;

    
}