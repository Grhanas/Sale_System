#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <dos.h>

#include "my_library.h"	




void eklesirali(cusptr ptr,int id,char* name,int type,double x,double y,int *cnt)              //I added values from main to linkedlist here
{
	


if(*cnt==0){                                                                 //Ýf value is equal to root of linked list 

ptr->ID=id;
strcat(ptr->name,name);
ptr->type=type;
ptr->x_coord=x;
ptr->y_coord=y;
}
cusptr iter=ptr;
cusptr temp;
temp=(customer*)malloc(sizeof(customer));
 if((*cnt==1)||(*cnt==2)||(*cnt==3)||(*cnt==4)){                           //Else value is element of linkedlist
	while(iter->next!=NULL){
		iter=iter->next;
	}
	temp->next=iter->next;
	iter->next=temp;
	temp->ID=id;
	
    strcat(temp->name,name);
    temp->type=type;
    temp->x_coord=x;
    temp->y_coord=y;
	
}
*cnt=*cnt+1;

}
		
void productidcontrol(proptr ptr,int proid){                            //I checked productID which is entered by user
	proptr iter=ptr;
	int a=0;
     while(iter!=NULL){
	iter=iter->next;
	a++;
	}
	if(proid>a){
		printf("\nEntered unvalid value");
		exit(1);
	}

}

void printcustomer(cusptr cus,int *cnt){                         //I print values about customer here like all customer according to customer type and single customer       
	int i;
	printf("2.Customer Information\n");
	printf("\t2.1 All customers\n");
	printf("\t2.2 According to the customer type\n");
	printf("\t2.3 Single customer\n");
	scanf("%d",&i);
	cusptr ptr=cus;
	if(i==1){
		while(ptr!=NULL){
			printf("%d\t",ptr->ID);
			printf("%s\t",ptr->name);
			printf("%d\t",ptr->type);
			printf("%lf\t",ptr->x_coord);
			printf("%lf\t",ptr->y_coord);
			printf("\n");
			ptr=ptr->next;
		}
	}
	if(i==2){
		int a;
		printf("Customer type:\n");
		printf("0.For personal   1.For commercial\n");
		scanf("%d",&a);
	    if(a==1){
	    	while(ptr!=NULL){
	    	if(ptr->type==1){
	    	printf("%d\t",ptr->ID);
			printf("%s\t",ptr->name);
			printf("%d\t",ptr->type);
			printf("%lf\t",ptr->x_coord);
			printf("%lf\t",ptr->y_coord);
			printf("\n");
			
	    			
				}
				ptr=ptr->next;
			}
		}
		else if(a==0){
			while(ptr!=NULL){
				if(ptr->type==0){
			printf("%d\t",ptr->ID);
			printf("%s\t",ptr->name);
			printf("%d\t",ptr->type);
			printf("%lf\t",ptr->x_coord);
			printf("%lf\t",ptr->y_coord);
			printf("\n");
			
				}
				ptr=ptr->next;
			}
		}
	}
	if(i==3){
		
		printf("Enter customer ID:");
		int b;
		scanf("%d",&b);
		cusidcontrol(cus,b);
		while(ptr!=NULL){
			if(ptr->ID==b){
				printf("%d\t",ptr->ID);
			printf("%s\t",ptr->name);
			printf("%d\t",ptr->type);
			printf("%lf\t",ptr->x_coord);
			printf("%lf\t",ptr->y_coord);
			printf("\n");
			}
			ptr=ptr->next;
		}
	}
	else{
		printf("\n You entered unvalid value\n");
	}
	printf("\n\n\t\t***1.Menu***\n");
	printf("\t\t***2.Exit***\n");
	int o;
	scanf("%d",&o);
	if(o==1){
		
	}
	else if(o==2){
		exit(1);
	}
	
}

