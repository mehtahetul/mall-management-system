#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<conio.h>

struct node{
    char name[100];
    int shop_id;
    char GST_no[50];
    char shop_type[100];
    char rent[50];
    int stock;
    int avg_sales;
    char owner_name[50];
	char carpet_area[100];
    int tick;
	struct node *next;
};

struct node *searched=NULL;

void make_f1(struct node **h1){
    FILE *f1 = fopen("floor1.txt","r");
    struct node shop,*temp1=*h1,*details;
    while(fscanf(f1,"%s %d %s %s %s %d %d %s %s\n",shop.name,&shop.shop_id,shop.GST_no,shop.shop_type,shop.rent,&shop.stock,&shop.avg_sales,shop.owner_name,shop.carpet_area)!=EOF){
        temp1=*h1;
        details = (struct node*)malloc(sizeof(struct node));
        strcpy(details->name,shop.name);
        details->shop_id=shop.shop_id;
        strcpy(details->GST_no,shop.GST_no);
        strcpy(details->shop_type,shop.shop_type);
        strcpy(details->rent,shop.rent);
        details->stock=shop.stock;
        details->avg_sales=shop.avg_sales;
        strcpy(details->owner_name,shop.owner_name);
        strcpy(details->carpet_area,shop.carpet_area);
        details->next=NULL;
        details->tick=0;
        if(*h1==NULL){
            *h1=details;
        }
        else{
            while(temp1->next!=NULL){
                temp1=temp1->next;
            }
            temp1->next=details;
        }
    }
}

void make_f2(struct node **h2){
    FILE *f2 = fopen("floor2.txt","r");
    struct node shop,*temp2=*h2,*details;
    while(fscanf(f2,"%s %d %s %s %s %d %d %s %s\n",shop.name,&shop.shop_id,shop.GST_no,shop.shop_type,shop.rent,&shop.stock,&shop.avg_sales,shop.owner_name,shop.carpet_area)!=EOF){
        temp2=*h2;
        details = (struct node*)malloc(sizeof(struct node));
        strcpy(details->name,shop.name);
        // strcpy(details->shop_id,shop.shop_id);
        details->shop_id = shop.shop_id;
        strcpy(details->GST_no,shop.GST_no);
        strcpy(details->shop_type,shop.shop_type);
        strcpy(details->rent,shop.rent);
        details->stock=shop.stock;
        details->avg_sales=shop.avg_sales;
        strcpy(details->owner_name,shop.owner_name);
        strcpy(details->carpet_area,shop.carpet_area);
        details->next=NULL;
        details->tick=0;
        if(*h2==NULL){
            *h2=details;
        }
        else{
            while(temp2->next!=NULL){
                temp2=temp2->next;
            }
            temp2->next=details;
        }
    }
}

void make_f3(struct node **h3){
    FILE *f3 = fopen("floor3.txt","r");
    struct node shop,*temp3=*h3,*details;
    while(fscanf(f3,"%s %d %s %s %s %d %d %s %s\n",shop.name,&shop.shop_id,shop.GST_no,shop.shop_type,shop.rent,&shop.stock,&shop.avg_sales,shop.owner_name,shop.carpet_area)!=EOF){
        temp3=*h3;
        details = (struct node*)malloc(sizeof(struct node));
        strcpy(details->name,shop.name);
        // strcpy(details->shop_id,shop.shop_id);
        details->shop_id = shop.shop_id;
        strcpy(details->GST_no,shop.GST_no);
        strcpy(details->shop_type,shop.shop_type);
        strcpy(details->rent,shop.rent);
        details->stock=shop.stock;
        details->avg_sales=shop.avg_sales;
        strcpy(details->owner_name,shop.owner_name);
        strcpy(details->carpet_area,shop.carpet_area);
        details->next=NULL;
        details->tick=0;
        if(*h3==NULL){
            *h3=details;
        }
        else{
            while(temp3->next!=NULL){
                temp3=temp3->next;
            }
            temp3->next=details;
        }
    }
}

