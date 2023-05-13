#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

class Exhibit
{
long ENo;
char Name_of_Exhibit[30];
char Location[25];
float Cost;
char Name_of_Artist[40];
char Medium_Used[20];
char Description[40];

public:
void Input_Exhibit();
void Output_Exhibit();
float Ret_Cost();
char* Ret_Location();
char* Ret_Artist();
long Ret_ENo();
};


class Visitor
{
long VNo;
char Name_of_Visitor[30];
char Gender[8];
int Age;
char Id_No[10];
long Phone_No;
char Email_Id[25];
long VENo;

public:
void Input_Visitor();
void Output_Visitor();
int Ret_Age();
long Ret_VNo();
long Ret_VENo();
};


void Exhibit::Input_Exhibit()
{
cout<<"\n*****************************************\n";
cout<<"\nEnter reference no.	      	\t:";
cin>>ENo;
cout<<"\nEnter Exhibit name	      	\t:";
gets(Name_of_Exhibit);
cout<<"\nEnter location of the exhibit	\t:";
gets(Location);
cout<<"\nEnter cost of exhibit		\t:";
cin>>Cost;
cout<<"\nEnter name of artist		\t:";
gets(Name_of_Artist);
cout<<"\nEnter medium used		\t:";
gets(Medium_Used);
cout<<"\nEnter size(in)			\t:";
gets(Description);
cout<<"\n*****************************************\n";
}

void Exhibit::Output_Exhibit()
{
cout<<"\n*****************************************\n";
cout<<"\n Reference no.			\t:";
cout<<ENo;
cout<<"\n Exhibit name			\t:";
puts(Name_of_Exhibit);
cout<<"\n Location of the exhibit	\t:";
puts(Location);
cout<<"\n Cost of exhibit		\t:";
cout<<Cost;
cout<<"\n Name of artist		\t:";
puts(Name_of_Artist);
cout<<"\n Medium used			\t:";
puts(Medium_Used);
cout<<"\n Size(in)			\t:";
puts(Description);
cout<<"\n****************************************\n";
}

float Exhibit::Ret_Cost()
{
return Cost;
}

char* Exhibit::Ret_Location()
{
return Location;
}


char* Exhibit::Ret_Artist()
{
return Name_of_Artist;
}

long Exhibit::Ret_ENo()
{
return ENo;
}



void Exhibit_Create()
{
system("cls");
fstream f;
Exhibit E[100];
f.open("Exhibit.dat",ios::out|ios::binary);
int n,i;
cout<<"\nEnter no.of exhibit: ";
cin>>n;
for(i=0;i<n;i++)
{
E[i].Input_Exhibit();
f.write((char*)&E[i],sizeof(E[i]));
}
f.close();
}


void Exhibit_Displayall()
{
system("cls");
fstream f;
Exhibit E;
f.open("Exhibit.dat",ios::in|ios::binary);
f.seekg(0);
while(f.read((char*)&E,sizeof(E)))
{
E.Output_Exhibit();
}
f.close();
}

void Exhibit_Displaywc1()               //Displaying a certain reference number
{
system("cls");
fstream f;
Exhibit E;
f.open("Exhibit.dat",ios::in|ios::binary);
f.seekg(0);
cout<<"\nEnter reference no.: ";
long n;
cin>>n;
while(f.read((char*)&E,sizeof(E)))
{
if(E.Ret_ENo()==n)
E.Output_Exhibit();
}
f.close();
}

void Exhibit_Displaywc2()               //Displaying a exhibit of certain range of cost
{
system("cls");
fstream f;
Exhibit E;
f.open("Exhibit.dat",ios::in|ios::binary);
f.seekg(0);
cout<<"\nEnter minimum cost:  ";
float n;
cin>>n;
cout<<"\nEnter maximum cost: ";
float N;
cin>>N;
while(f.read((char*)&E,sizeof(E)))
{
if((E.Ret_Cost()>=n) && (E.Ret_Cost()<=N))
E.Output_Exhibit();
}
f.close();
}