void readyproduct(proptr ptr,int id,char* name,int type,double price,int *cnt){    //I added values from main to linkedlist here
	if(*cnt==0){
		ptr->ID=id;
		strcat(ptr->name,name);
		ptr->type=type;
		ptr->price=price;
	}
proptr iter=ptr;
proptr temp;
temp=(product*)malloc(sizeof(product));
   if((*cnt==1)||(*cnt==2)||(*cnt==3)||(*cnt==4)||(*cnt==5)||(*cnt==6)){
   	while(iter->next!=NULL){
   		iter=iter->next;
	   }
	   	temp->next=iter->next;
	iter->next=temp;
	temp->ID=id;
	strcat(temp->name,name);
	temp->type=type;
	temp->price=price;
	   
	   
   }

	*cnt=*cnt+1;
	
	
}
	
void productinfo(proptr ptr,int *cnt){                           //I print values about products here like all products,according to product type and single product
	int i;
	printf("3.1 All products\n");
	printf("3.2 According to the product type \n");
	printf("3.3 Single product\n");
	scanf("%d",&i);
	if(i==1){
		while(ptr!=NULL){
			printf("%d\t",ptr->ID);
			printf("%-10s\t",ptr->name);
			printf("%d\t",ptr->type);
			printf("%.2lf\t",ptr->price);
			ptr=ptr->next;
			printf("\n");
		}
	}
else	if(i==2){
		int a;
		printf("enter product type:");
		scanf("%d",&a);
		if(a<1 || a>3){
			printf("\nEntered unvalid value");
			exit(1);
		}
			while(ptr!=NULL){
				if(ptr->type==a){
			printf("%d\t",ptr->ID);
			printf("%s\t",ptr->name);
			printf("%d\t",ptr->type);
			printf("%.2lf\t",ptr->price);
			
			printf("\n");
				}
				ptr=ptr->next;
			}
		
	
}
else if(i==3){
	printf("enter product id:");
	int u;
	scanf("%d",&u);
	productidcontrol(ptr,u);
	while(ptr!=NULL){
		if(ptr->ID==u){
				printf("%d\t",ptr->ID);
			printf("%s\t",ptr->name);
			printf("%d\t",ptr->type);
			printf("%.2lf\t",ptr->price);
		}
		ptr=ptr->next;
	}
}

else{
	printf("\n You entered unvalid value\n");
}
printf("\n\n\t\t***1.Menu***\n");
	printf("\t\t***2.Exit***\n");
	int o;
	scanf("%d",&o);
	if(o==1){
	}
	else if(o==2){
		exit(1);
	}
}



void purchaseds(purptr ptr,int id,int invoice,int customerid,int productid,double cost,int *cnt){  //I added values from main to linkedlist here

	if(*cnt==0){

ptr->ID=id;
ptr->invoice_ID=invoice;
ptr->customer_ID=customerid;
ptr->product_ID=productid;
ptr->cost=cost;

}



 else if((*cnt>0)&&(*cnt<20)){
purptr iter=ptr;
purptr temp;
temp=(purchased*)malloc(sizeof(purchased));

	while(iter->next!=NULL){
		iter=iter->next;
	}
	temp->next=iter->next;
	iter->next=temp;
	
	temp->ID=id;
    temp->invoice_ID=invoice;
    temp->customer_ID=customerid;
    temp->product_ID=productid;
    temp->cost=cost;
    
    
}






*cnt=*cnt+1;
}

double tutarhesapla(cusptr cus,proptr pro,purptr pur,int cusno,int proid,int promiktar){     //I calculate the price without cargo price here
	
double fiyat,sonfiyat;
	
	proptr iter=pro;
	while(iter->next!=NULL){
		
		if(iter->ID==proid){
			fiyat=iter->price;
		}
		iter=iter->next;
	}
	
    sonfiyat=fiyat*promiktar;
	printf("Price=%lf\n",sonfiyat);
	return sonfiyat;
}


