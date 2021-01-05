/* Project: Super Market Billing Application

Made By - ABHAY BHANDARI */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <windows.h>

using namespace std;


//class Seller_Products-----------------------------------------------------------------------------
class Seller_Products
{
	
	public:
		double price;
		char ProductName[20];
		void GetData();
		void PutData();
		char *returnProductName()
		{
			return(ProductName);
		}
}fav,fas,med,spo;

void Seller_Products::GetData()
{
	cout<<"\n\tProduct name: ";
	fflush(stdin);
	gets(ProductName);
	
	cout<<"\tPrice: ";
	cin>>price;	
	
}

void Seller_Products::PutData()
{
	cout<<"\n\t---------------------------------------------";
	cout<<"\n\tProduct Name: "<<ProductName<<endl;
	cout<<"\tPrice: "<<setprecision(2)<<fixed<<price<<endl;
	cout<<"\t---------------------------------------------"<<endl<<endl;
}

//-------------------------------------------------------------------------------------end



//-----------------------------------------------
//All Functions
void Customer();
void Seller();
void Main_Menu_CustomerSeller();
void SellerProducts();
void DatabaseChoice();
void Seller_Bills();
//-----------------------------------------------


//-------------------------------------------------------------------------------------
//Fruits and Vegetables Database Functions
void Display_Fruits_Vegetables();
void Fruits_And_Vegetables();
void Fruits_And_Vegetables_DataBase();
void Add_Fruits_Vegetables();
void Search_Fruits_Vegetables();
void Delete_Fruits_Vegetables();
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
//Fashion Database Functions
void Display_Fashion();
void Fashion();
void Fashion_DataBase();
void Add_Fashion();
void Search_Fashion();
void Delete_Fashion();
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
//Medicines Database Functions
void Display_Medicines();
void Medicines();
void Medicines_DataBase();
void Add_Medicines();
void Search_Medicines();
void Delete_Medicines();
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
//Sports Database Functions
void Display_Sports();
void Sports();
void Sports_DataBase();
void Add_Sports();
void Search_Sports();
void Delete_Sports();
//-------------------------------------------------------------------------------------



//Database Choice
void DatabaseChoice()
{
	system("color 2");
	cout<<"\t1.  Display All Products"<<endl;
	cout<<"\t2.  Search Product"<<endl;
	cout<<"\t3.  Add a New product"<<endl;
	cout<<"\t4.  Delete a product"<<endl;
	cout<<"\t5.  Go Back"<<endl;
	cout<<"\t6.  Go to Main Menu"<<endl;
	cout<<"\t0.  Exit"<<endl;
	cout<<"\t-----------------------------------"<<endl<<endl;
	cout<<"\tEnter your choice: ";
}



//Fruits and Vegetables Database-------------------------------------------------------------------------------------
void Fruits_And_Vegetables()
{
	system("cls");
	system("color 02");
	cout<<endl<<endl;
	cout<<"\t------------------------------------------"<<endl;
	cout<<"\t\tFruits and Vegetables"<<endl;
	cout<<"\t------------------------------------------"<<endl<<endl;
}

void Fruits_And_Vegetables_DataBase()
{
	system("color 02");
	Fruits_And_Vegetables();
	DatabaseChoice();
	int database_choice;
	cin>>database_choice;
	switch(database_choice)
	{
		case 1: Display_Fruits_Vegetables();
				break;
		case 2: Search_Fruits_Vegetables();
				break;
		case 3: Add_Fruits_Vegetables();
				break;
		case 4:	Delete_Fruits_Vegetables();
				break;
		case 5:	SellerProducts();
			    break;
		case 6: Main_Menu_CustomerSeller();
				break;
		case 0: exit(0);
				break;
		default: cout<<"\tWrong Input!"<<endl<<"\t";
				 system("pause");
				 Fruits_And_Vegetables_DataBase();		 
	}
}

void Add_Fruits_Vegetables()
{
	char ch;
	Fruits_And_Vegetables();
	fav.GetData();
	ofstream fout;
    fout.open("FruitsAndVegetables.dat",ios::app|ios::binary);
    fout.write(reinterpret_cast<char*>(&fav),sizeof(fav));
    fout.close();
    cout<<"\tRecord Saved Successfully . . ."<<endl;
    cout<<"\n\tDo you want to add more (Y/N): ";
    cin>>ch;
    if((ch=='y')||(ch=='Y'))
    Add_Fruits_Vegetables();
    else
    {
    	cout<<"\t";
    	system("pause");
    	Fruits_And_Vegetables_DataBase();
	}
}

void Display_Fruits_Vegetables()
{
	Fruits_And_Vegetables();
	ifstream fin;
	fin.open("FruitsAndVegetables.dat",ios::binary|ios::in);
	fin.seekg(0,ios::end);
	if(fin.tellg()==0)
	{
		cout<<"\tFile is empty!"<<endl;
	}
	else
	{
		fin.seekg(0);
		cout<<"\n\tList:"<<endl;
		while(fin.read(reinterpret_cast<char*>(&fav),sizeof(fav)))	
		{
			fav.PutData();
		}
	}
	fin.close();
	cout<<"\t";
	system("pause");
	Fruits_And_Vegetables_DataBase();
	
}

void Search_Fruits_Vegetables()
{
	Fruits_And_Vegetables();
	char found = 'n', search_productName[20], ch, isFile_empty='n';
	
	ifstream fin;
	fin.open("FruitsAndVegetables.dat",ios::binary|ios::in);
	fin.seekg(0,ios::end);
	if(fin.tellg()==0)
	{
		cout<<"\tFile is empty!"<<endl;
		isFile_empty = 'y';
	}
	else
	{
		cout<<"\n\tEnter name of Product: ";
		fflush(stdin);
		gets(search_productName);
		fin.seekg(0);
		while(fin.read(reinterpret_cast<char*>(&fav),sizeof(fav)))	
		{
			if(!strcmp(search_productName,fav.returnProductName()))
			{
				found = 'y';
				fav.PutData();
			}
		}
	}
	if(found=='n'&&(isFile_empty!='y'))
	{
		cout<<"\tRecord not found!"<<endl;
	}
	fin.close();
	if(isFile_empty!='y')
	{
		cout<<"\n\tDo you want to search more (Y/N): ";
		cin>>ch;
		if((ch=='y')||(ch=='Y'))
		Search_Fruits_Vegetables();
		else
		{
			cout<<"\t";
			system("pause");
			Fruits_And_Vegetables_DataBase();
		}
	}
	else
	cout<<"\t";
	system("pause");
	Fruits_And_Vegetables_DataBase();
		
}