void display(struct node *h){
    char name[10]= "Shop Name";
    char id[10]="Shop ID",GST[10]="GST no",type[10]="Shop Type",rentt[10]="Rent",stockk[10]="Stock",avgsls[20]="Average Sales",owname[25]="Owner Name",area[30]="Carpet Area";
    printf("%-15s%-10s%-15s%-20s%-15s%-15s%-15s%-15s%-15s%-20s\n",name,id,GST,type,rentt,stockk,avgsls,owname,area,"Customers visited");
    printf("\n\n");
    while(h!=NULL){
        if((h->stock) > 0){
            
        printf("%-15s%-10d%-15s%-20s%-15s%-15d%-15d%-15s%-15s%-20d\n",h->name,h->shop_id,h->GST_no,h->shop_type,h->rent,h->stock,h->avg_sales,h->owner_name,h->carpet_area,h->tick);
        }
        else{
            printf("%s is closed due to lack of stock!!!\n",h->name);
        }
        h=h->next;
    }
}

void details(struct node **h,char a[]){
    searched = *h;
    printf("Available shops: \n");
    while(searched!=NULL){
        if((searched->stock) > 0){
            
        if(!strcmp(searched->shop_type,a)){
            printf("Shop name: %s\n",searched->name);
            printf("Shop Number: %d\n",searched->shop_id);
            searched->tick++;
            printf("\n");
        }
        }
        searched=searched->next;
    }
}

void stock(struct node **h){
    searched = *h;
    while(searched != NULL){
        if(searched->tick != 0){
            printf("Enter today's sales for shop %s: ",searched->name);
            int salestoday;
            scanf("%d",&salestoday);
            searched->stock-=salestoday;
        }
        searched = searched->next;
    }
}

void close(struct node **h,char *a){
    searched = *h;
    struct node *t=(*h);
    t = searched;
    if(!strcmp((*h)->name,a)){
       (*h) = (*h)->next;
        free(t);
        return;
    }
    else{
    while(searched != NULL){
        if(!strcmp(searched->name,a)){
            break;
        }
        t=searched;
        searched = searched->next;
    }
    if(searched == NULL){
        printf("No such shop is there!!!\n");
    }
    else{
            t->next=searched->next;
            free(searched);
        }
    }
}

void user(struct node **h1, struct node **h2, struct node **h3){
    int flag=1;
    while(flag){
        printf("Welcome!!!\n\n");
        printf("Select from the following:\n1. Shopping\n2. Food\n3. Games\n4. Exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Shops are available on floor 1\n");
                printf("Select the genre:\n1. Cafe\n2. Clothing\n3. Footwear\n4. Electronics\n5. Watches\n");
                int k;
                scanf("%d",&k);
                switch(k){
                    case 1:
                        details(h1,"Cafe");
                        break;
                    case 2:
                        details(h1,"Clothing");
                        break;
                    case 3:
                        details(h1,"Footwear");
                        break;
                    case 4:
                        details(h1,"Electronics");
                        break;
                    case 5:
                        details(h1,"Watches");
                        break;
                    default:
                        printf("Enter appropriate integer\n");
                        break;
                }
                break;
            case 2:
                printf("Food is available on floor 2\n");
                printf("Select the genre:\n1. Tacos & nachos\n2. Subs\n3. Burgers & fries\n4. Pizzas\n5. Icecream\n6. SouthIndian\n7. Fastfood\n8. Cookies\n");
                int l;
                scanf("%d",&l);
                switch(l){
                    case 1:
                        details(h2,"Tacos&nachos");
                        break;
                    case 2:
                        details(h2,"Subs");
                        break;
                    case 3:
                        details(h2,"Burgers&fries");
                        break;
                    case 4:
                        details(h2,"Pizzas");
                        break;
                    case 5:
                        details(h2,"Icecream");
                        break;
                    case 6:
                        details(h2,"SouthIndian");
                        break;
                    case 7:
                        details(h2,"Fastfood");
                        break;
                    case 8:
                        details(h2,"Cookies");
                        break;
                    default:
                        printf("Enter appropriate integer\n");
                        break;
                }
                break;
            case 3:
                printf("Games are available on 3rd floor\n");
                printf("Select from the following:\n1. Cricket\n2. Bowling\n3. Lasertag\n4. Fun games\n5. Golf\n6. Jumping area\n");
                int game;
                scanf("%d",&game);
                switch(game){
                    case 1:
                        details(h3,"Cricket");
                        break;
                    case 2:
                        details(h3,"Bowling");
                        break;
                    case 3:
                        details(h3,"lasertag");
                        break;
                    case 4:
                        details(h3,"fungames");
                        break;
                    case 5:
                        details(h3,"golf");
                        break;
                    case 6:
                        details(h3,"Jumpingarea");
                        break;
                    default:
                        printf("Enter appropriate integer\n");
                        break;
                }
                break;
            case 4:
                flag=0;
                printf("Thank you for visiting\n");
                break;
            default:
                printf("Select an appropriate choice\n");
                break;
        }
    }
}