void kargohesapla(cusptr ptr,int x,int y,double tutar){         //I calculate just cargo price here
	double ucret;
	ucret=sqrt(pow(x,2)+pow(y,2));
	printf("Cargo Price:%lf\n",ucret);
	double sontutar=0;
	sontutar=ucret+tutar;
	printf("Last Price:%lf\n",sontutar);
}

void cusidcontrol(cusptr cus,int cid){                       //I checked customerID which is entered by user
int a=0;


cusptr iter=cus;
while(iter!=NULL){
	iter=iter->next;
	a++;
	
}

if(cid>a){
	printf("\nEntered unvalid value");
	exit(1);
}
	
}

void sales(cusptr cus,proptr pro,purptr pur,int* cnt,int *i,int *yor){        //I make sales for new customer and registered customer here also I add newcustomer here
	*i=*i+1;
int sonfatura,cusnumber,proid,proamount,tip,x,y,lastpurid,lastinvoice;
	int xc,yc,a,b;
	char name1[50];
char name2[50];
char *namex;	
int c;

	lastinvoice=findlastinvoice(pur);
	b=lastinvoice;
		b=b+1;
	
	printf("1.New Customer\n");
	printf("2.Listed Customer\n");
	int p;
	scanf("%d",&p);
	
	if(p==1){
	
	

printf("Enter Customer Name(enter first name do not enter surname):");
scanf("%s",&name1);

printf("Enter Customer Surname:");
scanf("%s",&name2);

strcat(name1," ");
strcat(name1,name2);

proptr iter=pro;

	printf("Customer Type\n");
	printf("0.For personal    1.For commercial\n");
	scanf("%d",&tip);
	if(tip!=1 && tip!=0){
		printf("\nYou entered unvalid value");
		exit(1);
	}
	printf("Enter Customer Number");
	printf("   (You can enter bigger than %d):",*yor);
	scanf("%d",&cusnumber);
	if(cusnumber<=*yor){
		printf("Unvalid Value");
		exit(1);
	}
	bas:
	printf("Which product you want to buy:\n");
	while(iter!=NULL){
			printf("%d\t",iter->ID);
			printf("%s\t",iter->name);
			printf("%d\t",iter->type);
			printf("%.2lf\t",iter->price);
			printf("\n");
			iter=iter->next;
	}

	scanf("%d",&proid);
	if(proid<1||proid>7){
			printf("Product is not on sale\n");
			exit(1);
		}
	printf("Enter Product Amount:");
	scanf("%d",&proamount);
	printf("x coordinate:");
	scanf("%d",&x);
	printf("y coordinate:");
	scanf("%d",&y);


   
	
	double fiyat;
	fiyat=tutarhesapla(cus,pro,pur,cusnumber,proid,proamount);
	
    hafizayakaydet(cus,pro,pur,cusnumber,proid,proamount,fiyat,tip,name1,x,y,cnt,lastinvoice,b);
    double t;
	kargohesapla(cus,x,y,fiyat);
	
		printf("\n\n\t\t***1.Menu***\n");
	printf("\t\t***2.Buy another product***\n");
	
	int o;
	scanf("%d",&o);
	if(o==2){
		
		goto bas;
	}
}

else if(p==2){
	system("cls");
	
	
	
		int cid;
		printf("Enter Customer ID:");
		scanf("%d",&cid);
		
		cusidcontrol(cus,cid);
	

		cusptr iter=cus;
		
		while(iter->next!=NULL){
			if(iter->ID==cid){
				cusnumber=iter->ID;
				xc=iter->x_coord;
				yc=iter->y_coord;
				
							}
			iter=iter->next;
		}
	
		
		proptr iterr=pro;
		urunal:
		printf("Which product you want to buy\n");
			while(iterr!=NULL){
				printf("%d\t",iterr->ID);
			printf("%s\t",iterr->name);
			printf("%d\t",iterr->type);
			printf("%.2lf\t",iterr->price);
			printf("\n");
			iterr=iterr->next;
		}
		int m,n;
		scanf("%d",&m);
		if(m<1||m>7){
			printf("Product is not on sale\n");
			exit(1);
		}
		printf("How many you want to buy\n");
		scanf("%d",&n);
		
	
		
			
			
		satinalinan(pur,m,n,cus,pro,i,b,cid,xc,yc);
		
		int h;
	printf("\n\n\t\t***1.Menu***\n");
	printf("\t\t***2.Buy another product***\n");
		scanf("%d",&h);
		
		if(h==1){
		
		}
		else if(h==2){
		goto urunal;
		}
		
}
else {
	printf("\nYou entered unvalid value\n");
		printf("\n\n\t\t***1.Menu***\n");
	printf("\t\t***2.Buy another product***\n");
	int h;
	scanf("%d",&h);
		
		if(h==1){
		
		}
		else if(h==2){
		goto urunal;
		}
}
*cnt=*cnt+1;
*i=*i+1;
*yor=*yor+1;
	}
	

	