void Delete_Fruits_Vegetables()
{
	Fruits_And_Vegetables();
	char found = 'n', search_productName[20], ch, isFile_empty = 'n';
	
	ifstream fin;
	fin.open("FruitsAndVegetables.dat",ios::binary|ios::in);
	ofstream temp;
	temp.open("Temp.dat",ios::binary);
	fin.seekg(0,ios::end);
	if(fin.tellg()==0)
	{
		cout<<"\tFile is empty!"<<endl;
		isFile_empty = 'y';
	}
	else
	{
		cout<<"\n\tEnter name of Product: ";
		fflush(stdin);
		gets(search_productName);
		fin.seekg(0);
		while(fin.read(reinterpret_cast<char*>(&fav),sizeof(fav)))	
		{
			if(strcmp(search_productName,fav.returnProductName()))
			{
				temp.write(reinterpret_cast<char*>(&fav),sizeof(fav));
			}
			else
			{
				found = 'y';
				cout<<"\tRecord deleted successfully. . ."<<endl;
			}
		}
	}
	if((found=='n')&&(isFile_empty!='y'))
	{
		cout<<"\t Record not found!"<<endl;
	}
	fin.close();
	temp.close();
	remove("FruitsAndVegetables.dat");
	rename("Temp.dat","FruitsAndVegetables.dat");
	if(isFile_empty!='y')
	{
		cout<<"\n\tDo you want to delete more (Y/N): ";
		cin>>ch;
		if((ch=='y')||(ch=='Y'))
		Delete_Fruits_Vegetables();
		else
		{
			cout<<"\t";
			system("pause");
			Fruits_And_Vegetables_DataBase();
		}
	}
	else
	cout<<"\t";
	system("pause");
	Fruits_And_Vegetables_DataBase();
	
}

//--------------------------------------------------------------------------------------end




//Fashion Database-------------------------------------------------------------------------------------
void Fashion()
{
	system("cls");
	system("color 02");
	cout<<endl<<endl;
	cout<<"\t----------------------------------------"<<endl;
	cout<<"\t\tFashion"<<endl;
	cout<<"\t----------------------------------------"<<endl<<endl;
}

void Fashion_DataBase()
{
	system("color 02");
	Fashion();
	DatabaseChoice();
	int database_choice;
	cin>>database_choice;
	switch(database_choice)
	{
		case 1: Display_Fashion();
				break;
		case 2: Search_Fashion();
				break;
		case 3: Add_Fashion();
				break;
		case 4:	Delete_Fashion();
				break;
		case 5:	SellerProducts();
			    break;
		case 6: Main_Menu_CustomerSeller();
				break;
		case 0: exit(0);
				break;
		default: cout<<"\tWrong Input!"<<endl<<"\t";
				 system("pause");
				 Fashion_DataBase();		 
	}
	
}

void Add_Fashion()
{
	char ch;
	Fashion();
	fas.GetData();
	ofstream fout;
    fout.open("Fashion.dat",ios::app|ios::binary);
    fout.write(reinterpret_cast<char*>(&fas),sizeof(fas));
    fout.close();
    cout<<"\tRecord Saved Successfully . . ."<<endl;
    cout<<"\n\tDo you want to add more (Y/N): ";
    cin>>ch;
    if((ch=='y')||(ch=='Y'))
    Add_Fashion();
    else
    {
    	cout<<"\t";
    	system("pause");
    	Fashion_DataBase();
	}
    
}

void Display_Fashion()
{
	Fashion();
	ifstream fin;
	fin.open("Fashion.dat",ios::binary|ios::in);
	fin.seekg(0,ios::end);
	if(fin.tellg()==0)
	{
		cout<<"\tFile is empty!"<<endl;
	}
	else
	{
		fin.seekg(0);
		cout<<"\n\tList:"<<endl;
		while(fin.read(reinterpret_cast<char*>(&fas),sizeof(fas)))	
		{
			fas.PutData();
		}
	}
	fin.close();
	cout<<"\t";
	system("pause");
	Fashion_DataBase();
	
}

void Search_Fashion()
{
	Fashion();
	char found = 'n', search_productName[20], ch, isFile_empty='n';
	
	ifstream fin;
	fin.open("Fashion.dat",ios::binary|ios::in);
	fin.seekg(0,ios::end);
	if(fin.tellg()==0)
	{
		cout<<"\tFile is empty!"<<endl;
		isFile_empty = 'y';
	}
	else
	{
		cout<<"\n\tEnter name of Product: ";
		fflush(stdin);
		gets(search_productName);
		fin.seekg(0);
		while(fin.read(reinterpret_cast<char*>(&fas),sizeof(fas)))	
		{
			if(!strcmp(search_productName,fas.returnProductName()))
			{
				found = 'y';
				fas.PutData();
			}
		}
	}
	if(found=='n'&&(isFile_empty!='y'))
	{
		cout<<"\tRecord not found!"<<endl;
	}
	fin.close();
	if(isFile_empty!='y')
	{
		cout<<"\n\tDo you want to search more (Y/N): ";
		cin>>ch;
		if((ch=='y')||(ch=='Y'))
		Search_Fashion();
		else
		{
			cout<<"\t";
			system("pause");
			Fashion_DataBase();
		}
	}
	else
	cout<<"\t";
	system("pause");
	Fashion_DataBase();
		
}

void Delete_Fashion()
{
	Fashion();
	char found = 'n', search_productName[20], ch, isFile_empty = 'n';
	
	ifstream fin;
	fin.open("Fashion.dat",ios::binary|ios::in);
	ofstream temp;
	temp.open("Temp.dat",ios::binary);
	fin.seekg(0,ios::end);
	if(fin.tellg()==0)
	{
		cout<<"\tFile is empty!"<<endl;
		isFile_empty = 'y';
	}
	else
	{
		cout<<"\n\tEnter name of Product: ";
		fflush(stdin);
		gets(search_productName);
		fin.seekg(0);
		while(fin.read(reinterpret_cast<char*>(&fas),sizeof(fas)))	
		{
			if(strcmp(search_productName,fas.returnProductName()))
			{
				temp.write(reinterpret_cast<char*>(&fas),sizeof(fas));
			}
			else
			{
				found = 'y';
				cout<<"\tRecord deleted successfully. . ."<<endl;
			}
		}
	}
	if((found=='n')&&(isFile_empty!='y'))
	{
		cout<<"\t Record not found!"<<endl;
	}
	fin.close();
	temp.close();
	remove("Fashion.dat");
	rename("Temp.dat","Fashion.dat");
	if(isFile_empty!='y')
	{
		cout<<"\n\tDo you want to delete more (Y/N): ";
		cin>>ch;
		if((ch=='y')||(ch=='Y'))
		Delete_Fashion();
		else
		{
			cout<<"\t";
			system("pause");
			Fashion_DataBase();
		}
	}
	else
	cout<<"\t";
	system("pause");
	Fashion_DataBase();
	
}

//--------------------------------------------------------------------------------------end




//Medicines Database-------------------------------------------------------------------------------------
void Medicines()
{
	system("cls");
	system("color 02");
	cout<<endl<<endl;
	cout<<"\t----------------------------------------"<<endl;
	cout<<"\t\tMedicines"<<endl;
	cout<<"\t----------------------------------------"<<endl<<endl;
}

