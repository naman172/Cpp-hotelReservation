#include<fstream.h>
#include<conio.h>
#include<stdio.h>

class room
{
 int roomno;
 char status;

 public:
  void add()
  {
   int rn;
   char st;

   cout<<"enter ";
   cin>>rn;
   cin>>st;

   status=st;
   roomno=rn;
  }

  void show()
  {
    cout<<roomno<<"\t"<<status;
  }

}ad;

void main()
{
 clrscr();

 fstream file;

 {
  remove("rallot.dat");
  file.open("rallot.dat",ios::out|ios::binary);

  while(1)
  {
   clrscr();
   ad.add();
   file.write((char*)&ad,sizeof(ad));

   cout<<"Do you want to add more items ? : ";
   char ch[5];
   gets(ch);

   if(ch[0]=='n')
    break;
  }

  file.close();

 }

 file.open("rallot.dat", ios::in);

 while (file.read((char*)&ad,sizeof(ad)))
 {
  ad.show();
  cout<<endl;
 }

 file.close();

 getch();
}