int findlastinvoice(purptr pur){                       //I find lastinvoice number here
	
	int a;
	purptr iter=pur;
	while(iter!=NULL){
		
		if(iter->next==NULL){
			
			printf("\nLast Invoice Number:%d\n",iter->invoice_ID);
			a=iter->invoice_ID;
			
		}
		iter=iter->next;
	}
	return a;
}


void hafizayakaydet(cusptr cus,proptr pro,purptr pur,int cusno,int proid,int proamiktar,int fiyat,int tip,char *name,int x,int y,int *cnt,int lastinvoice,int b){ //I save new customer to memory here
	purptr itar=pur;
	int a;
	while(itar!=NULL){
		
		itar=itar->next;
		a++;
	}
	cusptr iter=cus;
	cusptr temp;
	temp=(customer*)malloc(sizeof(customer));
		while(iter->next!=NULL){
		iter=iter->next;
	}
	temp->next=iter->next;
	iter->next=temp;
	temp->ID=cusno;
	temp->x_coord=x;
	temp->y_coord=y;
	temp->type=tip;
	strcat(temp->name,name);
	
	proptr iterr=pro;
	proptr tempp;
	tempp=(product*)malloc(sizeof(product));
	while(iterr->next!=NULL){
		iterr=iterr->next;
	}
	tempp->next=iterr->next;
	iterr->next=tempp;
	tempp->ID=proid;
	
	purptr iterrr=pur;
	purptr temppp;
	temppp=(purchased*)malloc(sizeof(purchased));
		while(iterrr->next!=NULL){
		iterrr=iterrr->next;
	}
	temppp->next=iterrr->next;
	iterrr->next=temppp;
	temppp->ID=a+1;
	temppp->invoice_ID=b;
	temppp->customer_ID=temp->ID;
	temppp->product_ID=tempp->ID;
	temppp->cost=fiyat;
	
}


void musteritercihi(cusptr cus,proptr pro,purptr pur,int b){   //I found most preferred product here
	
	int tercih=0;
	int a=0;
	purptr iter=pur;
	while(iter!=NULL){
		if(iter->customer_ID==b){
			tercih++;
		}
		iter=iter->next;
	}
	
	int tercihdizi[tercih];
	
	
	purptr itar=pur;
		while(itar!=NULL){
		if(itar->customer_ID==b){
			tercihdizi[a]=itar->product_ID;
			a++;
		}
		
		itar=itar->next;
		
	}
	int count = 1, tempCount;
  int popular = tercihdizi[0];
  int temp = 0;
	int i,j;
	 for (i=0;i<(tercih - 1);i++)
  {
    temp = tercihdizi[i];
    tempCount = 0;
    for (j=1;j<tercih;j++)
    {
      if (temp == tercihdizi[j])
        tempCount++;
    }
    if (tempCount > count)
    {
      popular = temp;
      count = tempCount;
    }
  }
proptr ptr=pro;
while(ptr!=NULL){
	if(ptr->ID==popular){
		printf("\nMost preferred product is %s",ptr->name);
	}
	ptr=ptr->next;
}
	
}