void Medicines_DataBase()
{
	system("color 02");
	Medicines();
	DatabaseChoice();
	int database_choice;
	cin>>database_choice;
	switch(database_choice)
	{
		case 1: Display_Medicines();
				break;
		case 2: Search_Medicines();
				break;
		case 3: Add_Medicines();
				break;
		case 4:	Delete_Medicines();
				break;
		case 5:	SellerProducts();
			    break;
		case 6: Main_Menu_CustomerSeller();
				break;
		case 0: exit(0);
				break;
		default: cout<<"\tWrong Input!"<<endl<<"\t";
				 system("pause");
				 Medicines_DataBase();		 
	}
	
}

void Add_Medicines()
{
	char ch;
	Medicines();
	med.GetData();
	ofstream fout;
    fout.open("Medicines.dat",ios::app|ios::binary);
    fout.write(reinterpret_cast<char*>(&med),sizeof(med));
    fout.close();
    cout<<"\tRecord Saved Successfully . . ."<<endl;
    cout<<"\n\tDo you want to add more (Y/N): ";
    cin>>ch;
    if((ch=='y')||(ch=='Y'))
    Add_Medicines();
    else
    {
    	cout<<"\t";
    	system("pause");
    	Medicines_DataBase();
	}
    
}

void Display_Medicines()
{
	Medicines();
	ifstream fin;
	fin.open("Medicines.dat",ios::binary|ios::in);
	fin.seekg(0,ios::end);
	if(fin.tellg()==0)
	{
		cout<<"\tFile is empty!"<<endl;
	}
	else
	{
		fin.seekg(0);
		cout<<"\n\tList:"<<endl;
		while(fin.read(reinterpret_cast<char*>(&med),sizeof(med)))	
		{
			med.PutData();
		}
	}
	fin.close();
	cout<<"\t";
	system("pause");
	Medicines_DataBase();
	
}

void Search_Medicines()
{
	Medicines();
	char found = 'n', search_productName[20], ch, isFile_empty='n';
	
	ifstream fin;
	fin.open("Medicines.dat",ios::binary|ios::in);
	fin.seekg(0,ios::end);
	if(fin.tellg()==0)
	{
		cout<<"\tFile is empty!"<<endl;
		isFile_empty = 'y';
	}
	else
	{
		cout<<"\n\tEnter name of Product: ";
		fflush(stdin);
		gets(search_productName);
		fin.seekg(0);
		while(fin.read(reinterpret_cast<char*>(&med),sizeof(med)))	
		{
			if(!strcmp(search_productName,med.returnProductName()))
			{
				found = 'y';
				med.PutData();
			}
		}
	}
	if(found=='n'&&(isFile_empty!='y'))
	{
		cout<<"\tRecord not found!"<<endl;
	}
	fin.close();
	if(isFile_empty!='y')
	{
		cout<<"\n\tDo you want to search more (Y/N): ";
		cin>>ch;
		if((ch=='y')||(ch=='Y'))
		Search_Medicines();
		else
		{
			cout<<"\t";
			system("pause");
			Medicines_DataBase();
		}
	}
	else
	cout<<"\t";
	system("pause");
	Medicines_DataBase();
		
}

void Delete_Medicines()
{
	Medicines();
	char found = 'n', search_productName[20], ch, isFile_empty = 'n';
	
	ifstream fin;
	fin.open("Medicines.dat",ios::binary|ios::in);
	ofstream temp;
	temp.open("Temp.dat",ios::binary);
	fin.seekg(0,ios::end);
	if(fin.tellg()==0)
	{
		cout<<"\tFile is empty!"<<endl;
		isFile_empty = 'y';
	}
	else
	{
		cout<<"\n\tEnter name of Product: ";
		fflush(stdin);
		gets(search_productName);
		fin.seekg(0);
		while(fin.read(reinterpret_cast<char*>(&med),sizeof(med)))	
		{
			if(strcmp(search_productName,med.returnProductName()))
			{
				temp.write(reinterpret_cast<char*>(&med),sizeof(med));
			}
			else
			{
				found = 'y';
				cout<<"\tRecord deleted successfully. . ."<<endl;
			}
		}
	}
	if((found=='n')&&(isFile_empty!='y'))
	{
		cout<<"\t Record not found!"<<endl;
	}
	fin.close();
	temp.close();
	remove("Medicines.dat");
	rename("Temp.dat","Medicines.dat");
	if(isFile_empty!='y')
	{
		cout<<"\n\tDo you want to delete more (Y/N): ";
		cin>>ch;
		if((ch=='y')||(ch=='Y'))
		Delete_Medicines();
		else
		{
			cout<<"\t";
			system("pause");
			Medicines_DataBase();
		}
	}
	else
	cout<<"\t";
	system("pause");
	Medicines_DataBase();
	
}

//--------------------------------------------------------------------------------------end




//Sports Database-------------------------------------------------------------------------------------
void Sports()
{
	system("cls");
	system("color 02");
	cout<<endl<<endl;
	cout<<"\t----------------------------------------"<<endl;
	cout<<"\t\tSports"<<endl;
	cout<<"\t----------------------------------------"<<endl<<endl;
}

void Sports_DataBase()
{
	system("color 02");
	Sports();
	DatabaseChoice();
	int database_choice;
	cin>>database_choice;
	switch(database_choice)
	{
		case 1: Display_Sports();
				break;
		case 2: Search_Sports();
				break;
		case 3: Add_Sports();
				break;
		case 4:	Delete_Sports();
				break;
		case 5:	SellerProducts();
			    break;
		case 6: Main_Menu_CustomerSeller();
				break;
		case 0: exit(0);
				break;
		default: cout<<"\tWrong Input!"<<endl<<"\t";
				 system("pause");
				 Sports_DataBase();		 
	}
	
}

void Add_Sports()
{
	char ch;
	Sports();
	spo.GetData();
	ofstream fout;
    fout.open("Sports.dat",ios::app|ios::binary);
    fout.write(reinterpret_cast<char*>(&spo),sizeof(spo));
    fout.close();
    cout<<"\tRecord Saved Successfully . . ."<<endl;
    cout<<"\n\tDo you want to add more (Y/N): ";
    cin>>ch;
    if((ch=='y')||(ch=='Y'))
    Add_Sports();
    else
    {
    	cout<<"\t";
    	system("pause");
    	Sports_DataBase();
	}
    
}

void Display_Sports()
{
	Sports();
	ifstream fin;
	fin.open("Sports.dat",ios::binary|ios::in);
	fin.seekg(0,ios::end);
	if(fin.tellg()==0)
	{
		cout<<"\tFile is empty!"<<endl;
	}
	else
	{
		fin.seekg(0);
		cout<<"\n\tList:"<<endl;
		while(fin.read(reinterpret_cast<char*>(&spo),sizeof(spo)))	
		{
			spo.PutData();
		}
	}
	fin.close();
	cout<<"\t";
	system("pause");
	Sports_DataBase();
	
}

