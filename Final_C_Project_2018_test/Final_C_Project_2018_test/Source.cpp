
  #include <stdio.h>   
  #include<string.h>
  #include <cstdlib>
  #include <ctime>


  struct product{
	  int PNO;
	  char name[50];
	  float price;
	  int discount;
  };

  product P[1000];  // Array
  int indexPro = 0;  // full that array

  void loadSystemData();  // Read

  void saveSystemData(); // Write
  void DisplayInfo(product x); 

  /**********************************************************/
  void mainMenu();  //structure for menu
  void listAllProducts();
  void addProduct();
  void deleteProduct();
  void updateProduct();

  product searchByID();
  product searchByName();

  void customerMenu();
  /**********************************************************/
  int main()
  {

	  loadSystemData(); // 34an y7fz el ta'3yr fy indexPro..


	  printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tMarket Project\n\n");
	  printf("\t\t\t        C Programming\n");

	  printf("\n\n MADE BY : Tamer A.Yassen");
	  printf("\n\n COMPLETED BY : Youssef F.Rashad & Rawan Osama & Engi Ashraf");
	  printf("\n\n SCHOOL : Faculty of Computers and Information, Helwan University");
	  
	  getchar();
	  system("cls");

	  int ch = 1;
	  while(ch != 3){
		  printf("\n\n\n\n\n\n\n\t\t\tWelcome to METRO Market\n\n");
		  printf("\t\t\t 1: Customer.\n\n");
		  printf("\t\t\t 2: Admin.\n\n");
		  printf("\t\t\t 3: Exit.\n\n");

		  printf("\t\t\t");
		  scanf("%d", &ch);
		  getchar();

		  system("cls");

		  if (ch == 1)
		  {
			  customerMenu();
		  }
		  else 
			  if(ch == 2){
				  char username[20], password[20];
				  printf( "\n\n\n\t\tAdmin Panal ...\n");
				  printf( "\n\t\tUser Name : ");
				  gets( username );
				  printf( "\n\t\tPassword : ");
				  gets( password );
				  if ((strcmp(username, "admin") == 0) && (strcmp(password, "0000")== 0))
				  {
					  printf( "\n\t\tWelcom Admin...");
					  mainMenu();
				  }
				  else
					  printf( "\n\n\n\t\tInvalid authentication ...\n\n");
			 
			  }
			  else
				  if(ch == 3){
					  printf( "\n\n\n\n\n\t\t\t\tThanks YOU ...\n\n\n\n");
				  }
				  else
					  printf( "\n\n\n\t\tInvalid Choice\n\n");
	  }

	 saveSystemData();

	 system("pause");
     return 0; 
  } // end main

  void DisplayInfo(product p){
	  printf("\n\t\t%d\t%s\t%d\t\t%0.1f\n", p.PNO, p.name, p.discount, p.price);
  }

  // Read Data
  void loadSystemData(){
	  product x;
	  FILE *myFileIn;
     if ( (myFileIn = fopen("Products.txt", "r")) == NULL )
     {
		 printf( "\n\tFile could not be opend ! ... \n");
		 exit(0);

     }
	 else{
     // read Product #, name, discount and Price from file, then place in Array of Products
	 fscanf(myFileIn, "%d%s%d%f", &x.PNO, x.name, &x.discount, &x.price);
	 while (! feof(myFileIn))
     {
		 P[indexPro] = x;

		 fscanf(myFileIn, "%d%s%d%f", &x.PNO, x.name, &x.discount, &x.price);
		 indexPro ++;
     } // end while
	 }
  }
 
	// Write Data By Use ( W )
   void saveSystemData(){
	   product x;
	   FILE *myFileOut;
     if ( (myFileOut = fopen("Products.txt", "w")) == NULL )
     {
		 printf( "\n\tFile could not be opend ! ... \n");
		 exit(0);

     }
	 else{

     for (int i = 0; i < indexPro ; i++)
	 {
		 fprintf(myFileOut, "%d\t%s\t%d\t%0.1f\n", P[i].PNO, P[i].name, P[i].discount, P[i].price);
	 }
	 }
   }


 ////////////////////////////////////////////////////////
  /*****************************************************/
  ////////////////////////////////////////////////////////

   void mainMenu(){

	int ch;
	product w;
	//cout<< "\n___________________________________________________\n";
	printf( "\n\n\n\t$ \t    Admin Menu            $\n\t_|_______________________________|_\n");

	printf("\t |\t                         |\n\t |\t1: List all Products.    |\n\t |\t2: Add new Product.      |\n\t |\t3: Delete Product.       |\n\t |\t4: Search by ID.         |\n\t |\t5: Search by Name.       |\n\t |\t6: Update Product info.  |\n\t |\t0: to Exit               |\n" );

	printf( "\t_|_______________________________|_\n\t$|\t                         |$\n");
	printf( "\t");
	scanf("%d", &ch);

	switch (ch)
	{
	case 1 :
		listAllProducts();
		break;
	case 2 :
		addProduct();
		break;
	case 3 :
		deleteProduct();
		break;

	case 4 : 
		w = searchByID();
		if (w.PNO == 0)
		{
			printf("\n\tProduct Not found ... :(\n");
		}
		else{
			printf("\n\tFound ... :) \n\n\tProduct Info ...");
			DisplayInfo(w);
		}
		mainMenu();

		break;

	case 5 : 
		w = searchByName();
		if (w.name== 0)
		{
			printf("\n\tProduct Not found ... :(\n");
		}
		else{
			printf("\n\tFound ... :) \n\n\tProduct Info ...");
			DisplayInfo(w);
		}
		mainMenu();

		break;
	case 6:
		updateProduct();
		break;

	default:
		system("cls");
		break;
	}
}

   void listAllProducts(){
	  printf("\n\t");
	  printf("Product # \tName\tDiscount\tPrice\n");
	  for (int i = 0; i < indexPro; i++)
	  {
		  DisplayInfo(P[i]);
	  }

	  int x;
      printf( "\n\tPress 0 for Main menu \n\t");
      scanf("%d", &x);
      if (x == 0)
		  mainMenu();
	  else
		  listAllProducts();
   }


   void addProduct(){
	   printf("\n\n");
	  printf("\n\tAdd New Product ... \n\t");
	  printf("Product # \tName\tDiscount\tPrice\n");
	  printf("\t");
		//  *********** ziadh ***************
	  FILE *fptr;
	  if((fptr=fopen("Products.txt","a"))==NULL)
	  {
		  printf("File Could not be opened ! ");
	  }
	  else
		{
	  product x;
	  scanf("%d%s%f%d",&x.PNO,x.name,&x.price,&x.discount);
	  P[indexPro]=x;
	  indexPro++;
	  fprintf(fptr,"%d\t%s\t%d\t%0.1f\n",x.PNO,x.name,x.discount,x.price);
			
	  // ***********             **************
	  int y;
      printf( "\n\tPress 0 for Main menu");
	  printf( "\n\tPress 1 to Add more Products \n\t");
      scanf("%d", &y);
      if (y == 0)
		  mainMenu();
	  if (y == 1)
	  {
		  addProduct();
	  }
   }
	  }

   product searchByID(){
	    int key;
		product x = {0,"",0.0,0};
		printf("\n\tEnter Product ID : ");
		scanf("%d",&key);
		for(int m=0 ; m<indexPro ; m++){
			if(key==P[m].PNO){return P[m];}
		}
		return x;
}


   product searchByName(){

	    char key[50];
		product x = {0,"",0.0,0};
		printf("\n\tEnter Product Name : ");
		scanf("%s",key);
		for(int m=0;m<indexPro;m++){
			if(strcmp(key,P[m].name)==0){return P[m];}
		}
		return x;
}

   int findLocation(){
	    int key;
		printf("\n\tEnter Product ID : ");
		scanf("%d", &key);
		getchar();
		for(int m=0 ; m<indexPro ; m++){
			if(key==P[m].PNO){return m;}
		}
		return -1;
   }

   void deleteProduct(){
	   FILE *fptr1;
	   if((fptr1=fopen("Products.txt","r"))==NULL)
	  {
		  printf("File Could not be opened ! ");
	  }
	   else{
	   char c;
	   printf("\n\tDeleting Product ... ");
	   int w = findLocation();
	   while ( w== -1)
	   {
		   printf("\n\tProduct ID Not Valid Try Again ...");
		    w = findLocation();
	   }
		   printf("\n\tAre You sure to Delete ...\n");
		   DisplayInfo(P[w]);
		   printf("\n\tPress ( y ) or ( n )\n\t");
		    // ***** ziadh******
		   scanf("%c",&c);
		   if(c=='y'){
			   for (int i = w; i < indexPro ; i++){
				   P[i]=P[i+1];
			   }
			   indexPro--;
		   }
		   // *******   ********
	int x;
      printf( "\n\tPress 0 for Main menu");
	  printf( "\n\tPress 1 to Delete more Products \n\t");
      scanf("%d", &x);
      if (x == 0)
		  mainMenu();
	  if (x == 1)
	  {
		  deleteProduct();
	  }
   }
  }

    void updateProduct(){
	   char c;
	   printf("\n\tUpdate Product ... ");
	   int w = findLocation();
	   while ( w== -1)
	   {
		   printf("\n\tProduct ID Not Valid Try Again ...");
		    w = findLocation();
	   }
		   printf("\n\tAre You sure to Update ...\n");
		   DisplayInfo(P[w]);
		   printf("\n\tPress ( y ) or ( n )\n\t");

		//**** Ziadh *****
		   scanf("%c",&c);
		   if(c=='y'){
			   printf("Product # \tName\tDiscount\tPrice\n");
			   FILE *fptr;
			   if((fptr=fopen("Products.txt","a"))==NULL){
					  printf("File Could not be opened ! ");
					}
	   else{
			   scanf("%d%s%f%d",&P[w].PNO,P[w].name,&P[w].price,&P[w].discount);
			   fprintf(fptr,"%d\t%s\t%d\t%0.1f\n",P[w].PNO,P[w].name,P[w].discount,P[w].price);
		   }
	   // ********  ******
	  int x;
      printf( "\n\tPress 0 for Main menu");
	  printf( "\n\tPress 1 to Update more Products \n\t");
      scanf("%d", &x);
      if (x == 0)
		  mainMenu();
	  if (x == 1)
	  {
		  updateProduct();
	  }
   }
	}
  ////////////////////////////////////////////////////////
  /*****************************************************/
  ////////////////////////////////////////////////////////
	void customerMenu(){
		product paidProduct[100];
		int quantity [100];
		int index = 0;
		int num;
		float total = 0.0, amount, amountAfterDiscount;
		char ch = 'y';
		printf("\n\t\t\tProduct Menu\n");
		printf("\n\t==============================================\n");
		printf("\n\t");
	    printf("Product # \tName\tDiscount\tPrice\n");
		printf("\n\t==============================================\n");
		for (int i = 0; i < indexPro; i++)
	    {
		  DisplayInfo(P[i]);
	    }
		printf("\n\t==============================================\n\n");
		printf("\n\t\t   Place Your Order\n\n");

		while(ch == 'y' || ch == 'Y'){
				product w  = searchByID();
				if (w.PNO != 0)
				{
					paidProduct[index] = w;
					printf("\n\tQuantity : ");
					scanf("%d", &num);
					getchar();
					quantity[index] = num;

					index ++;
				}
				else
					printf("\n\tProduct ID Invalid ...\n");

				printf("\n\n\tDo you want to Order Another Product ?\n");
				printf("\n\n\tPress ( y ) or ( n )\n\t");
				scanf("%c", &ch);
				
		}

		printf("\n\n\tThank You For Placing The Order ...\n\t");
		getchar();
		system("cls");

		printf("\n\n\n\t***************************** INVOICE ******************************\n\n\t");

		printf( "Product # \tName\tQuantity\tPrice\tAmount\tAfter Discount\n");
		for (int i = 0; i < index; i++)
		{
			amount = paidProduct[i].price * quantity[i];
			amountAfterDiscount = amount *(100 - paidProduct[i].discount) /100;
			total += amountAfterDiscount ;

			printf("\n\t\t%d\t%s\t%d\t\t%0.1f\t%0.1f\t  %0.1f\n", paidProduct[i].PNO, paidProduct[i].name, quantity[i], paidProduct[i].price, amount, amountAfterDiscount);
		}

		printf("\n\n\n\t\t\t\tTOTAL : %0.1f\n", total);
		printf("\n\n\n\t**************************** THANK YOU *****************************\n\n\t");

		 time_t now = time(0); 
		 printf("\n\tFCIH Development Team    \t\t %s", ctime(&now) );

		getchar();
		system("cls");
	}