void satinalinan(purptr pur,int proid,int miktar,cusptr cus,proptr pro,int *i,int b,int cid,int x,int y){ //I found the values for sent tutarhesapla and kargohesapla functions here

	purptr iter=pur;
	
	purptr temp;
	temp=(purchased*)malloc(sizeof(purchased));
	
	while(iter->next!=NULL){
		
		
		iter=iter->next;


	}

	 
	temp->next=iter->next;
	iter->next=temp;
	
    temp->ID=*i;
    temp->invoice_ID=b;
    
    temp->customer_ID=cid;
    temp->product_ID=proid;
    int tutar;
    tutar=tutarhesapla(cus,pro,pur,cid,proid,miktar);
    temp->cost=tutar;
    
    kargohesapla(cus,x,y,tutar);
    
	*i=*i+1;
}


double kargo(double x,double y){  //I found cargo price here and returned it
	
	double toplam;
	toplam=sqrt(x*x+y*y);
	return toplam;
}



double birmusteritutari(cusptr cus,proptr pro,purptr pur,int b){ //I found a cost for a customer here
	purptr iter=pur;
	double cost=0;
	while(iter!=NULL){
		if(iter->customer_ID==b){
			cost=cost+iter->cost;
		}
		iter=iter->next;
	}
	
	return cost;
}



double birfaturaicintotalcost(purptr pur,int b){        //I found the cost for one invoicenumber here
purptr iter=pur;
double cost=0;
while(iter!=NULL){
	if(iter->invoice_ID==b){
		cost=cost+iter->cost;
		
	}
	iter=iter->next;
}
return cost;
}


int satinalinanmiktar(purptr pur,int proid){   //I found the amount of saled product 
	purptr iter=pur;
	int sayac=0;
	
	while(iter!=NULL){
		if(iter->product_ID==proid){
		sayac++;
	}
	iter=iter->next;
	}
	
	return sayac;
	
}


void  musterienaz(cusptr cus,proptr pro,purptr pur,int b){ //I found least preferred product here
	int tercih=0;
	int a=0;
	purptr iter=pur;
	while(iter!=NULL){
		if(iter->customer_ID==b){
			tercih++;
		}
		iter=iter->next;
	}
	
	int tercihdizi[tercih];
	
	
	purptr itar=pur;
		while(itar!=NULL){
		if(itar->customer_ID==b){
			tercihdizi[a]=itar->product_ID;
			a++;
		}
		
		itar=itar->next;
		
	}
	
	int i;
	int freq[tercih];
	 for(i=0; i<tercih; i++)
    {
        freq[i] = -1;
    }
    int j;
     for(i=0; i<tercih; i++)
    {
        int count = 1;
        for(j=i+1; j<tercih; j++)
        {
           
            if(tercihdizi[i]==tercihdizi[j])
            {
                count++;

                
                freq[j] = 0;
            }
        }

        
        if(freq[i] != 0)
        {
            freq[i] = count;
        }
    }
    int s;
    int min=freq[0];
    for(i=0;i<tercih;i++){
    	if(freq[i]<=min && freq[i]!=0){
    		min=freq[i];
    		s=i+1;
		}
	}

	
proptr ptr=pro;
while(ptr!=NULL){
	if(ptr->ID==min){
		printf("\nLeast preferred product is %s",ptr->name);
	}
	ptr=ptr->next;
}
	

	
}