void Exhibit_Displaywc3()               //Displaying a exhibit at a certain location
{
system("cls");
fstream f;
Exhibit E;
f.open("Exhibit.dat",ios::in|ios::binary);
f.seekg(0);
cout<<"\nEnter the location: ";
char L[25];
gets(L);
while(f.read((char*)&E,sizeof(E)))
{
if(strcmpi(E.Ret_Location(),L)==0)
E.Output_Exhibit();
}
f.close();
}



void Exhibit_Search1()               //Searching an exhibit of certain cost
{
system("cls");
fstream f;
Exhibit E;
f.open("Exhibit.dat",ios::in|ios::binary);
f.seekg(0);
cout<<"\nEnter cost of exhibit: ";
int flag=0;
float c;
cin>>c;
while(f.read((char*)&E,sizeof(E)))
{
if(E.Ret_Cost()==c)
{
flag=1;
E.Output_Exhibit();
break;
}
}
if(flag==0)
cout<<"No exhibit found!!!";
f.close();
}

void Exhibit_Search2()               //Searching exhibits of a certain artist
{
system("cls");
fstream f;
Exhibit E;
f.open("Exhibit.dat",ios::in|ios::binary);
f.seekg(0);
cout<<"\nEnter name of artist to be searched: ";
int flag=0;
char n[20];
gets(n);
while(f.read((char*)&E,sizeof(E)))
{
if(strcmpi(E.Ret_Artist(),n)==0)
{
flag=1;
E.Output_Exhibit();
break;
}
}
if(flag==0)
cout<<"No exhibit found!!!";
f.close();
}


void Exhibit_Append()                //To add more exhibits from the end
{
system("cls");
fstream f;
Exhibit E;
f.open("Exhibit.dat",ios::app|ios::binary);
char ans;
do
{
E.Input_Exhibit();
f.write((char*)&E,sizeof(E));
cout<<"\nDo you want to add more?\n";
cin>>ans;
}
while(ans=='Y'||ans=='y');
f.close();
}


void Exhibit_Copy1()                 //Copy exhibits above a certain cost
{
system("cls");
fstream f,t;
Exhibit E;
f.open("Exhibit.dat",ios::in|ios::binary);
t.open("Cost.dat",ios::out|ios::binary);
f.seekg(0);
cout<<"\nEnter the cost to be copied: ";
float n;
cin>>n;
while(f.read((char*)&E,sizeof(E)))
{
if(E.Ret_Cost()==n)
t.write((char*)&E,sizeof(E));
}
f.close();
t.close();
}


void Exhibit_Copy2()                 //Copy exhibits of a particular artist
{
system("cls");
fstream f,t;
Exhibit E;
f.open("Exhibit.dat",ios::in|ios::binary);
t.open("Artist.dat",ios::out|ios::binary);
f.seekg(0);
cout<<"\nEnter the artist name to be copied: ";
char n[30];
gets(n);
while(f.read((char*)&E,sizeof(E)))
{
if(strcmpi(E.Ret_Artist(),n)==0)
t.write((char*)&E,sizeof(E));
}
f.close();
t.close();
}


void Exhibit_Move1()                 //Moving exhibits of price below 150000
{
system("cls");
fstream f,t1,t2;
Exhibit E;
f.open("Exhibit.dat",ios::in|ios::binary);
t1.open("HCost.dat",ios::out|ios::binary);
t2.open("temps.dat",ios::out|ios::binary);
f.seekg(0);
while(f.read((char*)&E,sizeof(E)))
{
if(E.Ret_Cost()<150000)
t1.write((char*)&E,sizeof(E));
else
t2.write((char*)&E,sizeof(E));
}
f.close();
t1.close();
t2.close();
remove("Exhibit.dat");
rename("temps.dat","Exhibit.dat");
}