void Search_Sports()
{
	Sports();
	char found = 'n', search_productName[20], ch, isFile_empty='n';
	
	ifstream fin;
	fin.open("Sports.dat",ios::binary|ios::in);
	fin.seekg(0,ios::end);
	if(fin.tellg()==0)
	{
		cout<<"\tFile is empty!"<<endl;
		isFile_empty = 'y';
	}
	else
	{
		cout<<"\n\tEnter name of Product: ";
		fflush(stdin);
		gets(search_productName);
		fin.seekg(0);
		while(fin.read(reinterpret_cast<char*>(&spo),sizeof(spo)))	
		{
			if(!strcmp(search_productName,spo.returnProductName()))
			{
				found = 'y';
				spo.PutData();
			}
		}
	}
	if(found=='n'&&(isFile_empty!='y'))
	{
		cout<<"\tRecord not found!"<<endl;
	}
	fin.close();
	if(isFile_empty!='y')
	{
		cout<<"\n\tDo you want to search more (Y/N): ";
		cin>>ch;
		if((ch=='y')||(ch=='Y'))
		Search_Sports();
		else
		{
			cout<<"\t";
			system("pause");
			Sports_DataBase();
		}
	}
	else
	cout<<"\t";
	system("pause");
	Sports_DataBase();
		
}

void Delete_Sports()
{
	Sports();
	char found = 'n', search_productName[20], ch, isFile_empty = 'n';
	
	ifstream fin;
	fin.open("Sports.dat",ios::binary|ios::in);
	ofstream temp;
	temp.open("Temp.dat",ios::binary);
	fin.seekg(0,ios::end);
	if(fin.tellg()==0)
	{
		cout<<"\tFile is empty!"<<endl;
		isFile_empty = 'y';
	}
	else
	{
		cout<<"\n\tEnter name of Product: ";
		fflush(stdin);
		gets(search_productName);
		fin.seekg(0);
		while(fin.read(reinterpret_cast<char*>(&spo),sizeof(spo)))	
		{
			if(strcmp(search_productName,spo.returnProductName()))
			{
				temp.write(reinterpret_cast<char*>(&spo),sizeof(spo));
			}
			else
			{
				found = 'y';
				cout<<"\tRecord deleted successfully. . ."<<endl;
			}
		}
	}
	if((found=='n')&&(isFile_empty!='y'))
	{
		cout<<"\t Record not found!"<<endl;
	}
	fin.close();
	temp.close();
	remove("Sports.dat");
	rename("Temp.dat","Sports.dat");
	if(isFile_empty!='y')
	{
		cout<<"\n\tDo you want to delete more (Y/N): ";
		cin>>ch;
		if((ch=='y')||(ch=='Y'))
		Delete_Sports();
		else
		{
			cout<<"\t";
			system("pause");
			Sports_DataBase();
		}
	}
	else
	cout<<"\t";
	system("pause");
	Sports_DataBase();
	
}


//--------------------------------------------------------------------------------------end
//Seller Bills
//---------------------------------------------------------------------------------------
void Seller_Bills()
{
	system("cls");
	char Bill_Data;
	int tellPos;
	ifstream fin;
	fin.open("Bills.dat",ios::binary);
	cout<<"\n\t*****************************"<<endl;
	cout<<"\t\tAll Bills"<<endl;
	cout<<"\t*****************************"<<endl<<endl;
	fin.seekg(0,ios::end);
	tellPos = fin.tellg();
	tellPos = tellPos-1;
	if(fin.tellg()==0)
	{
		cout<<"\tNothing is purchased yet!"<<endl;
	}
	else
	{
		fin.seekg(0);
		cout<<setw(20)<<"Products"<<setw(25)<<"Price"<<setw(30)<<"Quantity"<<setw(30)<<"Amount"<<endl;
		cout<<"\t------------------------------------------------------------------------------------------------------"<<endl;
		while(!fin.eof())
		{
			Bill_Data = fin.get();
			cout<<Bill_Data;
		}
	}
	fin.close();
	cout<<"\t";
	system("pause");
	Seller();
}

//-------------------------------------------------------------------------------------end
void SellerProducts()
{
	system("cls");
	system("color 70");
	int ch;
	cout<<"\n\t*********************************"<<endl;
	cout<<"\t\tProduct Database"<<endl;
	cout<<"\t*********************************"<<endl<<endl;
	cout<<"\t1. Fruits and Vegetables"<<endl;
	cout<<"\t2. Fashion"<<endl;
	cout<<"\t3. Medicines"<<endl;
	cout<<"\t4. Sports"<<endl;
	cout<<"\t5. Go Back"<<endl;
	cout<<"\t6. Go to Main Menu"<<endl;
	cout<<"\t0. Exit"<<endl;
	cout<<"\t---------------------------------"<<endl<<endl;
	cout<<"\tEnter your Choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:	Fruits_And_Vegetables_DataBase();
			    break;
		case 2:	Fashion_DataBase();
			    break;
		case 3:	Medicines_DataBase();
			    break;
		case 4:	Sports_DataBase();
			    break;
		case 5: Seller();
				break;
		case 6:	Main_Menu_CustomerSeller();
			    break;
		case 0: exit(0);
			    break;	
		default: cout<<"\tWrong Input!"<<endl<<"\t";
				 system("pause");
				 SellerProducts();
	}
}

void Change_Password()
{
	system("cls");
    system("color 0C");
    string new_password, curr_password, compare_password;
    ifstream openFile("Password.dat",ios::binary);
    ofstream writeFile;
	cout<<endl;
    cout<<"\t##################################"<<endl;
    cout<<"\t\tChange Password"<<endl;
    cout<<"\t##################################"<<endl<<endl;
	cout<<endl<<"\t---------------------------------"<<endl<<endl;
	
	cout<<"\tEnter current password: ";
	cin.ignore();
    getline(cin,curr_password);
    openFile>>compare_password;
	for(int i=0;i<compare_password.size();i++)
	{
	    compare_password[i] -=4; //Dencrypting Password
	}
	
	openFile.close();
	
	if(curr_password==compare_password)
	{
		cout<<"\tEnter new password: ";
		getline(cin,new_password);
		writeFile.open("Password.dat",ios::binary|ios::out);
		for(int i=0;i<compare_password.size();i++)
		{
	    	new_password[i] +=4; //Encrypting Password
		}
		writeFile<<new_password;
		writeFile.close();
		cout<<"\tPassword updated successfully!\n\tRedirecting you to Main Menu\n\tWait For a While ";
		for(int i=0;i<5;i++)
			    {
			        Sleep(800);
			        cout<<". ";
			    }
		Main_Menu_CustomerSeller();
	}
	else
	{
		cout<<"\tPassword does not matched!\n";
		int AskChoice;
			cout<<"\n\t1. Re-Enter Password\n\t2. Go Back\n\t3. Go to Main Menu"<<endl;
			cout<<"\tEnter choice: ";
			cin>>AskChoice;
			if(AskChoice==3)
			{
				cout<<"\tRedirecting you to Main Menu";
				for(int i=0;i<5;i++)
			    {
			        Sleep(700);
			        cout<<".";
			    }
				Main_Menu_CustomerSeller();	
			} 
			
			else if(AskChoice==1)
			Change_Password();
			
			else if(AskChoice==2)
			Seller();
			
			else
			{
				cout<<"\tWrong Input!"<<endl;
				cout<<"\tRedirecting you";
				for(int i=0;i<5;i++)
			    {
			        Sleep(700);
			        cout<<".";
			    }
				Seller();
			}
	}
    
}