void add_new(struct node **h,char *a){
    searched = *h;
    struct node *t = (struct node *)malloc(sizeof(struct node));
    while(searched->next != NULL){
        searched = searched->next;
    }
    searched->next = t;
    t->shop_id = searched->shop_id + 1;
    printf("\nThe shop ID is: %d\n",(searched->shop_id)+1);
    strcpy(t->shop_type,a);
    printf("\nEnter the following details:\n");
    printf("\nName: ");
    scanf("%s",t->name);
    printf("GST no.: ");
    scanf("%s",t->GST_no);
    printf("Rent: ");
    scanf("%s",t->rent);
    printf("Stock: ");
    scanf("%d",&t->stock);
    printf("Avg Sales: ");
    scanf("%d",&t->avg_sales);
    printf("Owner's name: ");
    scanf("%s",t->owner_name);
    printf("Carpet area: ");
    scanf("%s",t->carpet_area);
    t->tick=0;
    t->next = NULL;
    printf("\n\n");
}

void admin(struct node **h1, struct node **h2, struct node **h3){
    int key;
    printf("Enter the security key: ");
    retry:
    scanf("%d",&key);
    if(key==7){
        int flag1=1;
        while(flag1){
            printf("Select from the following\n1. Display details\n2. Close a shop\n3. Add a new shop\n4. Exit\n");
            int m;
            scanf("%d",&m);
            switch(m){
                case 1:
                    printf("FLOOR 1:\n");
                    display(*h1);
                    printf("\n\n\n");
                    printf("FLOOR 2:\n");
                    display(*h2);
                    printf("\n\n\n");
                    printf("FLOOR 3:\n");
                    display(*h3);
                    break;
                case 2:
                    printf("Which floor's shop do you want to close ?\n1. FLOOR 1\n2. FLOOR 2\n3. FLOOR 3\n");
                    int de;
                    scanf("%d",&de);
                    switch(de){
                        case 1:
                            printf("Enter the shop name (case sensitive): ");
                            char sh1[20];
                            fflush(stdin);
                            gets(sh1);
                            close(h1,sh1);
                            break;
                        case 2:
                            printf("Enter the shop name (case sensitive): ");
                            char sh2[20];
                            fflush(stdin);
                            gets(sh2);
                            close(h2,sh2);
                            break;
                        case 3:
                            printf("Enter the shop name (case sensitive): ");
                            char sh3[20];
                            fflush(stdin);
                            gets(sh3);
                            close(h3,sh3);
                            break;
                        default:
                            printf("Enter the appropriate choice!!!\n");
                            break;
                    }
                    break;
                case 3:
                    printf("Select the type of the shop:\n1. Shopping\n2. Food\n3. Game\n");
                    int stype;
                    scanf("%d",&stype);
                    switch(stype){
                        case 1:
                            printf("Select the genre:\n1. Cafe\n2. Clothing\n3. Footwear\n4. Electronics\n5. Watches\n");
                            int k;
                            scanf("%d",&k);
                            switch(k){
                                case 1:
                                    add_new(h1,"Cafe");
                                    break;
                                case 2:
                                    add_new(h1,"Clothing");
                                    break;
                                case 3:
                                    add_new(h1,"Footwear");
                                    break;
                                case 4:
                                    add_new(h1,"Electronics");
                                    break;
                                case 5:
                                    add_new(h1,"Watches");
                                    break;
                                default:
                                    printf("Enter appropriate integer\n");
                                    break;
                            }
                            break;
                        case 2:
                            printf("Select the genre:\n1. Tacos & nachos\n2. Subs\n3. Burgers & fries\n4. Pizzas\n5. Icecream\n6. SouthIndian\n7. Fastfood\n8. Cookies\n");
                            int l;
                            scanf("%d",&l);
                            switch(l){
                                case 1:
                                    add_new(h2,"Tacos&nachos");
                                    break;
                                case 2:
                                    add_new(h2,"Subs");
                                    break;
                                case 3:
                                    add_new(h2,"Burgers&fries");
                                    break;
                                case 4:
                                    add_new(h2,"Pizzas");
                                    break;
                                case 5:
                                    add_new(h2,"Icecream");
                                    break;
                                case 6:
                                    add_new(h2,"SouthIndian");
                                    break;
                                case 7:
                                    add_new(h2,"Fastfood");
                                    break;
                                case 8:
                                    add_new(h2,"Cookies");
                                    break;
                                default:
                                    printf("Enter appropriate integer\n");
                                    break;
                            }
                            break;
                        case 3:
                            printf("Select from the following:\n1. Cricket\n2. Bowling\n3. Lasertag\n4. Fun games\n5. Golf\n6. Jumping area\n");
                            int game;
                            scanf("%d",&game);
                            switch(game){
                                case 1:
                                    add_new(h3,"Cricket");
                                    break;
                                case 2:
                                    add_new(h3,"Bowling");
                                    break;
                                case 3:
                                    add_new(h3,"lasertag");
                                    break;
                                case 4:
                                    add_new(h3,"fungames");
                                    break;
                                case 5:
                                    add_new(h3,"golf");
                                    break;
                                case 6:
                                    add_new(h3,"Jumpingarea");
                                    break;
                                default:
                                    printf("Enter appropriate integer\n");
                                    break;
                                }
                            break;
                    }
                    break;
                case 4:
                    flag1=0;
                    break;
                default:
                    printf("Enter the appropriate choice\n");
                    break;
            }
        }
    }
    else{
        printf("RETRY!!!\n");
        goto retry;
    }
}

