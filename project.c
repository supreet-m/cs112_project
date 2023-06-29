#include<stdio.h>
#include<string.h>
#include<conio.h>

typedef struct{

    char name[50];
    char address[50];
    char phone_no[10];
    int amount_to_pay;

} customer;

typedef struct{
    char product_no[50];
    char product_name[50];
    int quantity;
    int price;
} item;


void add_new_products(){

    FILE *products; //file pointer
    products=fopen("products.csv","a");
    if(products == NULL){
        printf("Errror opening file.\n");
        //exit(0);
    }
    else{
        printf("Enter number of products : ");
        int num; //number of records
        scanf("%d",&num);
        item prdct[num];  // prdct is stucture name of datatype item
        for(int i=0; i<num; i++){

            printf("Enter product number : ");
            scanf("%s",prdct[i].product_no);
            printf("Enter product_name : ");
            scanf("%s",prdct[i].product_name);
            printf("Enter quantity : ");
            scanf("%d",&prdct[i].quantity);
            printf("Enter price : ");
            scanf("%d",&prdct[i].price);

            fprintf(products,"%s,%s,%d,%d\n",
                            prdct[i].product_no,
                            prdct[i].product_name,
                            prdct[i].quantity,
                            prdct[i].price);

            if(ferror(products)){
                printf("Error writing to file");
                //exit(0);
            }
            
        }
    }

    fclose(products);
}

void newCustomer(){

    FILE *file;
    file = fopen("customer_file.csv","a");
    if(file == NULL) printf("Error opening file.\n");
    else
    {
        customer cstmr;
        printf("Enter name of the customer : ");
        scanf("%s",cstmr.name);
        printf("Enter address of customer : ");
        scanf("%s",cstmr.address);
        printf("Enter phone_no of customer : ");
        scanf("%s",cstmr.phone_no);
        cstmr.amount_to_pay=0;
        // printf("Enter amount_to_pay : ");
        // scanf("%d",&cstmr.amount_to_pay);

        //fprintf(file,"%s\t\t%s\t\t%s\t\t%d\n",customer_name , address , phone_no , due_amount);

        fprintf(file,"%s,%s,%s,%d",
                    cstmr.name,
                    cstmr.address,
                    cstmr.phone_no,
                    cstmr.amount_to_pay);

        fclose(file);
    }
}

void modify_products(){
    FILE *file;
    file=fopen("products.csv","a+");
    if(file==NULL) {
        printf("Error opening file.\n");
    }
    else{

    }


}

void cart(){

    FILE *prdct;
    prdct=fopen("products.csv","r+");
    int total_amount=0;
    item buy_items[50];   //to store the purchased items
    item array[50];       // to strore the items available


    int read=0; 
    int records=0;
    do
    {
        read=fscanf(prdct,"%49[^,],%49[^,],%d,%d",
                array[records].product_no,
                array[records].product_name,
                &array[records].quantity,
                &array[records].price);
        if(read==4) records++;
        
        if(read != 4 &&  (!feof(prdct))){
            printf("File formatting issue.\n");
        }

        if(ferror(prdct)) {
            printf("Error reading file.\n");
        }
    }
    while(!feof(prdct));


    int index = 0;  //index of array of structs (buy_items)
    
    buy: printf("");
    item product1;  //product1 is structure name of datatype item
    printf("Enter products_no of product to buy : ");
    scanf("%s",product1.product_no);
    printf("Enter product name : ");
    scanf("%s",product1.product_name);
    printf("Enter quantity : ");
    scanf("%d",&product1.quantity);

    for(int i=0; i<records; i++){
        if(strcmp(array[i].product_no , product1.product_no)){    //string comparision
            if(product1.quantity > array[i].quantity) {
                printf("Not enoungh quantity available of required product.\n");
            }
            else {
                product1.price = array[i].price;
                buy_items[index] = product1;
                index++;
                total_amount += (array[i].price * product1.quantity);
                break;
            }
        }
    }
    char ch[2];
    printf("Do you want to buy more(y/n) : ");
    scanf("%s",ch);
    
    if(!strcmp(ch,"y")){
        goto buy;
    }


    
    FILE *buy;
    buy = fopen("bought_items.csv","w");
    if(buy == NULL) {
        printf("Error in opening file.\n");
    }
    else {
        for(int i=0; i<index; i++){
            fprintf(buy,"%s,%s,%d,%d",
                    buy_items[i].product_no,
                    buy_items[i].product_name,
                    buy_items[i].quantity,
                    buy_items[i].price);
        }
    }

    modify_products();   // update the available products quantity  (not completed yet)
    
    fclose(buy);
    fclose(prdct);
} 

void bill(){

}

void display_available_products(){

    FILE *products;
    products=fopen("products.csv","r");
    if(products==NULL){
        printf("Error opening file.\n");
    }
    else{
        printf("Product No\tProduct Name\tQuantity\tPrice\n");

        item item1[100];   //array of structs to store products 

        int read = 0;
        int records = 0;
        do{
            //printf("tugu1");
            read=fscanf(products,"%49[^,],%49[^,],%d,%d",
                            item1[records].product_no,
                            item1[records].product_name,
                            &item1[records].quantity,
                            &item1[records].price);

            if(read==4) records++;
             //printf("tugu1");
            if(read != 4 &&  (!feof(products))){
                printf("File formatting issue.\n");
            }

            if(ferror(products)) {
                printf("Error reading file.\n");
            }
        }
        while(!feof(products));

        //printf("%d",records);
        for(int i=0; i<records; i++){
            printf("%s\t\t%s\t\t%d\t\t%d",
                    item1[i].product_no,
                    item1[i].product_name,
                    item1[i].quantity,
                    item1[i].price);
        }

    }

    fclose(products);
}

void administrator(){
    printf("Please Enter an Option: ");
    printf("01.Add New Products");
    printf("02.Display Available Products");
    printf("03.Main Menu");

    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        add_new_products();
        break;
    case 2:
        display_available_products();
        break;
    case 3:
        mainMenu();
        break;
    default:
        break;
    }

}

void customer_func(){

}

void mainMenu(){
    printf("                        Welcome to IITP departmental store\n");

    printf("01. ADMINISTRATOR\n");
	printf("02. CUSTOMER\n");
	printf("03. EXIT\n");

	printf("Please Enter an Option: ");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
            administrator();
            break;
        case 2:
            customer_func();
        case 3:
            printf("     !!!! THANK YOU !!!!     \n");
            printf("         Visit again   :)       ");
            break;
        default:
            printf("Wrong choice\n Please select a valid choice\n");
            break;
    }

}

int main(){

    cart();
    //mainMenu();
    //add_new_products();
    //newCustomer();
    //display_available_products();

}