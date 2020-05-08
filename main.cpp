/*
HOTLE PANDEMONIUM
-> Charge per night is rupees 1000
-> There are only 5 rooms available in this hotel
-> It is believed that no two customers residing at the hotel at the same
   time have same names
-> Please keep the number of items in the food menu to be less than or equal
   to 12 for the sake of formating (Though the program execution will occur
   correctly in either case.).
-> To navigate through the menu(s) use 'W' for up and 'S' for Down.
-> To select an item from the menu use 'P'.
-> To quit any point of time from a "menu screen" press 'Q'.
*/

#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<stdio.h>
#include<string.h>

int x,y,z,n1,n2,n3,vacant;

/*
  Coding for the graphic animation of the start screen.
  All of the graphic animation is done using gotoxy.
*/

void maint()
{ int k=1;
 clrscr();
 for(int i=0;i<26;i++)
 {
  gotoxy(k,1);cout<<" \xB1 ";
  gotoxy(k,25);cout<<" \xB1 ";
  delay(20);
  k=k+3;
 }

 k=1;

 for( i=0;i<26;i++)
 {
  gotoxy(k,2);cout<<" * ";
  gotoxy(k,24);cout<<" * ";
  delay(20);
  k=k+3;
 }

 k=1;

 for( i=0;i<26;i++)
 {
  gotoxy(k,3);cout<<" \xF6 ";
  gotoxy(k,23);
  cout<<" \xF6 ";
  delay(20);
  k=k+3;
 }

 k=1;

 for(int l=0;l<15;l++)
 {
  if(l%4==0)
  for( i=0;i<26;i++)
  {
   if(k%2==0)
   {
    gotoxy(k,3);cout<<" \xF6 ";
    gotoxy(k,23);cout<<" \xF6 ";
   }
   k=k+3;
  }

  if(l%2==0)
  for( i=0;i<26;i++)
  {
   if(k%2==0)
   {
    gotoxy(k,3);cout<<"  ";
    gotoxy(k,23);cout<<"  ";
   }
   k=k+3;
  }
  k=1;

  for( i=0;i<26;i++)
  {
   if(k%2==0)
   {
    gotoxy(k,2);cout<<"  ";
    gotoxy(k,24);cout<<"  ";
   }
   k=k+3;
  }
  k=1;
  delay(100);
  for( i=0;i<26;i++)
  {
   if(k%2==0)
   {
    gotoxy(k,2);cout<<" * ";
    gotoxy(k,24);cout<<" * ";
   }
   k=k+3;
  }
  k=1;
  delay(100);
  for( i=0;i<26;i++)
  {
   if(k%2!=0)
   {
    gotoxy(k,2);cout<<"  ";
    gotoxy(k,24);cout<<"  ";
   }
   k=k+3;
  }
  k=1;
  delay(100);
  for( i=0;i<26;i++)
  {
   if(k%2!=0)
   {
    gotoxy(k,2);cout<<" * ";
    gotoxy(k,24);cout<<" * ";
   }
   k=k+3;
  }
  k=1;
  delay(100);
  if(l>=4)
  {
   if(l%2==0)
   {
    gotoxy(27,10);
    cout<<"* * * HOTEL PANDEMONIUM * * *";}
    else
    {
     gotoxy(27,10);
     cout<<"                                   ";
    }
   }
  }
}

/*
 The functions for display and working of the various menu(s) used in
 the program
*/

// Main menu

void menudisplay()
{
   clrscr();
   gotoxy(25,8);
   cout<<"Let's get some work done,";
   gotoxy(27,9);
   cout<<"What do you want to do ?";
   gotoxy(28,11);
   cout<<"1. Food services ";
   gotoxy(28,12);
   cout<<"2. Customer services ";
   gotoxy(28,13);
   cout<<"3. Exit ";
   gotoxy(50,x);
   cout<<"<--";
   gotoxy(25,8);
}

void input()
{
 if(kbhit())
 {
  switch(getch())
  {
   case 'w':if(x>11)
	     x--;
	    break;

   case 's':if(x<13)
	     x++;
	    break;

   case 'q':exit(0);

   case 'p':n1=1;
	    break;
  }
 }
}

// Food services menu