void reset_tick(struct node **h){
    searched = *h;
    while(searched != NULL){
        searched->tick=0;
        searched = searched->next;
    }
}

int main()
{
    int wee=1;
    struct node *h1=NULL, *h2=NULL, *h3 = NULL;
    make_f1(&h1);
    make_f2(&h2);
    make_f3(&h3);
    while(wee){
        user(&h1,&h2,&h3);
        stock(&h1);
        stock(&h2);
        stock(&h3);
        printf("\n\nDo you want to use Admin controls ?\n1. Yes\n2. No\n");
        int y;
        label1:
        scanf("%d",&y);
        if(y==1){
            admin(&h1,&h2,&h3);
            
        }
        else if(y!=1 && y!=2){
            printf("Enter the appropriate choice!!!\n");
            goto label1;
        }
        printf("\n\nDo you want to reset the original data of the Mall?\n1. Yes\n2. No\n");
        int x;
        label:
        scanf("%d",&x);
        if(x==1){
            h1=NULL, h2=NULL, h3 = NULL;
            make_f1(&h1);
            make_f2(&h2);
            make_f3(&h3);
        }
        else if(x==2){
            reset_tick(&h1);
            reset_tick(&h2);
            reset_tick(&h3);
        }
        else if(x!=1 && x!=2){
            printf("Enter the appropriate choice!!!\n");
            goto label;
        }
        printf("To continue, press any\n");
        printf("To close, press 0\n");
        int bye;
        scanf("%d",&bye);
        if (!bye){
            wee=0;
        }
    }
    return 0;
}