#ifndef my_library
#define my_library

struct custom {                                      //I defined struct for customers here
int ID;
char name[50];
unsigned int type: 1;
double x_coord;
double y_coord;
struct custom *next;
};
typedef struct custom customer;
typedef customer *cusptr;  


struct prod {                      //I defined struct for producsts here
int ID;
char name[50];
unsigned int type : 4;
double price;
struct prod *next;
};
typedef struct prod product;
typedef product * proptr;



struct purchase {                //I defined struct for purchased products here
int ID;
int invoice_ID;
int customer_ID;
int product_ID;
double cost;
struct purchase *next;
}; 
typedef struct purchase purchased;
typedef purchased * purptr; 

cusptr musterisil(cusptr r,int id);
void urunanalis(cusptr cus,proptr pro,purptr pur);
void findmaxminfatura(purptr pur,double dizi[],int e);
void encoktercih(purptr pur,proptr pro);
int satinalinanmiktar(purptr pur,int proid);
double birfaturaicintotalcost(purptr pur,int b);
double birmusteritutari(cusptr cus,proptr pro,purptr pur,int b);
double kargo(double x,double y);
void satinalinan(purptr pur,int proid,int miktar,cusptr cus,proptr pro,int *i,int b,int cid,int x,int y);
void musteritercihi(cusptr cus,proptr pro,purptr pur,int b);
void hafizayakaydet(cusptr cus,proptr pro,purptr pur,int cusno,int proid,int proamiktar,int fiyat,int tip,char *name,int x,int y,int *cnt,int lastinvoice,int b);
int findlastinvoice(purptr pur);
void sales(cusptr cus,proptr pro,purptr pur,int* cnt,int *i,int *yor);
void kargohesapla(cusptr ptr,int x,int y,double tutar);
double tutarhesapla(cusptr cus,proptr pro,purptr pur,int cusno,int proid,int promiktar);
void purchaseds(purptr ptr,int id,int invoice,int customerid,int productid,double cost,int *cnt);
void productinfo(proptr ptr,int *cnt);
void readyproduct(proptr ptr,int id,char* name,int type,double price,int *cnt);
void printcustomer(cusptr cus,int *cnt);
void eklesirali(cusptr ptr,int id,char* name,int type,double x,double y,int *cnt);
void cusidcontrol(cusptr cus,int cid);
void productidcontrol(proptr pro,int proid);
void  musterienaz(cusptr cus,proptr pro,purptr,int b);
#endif