void foodmenu()
{
   clrscr();
   gotoxy(30,8);
   cout<<"Food services";
   gotoxy(26,9);
   cout<<"What do you want to do ?";
   gotoxy(28,11);
   cout<<"1. Add items to menu ";
   gotoxy(28,12);
   cout<<"2. Display menu ";
   gotoxy(28,13);
   cout<<"3. Delete one item from menu ";
   gotoxy(28,14);
   cout<<"4. Delete entire menu";
   gotoxy(28,15);
   cout<<"5. Payments ";
   gotoxy(28,16);
   cout<<"6. Back to main menu ";
   gotoxy(60,y);
   cout<<"<--";
   gotoxy(30,8);
}

void inputf()
{
 if(kbhit())
 {
  switch(getch())
  {
   case 'w':if(y>11)
	     y--;
	    break;

   case 's':if(y<16)
	     y++;
	    break;

   case 'q':exit(0);

   case 'p':n2=1;
	    break;
  }
 }
}

// Customer services menu

void customermenu()
{
   clrscr();
   gotoxy(30,8);
   cout<<"Customer services";
   gotoxy(26,9);
   cout<<"What do you want to do ?";
   gotoxy(28,11);
   cout<<"1. New booking ";
   gotoxy(28,12);
   cout<<"2. Customer info ";
   gotoxy(28,13);
   cout<<"3. Customer data updation ";
   gotoxy(28,14);
   cout<<"4. Checkout";
   gotoxy(28,15);
   cout<<"5. Back to main menu ";
   gotoxy(60,z);
   cout<<"<--";
   gotoxy(30,8);
}

void inputc()
{
 if(kbhit())
 {
  switch(getch())
  {
   case 'w':if(z>11)
	     z--;
	    break;

   case 's':if(z<15)
	     z++;
	    break;

   case 'q':exit(0);

   case 'p':n3=1;
	    break;
  }
 }
}

//Function for displaying the processing screen

int load=0;
void processor()
{
 clrscr();

 gotoxy(35,12);
 cout<<"Processing";

 for(int i=0;i<3;i++)
 {
  gotoxy(41,13);
  cout<<"*";
  delay(150);

  gotoxy(42,14);
  cout<<"*";
  delay(150);

  gotoxy(41,15);
  cout<<"*";
  delay(150);

  gotoxy(38,15);
  cout<<"*";
  delay(150);

  load=0;
  load++;

  switch(load)
  {
   case 1:gotoxy(37,14);
	  cout<<"*";
	  gotoxy(41,13);
	  cout<<" ";
	  delay(150);
   case 2:gotoxy(38,13);
	  cout<<"*";
	  gotoxy(42,14);
	  cout<<" ";
	  delay(150);
	  break;
  }
  gotoxy(41,15);
  cout<<" ";
  delay(150);

  gotoxy(38,15);
  cout<<" ";
  delay(150);

  gotoxy(37,14);
  cout<<" ";
  delay(150);

  gotoxy(38,13);
  cout<<" ";
  delay(150);
 }
 clrscr();
}

// Structure(s) used for storing records in differnt data file

struct roomno
{
 int roomno;
 char status;
}
ad;

struct add
{
 char fname[20];
 float cost;}food;

//Function for alloting room number

int roomalot()
{
 fstream allot;
 int r=0;
 allot.open("rallot.dat", ios::in|ios::binary|ios::out);

 while (allot.read((char*)&ad,sizeof(ad)))
 {
  int pos=allot.tellg()-sizeof(ad);
  if(ad.status=='e')
  {
   r=ad.roomno;
   ad.status='f';
   allot.seekg(pos);
   allot.write((char*)&ad,sizeof(ad));
   break;
  }
 }
allot.close();
return r;
}

// Function for calculating total food bill

long double genfbill(int rno)
{
 float total=0;
 char roomnumber[20],extension[]=".txt";

 sprintf(roomnumber,"%d",rno);
 strcat(roomnumber,extension);

 fstream item(roomnumber,ios::out|ios::in);

 while (item.read((char*)&food,sizeof(food)))
 {
  total=total+food.cost;
 }

 return total;
}

// Function for clearing out room after a customer checkout

void clrroom(int rno)
{
 fstream allot("rallot.dat", ios::in|ios::binary|ios::out);;
 char roomnumber[20],extension[]=".txt";

 sprintf(roomnumber,"%d",rno);
 strcat(roomnumber,extension);
 remove(roomnumber);

 while (allot.read((char*)&ad,sizeof(ad)))
 {
  int pos=allot.tellg()-sizeof(ad);

  if(ad.roomno==rno)
  {
   ad.status='e';
   allot.seekg(pos);
   allot.write((char*)&ad,sizeof(ad));
   break;
  }
 }
allot.close();
}