void Exhibit_DisplayCopy1()
{
system("cls");
fstream f;
Exhibit E;
f.open("Cost.dat",ios::in|ios::binary);
f.seekg(0);
while(f.read((char*)&E,sizeof(E)))
{
E.Output_Exhibit();
}
f.close();
}

void Exhibit_DisplayCopy2()
{
system("cls");
fstream f;
Exhibit E;
f.open("Artist.dat",ios::in|ios::binary);
f.seekg(0);
while(f.read((char*)&E,sizeof(E)))
{
E.Output_Exhibit();
}
f.close();
}

void Exhibit_DisplayMove1()
{
system("cls");
fstream f;
Exhibit E;
f.open("HCost.dat",ios::in|ios::binary);
f.seekg(0);
while(f.read((char*)&E,sizeof(E)))
{
E.Output_Exhibit();
}
f.close();
}


void Exhibit_Insert()                //Insert after a particular exhibit
{
system("cls");
fstream f,t;
Exhibit E;
f.open("Exhibit.dat",ios::in|ios::binary);
t.open("temp.dat",ios::out|ios::binary);
f.seekg(0);
long n;
cout<<"\nEnter exhibit no. after which to be added: ";
cin>>n;
{
while(f.read((char*)&E,sizeof(E)))
{
t.write((char*)&E,sizeof(E));
if(E.Ret_ENo()==n)
{
cout<<"\nEnter new record: ";
E.Input_Exhibit();
t.write((char*)&E,sizeof(E));
}
}
f.close();
t.close();
}
remove("Exhibit.dat");
rename("temp.dat","Exhibit.dat");
}


void Exhibit_Delete()                //Delete a particular exhibit
{
system("cls");
fstream f,t;
Exhibit E;
f.open("Exhibit.dat",ios::in|ios::binary);
t.open("temp.dat",ios::out|ios::binary);
f.seekg(0);
long n;
cout<<"\nEnter exhibit no. to be deleted: ";
cin>>n;
while(f.read((char*)&E,sizeof(E)))
{
if(E.Ret_ENo()!=n)
t.write((char*)&E,sizeof(E));
else
cout<<"\nRecord Deleted!!! ";
}
f.close();
t.close();
remove("Exhibit.dat");
rename("temp.dat","Exhibit.dat");
}


void Exhibit_Modify()                //Modify a particular exhibit
{
system("cls");
fstream f,t;
Exhibit E;
f.open("Exhibit.dat",ios::in|ios::binary);
t.open("temp.dat",ios::out|ios::binary);
f.seekg(0);
long n;
cout<<"\nEnter exhibit no. to be modified: ";
cin>>n;
while(f.read((char*)&E,sizeof(E)))
{
if(E.Ret_ENo()==n)
{
cout<<"\nEnter new details: ";
E.Input_Exhibit();
}
t.write((char*)&E,sizeof(E));
}
f.close();
t.close();
remove("Exhibit.dat");
rename("temp.dat","Exhibit.dat");
}


void Exhibit_Visitor1()                //Displaying details of visitor purchasing a certain exhibit
{
system("cls");
fstream f,t;
Visitor V;
Exhibit E;
f.open("Visitor.dat",ios::in|ios::binary);
t.open("Exhibit.dat",ios::in|ios::binary);
f.seekg(0);
long n;
cout<<"\nEnter exhibit no.: ";
cin>>n;
while(f.read((char*)&V,sizeof(V)))
{
if(V.Ret_VENo()==n)
{
cout<<"\nVisitor's Detail:";
V.Output_Visitor();
}
}
f.close();
t.close();
}


void Visitor::Input_Visitor()
{
cout<<"\n****************************************\n";
cout<<"\nEnter Visitor no.	\t:";
cin>>VNo;
cout<<"\nEnter Visitor name	\t:";
gets(Name_of_Visitor);
cout<<"\nEnter gender of visitor\t:";
gets(Gender);
cout<<"\nEnter age of visitor	\t:";
cin>>Age;
cout<<"\nEnter Id No.		\t:";
gets(Id_No);
cout<<"\nEnter phone no.	\t:";
cin>>Phone_No;
cout<<"\nEnter email ID		\t:";
gets(Email_Id);
cout<<"\nEnter Exhibit purchased\t:";
cin>>VENo;
cout<<"\n*****************************************\n";
}



