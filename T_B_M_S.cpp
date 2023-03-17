#include<iostream>
#include<windows.h>
using namespace std;

void Setcolor(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

class Person {
private:
	char* Name;
	int Age;
	char Gender;
public:
	Person()
	{
		Name = nullptr;
		Age = 00;
		Gender = NULL;
	}
	Person(char* Name, int Age, char Gender)
	{
		int x = strlen(Name);
		x++;
		this->Name = new char[x];
		strcpy_s(this->Name, x, Name);

		this->Age = Age;

		this->Gender = Gender;
	}
	void virtual Print_I() = 0;
	int Get_Age()
	{
		return Age;
	}
	char*Get_Name()
	{
		return Name;
	}
	char Get_Gender()
	{
		return Gender;
	}
	~Person()
	{

	}
};

class Adult :public Person {
private:
	char* Occupation;
	char* Qualification;
	char* NIC;
public:
	Adult() :Person()
	{
		Occupation = nullptr;
		Qualification = nullptr;
		NIC = nullptr;
	}
	Adult(char* Name, int Age, char Gender, char* Occupation, char* Qualification, char* NIC)
		:Person(Name, Age, Gender)
	{
		int x = strlen(Occupation);
		x++;
		this->Occupation = new char[x];
		strcpy_s(this->Occupation, x, Occupation);

		int y = strlen(Qualification);
		y++;
		this->Qualification = new char[y];
		strcpy_s(this->Qualification, y, Qualification);

		int z = strlen(NIC);
		z++;
		this->NIC = new char[z];
		strcpy_s(this->NIC, z, NIC);

	}
	void Print_I()
	{
		Setcolor(6);
		cout << "Passenger Information :" << endl

			<< "Name:";
		Setcolor(14);
		cout << Get_Name() << endl;

		Setcolor(6);
		cout << "Age: ";
		Setcolor(14);
		cout << Get_Age() << endl;

		Setcolor(6);
		cout << "Gender: ";
		Setcolor(14);
		cout << Get_Gender() << endl;

		Setcolor(6);
		cout << "Occuptation: ";
		Setcolor(14);
		cout << Occupation << endl;

		Setcolor(6);
		cout << "Qualifcation: ";
		Setcolor(14);
		cout << Qualification << endl;

		Setcolor(6);
		cout << "NIC: "; 
		Setcolor(14);
		cout << NIC << endl << endl;

	}
	~Adult()
	{

	}
};

class Kid :public Person
{
private:
	char* B_Form_Num;
public:
	Kid():Person()
	{
		B_Form_Num = nullptr;
	}
	Kid(char* Name, int Age, char Gender, char* B_Form_Num)
		:Person(Name, Age, Gender)
	{
		int x = strlen(B_Form_Num);
		x++;
		this->B_Form_Num = new char[x];
		strcpy_s(this->B_Form_Num, x, B_Form_Num);
	}
	void Print_I()
	{
		Setcolor(6);
		cout << "Passenger Information :" << endl

			<< "Name:";
		Setcolor(14);
		cout << Get_Name() << endl;

		Setcolor(6);
		cout << "Age: ";
		Setcolor(14);
		cout << Get_Age() << endl;

		Setcolor(6);
		cout << "Gender: ";
		Setcolor(14);
		cout << Get_Gender() << endl;

		Setcolor(6);
		cout << "B Form NO: ";
		Setcolor(14);
		cout<< B_Form_Num << endl;
	}
	~Kid()
	{

	}

};

class Bogie {
private:
	int Bogie_ID;
	Bogie* Next;
	Person** Adults;
	Person** kids;
	char* family_Name;
public:
	int Total_Adults = 0;
	int Total_Kids = 0;
	Bogie(int id)
	{
		Bogie_ID = id;
		Next = nullptr;
		family_Name = nullptr;
	}
	void AddPassengers()
	{
		if (Total_Adults < 5 || Total_Kids < 7)
		{
			char choice;
			Setcolor(12);
			cout << "Which kind of Passenger you want to add..? " << endl
				<< "Press 'A' for Adult" << endl
				<< "Press 'K' for Kid" << endl;
			Setcolor(7);
			cin >> choice;
			system("cls");

			if (choice == 'A'|| choice == 'a')
			{
				if (Total_Adults < 5)
				{
					Total_Adults++;

					if (Total_Adults>1)
					{
						Setcolor(14);
						cout << "Current Status." << endl
							<< "Adults :" << Total_Adults - 1 << endl
							<< "Kids :" << Total_Kids << endl;
						cout << "Max Limit of Adults per bogie is 5 and Kids is 7." << endl<<endl;

						Setcolor(11);
						char nam[50];
						cout << "Enter Name :";
						cin.ignore();
						Setcolor(7);
						cin.getline(nam, 50);

						Setcolor(11);
						int age;
						cout << "Enter Age :";
						Setcolor(7);
						cin >> age;
						
						Setcolor(11);
						char Gen;
						cout << "Enter Gender (M for male & F for female) :";
						Setcolor(7);
						cin >> Gen;

						Setcolor(11);
						char occ[100];
						cout << "Enter Occupation :";
						cin.ignore();
						Setcolor(7);
						cin.getline(occ, 100);

						Setcolor(11);
						char Qua[100];
						cout << "Enter Qualifcation :";
						Setcolor(7);
						cin.getline(Qua, 100);

						Setcolor(11);
						char Nic[12];
						cout << "Enter NIC Number :";
						Setcolor(7);
						cin.getline(Nic, 12);

						Person** temp = new Person * [Total_Adults];
						for (int i = 0; i < Total_Adults - 1; i++)
						{
							temp[i] = Adults[i];
						}
						Adults = new Person * [Total_Adults];
						for (int i = 0; i < Total_Adults - 1; i++)
						{
							Adults[i] = temp[i];
						}
						Adults[Total_Adults - 1] = new Adult(nam, age, Gen, occ, Qua, Nic);
						system("cls");
					}

					else
					{
						Setcolor(14);
						cout << "Current Status." << endl
							<< "Adults :" << Total_Adults - 1 << endl
							<< "Kids :" << Total_Kids << endl;
						cout << "Max Limit of Adults per bogie is 5 and Kids is 7." << endl << endl;

						Setcolor(11);
						char nam[50];
						cout << "Enter Name :";
						cin.ignore();
						Setcolor(7);
						cin.getline(nam, 50);

						Setcolor(11);
						int age;
						cout << "Enter Age :";
						Setcolor(7);
						cin >> age;

						Setcolor(11);
						char Gen;
						cout << "Enter Gender (M for male & F for female) :";
						Setcolor(7);
						cin >> Gen;

						Setcolor(11);
						char occ[100];
						cout << "Enter Occupation :";
						cin.ignore();
						Setcolor(7);
						cin.getline(occ, 100);

						Setcolor(11);
						char Qua[100];
						cout << "Enter Qualifcation :";
						Setcolor(7);
						cin.getline(Qua, 100);

						Setcolor(11);
						char Nic[12];
						cout << "Enter NIC Number :";
						Setcolor(7);
						cin.getline(Nic, 12);

						Adults = new Person * [Total_Adults];
						Adults[0] = new Adult(nam, age, Gen, occ, Qua, Nic);
						system("cls");
					}
					
				}
				else
				{
				    Setcolor(11);
					cout << "You can't Add any more Adults in this Bogie. " << endl;
				}

			}

			else if (choice == 'K'||choice == 'k')
			{
				if (Total_Kids<7)
				{
					Total_Kids++;

					if (Total_Kids > 1)
					{
						Setcolor(14);
						cout << "Current Status." << endl
							<< "Adults :" << Total_Adults << endl
							<< "Kids :" << Total_Kids-1 << endl;
						cout << "Max Limit of Adults per bogie is 5 and Kids is 7." << endl << endl;

						Setcolor(9);
						char nam[50];
						cout << "Enter Name :";
						cin.ignore();
						Setcolor(7);
						cin.getline(nam, 50);

						Setcolor(9);
						int age;
						cout << "Enter Age :";
						Setcolor(7);
						cin >> age;

						Setcolor(9);
						char Gen;
						cout << "Enter Gender (M for male & F for female) :";
						Setcolor(7);
						cin >> Gen;
				
						Setcolor(9);
						char B_Form[12];
						cout << "Enter B Form Number Number :";
						cin.ignore();
						Setcolor(7);
						cin.getline(B_Form, 12);
						
						Person** temp = new Person * [Total_Kids];
						for (int i = 0; i < Total_Kids - 1; i++)
						{
							temp[i] = kids[i];
						}
						kids = new Person * [Total_Kids];
						for (int i = 0; i < Total_Kids - 1; i++)
						{
							kids[i] = temp[i];
						}
						kids[Total_Kids - 1] = new Kid(nam, age, Gen, B_Form);
						system("cls");
					}

					else
					{
						
						Setcolor(14);
						cout << "Current Status." << endl
							<< "Adults :" << Total_Adults << endl
							<< "Kids :" << Total_Kids - 1 << endl;
						cout << "Max Limit of Adults per bogie is 5 and Kids is 7." << endl << endl;

						Setcolor(9);
						char nam[50];
						cout << "Enter Name :";
						cin.ignore();
						Setcolor(7);
						cin.getline(nam, 50);

						Setcolor(9);
						int age;
						cout << "Enter Age :";
						Setcolor(7);
						cin >> age;

						Setcolor(9);
						char Gen;
						cout << "Enter Gender (M for male & F for female) :";
						Setcolor(7);
						cin >> Gen;

						Setcolor(9);
						char B_Form[12];
						cout << "Enter B Form Number Number :";
						cin.ignore();
						Setcolor(7);
						cin.getline(B_Form, 12);

						kids = new Person * [Total_Kids];
						kids[0] = new Kid(nam, age, Gen,B_Form);
						system("cls");
					}
				}
				else
				{
					Setcolor(11);
					cout << "You can't Add any more Kids in this Bogie" << endl;
				}
			}
		}
	
	}
	void Print()
	{
		for (int i = 0; i < Total_Adults; i++)
		{
			Adults[i]->Print_I();
			cout << endl;
		}

		for (int i = 0; i < Total_Kids ; i++)
		{
			kids[i]->Print_I();
			cout << endl;
		}
	}
	void Set_Next(Bogie *obj)
	{
		Next = obj;
	}
	Bogie* Get_Next()
	{
		return Next;
	}
	void Set_Family(char* Fam)
	{
		int x = strlen(Fam);
		x++;
		family_Name = new char[x];
		strcpy_s(family_Name,x,Fam);
	}
	int Get_Bogie_ID()
	{
		return Bogie_ID;
	}
	char* Get_Family_Name()
	{
		return family_Name;
	}
	~Bogie()
	{

	}

};

class Train {
private:
	Bogie* Engine;
	Bogie* Current_Bogie;
	Bogie* Next_Bogie;
public:
	int Total_Bogies = 0;
	Train()
	{
		Engine = nullptr;
		Current_Bogie = nullptr;
	}
	void Add_Bogie(int id)
	{
		Total_Bogies++;

		if (Total_Bogies>1)
		{
			Next_Bogie = new Bogie(id);
			system("CLS");
			char fam[50];
			Setcolor(9);
			cout << "Enter Family Name :";
			Setcolor(7);
			cin.ignore();
			cin.getline(fam, 50);
			char cho;
			Setcolor(9);
			cout << "Do you want to add passengers in this Bogie.?" << endl
				<< "Press 'Y' for Yes and 'N' for No  ";
			Setcolor(7);
			cin >> cho;
			system("CLS");
			while (cho != 'N')
			{
				bool t = false;
				if (cho == 'Y')
				{
					Setcolor(3);
					cout << "Bogie ID :";
					Setcolor(7);
					cout<< id << endl;

					Setcolor(3);
					cout << "Family Name :";
					Setcolor(7);
					cout<< fam << endl;

					Next_Bogie->AddPassengers();
					Setcolor(3);
					cout << "Do you want to add more passengers in this Bogie.?" << endl
						<< "Press 'Y' for Yes and 'N' for No  ";
					Setcolor(7);
					cin >> cho;
					system("CLS");
					t = true;
				}
				else if (t == false)
				{
					Setcolor(4);
					cout << "Invalid Choice..!" << endl;
					Setcolor(3);
					cout<< "Do you want to add passengers in this Bogie.?" << endl
						<< "Press 'Y' for Yes and 'N' for No  ";
					Setcolor(7);
					cin >> cho;
					system("CLS");
				}
			}
			Current_Bogie->Set_Next(Next_Bogie);
			Current_Bogie = Next_Bogie;
		}

		else
		{
			Next_Bogie = new Bogie(id);
			system("CLS");
			char fam[50];
			Setcolor(9);
			cout << "Enter Family Name :";
			Setcolor(7);
			cin.ignore();
			Setcolor(7);
			cin.getline(fam, 50);
			char cho;
			Setcolor(9);
			cout << "Do you want to add passengers in this Bogie.?" << endl
				<< "Press 'Y' for Yes and 'N' for No  ";
			Setcolor(7);
			cin >> cho;
			system("CLS");
		
			while (cho != 'N')
			{
				bool t = false;
				if (cho == 'Y')
				{
					Setcolor(3);
					cout << "Bogie ID :";
					Setcolor(7);
					cout << id << endl;

					Setcolor(3);
					cout << "Family Name :";
					Setcolor(7);
					cout << fam << endl;

					Next_Bogie->AddPassengers();
					Setcolor(3);
					cout << "Do you want to add more passengers in this Bogie.?" << endl
						<< "Press 'Y' for Yes and 'N' for No  ";
					Setcolor(7);
					cin >> cho;
					system("CLS");
					t = true;
				}
				else if (t == false)
				{
					Setcolor(4);
					cout << "Invalid Choice..!" << endl;
					Setcolor(3);
					cout << "Do you want to add passengers in this Bogie.?" << endl
						<< "Press 'Y' for Yes and 'N' for No  ";
					Setcolor(7);
					cin >> cho;
					system("CLS");
					
				}
			}
			Engine = new Bogie(0);
			Engine->Set_Next(Next_Bogie);
			Current_Bogie = Next_Bogie;
		}
	}
	void Print_Train()
	{
		Setcolor(3);
		cout << "Bogie ID's"<<endl;
		for (int i = 0; i <= Total_Bogies; i++)
		{
			if (i == 0)
			{
				Next_Bogie = Engine;
				Current_Bogie = Next_Bogie->Get_Next();
				Next_Bogie = Current_Bogie;
			}
			else
			{
				Setcolor(9);
				cout << "Bogie No " << i << " ID: ";
				Setcolor(7);
				cout<< Next_Bogie->Get_Bogie_ID() << endl;
				Current_Bogie = Next_Bogie->Get_Next();
				Next_Bogie = Current_Bogie;
			}
		}
	}
    void Search_Bogie(int ID) 
	{
		bool avalible = false;
		for (int i = 0; i <= Total_Bogies; i++)
		{
			if (i == 0)
			{
				Next_Bogie = Engine;
				Current_Bogie = Next_Bogie->Get_Next();
				Next_Bogie = Current_Bogie;

			}
			else
			{
				Current_Bogie = Next_Bogie->Get_Next();
				if (Next_Bogie->Get_Bogie_ID() == ID)
					avalible = true;
				Next_Bogie = Current_Bogie;
			}
		}
		if (avalible == true)
		{
			Setcolor(11);
			cout << "Yes.! Bogie of ID " << ID << " is avalible." << endl;
		}
		else
		{
			Setcolor(4);
			cout << "No.! Bogie of ID " << ID << " is not avalible." << endl;
		}
	}
	void Remove_Bogie(int ID)
	{
		bool avalible = false;
		for (int i = 0; i < Total_Bogies; i++)
		{
			if (i == 0)
			{
				Next_Bogie = Engine;
				Current_Bogie = Next_Bogie->Get_Next();
				if (Current_Bogie->Get_Bogie_ID() == ID)
				{
					avalible = true;
					Bogie* t = Current_Bogie;
					Bogie* t1 = t->Get_Next();
					Next_Bogie->Set_Next(t1);
					i = Total_Bogies + 1;
				}
				if (avalible == false)
					Next_Bogie = Current_Bogie;

			}
			else
			{
				Current_Bogie = Next_Bogie->Get_Next();
				if (Current_Bogie->Get_Bogie_ID() == ID)
				{
					avalible = true;
					Bogie* t= Current_Bogie;
					Bogie* t1 = t->Get_Next();
					Next_Bogie->Set_Next (t1);
					i = Total_Bogies + 1;
				}
				if(avalible==false)
				Next_Bogie = Current_Bogie;
			}
		}
		if (avalible == true)
		{
			Setcolor(11);
			cout << "Bogie of ID " << ID << " has been removed successfully.!" << endl;
			Total_Bogies--;
		}
		else
		{
			Setcolor(7);
			cout << "Bogie removel unsuccessful.! "<<endl<< "Bogie of ID " << ID << " is unavalible." << endl;
		}
	}
	void Print_Info_All()
	{
		bool avalible = false;
		for (int i = 0; i <= Total_Bogies; i++)
		{
			if (i == 0)
			{
				Next_Bogie = Engine;
				Current_Bogie = Next_Bogie->Get_Next();
				Next_Bogie = Current_Bogie;

			}
			else
			{
				Current_Bogie = Next_Bogie->Get_Next();
				Setcolor(12);
				cout << "Bogie ID :";
				Setcolor(7);
				cout<< Next_Bogie->Get_Bogie_ID() << endl;

				Setcolor(12);
				cout << "Total Adults :";
				Setcolor(7);
				cout<< Next_Bogie->Total_Adults << endl;

				Setcolor(12);
				cout << "Total Kids :";
				Setcolor(7);
				cout<< Next_Bogie->Total_Kids << endl << endl;

				Next_Bogie->Print();
				Next_Bogie = Current_Bogie;
			}
		}
		
	}
	void Print_Info(int ID)
	{
		bool avalible = false;
		for (int i = 0; i <= Total_Bogies; i++)
		{
			if (i == 0)
			{
				Next_Bogie = Engine;
				Current_Bogie = Next_Bogie->Get_Next();
				Next_Bogie = Current_Bogie;
			}
			else
			{
				Current_Bogie = Next_Bogie->Get_Next();
				if (Next_Bogie->Get_Bogie_ID() == ID)
				{
					avalible = true;
					Current_Bogie = Next_Bogie->Get_Next();
					Setcolor(12);
					cout << "Bogie ID :";
					Setcolor(7);
					cout << Next_Bogie->Get_Bogie_ID() << endl;

					Setcolor(12);
					cout << "Total Adults :";
					Setcolor(7);
					cout << Next_Bogie->Total_Adults << endl;

					Setcolor(12);
					cout << "Total Kids :";
					Setcolor(7);
					cout << Next_Bogie->Total_Kids << endl << endl;
					Next_Bogie->Print();
				}
				Next_Bogie = Current_Bogie;
			}
		}
		
		if(avalible==false)
		{
			Setcolor(4);
			cout << "Invalid Bogie ID.! " << endl;
		}
	}
	~Train()
	{

	}
};

void M_Choice()
{
	Setcolor(8);
	cout << "Press 'A' to Add Bogie. " << endl
		<< "Press 'P' to Print the ID's of all bogies. " << endl
		<< "Press 'I' to Print Information of passengers. " << endl
		<< "Press 'S' to Search a perticular bogie. " << endl
		<< "Press 'R' to Remove a perticular bogie. " << endl
		<< "Press 'Q' to Quit. " << endl
		<< "Please Enter your choice ";
	Setcolor(7);
}

int main()
{
	Train T;
	char Main_Choice;
	Setcolor(14);
	cout<< "                                                   Resembool Express..!" << endl;
	M_Choice();
	Setcolor(7);
	cin >> Main_Choice;

	while (Main_Choice != 'Q' && Main_Choice != 'Y')
	{
		if (Main_Choice == 'A')
		{
			system("CLS");
			Setcolor(3);
			int id;
			cout << "Please Enter Bogie ID :";
			Setcolor(7);
			cin >> id;
			T.Add_Bogie(id);
			system("CLS");
			Setcolor(3);
			cout << "Bogie with ID " << id << " has been successfully added." << endl<<endl;

			M_Choice();
			cin >> Main_Choice;
		}
		else if (Main_Choice == 'P')
		{
			system("CLS");
			T.Print_Train();
			cout << endl;
			M_Choice();
			Setcolor(7);
			cin >> Main_Choice;
		}
		else if (Main_Choice == 'S')
		{
			system("CLS");
			Setcolor(3);
			int id;
			cout << "Please Enter Bogie ID :";
			Setcolor(7);
			cin >> id;
			T.Search_Bogie(id);
			cout << endl;
			M_Choice();
			cin >> Main_Choice;

		}
		else if (Main_Choice == 'R')
		{
			system("CLS");
			Setcolor(3);
			int id;
			cout << "Please Enter Bogie ID :";
			Setcolor(7);
			cin >> id;
			T.Remove_Bogie(id);
			cout << endl;
			M_Choice();
			cin >> Main_Choice;
		}
		else if (Main_Choice == 'I')
		{
			system("CLS");
			char C;
			Setcolor(12);
			cout << "Press 'A' to print information of all passengers. " << endl;
			cout << "Press 'P' to print information of passengers of a perticular bogie. " << endl;
			Setcolor(7);
			cin >> C;
			if (C == 'A')
			{
				system("CLS");
				T.Print_Info_All();
			}
			else if (C == 'P')
			{
				Setcolor(3);
				int id;
				cout << "Please Enter Bogie ID :";
				Setcolor(7);
				cin >> id;
				system("CLS");
				T.Print_Info(id);
			}
			cout << endl;
			M_Choice();
			cin >> Main_Choice;
		}
		if (Main_Choice == 'Q')
		{
			system("CLS");
			Setcolor(12);
			cout << "Do you really want to Quit.?" << endl
				<< "(Press 'Y' for Yes and 'N' for No)" << endl;
			Setcolor(7);
			cin >> Main_Choice;
			if (Main_Choice == 'N')
			{
				system("CLS");
				M_Choice();
				Setcolor(7);
				cin >> Main_Choice;
			}
		}
	}
	system("Pause");
	return 0;
}
