#include<stdio.h>
#include<stdlib.h>
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
void mainList(void){
    system("cls");
printf("\t            -------------------------------------------------------\n");
    printf("                          Welcome to IITP departmental store\n");
    printf("\t            -------------------------------------------------------\n");
   printf("\t 1. CUSTOMER SECTION\n \t 2. ABOUT THE PROJECT \n\t 3. EXIT-->\n\n\n Enter your choice--->");
    int choice;
    scanf("%d", &choice);
    if(choice==1){
     customer();

    }
    else if(choice==2){
        // system("cls");
        printf("About project");
        if(getch())
        mainList();

    }
    else{
        system("cls");

        printf("     !!!! THANK YOU !!!!     \n");
        printf("         Visit again   :)       ");
        exit(0);
    }

 }

void customer(void){
     system("cls");//To escape from previous printed screen.
    printf("\tYou are about to Order----->\n \t 1.Grocery Items\n\t 2. Medicines\n\t 3.Electrical Appliances\n\t 4.Fast Food\n\t 5.Clothing \n\t 6.View Order\n\t 7.Back to Main Menu\n\n\n Enter your choice--->");
    int c;
    scanf("%d",&c);
    if(c==1){
        system("cls");
    add_new_products();
       //groceryItem();
    }
    else if(c==2){
         system("cls");
       // Medicine();
    }
    else if(c==3){
         system("cls");
        //groceryItem();
    }
    else if(c==4){
         system("cls");
        //groceryItem();
    }
    else if(c==5){
         system("cls");
        //groceryItem();
    }
    else if(c==6){
         system("cls");
      //  ViewOrder();
    }
    else if(c==7){
         system("cls");
       mainList();
    }
    else{
        printf("Wrong Input .......\n\t Kindly input the correct option.");
        if(getch())
        customer();
    }

}
void add_new_products(void){

    printf("Enter number of products: ");
    int num;
    scanf("%d",&num);
    for(int i=0; i<num; i++){

        char product_no[50];
        char product_name[100];
        int quantity;
        int price;

        printf("Enter product number : ");
        scanf("%s",&product_no);
        printf("Enter product_name : ");
        scanf("%s",&product_name);
        printf("Enter quantity : ");
        scanf("%d",&quantity);
        printf("Enter price : ");
        scanf("%d",&price);

     FILE *products;
    products=fopen("products.txt","a");
        fprintf(products,"%s \t\t\t %s \t\t\t %d \t\t\t %d\n", product_no , product_name , quantity , price);
       fclose(products);
    }
    int select;
      printf("Press number: \n 1. Continue Shopping \n 2.Exit");
      scanf("%d",&select);
      if(select==1){
        customer();
      }
      else if(select==2){
       newCustomer();
      }
   
}
void groceryItem(){

}
void newCustomer(){

   

    char customer_name[50];
    char address[100];
    int phone_no[10];
    int due_amount;
    printf("Input Customer Details \n");
    printf("NAME : ");
    scanf("%s",&customer_name);
    printf("ADDRESS : ");
    scanf("%s",&address);
    printf(" PHONE NO. : ");
    scanf("%d",&phone_no);
    printf("Enter due_amount : ");
    scanf("%d",&due_amount);
    printf("\n\n");
    printf("Your Entered Details are---> \n");

   FILE *customer;
    customer=fopen("customer.txt","a");
    fprintf(customer,"Order by: \n%s \t %s \t %d \t %d\n",customer_name , address , phone_no , due_amount);
    fclose(customer);
    printf("Name--> %s\n Address-->%s \n Phone No.-->%d\n Due Amount--> %d\n",customer_name , address , phone_no , due_amount);
     display_available_products();
   printf("--------------------------------------------\n");
  printf("Your Order will be delivered at your address tomorrow...\n \t\t\t THANK YOU!!!");
   printf("--------------------------------------------\n");
    
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
    products=fopen("products.txt","r");
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
   mainList();
  

 
return 0;
}