void Visitor::Output_Visitor()
{
cout<<"\n****************************************\n";
cout<<"\n Visitor no.	   	\t:";
cout<<VNo;
cout<<"\n Viistor's name   	\t:";
puts(Name_of_Visitor);
cout<<"\n Gender	   	\t:";
puts(Gender);
cout<<"\n Age		   	\t:";
cout<<Age;
cout<<"\n Id No.	   	\t:";
puts(Id_No);
cout<<"\n Phone No.	   	\t:";
cout<<Phone_No;
cout<<"\n Email ID     	   	\t:";
puts(Email_Id);
cout<<"\n Exhibit purchased	\t:";
cout<<VENo;
cout<<"\n*****************************************\n";
}



int Visitor::Ret_Age()
{
return Age;
}

long Visitor::Ret_VNo()
{
return VNo;
}

long Visitor::Ret_VENo()
{
return VENo;
}


void Visitor_Create()
{
system("cls");
fstream f;
Visitor V[100];
f.open("Visitor.dat",ios::out|ios::binary);
int n,i;
cout<<"\nEnter no.of visitor: ";
cin>>n;
for(i=0;i<n;i++)
{
V[i].Input_Visitor();
f.write((char*)&V[i],sizeof(V[i]));
}
f.close();
}


void Visitor_Displayall()
{
system("cls");
fstream f;
Visitor V;
f.open("Visitor.dat",ios::in|ios::binary);
f.seekg(0);
while(f.read((char*)&V,sizeof(V)))
{
V.Output_Visitor();
}
f.close();
}

void Visitor_Displaywc1()               //Displaying a certain visitor number
{
system("cls");
fstream f;
Visitor V;
f.open("Visitor.dat",ios::in|ios::binary);
f.seekg(0);
cout<<"\nEnter visitor no.: ";
long n;
cin>>n;
while(f.read((char*)&V,sizeof(V)))
{
if(V.Ret_VNo()==n)
V.Output_Visitor();
}
f.close();
}



void Visitor_Search1()               //Searching visitors of certain age
{
system("cls");
fstream f;
Visitor V;
f.open("Visitor.dat",ios::in|ios::binary);
f.seekg(0);
cout<<"\nEnter the age to be searched: ";
int flag=0;
int A;
cin>>A;
while(f.read((char*)&V,sizeof(V)))
{
if(V.Ret_Age()==A)
{
flag=1;
V.Output_Visitor();
break;
}
}
if(flag==0)
cout<<"No visitor found!!!";
f.close();
}



void Visitor_Append()                //To add more visitors from the end
{
system("cls");
fstream f;
Visitor V;
f.open("Visitor.dat",ios::app|ios::binary);
char ans;
do
{
V.Input_Visitor();
f.write((char*)&V,sizeof(V));
cout<<"\nDo you want to add more?\n";
cin>>ans;
}
while(ans=='Y'||ans=='y');
f.close();
}

void Visitor_Insert()                //Insert after a particular visitor
{
system("cls");
fstream f,t;
Visitor V;
f.open("Visitor.dat",ios::in|ios::binary);
t.open("temp.dat",ios::out|ios::binary);
f.seekg(0);
long n;
cout<<"\nEnter visitor no. after which to be added: ";
cin>>n;
{
while(f.read((char*)&V,sizeof(V)))
{
t.write((char*)&V,sizeof(V));
if(V.Ret_VNo()==n)
{
cout<<"\nEnter new record: ";
V.Input_Visitor();
t.write((char*)&V,sizeof(V));
}
}
f.close();
t.close();
}
remove("Visitor.dat");
rename("temp.dat","Visitor.dat");
}


