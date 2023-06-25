#include<stdio.h>
#include<string.h>
#include<conio.h>

struct customer{

    char name[50];
    char address[100];
    char phone_no[10];
    int udhar;

};

struct item{
    char product_no[50];
    char product_name[100];
    int quantity;
    int price;
};

void add_new_products(){

    FILE *products;
    products=fopen("products.txt","a");
    printf("Enter number of products : ");
    int num;
    scanf("%d",&num);
    for(int i=0; i<num; i++){

        char product_no[50];
        char product_name[100];
        int quantity;
        int price;

        printf("Enter product number : ");
        scanf("%s",product_no);
        printf("Enter product_name : ");
        scanf("%s",product_name);
        printf("Enter quantity : ");
        scanf("%d",&quantity);
        printf("Enter price : ");
        scanf("%d",&price);

        fprintf(products,"%s \t %s \t %d \t %d\n", product_no , product_name , quantity , price);

    }

    fclose(products);
}

void newCustomer(){

    FILE *customer;
    customer=fopen("customer.txt","a");

    char customer_name[50];
    char address[100];
    char phone_no[10];
    int due_amount;

    printf("Enter name of the customer : ");
    scanf("%s",customer_name);
    printf("Enter address of customer : ");
    scanf("%s",address);
    printf("Enter phone_no of customer : ");
    scanf("%s",phone_no);
    printf("Enter due_amount : ");
    scanf("%d",&due_amount);

    fprintf(customer,"%s \t %s \t %s \t %d\n",customer_name , address , phone_no , due_amount);

    fclose(customer);
}

void cart(){

    FILE *cart;
    cart=fopen("cart.txt","w");
    printf("Enter products_no of product to buy : ");
    char product_no[50];
    scanf("s",product_no);

    fclose(cart);
} 

void display_available_products(){

    FILE *products;
    products=fopen("products,txt","r");
    printf("Product No\t Product Name\t Quantity\t Price\n");

    struct item item1;
    int st;
    char str[50];
    while(fscanf(products,"%*s %s %*s %*s",str)==1){
        printf("str == %s\n",str);
        //printf("%s %s %d %d",item1.product_no, item1.product_name, item1.quantity, item1.price);
    }

    fclose(products);
}

int main(){

    printf("                        Welcome to IITP departmental store\n");

    
    add_new_products();
    display_available_products();

}