void Seller_Login()
{
	system("cls");
    system("color 0C");
    string compare_password,password;    
    ifstream openFile;
	cout<<endl;
    cout<<"\t###############################"<<endl;
    cout<<"\t\tSeller Login"<<endl;
    cout<<"\t###############################"<<endl<<endl;
	cout<<endl<<"\t---------------------------------"<<endl;
	openFile.open("Password.dat",ios::binary);
	if(!openFile)
	{
		ofstream writeFile("Password.dat",ios::out|ios::binary);
		cout<<"\t\tRegistration\n\t---------------------------------"<<endl;
		cout<<"\tEnter password: ";
		cin.ignore();
        getline(cin,password);
        cout<<"\tPassword saved successfully . . ."<<endl;
        for(int i=0;i<password.size();i++)
        {
        	password[i] += 4; //Encrypting Password
		}
		writeFile<<password;
       	writeFile.close();
       	cout<<"\t"; system("pause");
       	Main_Menu_CustomerSeller();
	}
	
	else
	{
		cout<<"\tEnter password: ";
		cin.ignore();
        getline(cin,password);

		openFile>>compare_password;
		for(int i=0;i<compare_password.size();i++)
	   	{
	       	compare_password[i] -=4; //Dencrypting Password
		}
		
		openFile.close();
		
	    if(password==compare_password)
	    {
	    	cout<<"\t---------------------------------"<<endl;
	        cout<<"\tPassword Matched........"<<endl<<"\t";
	        system("pause");
	        Seller();
		}
		else
		{
			cout<<"\t---------------------------------"<<endl;
			cout<<"\tWrong Password Entered!"<<endl;
			int AskChoice;
			cout<<"\n\t1. Go to Main Menu\n\t2. Re-Enter Password"<<endl;
			cout<<"\tEnter choice: ";
			cin>>AskChoice;
			if(AskChoice==1)
			{
				cout<<"\tRedirecting you to Main Menu";
				for(int i=0;i<5;i++)
			    {
			        Sleep(600);
			        cout<<".";
			    }
				Main_Menu_CustomerSeller();	
			}
			
			else if(AskChoice==2)
			Seller_Login();
			
			else
			{
				cout<<"\tWrong Input!"<<endl;
				cout<<"\tRedirecting you to Main Menu";
				for(int i=0;i<5;i++)
			    {
			        Sleep(600);
			        cout<<".";
			    }
				Main_Menu_CustomerSeller();	
			}
							
		}
		
	}				
}



void Seller() //Seller Menu
{
    int ch;
    system("cls");
    system("color f0");
    cout<<endl;
    cout<<"\t-------------------------"<<endl;
    cout<<setw(20)<<"\tSeller Menu"<<endl;
    cout<<"\t-------------------------"<<endl<<endl;
    cout<<setw(22)<<"1. All Bills"<<endl;
    cout<<setw(29)<<"2. Product Database"<<endl;
    cout<<setw(28)<<"3. Change Password"<<endl;
    cout<<setw(22)<<"4. Main Menu"<<endl;
    cout<<setw(17)<<"0. Exit"<<endl;
    cout<<"\t-------------------------"<<endl<<endl;
    cout<<setw(29)<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1:	Seller_Bills();
                break;
        case 2: SellerProducts();
                break;
        case 3: Change_Password();
        		break;
        case 4:	Main_Menu_CustomerSeller();
                break;
        case 0: exit(0);
                break;
        default: cout<<"\t  Wrong Input!\n\t  ";
        		 system("pause");
                 Seller();
    }

}

void Main_Menu_CustomerSeller()
{
	system("cls");
    system("color f1");
    int ch;
    cout<<endl;
    cout<<"\t-------------------------"<<endl;
    cout<<"\t\tMain Menu"<<endl;
    cout<<"\t-------------------------"<<endl<<endl;
    cout<<setw(22)<<"1. Customer"<<endl;
    cout<<setw(20)<<"2. Seller"<<endl;
    cout<<setw(18)<<"0. Exit"<<endl;
    cout<<"\t-------------------------"<<endl<<endl;
    cout<<setw(30)<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1: Customer();
                break;
        case 2: Seller_Login();
				break;
        case 0: exit(0);
                break;
        default: cout<<endl<<setw(23)<<"Wrong Input!"<<endl<<"\t";

    }
}


//Customer 


//Customer All Functions
//---------------------------------------------------------------------------------
void Buy_Products();
void Customer_Bills();
//-------------------------------------------------------------------------------end

void Customer_Bills()
{
	system("cls");
	char Bill_Data;
	int tellPos;
	ifstream fin;
	fin.open("Bills.dat",ios::binary);
	cout<<"\n\t*****************************"<<endl;
	cout<<"\t\tAll Bills"<<endl;
	cout<<"\t*****************************"<<endl<<endl;
	fin.seekg(0,ios::end);
	tellPos = fin.tellg();
	tellPos = tellPos-1;
	if(fin.tellg()==0)
	{
		cout<<"\tYou have not Purchased anything yet!"<<endl;
	}
	else
	{
		fin.seekg(0);
		cout<<setw(20)<<"Products"<<setw(25)<<"Price"<<setw(30)<<"Quantity"<<setw(30)<<"Amount"<<endl;
		cout<<"\t------------------------------------------------------------------------------------------------------"<<endl;
		while(!fin.eof())
		{
			Bill_Data = fin.get();
			cout<<Bill_Data;
		}
	}
	fin.close();
	cout<<"\t";
	system("pause");
	Customer();
}