void encoktercih(purptr pur,proptr pro){      //I found the most preferred product here twice but this is for customerID

int sonid;
	purptr iter=pur;
	
	while(iter->next!=NULL){
		
		iter=iter->next;
	}

	sonid=iter->ID;
	int array[sonid];
	purptr itar=pur;
	int a=0;
	while(itar!=NULL){
		
		array[a]=itar->product_ID;
		itar=itar->next;
		a++;
	}
	
	int count = 1, tempCount;
  int popular = array[0];
  int temp = 0;
	int i,j;
	 for (i=0;i<(a-1);i++)
  {
    temp = array[i];
    tempCount = 0;
    for (j=1;j<a;j++)
    {
      if (temp == array[j])
        tempCount++;
    }
    if (tempCount > count)
    {
      popular = temp;
      count = tempCount;
    }
}

proptr iterr=pro;
while(iterr!=NULL){
	if(iterr->ID==popular){
		printf("Most preferred product is %s\n",iterr->name);
	}
	iterr=iterr->next;
}

	
}


void findmaxminfatura(purptr pur,double dizi[],int e){   //I found the invoice which are maximum and minimum price
	int i;
	double max=dizi[0];
	for(i=0;i<e;i++){
		
		if(dizi[i]>=max){
			max=dizi[i];
		}
	}
	printf("Maximum invoice =%lf\n",max);
	
	double min=dizi[0];
	for(i=0;i<e;i++){
		
		if(dizi[i]<=min){
			min=dizi[i];
		}
	}
	printf("Minimum invoice=%lf\n",min);
} 


 void musterianalizi(cusptr cus,proptr pro,purptr pur,int *cnt){  //I  analyze purchased products like products purchased by a customer,total amount of purchased by a customer...
 	printf("\n4.1 Products purchased by a customer\n");
 	printf("4.2 Total amount of purchased by a customer\n");
    printf("4.3 Total amount of products purchased by all customer\n");
    printf("4.4 Customers shipping fee\n");
    int a;
    scanf("%d",&a);
    
    if(a==1){
    	printf("\nEnter customer ID:");
    	int b;
    	int c;
    	scanf("%d",&b);
    	cusidcontrol(cus,b);
    	printf("\nProducts which are bought by customer:\n");
    	purptr iter=pur;
    	proptr itar=pro;
    	while(iter!=NULL){
    		if(iter->customer_ID==b){
    			c=iter->product_ID;
    			while(itar!=NULL){
    				
    				if(itar->ID==c){
    					printf("%s,",itar->name);
					}
    				
    				itar=itar->next;
				}
				itar=pro;
			}
    		iter=iter->next;
		}
		iter=pur;
		musteritercihi(cus,pro,pur,b);
		musterienaz(cus,pro,pur,b);
		 birmusteritutari(cus,pro,pur,b);
		 
		 printf("\nTotal cost for a customer=%lf", birmusteritutari(cus,pro,pur,b));
		
		
	}
	else if(a==2){
			printf("\nEnter customer ID:");
    	int b;
    	double c;
    	double tutar=0;
    	scanf("%d",&b);
    	cusidcontrol(cus,b);
    	
    	purptr iter=pur;
    	proptr itar=pro;
    	while(iter!=NULL){
    		if(iter->customer_ID==b){
    			c=iter->cost;
    			tutar=tutar+c;
			}
			
    		iter=iter->next;
		}
		iter=pur;
		printf("Total for a customer cost=%lf\n",tutar);
		musteritercihi(cus,pro,pur,b);
		musterienaz(cus,pro,pur,b);
		 
		 
		
		
	}
	else if(a==3){
		double c;
		double tutar=0;
		purptr iter=pur;
		while(iter!=NULL){
		
		c=iter->cost;
		tutar=tutar+c;
		iter=iter->next;
		}
		printf("\nTotal price for all customers=%lf\n",tutar);
	}
	else if(a==4){
		double x,y;
		double total=0;
		cusptr iter=cus;
		while(iter!=NULL){
			x=iter->x_coord;
			y=iter->y_coord;
			kargo(x,y);
			total=total+kargo(x,y);
			iter=iter->next;
		}
	
		
	printf("\nTotal cargo cost=%lf\n",total);
	}
	
		else{
			printf("You entered unvalid value\n");
			exit(1);
		}
	int e;
	int h;
	int u;
	e= findlastinvoice(pur);
	double dizi[e];
	for(h=0;h<e;h++){
		u=h+1;
		dizi[h]=birfaturaicintotalcost(pur,u);
		
		
	}
	
	findmaxminfatura(pur,dizi,e);
	
	
	
	printf("\n\n\t\t***1.Menu***\n");
	printf("\t\t***2.Exit***\n");
	int o;
	scanf("%d",&o);
	if(o==1){
		
	}
	else if(o==2){
		exit(1);
	}
 	
 }