//Function to calculate the number of days of stay
int days(int ar1[], int ar2[])
{
  int md[]={31,28,31,30,31,30,31,31,30,31,30,31};
  int s=0,s1=0;
  long double n1,n2,days;

  for(int x=0; x<(ar1[1]-1);x++)
   s=md[x]+s;

  n1=(ar1[2]*365)+s+ar1[0];

  for(x=0; x<(ar2[1]-1);x++)
   s1=md[x]+s1;

  n2=(ar2[2]*365)+s1+ar2[0];

  days=n2-n1;

  return days;
}

//Class for managing all the food based functions

class food
{
 fstream menu;
 add f;

 struct bill
 {
  char fname[20];
  int quant;
 }
  b;

public:

//Function for adding an item to the menu

void app()
{
   menu.open("menu.txt",ios::app);
   gotoxy(15,21);
   cout<<"Enter the name of the food item \t ";
   gets(f.fname);
   gotoxy(15,22);
   cout<<"Enter the cost \t \t";
   cin>>f.cost;
   menu.write((char*)&f,sizeof(f));
   menu.close();

}

//Function for displaying the menu

void display()
{
 clrscr();

 int i1=4,i2,n=0;

 menu.open("menu.txt", ios::in);
 menu.seekg(0);

 gotoxy(15,i1);

 for(int o=15 ;o<70 ;o++)
 cout<<"\xB2";

 gotoxy(20,++i1);
 cout<<"Food item";
 gotoxy(50,i1++);
 cout<<"Cost (per serving)";
 cout<<endl;

 while (menu.read((char*)&f,sizeof(f)))
  {
   n++;
   gotoxy(20,++i1);
   cout<<n<<". " <<f.fname;
   gotoxy(60,i1);
   cout<<"Rs."<<f.cost;
  }
 cout<<endl;
 menu.close();

 n=0;

while(n<3)
{
  if(n==0)
  {
   gotoxy(15,4);
   i2=15;
  }
  else if(n==1)
  {
   gotoxy(45,4);
   i2=45;
  }
  else if(n==2)
  {
   gotoxy(69,4);
   i2=69;
  }

  n++;

  for(o=5;o<=i1;o++)
  {
   gotoxy(i2,o);
   cout<<"*";
  }

}

gotoxy(15,i1+1);
 for(int s=15;s<70;s++)
 cout<<"\xB2";

 cout<<endl<<endl;
}

//Function for deleting one item from the menu

void delone()
{
 int c=0;
 char del[20];
 menu.open("menu.txt",ios::in|ios::out);
 fstream temp("temp.txt",ios::in|ios::out);
 gotoxy(15,22);
 cout<<"Enter the name of the food item \t ";
 gets(del);

 while (menu.read((char*)&f,sizeof(f)))
  {
   if(strcmpi(f.fname,del)==0)
    c=1;
   else
    temp.write((char*)&f,sizeof(f));
  }
  menu.close();
  temp.close();
  remove("menu.txt");
  rename("temp.txt","menu.txt");

 if(c==0)
  { gotoxy(15,23);
    cout<<"Item does not exist"<<endl;
    getch();
  }
 else
 { clrscr();
   gotoxy(10,5);
   cout<<del<<" has been deleted from the menu \n ";
   getch();
   display();

 }
}

//Function for deleting the entire existing menu

void delall()
{
 remove("menu.txt");
 menu.open("menu.txt",ios::out);
 menu.close();
}

// Function for adding items to the food bill of a customer

void fbilladd(char roomnumber[])
{
 int exist=0;
 fstream billadd;
 gotoxy(20,7);
 cout<<"Enter the name of food item : ";
 gets(b.fname);
 gotoxy(30,8);
 cout<<"Quantity : ";
 cin>>b.quant;
 menu.open("menu.txt",ios::in|ios::out);
 billadd.open(roomnumber,ios::app);

 while (menu.read((char*)&f,sizeof(f)))
  {
   if(strcmpi(f.fname,b.fname)==0)
    {
     exist++;
     for(int i=1;i<=b.quant;i++)
     billadd.write((char*)&f,sizeof(f));
    }
  }

 if(exist==0)
 {
  gotoxy(10,9);
  cout<<"Sorry but this item does not exist in our menu ";
 }

 menu.close();
 billadd.close();
}

//Function for displaying the food bill of a customer

void dispfbill(char roomnumber[])
{
 clrscr();
 processor();

 int r=5;
 float total=0;
 fstream item(roomnumber,ios::out|ios::in);

 gotoxy(10,r++);
 cout<<"Food bill of room number "<<roomnumber[0]<<" is :"<<endl<<endl;
 gotoxy(25,++r);
 cout<<"Item name";
 gotoxy(55,r++);
 cout<<"Price ";
 while (item.read((char*)&f,sizeof(f)))
  {
   total=total+f.cost;
   gotoxy(29,++r);
   cout<<f.fname;
   gotoxy(56,r);
   cout<<"Rs."<<f.cost<<endl;
  }
 gotoxy(25,++r);
 cout<<"-----------------------------------------";
 gotoxy(40,++r);
 cout<<"Total: \t Rs."<<total;
}

}
foodie;