//Buy Products---------------------------------------------------------------------------------
void Buy_Fruits_Vegetables()
{
	system("cls");
	system("color 9");
	
	char product_name[20], addMore,found,found_atleast1 = 'n';
	float iquantity = 0;
	int quantity = 0;
	double TotalPrice = 0, Amount;
	vector<string>products;
	vector<double>amount;
	vector<double>price_array;
	vector<int>quan;
	cout<<"\n\t-------------------------------------------------"<<endl;	
	cout<<"\t\tBuy Fruits and Vegetables"<<endl;
	cout<<"\n\t-------------------------------------------------"<<endl<<endl;
	cout<<"\n\tAvailable items: "<<endl;
	ifstream inFile;
	inFile.open("FruitsAndVegetables.dat",ios::binary);
	while(inFile.read(reinterpret_cast<char*>(&fav),sizeof(fav)))
	{
		fav.PutData();
	}
	inFile.close();
	
	ofstream outFile;
	outFile.open("Bills.dat",ios::app|ios::binary);
	
	do
	{
	    found = 'n';
		inFile.open("FruitsAndVegetables.dat",ios::binary);
		cout<<"\tEnter name of product you want: ";
		fflush(stdin);
		gets(product_name);
		while(inFile.read(reinterpret_cast<char*>(&fav),sizeof(fav)))
		{
			if(!strcmp(product_name,fav.returnProductName()))
			{
				found_atleast1 = 'y';
				found = 'y';
				
				quantity = 0;
				while(quantity<1)
				{
					cout<<"\tEnter Quantity: ";
					cin>>iquantity;
					quantity = iquantity;
					if(quantity<1)
					{
						cout<<"\tQuantity Cannot be Less than 1!"<<endl;
					}
				}
				
				outFile<<setw(20)<<fav.ProductName<<setw(25)<<fav.price<<setw(27)<<quantity;
				Amount = (fav.price)*quantity;
				TotalPrice += Amount;
				outFile<<setw(33)<<Amount<<endl;
				products.push_back(fav.ProductName);
				price_array.push_back(fav.price);
				amount.push_back(Amount);	
				quan.push_back(quantity);
			}
		}
		if(found=='n')
		{
			cout<<"\tProduct not found!"<<endl;
		}
		inFile.close();
		cout<<"\tDo you want to add more (Y/N): ";
		cin>>addMore;
	}while((addMore=='y')||(addMore=='Y'));
	
	if(found_atleast1=='y')
	{	outFile<<endl<<setw(110)<<"---------------"<<endl;
		outFile<<setw(102)<<"Total: "<<TotalPrice<<endl;
		outFile<<setw(110)<<"---------------"<<endl;
		outFile<<"        ------------------------------------------------------------------------------------------------------"<<endl;
	}
	outFile.close();
	
	if(found_atleast1=='y')
	{
		system("cls");
		cout<<"\n\n\t--------------------------------------"<<endl;
		cout<<"\t\t\tYour Bill: "<<endl;
		cout<<"\t--------------------------------------"<<endl<<endl;
		cout<<setw(20)<<"Products"<<setw(25)<<"Price"<<setw(30)<<"Quantity"<<setw(30)<<"Amount"<<endl;
		cout<<"\t------------------------------------------------------------------------------------------------------"<<endl;
		for(int i=0;i<price_array.size();i++)
		{
			cout<<setw(20)<<products[i]<<setw(25)<<price_array[i]<<setw(27)<<quan[i]<<setw(33)<<amount[i]<<endl;
		}
		cout<<"\n"<<setw(110)<<"---------------"<<endl;
		cout<<setw(102)<<"Total: "<<TotalPrice<<endl;
		cout<<setw(110)<<"---------------"<<endl;
		cout<<"\t------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"\tThanks for Shopping"<<endl;
		cout<<"\n\t";system("pause");
		Buy_Products();
	}
	else
	{
		system("cls");
		cout<<"\n\n\t--------------------------------------"<<endl;
		cout<<"\t\t\tYour Bill: "<<endl;
		cout<<"\t--------------------------------------"<<endl<<endl;
		cout<<"\tNOTHING BOUGHT!!"<<endl;
		cout<<"\n\t";system("pause");
		Buy_Products();
	}
	
	
}


void Buy_Medicines()
{
	system("cls");
	system("color 9");
	
	char product_name[20], addMore,found,found_atleast1 = 'n';
	int quantity = 0;
	float iquantity = 0;
	double TotalPrice = 0, Amount;
	vector<string>products;
	vector<double>amount;
	vector<double>price_array;
	vector<int>quan;
	cout<<"\n\t-------------------------------------------------"<<endl;	
	cout<<"\t\tBuy Medicines"<<endl;
	cout<<"\n\t-------------------------------------------------"<<endl<<endl;
	cout<<"\n\tAvailable items: "<<endl;
	ifstream inFile;
	inFile.open("Medicines.dat",ios::binary);
	while(inFile.read(reinterpret_cast<char*>(&med),sizeof(med)))
	{
		med.PutData();
	}
	inFile.close();
	
	ofstream outFile;
	outFile.open("Bills.dat",ios::app|ios::binary);
	
	do
	{
	    found = 'n';
		inFile.open("Medicines.dat",ios::binary);
		cout<<"\tEnter name of product you want: ";
		fflush(stdin);
		gets(product_name);
		while(inFile.read(reinterpret_cast<char*>(&med),sizeof(med)))
		{
			if(!strcmp(product_name,med.returnProductName()))
			{
				found_atleast1 = 'y';
				found = 'y';
				
				quantity = 0;
				while(quantity<1)
				{
					cout<<"\tEnter Quantity: ";
					cin>>iquantity;
					quantity = iquantity;
					if(quantity<1)
					{
						cout<<"\tQuantity Cannot be Less than 1!"<<endl;
					}
				}
				
				outFile<<setw(20)<<med.ProductName<<setw(25)<<med.price<<setw(27)<<quantity;
				Amount = (med.price)*quantity;
				TotalPrice += Amount;
				outFile<<setw(33)<<Amount<<endl;	
				products.push_back(med.ProductName);
				price_array.push_back(med.price);
				amount.push_back(Amount);	
				quan.push_back(quantity);
			}
		}
		if(found=='n')
		{
			cout<<"\tProduct not found!"<<endl;
		}
		inFile.close();
		cout<<"\tDo you want to add more (Y/N): ";
		cin>>addMore;
	}while((addMore=='y')||(addMore=='Y'));
	
	if(found_atleast1=='y')
	{
		outFile<<endl<<setw(110)<<"---------------"<<endl;
		outFile<<setw(102)<<"Total: "<<TotalPrice<<endl;
		outFile<<setw(110)<<"---------------"<<endl;
		outFile<<"        ------------------------------------------------------------------------------------------------------"<<endl;	
	}
	outFile.close();
	
	if(found_atleast1=='y')
	{
		system("cls");
		cout<<"\n\n\t--------------------------------------"<<endl;
		cout<<"\t\t\tYour Bill: "<<endl;
		cout<<"\t--------------------------------------"<<endl<<endl;
		cout<<setw(20)<<"Products"<<setw(25)<<"Price"<<setw(30)<<"Quantity"<<setw(30)<<"Amount"<<endl;
		cout<<"\t------------------------------------------------------------------------------------------------------"<<endl;
		for(int i=0;i<price_array.size();i++)
		{
			cout<<setw(20)<<products[i]<<setw(25)<<price_array[i]<<setw(27)<<quan[i]<<setw(33)<<amount[i]<<endl;
		}
		cout<<"\n"<<setw(110)<<"---------------"<<endl;
		cout<<setw(102)<<"Total: "<<TotalPrice<<endl;
		cout<<setw(110)<<"---------------"<<endl;
		cout<<"\t------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"\tThanks for Shopping"<<endl;
		cout<<"\n\t";system("pause");
		Buy_Products();
	}
	else
	{
		system("cls");
		cout<<"\n\n\t--------------------------------------"<<endl;
		cout<<"\t\t\tYour Bill: "<<endl;
		cout<<"\t--------------------------------------"<<endl<<endl;
		cout<<"\tNOTHING BOUGHT!!"<<endl;
		cout<<"\n\t";system("pause");
		Buy_Products();
	}
}