void Visitor_Delete()                //Delete a particular visitor
{
system("cls");
fstream f,t;
Visitor V;
f.open("Visitor.dat",ios::in|ios::binary);
t.open("temp.dat",ios::out|ios::binary);
long n;
cout<<"\nEnter visitor no. to be deleted: ";
cin>>n;
while(f.read((char*)&V,sizeof(V)))
{
if(V.Ret_VNo()!=n)
t.write((char*)&V,sizeof(V));
else
cout<<"\nRecord Deleted!!! ";
}
f.close();
t.close();
remove("Visitor.dat");
rename("temp.dat","Visitor.dat");
}


void Visitor_Modify()                //Modify a particular  visitor
{
system("cls");
fstream f,t;
Visitor V;
f.open("Visitor.dat",ios::in|ios::binary);
t.open("temp.dat",ios::out|ios::binary);
f.seekg(0);
long n;
cout<<"\nEnter visitor no. to be modified: ";
cin>>n;
while(f.read((char*)&V,sizeof(V)))
{
if(V.Ret_VNo()==n)
{
cout<<"\nEnter new details: ";
V.Input_Visitor();
}
t.write((char*)&V,sizeof(V));
}
f.close();
t.close();
remove("Visitor.dat");
rename("temp.dat","Visitor.dat");
}


void Visitor_Exhibit1()                //Displaying details of exhibit purchased by a visitor
{
system("cls");
fstream f,t;
Visitor V;
Exhibit E;
f.open("Visitor.dat",ios::in|ios::binary);
t.open("Exhibit.dat",ios::in|ios::binary);
f.seekg(0);
long n;
cout<<"\nEnter exhibit no.: ";
cin>>n;
while(t.read((char*)&E,sizeof(E)))
{
if(E.Ret_ENo()==n)
{
cout<<"\nExhibit's Detail:";
E.Output_Exhibit();
}
}
f.close();
t.close();
}