//Class for managing all the customer based functions

class customer
{
 fstream cust;

 struct info
  {
   char name[20];
   char phoneno[10];
   char add[20];
   int people;
   int rno;
   int date[3];
   float foodbill;
  }
 cut;

 public:

//Function for customer chech-in and allotment of room number to the customer
void get()
{
 clrscr();
 int avail=0,k=5;

 cust.open("customer.dat",ios::binary|ios::in|ios::app);

  gotoxy(15,k);cout<<"Enter name";
  gotoxy(45,k);cout<<"-->";
  gotoxy(60,k++);gets(cut.name);
  gotoxy(15,k);cout<<"Enter phone number";
  gotoxy(45,k);cout<<"-->";
  gotoxy(60,k++);gets(cut.phoneno);
  gotoxy(15,k);cout<<"Enter address";
  gotoxy(45,k);cout<<"-->";
  gotoxy(60,k++);gets(cut.add);
  gotoxy(15,k);cout<<"Number of people staying";
  gotoxy(45,k);cout<<"-->";
  gotoxy(60,k++);cin>>cut.people;

 cut.rno=roomalot();

 if(cut.rno==0)
  {
    gotoxy(30,++k);cout<<"No room is vacant ";
   getch();
   avail=1;
   vacant=1;
  }

 if(avail==0)
  {
    gotoxy(15,++k);
   cout<<"Room alloted is "<<cut.rno;
    gotoxy(15,++k);
   cout<<"\nCheck-in date:\n";
    gotoxy(15,++k);cout<<"  Day";
    gotoxy(45,k);cout<<"-->";
    gotoxy(60,k++);cin>>cut.date[0];
    gotoxy(15,k);cout<<"  Month";
    gotoxy(45,k);cout<<"-->";
    gotoxy(60,k++);cin>>cut.date[1];
    gotoxy(15,k);cout<<"  Year";
    gotoxy(45,k);cout<<"-->";
    gotoxy(60,k++);cin>>cut.date[2];

   cust.write((char*)&cut,sizeof(cut));
  }

 cust.close();

}

//Functions for displaying the details of a customer

void display()
{
 clrscr();
 char cname[20];
 int d=0,k=5;
 cust.open("customer.dat",ios::in|ios::out|ios::binary);
 gotoxy(25,10);
 cout<<"Enter the name of the customer: ";
 gets(cname);

 clrscr();
 processor();
 while(cust.read((char*)&cut,sizeof(cut)))
  {
   if(strcmpi(cut.name,cname)==0)
    {
     gotoxy(15,k);cout<<" Name";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.name;
     gotoxy(15,k);cout<<" Phone number";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);
     for(int ph=0;ph<10;ph++)
      cout<<cut.phoneno[ph];

     gotoxy(15,k);cout<<" Address";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.add;
     gotoxy(15,k);cout<<" Number of people";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.people;
     gotoxy(15,k);cout<<" Room number ";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.rno;
     gotoxy(10,++k);cout<<"\nCheck in date: \n";
     gotoxy(15,k);cout<<" Day";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.date[0];
     gotoxy(15,k);cout<<" Month";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.date[1];
     gotoxy(15,k);cout<<" Year";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.date[2];
     gotoxy(15,++k);cout<<" Food bill";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);

     long double foodshow ;
     foodshow=genfbill(cut.rno);
     cout<<"Rs."<<foodshow;
     getch();
     d=1;

    break;
   }
  }
 if(d==0)
  {gotoxy(30,12);
   cout<<"Record does not exist";
   getch();
   clrscr();
  }

 cust.close();
}