void urunanalis(cusptr cus,proptr pro,purptr pur){  //I analyze products here like total purchase quantity of a product,total purchase amount of a product type...
		printf("\n5.1 Total purchase quantity of a product \n");
		printf("5.2 Total purchase amount of a product type\n");
		printf("5.3 Total purchase amount for all products\n");
		int secim;
		scanf("%d",&secim);
		
		if(secim==1){
			printf("Enter product ID:");
			int proid;
			scanf("%d",&proid);
			productidcontrol(pro,proid);
			double cost=0;
			purptr iter=pur;
			while(iter!=NULL){
				if(iter->product_ID==proid){
					cost=cost+iter->cost;
				}
				iter=iter->next;
			}
			printf("Cost for this product=%lf\n",cost);
			printf("Amount of product=%d\n",satinalinanmiktar(pur,proid));
		satinalinanmiktar(pur,proid);
			
			
			
		}
		
		
		else if(secim==2){
			printf("Enter product type:");
			int type;
			scanf("%d",&type);
			if(type<1 || type>3){
				printf("\nEntered unvalid value");
				exit(1);
			}
			proptr iter=pro;
			purptr itar=pur;
			int proid;
			double cost=0;
			while(iter!=NULL){
				if(iter->type==type){
					proid=iter->ID;
					while(itar!=NULL){
						if(itar->product_ID==proid){
							
							cost=cost+itar->cost;
						}
						itar=itar->next;
					}
					itar=pur;
				}	
				iter=iter->next;
			}
			printf("\nCost for this product ID=%lf\n",cost);
			printf("Amount of product=%d\n",satinalinanmiktar(pur,proid));
		satinalinanmiktar(pur,proid);
			
					
		}
		else if(secim==3){
			
			purptr iter=pur;
			double cost=0;
			while(iter!=NULL){
				cost=cost+iter->cost;
				iter=iter->next;
			}
			printf("\nTotal cost=%lf\n",cost);
			
		}
		else{
			printf("\nYou entered unvalid value\n");
		}
		
	
		encoktercih(pur,pro);
		printf("\n\n\t\t***1.Menu***\n");
	printf("\t\t***2.Exit***\n");
	int o;
	scanf("%d",&o);
	if(o==1){
		
	}
	else if(o==2){
		exit(1);
	}
		
	}


cusptr musterisil(cusptr r,int id){  //I delete the customer which is user enter
  
  cusptr temp;
  cusptr iter=r;
  
  if(r->ID==id){
  	temp=r;
  	r=r->next;
  	free(temp);
  	return r;
  }
  while(iter->next!=NULL && iter->next->ID!=id){
  	iter=iter->next;
  }
  if(iter->next==NULL){
  	printf("\nUnvalid ID");
  	return r;
  }
  temp=iter->next;
  iter->next=iter->next->next;
  free(temp);
  return r;
  
  int o;
  
  printf("\n\t***1.Menu***\n");
  printf("\n\t***2.Exit***\n");
  scanf("%d",&o);
  
  if(o==1){
  	
  }
  else if(o==2){
  	exit(1);
  }
  
}