void main()
{
system("cls");
int i,n,c;
char a,b,d;
do
{
system("cls");
cout<<"\n\t\t\t***WELCOME TO ART EXHIBITION***\n\n";
cout<<"\nMAIN MENU:\n\n";
cout<<"\n\t1-The Exhibition \n\t2-Visitors ";
cout<<"\n\nEnter your choice: \n";
cin>>i;
system("cls");
{
switch(i)
{
case 1:do{
	cout<<"\nThe Exhibition\n\n"  ;
	cout<<"\nEnter choice: ";
	cout<<"\n\t1-Create";
	cout<<"\n\t2-Display All";
	cout<<"\n\t3-Display details of certain reference no";
	cout<<"\n\t4-Display details of exhibit at certain location";
	cout<<"\n\t5-Display details of exhibit at a certain range of cost";
	cout<<"\n\t6-Search exhibit at a certain cost";
	cout<<"\n\t7-Search exhibit of a certain artist";
	cout<<"\n\t8-Append ";
	cout<<"\n\t9-Copying exhibit of a certain cost";
	cout<<"\n\t10-Copying exhibit of a certain artist";
	cout<<"\n\t11-Move exhibits below the cost 150000 ";
	cout<<"\n\t12-Display copied exhibit of certain cost ";
	cout<<"\n\t13-Display copied exhibit of certain artist ";
	cout<<"\n\t14-Display moved exhibits below the cost 150000 ";
	cout<<"\n\t15-Insert details of new exhibit";
	cout<<"\n\t16-Delete details of certain exhibit";
	cout<<"\n\t17-Modify details of certain exhibit";
	cout<<"\n\t18-Displaying details of visitor purchasing a certain exhibit\n\n->>>";
	cin>>n;
	switch(n)
	{
	case 1:cout<<"\nCreate:\n";
		Exhibit_Create();
		break;
	case 2:cout<<"\nDisplaying All\n";
		Exhibit_Displayall();
		break;
	case 3:cout<<"\nDisplaying details of certain exhibit no\n";
		Exhibit_Displaywc1();
		break;
	case 4:cout<<"\nDisplaying details of exhibit at certain location\n";
		Exhibit_Displaywc3();
		break;
	case 5:cout<<"\nDisplaying details of exhibit at a certain range of cost\n";
		Exhibit_Displaywc2();
		break;
	case 6:cout<<"\nSearching for exhibits at a certain cost\n";
		Exhibit_Search1();
		break;
	case 7:cout<<"\nSearching for exhibit of a certain artist\n";
		Exhibit_Search2();
		break;
	case 8:cout<<"\nAppend\n ";
		Exhibit_Append();
		break;
	case 9:cout<<"\nCopying exhibit of a certain cost\n";
		Exhibit_Copy1();
		break;
	case 10:cout<<"\nCopying exhibit of a certain artist\n";
		Exhibit_Copy2();
		break;
	case 11:cout<<"\nMove exhibits below the cost 150000\n ";
		Exhibit_Move1();
		break;
	case 12:cout<<"\nDisplaying copied exhibits of a certain cost\n ";
		Exhibit_DisplayCopy1();
		break;
	case 13:cout<<"\nDisplaying copied exhibits of a certain artist\n ";
		Exhibit_DisplayCopy2();
		break;
	case 14:cout<<"\nDisplaying moved exhibits below the cost 150000\n ";
		Exhibit_DisplayMove1();
		break;
	case 15:cout<<"\nInsert details of new exhibit:\n";
		Exhibit_Insert();
		break;
	case 16:cout<<"\nDelete details of certain exhibit\n";
		Exhibit_Delete();
		break;
	case 17:cout<<"\nModify details of certain exhibit\n";
		Exhibit_Modify();
		break;
	case 18:cout<<"\nDisplaying deatils of visitor purchasing a certain exhibit\n";
		Exhibit_Visitor1();
		break;
	}
	cout<<"\n\n\nDo you wish to  continue?(Y-yes/N-no)\n";
	cin>>a;
	}
	while(a=='Y'||a=='y');
	break;


case 2:do{
	cout<<"\nThe Visitor\n\n"  ;
	cout<<"\nEnter choice: ";
	cout<<"\n\t1-Create";
	cout<<"\n\t2-Display All";
	cout<<"\n\t3-Display details of certain visitor no";
	cout<<"\n\t4-Search visitors of a certain age";
	cout<<"\n\t5-Append ";
	cout<<"\n\t6-Insert details of new visitor";
	cout<<"\n\t7-Delete details of certain visitor";
	cout<<"\n\t8-Modify details of certain visitor";
	cout<<"\n\t9-Displaying details of exhibit purchased by a certain visitor\n->";
	cin>>c;
	switch(c)
	{
	case 1:cout<<"\nCreate:\n";
		Visitor_Create();
		break;
	case 2:cout<<"\nDisplaying All\n";
		Visitor_Displayall();
		break;
	case 3:cout<<"\nDisplaying details of certain visitor no\n";
		Visitor_Displaywc1();
		break;
	case 4:cout<<"\nSearching for visitor of a certain age\n";
		Visitor_Search1();
		break;
	case 5:cout<<"\nAppend\n ";
		Visitor_Append();
		break;
	case 6:cout<<"\nInsert details of new visitor:\n";
		Visitor_Insert();
		break;
	case 7:cout<<"\nDelete details of certain visitor\n";
		Visitor_Delete();
		break;
	case 8:cout<<"\nModify details of certain visitor\n";
		Visitor_Modify();
		break;
	case 9:cout<<"\nDisplaying details of exhibit purchased by a certain visitor\n";
		Visitor_Exhibit1();
		break;
	}
	cout<<"\n\n\nDo you wish to  continue?(Y-yes/N-no)\n";
	cin>>b;
	}
	while(b=='Y'||b=='y') ;
	break;

}
cout<<"\n\n\nDo you wish to  continue?(Y-yes/N-no)\n";
cin>>d;
}
}
while(d=='Y'||d=='y');
}