//Function for modification of details of a customer

void mod()
{
 clrscr();
 char cname[20];
 int n=0,k=5;
 cust.open("customer.dat",ios::in|ios::out|ios::binary);
 fstream temp("temp.dat",ios::binary|ios::in|ios::out);

 gotoxy(25,10);
 cout<<"Enter the name of customer : ";
 gets(cname);

 clrscr();
 processor();

 while(cust.read((char*)&cut,sizeof(cut)))
 {
  if(strcmpi(cut.name,cname)==0 && n==0)
   {
    n=1;
    gotoxy(15,k);cout<<"Name";
    gotoxy(45,k);cout<<"-->";
    gotoxy(60,k++);cout<<cut.name;
    gotoxy(15,k);cout<<"Room number";
    gotoxy(45,k);cout<<"-->";
    gotoxy(60,k++);cout<<cut.rno;
    gotoxy(15,++k);cout<<"Enter phone number";
    gotoxy(45,k);cout<<"-->";
    gotoxy(60,k++);gets(cut.phoneno);
    gotoxy(15,++k);cout<<"Enter address";
    gotoxy(45,k);cout<<"-->";
    gotoxy(60,k++);gets(cut.add);
    gotoxy(15,++k);cout<<"Number of people";
    gotoxy(45,k);cout<<"-->";
    gotoxy(60,k++);cin>>cut.people;
   }

  temp.write((char*)&cut,sizeof(cut));

 }

cust.close();
temp.close();
remove("customer.dat");
rename("temp.dat","customer.dat");
}

// Fuction for carrying out the check-out process

void checkout()
{
 clrscr();
 fstream temp;
 int checkout[3],ch=0,n=0,k=4;
 long double ndays,staybill,foodbill,totalbill;
 char c_name[20];
 cust.open("customer.dat",ios::binary|ios::in|ios::out);
 temp.open("temp.dat",ios::binary|ios::in|ios::out);
 gotoxy(25,10);
 cout<<"Enter the name of the customer: ";gets(c_name);

 while(cust.read((char*)&cut,sizeof(cut)))
  {
   if(strcmpi(cut.name,c_name)==0 && n==0)
    {
     n=1;
     ch=1;
     gotoxy(25,12);cout<<"Please enter the checkout date : \n";
     gotoxy(35,14);cout<<"Day   : ";cin>>checkout[0];
     gotoxy(35,15);cout<<"Month : ";cin>>checkout[1];
     gotoxy(35,16);cout<<"Year  : ";cin>>checkout[2];
     ndays=days(cut.date,checkout);
     staybill=1000*ndays;
     foodbill=genfbill(cut.rno);
     totalbill=staybill+foodbill;

     processor();
     clrscr();

     gotoxy(15,k);cout<<"Name";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.name;
     gotoxy(15,k);cout<<"Phone number";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);
     for(int ph=0;ph<10;ph++)
      cout<<cut.phoneno[ph];

     gotoxy(15,k);cout<<"Address";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.add;
     gotoxy(15,k);cout<<"Number of people";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.people;
     gotoxy(15,k);cout<<"Room number";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.rno;
     gotoxy(8,++k);cout<<"\nCheck-in date: \n";
     gotoxy(15,k);cout<<"Day";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.date[0];
     gotoxy(15,k);cout<<"Month";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.date[1];
     gotoxy(15,k);cout<<"Year";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<cut.date[2];
     gotoxy(8,++k);cout<<"\nCheck-out date: \n";
     gotoxy(15,k);cout<<"Day";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<checkout[0];
     gotoxy(15,k);cout<<"Month";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<checkout[1];
     gotoxy(15,k);cout<<"Year";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<checkout[2];
     gotoxy(15,++k);cout<<"Number of days of stay";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<ndays;
     gotoxy(15,++k);cout<<"Food bill";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<foodbill;
     gotoxy(15,k);cout<<"Stay bill";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<staybill;
     gotoxy(15,k);cout<<"Total bill";
     gotoxy(45,k);cout<<"-->";
     gotoxy(60,k++);cout<<totalbill;

     getch();
     clrroom(cut.rno);

     processor();
     clrscr();

     gotoxy(33,10);cout<<" Payment recieved";
     getch();

   }

   else temp.write((char*)&cut,sizeof(cut));

  }

 if(ch==0)
 { gotoxy(25,12);
   cout<<"No record with this name exists in our database ";
 }
 else
 {
  gotoxy(20,12);
  cout<<"Customer "<<c_name<<" has checked out of the hotel";
  gotoxy(22,13);
  cout<<" Thank you for staying at Hotel Pandemonium";
 }
 getch();

 cust.close();
 temp.close();
 remove("customer.dat");
 rename("temp.dat","customer.dat");
}

}
operate;