void Buy_Fashion()
{
	system("cls");
	system("color 9");
	
	char product_name[20], addMore,found,found_atleast1 = 'n';
	int quantity = 0;
	float iquantity = 0;
	double TotalPrice = 0, Amount;
	vector<string>products;
	vector<double>amount;
	vector<double>price_array;
	vector<int>quan;
	cout<<"\n\t-------------------------------------------------"<<endl;	
	cout<<"\t\tBuy Fashion"<<endl;
	cout<<"\n\t-------------------------------------------------"<<endl<<endl;
	cout<<"\n\tAvailable items: "<<endl;
	ifstream inFile;
	inFile.open("Fashion.dat",ios::binary);
	while(inFile.read(reinterpret_cast<char*>(&fas),sizeof(fas)))
	{
		fas.PutData();
	}
	inFile.close();
	
	ofstream outFile;
	outFile.open("Bills.dat",ios::app|ios::binary);
	
	do
	{
	    found = 'n';
		inFile.open("Fashion.dat",ios::binary);
		cout<<"\tEnter name of product you want: ";
		fflush(stdin);
		gets(product_name);
		while(inFile.read(reinterpret_cast<char*>(&fas),sizeof(fas)))
		{
			if(!strcmp(product_name,fas.returnProductName()))
			{
				found_atleast1 = 'y';
				found = 'y';
				
				quantity = 0;
				while(quantity<1)
				{
					cout<<"\tEnter Quantity: ";
					cin>>iquantity;
					quantity = iquantity;
					if(quantity<1)
					{
						cout<<"\tQuantity Cannot be Less than 1!"<<endl;
					}
				}
				outFile<<setw(20)<<fas.ProductName<<setw(25)<<fas.price<<setw(27)<<quantity;
				Amount = (fas.price)*quantity;
				TotalPrice += Amount;
				outFile<<setw(33)<<Amount<<endl;	
				products.push_back(fas.ProductName);
				price_array.push_back(fas.price);
				amount.push_back(Amount);	
				quan.push_back(quantity);
			}
		}
		if(found=='n')
		{
			cout<<"\tProduct not found!"<<endl;
		}
		inFile.close();
		cout<<"\tDo you want to add more (Y/N): ";
		cin>>addMore;
	}while((addMore=='y')||(addMore=='Y'));
	
	if(found_atleast1=='y')
	{
		outFile<<endl<<setw(110)<<"---------------"<<endl;
		outFile<<setw(102)<<"Total: "<<TotalPrice<<endl;
		outFile<<setw(110)<<"---------------"<<endl;
		outFile<<"        ------------------------------------------------------------------------------------------------------"<<endl;
	}
	outFile.close();
	
	if(found_atleast1=='y')
	{
		system("cls");
		cout<<"\n\n\t--------------------------------------"<<endl;
		cout<<"\t\t\tYour Bill: "<<endl;
		cout<<"\t--------------------------------------"<<endl<<endl;
		cout<<setw(20)<<"Products"<<setw(25)<<"Price"<<setw(30)<<"Quantity"<<setw(30)<<"Amount"<<endl;
		cout<<"\t------------------------------------------------------------------------------------------------------"<<endl;
		for(int i=0;i<price_array.size();i++)
		{
			cout<<setw(20)<<products[i]<<setw(25)<<price_array[i]<<setw(27)<<quan[i]<<setw(33)<<amount[i]<<endl;
		}
		cout<<"\n"<<setw(110)<<"---------------"<<endl;
		cout<<setw(102)<<"Total: "<<TotalPrice<<endl;
		cout<<setw(110)<<"---------------"<<endl;
		cout<<"\t------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"\tThanks for Shopping"<<endl;
		cout<<"\n\t";system("pause");
		Buy_Products();
	}
	else
	{
		system("cls");
		cout<<"\n\n\t--------------------------------------"<<endl;
		cout<<"\t\t\tYour Bill: "<<endl;
		cout<<"\t--------------------------------------"<<endl<<endl;
		cout<<"\tNOTHING BOUGHT!!"<<endl;
		cout<<"\n\t";system("pause");
		Buy_Products();
	}
}


void Buy_Sports()
{
	system("cls");
	system("color 9");
	
	char product_name[20], addMore,found,found_atleast1 = 'n';
	int quantity = 0;
	float iquantity = 0;
	double TotalPrice = 0, Amount;
	vector<string>products;
	vector<double>amount;
	vector<double>price_array;
	vector<int>quan;
	cout<<"\n\t-------------------------------------------------"<<endl;	
	cout<<"\t\tBuy Sports"<<endl;
	cout<<"\n\t-------------------------------------------------"<<endl<<endl;
	cout<<"\n\tAvailable items: "<<endl;
	ifstream inFile;
	inFile.open("Sports.dat",ios::binary);
	while(inFile.read(reinterpret_cast<char*>(&spo),sizeof(spo)))
	{
		spo.PutData();
	}
	inFile.close();
	
	ofstream outFile;
	outFile.open("Bills.dat",ios::app|ios::binary);
	
	do
	{
	    found = 'n';
		inFile.open("Sports.dat",ios::binary);
		cout<<"\tEnter name of product you want: ";
		fflush(stdin);
		gets(product_name);
		while(inFile.read(reinterpret_cast<char*>(&spo),sizeof(spo)))
		{
			if(!strcmp(product_name,spo.returnProductName()))
			{
				found_atleast1 = 'y';
				found = 'y';
				
				quantity = 0;
				while(quantity<1)
				{
					cout<<"\tEnter Quantity: ";
					cin>>iquantity;
					quantity = iquantity;
					if(quantity<1)
					{
						cout<<"\tQuantity Cannot be Less than 1!"<<endl;
					}
				}
				
				outFile<<setw(20)<<spo.ProductName<<setw(25)<<spo.price<<setw(27)<<quantity;
				Amount = (spo.price)*quantity;
				TotalPrice += Amount;
				outFile<<setw(33)<<Amount<<endl;
				products.push_back(spo.ProductName);
				price_array.push_back(spo.price);
				amount.push_back(Amount);	
				quan.push_back(quantity);
			}
		}
		if(found=='n')
		{
			cout<<"\tProduct not found!"<<endl;
		}
		inFile.close();
		cout<<"\tDo you want to add more (Y/N): ";
		cin>>addMore;
	}while((addMore=='y')||(addMore=='Y'));
	
	if(found_atleast1=='y')
	{
		outFile<<endl<<setw(110)<<"---------------"<<endl;
		outFile<<setw(102)<<"Total: "<<TotalPrice<<endl;
		outFile<<setw(110)<<"---------------"<<endl;
		outFile<<"        ------------------------------------------------------------------------------------------------------"<<endl;
	}
	outFile.close();
	if(found_atleast1=='y')
	{
		system("cls");
		cout<<"\n\n\t--------------------------------------"<<endl;
		cout<<"\t\t\tYour Bill: "<<endl;
		cout<<"\t--------------------------------------"<<endl<<endl;
		cout<<setw(20)<<"Products"<<setw(25)<<"Price"<<setw(30)<<"Quantity"<<setw(30)<<"Amount"<<endl;
		cout<<"\t------------------------------------------------------------------------------------------------------"<<endl;
		for(int i=0;i<price_array.size();i++)
		{
			cout<<setw(20)<<products[i]<<setw(25)<<price_array[i]<<setw(27)<<quan[i]<<setw(33)<<amount[i]<<endl;
		}
		cout<<"\n"<<setw(110)<<"---------------"<<endl;
		cout<<setw(102)<<"Total: "<<TotalPrice<<endl;
		cout<<setw(110)<<"---------------"<<endl;
		cout<<"\t------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"\tThanks for Shopping"<<endl;
		cout<<"\n\t";system("pause");
		Buy_Products();
	}
	else
	{
		system("cls");
		cout<<"\n\n\t--------------------------------------"<<endl;
		cout<<"\t\t\tYour Bill: "<<endl;
		cout<<"\t--------------------------------------"<<endl<<endl;
		cout<<"\tNOTHING BOUGHT!!"<<endl;
		cout<<"\n\t";system("pause");
		Buy_Products();
	}
}
//------------------------------------------------------------------------------end

