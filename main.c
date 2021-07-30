#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <dos.h>

#include "my_library.h"	

int main(){
	
	
		int var =0;                     //I defined control variables to check customerID and productID vs. 
	int *control=&var;
	cusptr cus;
	  
	    int vur=20;
	    int *i=&vur;
int yoruldum=5;
int*yor=&yoruldum;

	cus=(customer*)malloc(sizeof(customer));
    cus->next=NULL;
	eklesirali(cus,1,"Ali Karaman",1,(16.8),10,control);                            //I sent the values to function to save them in linkedlist here
	eklesirali(cus,2,"Zehra Çilek",0,(12.4),(6.9),control);
	eklesirali(cus,3,"Mehmet Derin",0,(10.55),(15,4),control);
	eklesirali(cus,4,"Veli Ortanca",1,(5.1),(1.2),control);
	eklesirali(cus,5,"Menekse Serin",1,2,(7.9),control);

	
	 *control=0;
	proptr pro;
	pro=(product*)malloc(sizeof(product));
	pro->next=NULL;
	readyproduct(pro,1,"Portakal Sikma",1,(5.99),control);                          //I sent the values to function to save them in linkedlist here
	readyproduct(pro,2,"Muz Yerli",1,(12.95),control);
	readyproduct(pro,3,"Sogan",2,(7.45),control);
	readyproduct(pro,4,"Pirasa",2,(3.95),control);
	readyproduct(pro,5,"Lahana",2,(5.95),control);
	readyproduct(pro,6,"Limon",1,(7.45),control);
    readyproduct(pro,7,"Hamsi",3,15,control);
	
	*control=0;
   purptr pur;
   pur=(purchased*)malloc(sizeof(purchased));
   pur->next=NULL;
   purchaseds(pur,1,1,5,7,(123.50),control);                                         //I sent the values to function to save them in linkedlist here
   purchaseds(pur,2,1,5,2,(12.40),control);
   purchaseds(pur,3,1,5,1,(23.45),control);
   purchaseds(pur,4,1,5,4,(56.75),control);
   purchaseds(pur,5,2,1,1,(45.50),control);
   purchaseds(pur,6,2,1,2,(30.60),control);
   purchaseds(pur,7,2,1,5,(25.50),control);
   purchaseds(pur,8,2,1,5,(30.00),control);
   purchaseds(pur,9,2,1,3,(23.78),control);
   purchaseds(pur,10,3,3,5,(34.50),control);
   purchaseds(pur,11,3,3,1,(567.00),control);
   purchaseds(pur,12,3,3,2,(45.00),control);
   purchaseds(pur,13,3,3,7,(32.00),control);
   purchaseds(pur,14,3,3,6,(40.95),control);
   purchaseds(pur,15,3,3,2,(34.50),control);
   purchaseds(pur,16,4,5,6,(71.20),control);
   purchaseds(pur,17,4,5,3,(63.30),control);
   purchaseds(pur,18,5,4,2,(17.30),control);
   purchaseds(pur,19,5,4,7,(29.40),control);
   purchaseds(pur,20,5,4,3,(20.05),control);
   
	
	*control=0;
	
	menu:                                                         //Menu design codes
		system("cls");
	printf("1.Sales\n");
	printf("2.Customer Information\n");
	printf("3.Product Information\n");
	printf("4.Customer Analysis\n");
	printf("5.Product Analysis\n");
	printf("6.Delete Customer\n");
	int x;
	scanf("%d",&x);
	
	
	if(x==1){
		*control=0;
		system("cls");
	    
		sales(cus,pro,pur,control,i,yor);                  //Values go to sales function to make a sale
		
		
		goto menu;
		
	}
	
	
	else if(x==2){
		*control=0;
	system("cls");

	printcustomer(cus,control);                     //Values go to printcustomer function to print customer
	
	goto menu;
}
	
	
else if(x==3){
	system("cls");
   
    *control=0;
    productinfo(pro,control);                  //Values go to productinfo function to do desired action
 
    goto menu;
}
else if(x==4){
	*control=0;
system("cls");
 musterianalizi(cus,pro,pur,control);         //Values go to musterianalizi function to analyze customers
 
   goto menu;
   
}
else if(x==5){
	*control=0;
	system("cls");
	
	
	urunanalis(cus,pro,pur);             //Values go to urunalis function to analyze products
	
	goto menu;
	
	
}
else if(x==6){
	
	*control=0;
	system("cls");
	printf("Which customer you want to delete:\n");
	cusptr iter=cus;
	int id;
	

	while(iter!=NULL){
	
	printf("%d\t",iter->ID);                                         //I print all customers to see for user here
			printf("%s\t",iter->name);
			printf("%d\t",iter->type);
			printf("%lf\t",iter->x_coord);
			printf("%lf\t",iter->y_coord);
			printf("\n");
			iter=iter->next;
		}
		scanf("%d",&id);                                             //I get customerID from user
    cusidcontrol(cus,id);
     
     cus=musterisil(cus,id);                                        //I checked customerID here                            
    
	
	goto menu;
}
   else{
   	
   	printf("\n You entered unvalid value\n");                         //Ýf user enter unvalid value user will see this and user can go to menu also user can exit here
   	printf("\t***1.Menu***\n");
   	printf("\t***2.Exit***");
   	int a;
   	scanf("%d",&a);
   	
   	if(a==1){
   		goto menu;
	   }
	   else if(a==2){
	   	exit(1);
	   }
   }

}