//Main function

void main()
{
  maint();
  gotoxy(20,11);cout<<" \"Welcome to stay and forget your strains\" ";
  getch();
  while(1)
  {
   clrscr();
   x=y=z=11;
   n1=n2=n3=0;

   //Main menu
   while(n1!=1)
   {
   menudisplay();
   input();
   delay(200);
   }

   switch(x)
    {
     //Food services menu
     case 11:  while(1)
		{
		 n2=0;
		 y=11;
		 while(n2!=1)
		 {
		  foodmenu();
		  inputf();
		  delay(200);
		 }
		 switch(y)
		 {
		  case 11 : while(1)
			     {
			      foodie.display();
			      foodie.app();
			      cout<<"\n Do you want to add more items ? : ";
			      char ch[5];gets(ch);
			      if(ch[0]=='y');
			      else break;
			     }
			     break;

		   case 12 : foodie.display();
			     getch();
			     break;

		   case 13 : while(1)
			     {
			      foodie.display();
			      foodie.delone();
			      cout<<"\n Do you want to delete more items ? : ";
			      char ch[5];gets(ch);
			      if(ch[0]=='y');
			      else break;
			     }
			     break;

		   case 14 : { clrscr();
			       gotoxy(15,10);
			       cout<<"Are you sure you want to delete the entire menu ? ";
			       gotoxy(40,12);
			       char ch[5];gets(ch);
			       if(ch[0]=='y')
			       foodie.delall();
			     }
			     break;

		   case 15 :  clrscr();
			      gotoxy(10,4);
			      cout<<"Please enter the room number : ";
			      char roomnumber[20];
			      gets(roomnumber);
			      strcpy(roomnumber,strcat(roomnumber,".txt"));

			       while(1)
			     {
			      foodie.fbilladd(roomnumber);
			      gotoxy(10,9);
			      cout<<"\n Do you want to add more items to bill of room number "<<roomnumber[0]<<" ? : ";
			      char ch[5];gets(ch);

			      if(ch[0]=='y')
			      clrscr();
			      else
			      {gotoxy(10,11);
			       cout<<"\n Do you want to see the total food bill of room number "<<roomnumber[0]<<" ? ";
			       gets(ch);
			       if(ch[0]=='y')
			       {
				foodie.dispfbill(roomnumber);
				getch();
				break;
			       }
			       else break;
			      }
			     }
			     break;
		  }
		  if(y==16)
		   break;
		}
		break;

     //Customer services menu
     case 12: while(1)
	      {
	       n3=0;
	       z=11;
	       while(n3!=1)
	       {
		customermenu();
		inputc();
		delay(200);
	       }
	       switch(z)
	       {
		case 11 : while(1)
			  {
			   vacant=0;
			   operate.get();
			   if(vacant==0)
			   {
			    cout<<"\n Do you want to add another record?  ";
			    char ch[5]; gets(ch);
			    if(ch[0]=='y');
			    else
			    break;
			   }
			   else break;
			  }
			  break;

		case 12 :  while(1)
			   {
			    operate.display();
			    cout<<"\n\n Do you want to view another record?  ";
			    char ch[5]; gets(ch);
			    if(ch[0]=='y')
			    continue;
			    else
			    break;
			   }
			   break;

		case 13 : while(1)
			  {
			   operate.mod();
			   cout<<"\n Do you want to modify another record ? : ";
			   char ch[5];gets(ch);
			   if(ch[0]=='y');
			   else break;
			  }
			  break;

		case 14 : clrscr();
			  operate.checkout();
			  break;
	       }
	      if(z==15)
	      break;
	      }
	      break;
     // Exit
     case 13: clrscr();
	      exit(0);
    }

  }
  getch();
}