void Search_Product()
{
	system("cls");
	system("color 9");
	cout<<"\n\t------------------------------------"<<endl;
	cout<<"\tSearch Product"<<endl;
	cout<<"\t------------------------------------"<<endl<<endl;
	char search_product[20],found = 'n',ch;
	cout<<"\tEnter Product Name: ";
	fflush(stdin);
	gets(search_product);
	ifstream inFile;
	inFile.open("FruitsAndVegetables.dat",ios::binary);
	while(inFile.read(reinterpret_cast<char*>(&fav),sizeof(fav)))
	{
		if(!strcmp(search_product,fav.returnProductName()))
		{
			found = 'y';
			fav.PutData();
		}
	}
	inFile.close();
	if(found!='y')
	{
		inFile.open("Fashion.dat",ios::binary);
		while(inFile.read(reinterpret_cast<char*>(&fas),sizeof(fas)))
		{
			if(!strcmp(search_product,fas.returnProductName()))
			{
				found = 'y';
				fas.PutData();
			}
		}
		inFile.close();
		if(found!='y')
		{
			inFile.open("Fashion.dat",ios::binary);
			while(inFile.read(reinterpret_cast<char*>(&fas),sizeof(fas)))
			{
				if(!strcmp(search_product,fas.returnProductName()))
				{
					found = 'y';
					fas.PutData();
				}
			}
			inFile.close();
			if(found!='y')
			{
				inFile.open("Medicines.dat",ios::binary);
				while(inFile.read(reinterpret_cast<char*>(&med),sizeof(med)))
				{
					if(!strcmp(search_product,med.returnProductName()))
					{
						found = 'y';
						med.PutData();
					}
				}
				inFile.close();
				if(found!='y')
				{
					inFile.open("Sports.dat",ios::binary);
					while(inFile.read(reinterpret_cast<char*>(&spo),sizeof(spo)))
					{
						if(!strcmp(search_product,spo.returnProductName()))
						{
							found = 'y';
							spo.PutData();
						}
					}
					inFile.close();
				}
			}
		}
	}
	if(found=='n')
	{
		cout<<"\tProduct Not Found!"<<endl;
	}
	cout<<"\tDo you want to search more (Y/N): ";
	cin>>ch;
	cout<<"\n\t------------------------------------"<<endl;
	if(ch=='y'||(ch=='Y'))
	Search_Product();
	else
	Customer();
}

void Buy_Products()//Select Category
{
	system("cls");
	system("color 9");
	int ch;
	cout<<"\n\t*********************************"<<endl;
	cout<<"\t\tSelect Category"<<endl;
	cout<<"\t*********************************"<<endl<<endl;
	cout<<"\t1. Fruits and Vegetables"<<endl;
	cout<<"\t2. Fashion"<<endl;
	cout<<"\t3. Medicines"<<endl;
	cout<<"\t4. Sports"<<endl;
	cout<<"\t5. Go Back"<<endl;
	cout<<"\t6. Go to Main Menu"<<endl;
	cout<<"\t0. Exit"<<endl;
	cout<<"\t---------------------------------"<<endl<<endl;
	cout<<"\tEnter your Choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:	Buy_Fruits_Vegetables();
				break;
		case 2:	Buy_Fashion();
				break;
		case 3: Buy_Medicines();
				break;
		case 4:	Buy_Sports();
				break;
		case 5: Customer();
				break;
		case 6:	Main_Menu_CustomerSeller();
				break;
		case 0:	exit(0);
				break;	
		default: cout<<"\tWrong Input!"<<endl;
				 system("pause");
				 Buy_Products();	
	}
}


//Customer Menu---------------------------------------------------------------------
void Customer() 
{
	system("cls");
    int ch;
    system("color 9");
    cout<<endl;
    cout<<"\t-------------------------------------"<<endl;
    cout<<"\t\tCustomer Menu"<<endl;
    cout<<"\t-------------------------------------"<<endl<<endl;
    cout<<"\t1. Buy Products"<<endl;
    cout<<"\t2. Search Products"<<endl;
    cout<<"\t3. Your Bills"<<endl;
    cout<<"\t4. Main Menu"<<endl;
    cout<<"\t0. Exit"<<endl<<endl;
    cout<<"\t----------------------------"<<endl;
    cout<<"\tEnter your choice: ";
    cin>>ch;
    cout<<"\t----------------------------"<<endl;
    switch(ch)
    {
        case 1:	Buy_Products();
                break;
        case 2:	Search_Product();
                break;
        case 3:	Customer_Bills();
                break;
        case 4: Main_Menu_CustomerSeller();
                break;
        case 0: exit(0);
                break;
        default: cout<<"\tWrong Input!"<<endl<<"\t";
        		 system("pause");
                 Customer();
    }
}

//---------------------------------------------------------------------------------end

int main()
{
	system("color 0E");
	cout<<"\n\n\n\n\t\t-------------------------------"<<endl;
	cout<<"\t\tMade By:"<<endl;
	cout<<"\t\t\tAbhay Bhandari"<<endl;
	cout<<"\t\t-------------------------------\n\n\n\t\t";
	system("pause");
	ofstream f1("FruitsAndVegetables.dat",ios::app|ios::binary);
	ofstream f2("Sports.dat",ios::app|ios::binary);
	ofstream f3("Medicines.dat",ios::app|ios::binary);
	ofstream f4("Fashion.dat",ios::app|ios::binary);
	ofstream f5("Bills.dat",ios::app|ios::binary);
	f1.close();
	f2.close();
	f3.close();
	f4.close();
	f5.close();
    char ch;
    do
    {
        Main_Menu_CustomerSeller();
        cout<<"\n\tPress Y to Continue or any other Key to Exit: ";
        ch = getche();
        system("cls");

    }while((ch=='y')||(ch=='Y'));
    return 0;
}



