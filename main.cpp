#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <unistd.h>
#include <limits>
#include "List.h"
#include "Article.h"
#include "Author.h"
using namespace std;
int w = 5;
int e = 5;
int line = 3;
/*===========Cac ham chuc nang chuong trinh===========*/
void importData(List &l, ifstream &f);	//nhap du lieu tu file
void exportData(List &l);	//xuat du lieu ra file
void filterMagazine(List &l);
void filterType(List &l);
void filterYear(List &l);
void filterMainAuthor(List &l);
void filterCoAuthor(List &l);
void sortTitle(List &l);
void sortYear(List &l);
void findTitle(List &l);
void inputAddArticle(List &l, int mode);
void inputPosition(List &l, int &position);
Article* inputAnArticle(List &l);
void editArticle(List &l);
void deletePosition(List &l);
Article* findPosition(List &l, int position);
void output(List &l);
void detailArticle(List &l, string idArticle);
void showArticle(Article *p);
/*===========Menu===========*/
void header();
void ender();
void Menu(List &l);
void menuImport(List &l);
void menuInsert(List &l);
void menuFilter(List &l);
void menuSort(List &l);
/*===========Cac ham xu li phu===========*/
string NumtoString(int Number);
string getNameNow();
string fitText(string str, int num);
void gotoxy(int x, int y);
void resizeConsole(int width, int height);
int lengthList(List &l);
void resizeConsole(int width, int height);
void swap(Article *a, Article *b);
template <typename T>
void HoanVi(T &a, T &b);
void checkChangeStr(string &a, string &b);
void checkChangeInt(int &a, int &b);

int main()
{
	system("color f0");
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);
	resizeConsole(x+20,y+20);
	List l;
	Menu(l);
	return 0;
}

void Menu(List &l)
{	
	system("cls");	
	char ch;
	do
    {	
		int x = 106;
      	cout<<"\n\n\n\n";
      	cout<<setw(x)<<right<<"_______________________________________________\n";
      	cout<<setw(x)<<right<<"||                                           ||\n";
      	cout<<setw(x)<<right<<"||     HE THONG QUAN LY BAI BAO KHOA HOC     ||\n";
      	cout<<setw(x)<<right<<"||___________________________________________||\n";
      	cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"|| 1.Nhap Danh Sach Tu File.                 ||\n";
        cout<<setw(x)<<right<<"|| 2.In Danh Sach.                           ||\n";
        cout<<setw(x)<<right<<"|| 3.Them Vao Danh Sach.                     ||\n";
        cout<<setw(x)<<right<<"|| 4.Sua Danh Sach.                          ||\n";
        cout<<setw(x)<<right<<"|| 5.Xoa Phan Tu Trong Danh Sach.            ||\n";
        cout<<setw(x)<<right<<"|| 6.Tim Phan Tu Trong Danh Sach.            ||\n";
        cout<<setw(x)<<right<<"|| 7.Filter.                                 ||\n";
        cout<<setw(x)<<right<<"|| 8.Sap Xep Bai Bao.                        ||\n";
        cout<<setw(x)<<right<<"|| 0.Ket Thuc.                               ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"|_____________________________________________|\n";
        cout<<"\n\n\n"<<setw(75)<<right<<"CHON CONG VIEC : ";
        ch = getch();
        switch(ch)
        {
            case '1': 
           		system("cls");
                menuImport(l);
                break;
            case '2': 
           		system("cls");
                output(l);
                cout<<endl;
                system("cls");
                break;
            case '3': 
                menuInsert(l);
                break;
            case '4':
            	system("cls");
                editArticle(l);
                break;
            case '5': 
            	system("cls");
                deletePosition(l);
                break;
            case '6':
            	system("cls");
            	findTitle(l);
            	break;
            case '7':
            	system("cls");
            	menuFilter(l);
            	break;
            case '8':
            	system("cls");
            	menuSort(l);
            	break;
            case '0':
            	exit(0);
            	break;
            default:
            	Menu(l);
		}
    }while(ch!='0');
}

void menuImport(List &l)
{
	char ch;
	do
    {	
		int x = 106;
      	cout<<"\n\n\n\n";
      	cout<<setw(x)<<right<<"_______________________________________________\n";
      	cout<<setw(x)<<right<<"||                                           ||\n";
      	cout<<setw(x)<<right<<"||     HE THONG QUAN LY BAI BAO KHOA HOC     ||\n";
      	cout<<setw(x)<<right<<"||___________________________________________||\n";
      	cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"|| 1.Nhap Danh Sach Tu File.                 ||\n";
        cout<<setw(x)<<right<<"|| 2.Xuat Du Lieu Ra File.                   ||\n";
        cout<<setw(x)<<right<<"|| <.Quay Lai.                               ||\n";
        cout<<setw(x)<<right<<"|| 0.Ket Thuc.                               ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"|_____________________________________________|\n";
        cout<<"\n\n\n"<<setw(75)<<right<<"CHON CONG VIEC : ";
        ch = getch();
        while(true)
		{
			switch(ch)
	        {
	            case '1': 
	           		{
		           		ifstream f;
						f.open("Import\\data.txt");
		                importData(l,f);
		                f.close();
		                cout<<right<<"DA NHAP DU LIEU THANH CONG!";
		                sleep(1);
		                system("cls");
		                menuImport(l);
	            	}
	                break;
	            case '2':
	            	{
	            		exportData(l);
	            		cout<<right<<"DA XUAT DU LIEU THANH CONG!";
		                sleep(1);
		            	system("cls");
		                menuImport(l);
					}
	            	break;
	            case 8:
	            	system("cls");
	            	Menu(l);
	            	break;
	            case '0':
	            	exit(0);
			}
			ch = getch();
		}
		
    }while(ch!='0');
}

void menuInsert(List &l)
{
	system("cls");
	char ch;
	do
    {	
		int x = 106;
      	cout<<"\n\n\n\n";
      	cout<<setw(x)<<right<<"_______________________________________________\n";
      	cout<<setw(x)<<right<<"||                                           ||\n";
      	cout<<setw(x)<<right<<"||     HE THONG QUAN LY BAI BAO KHOA HOC     ||\n";
      	cout<<setw(x)<<right<<"||___________________________________________||\n";
      	cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"|| 1.Them vao dau danh sach.                 ||\n";
        cout<<setw(x)<<right<<"|| 2.Them vao cuoi danh sach.                ||\n";
        cout<<setw(x)<<right<<"|| 3.Them vao vi tri bat ky.                 ||\n";
        cout<<setw(x)<<right<<"|| <.Quay Lai.                               ||\n";
        cout<<setw(x)<<right<<"|| 0.Ket Thuc.                               ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"|_____________________________________________|\n";
        cout<<"\n\n\n"<<setw(75)<<right<<"CHON CONG VIEC : ";
        ch = getch();
        while(true)
		{
			switch(ch)
	        {
	            case '1': 
	           		{
		           		inputAddArticle(l,1);
	            	}
	                break;
	            case '2':
	            	{
	            		inputAddArticle(l,2);
					}
	            	break;
	            case '3':
	            	{
	            		inputAddArticle(l,3);
					}
	            	break;
	            case 8:
	            	system("cls");
	            	Menu(l);
	            	break;
	            case '0':
	            	exit(0);
			}
			ch = getch();
		}
		
    }while(ch!='0');
}

void menuFilter(List &l)
{
	system("cls");
	char ch;
	do
    {	
		int x = 106;
      	cout<<"\n\n\n\n";
      	cout<<setw(x)<<right<<"_______________________________________________\n";
      	cout<<setw(x)<<right<<"||                                           ||\n";
      	cout<<setw(x)<<right<<"||     HE THONG QUAN LY BAI BAO KHOA HOC     ||\n";
      	cout<<setw(x)<<right<<"||___________________________________________||\n";
      	cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"|| 1.Filter Theo Nam San Xuat.               ||\n";
        cout<<setw(x)<<right<<"|| 2.Filter Theo Ten Tac Gia Chinh.          ||\n";
        cout<<setw(x)<<right<<"|| 3.Filter Theo Ten Dong Tac Gia.           ||\n";
        cout<<setw(x)<<right<<"|| 4.Filter Theo Ten Tap Chi.                ||\n";
        cout<<setw(x)<<right<<"|| 5.Filter Theo Loai Tap Chi.               ||\n";
        cout<<setw(x)<<right<<"|| <.Quay Lai.                               ||\n";
        cout<<setw(x)<<right<<"|| 0.Ket Thuc.                               ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"|_____________________________________________|\n";
        cout<<"\n\n\n"<<setw(75)<<right<<"CHON CONG VIEC : ";
        ch = getch();
        while(true)
		{
			switch(ch)
	        {
	            case '1': 
	           		{
		                system("cls");
		                filterYear(l);
	            	}
	                break;
	            case '2':
	            	{
	            		system("cls");
		                filterMainAuthor(l);
					}
	            	break;
	            case '3':
	            	{
	            		system("cls");
		                filterCoAuthor(l);
					}
	            	break;
	            case '4':
	            	{
	            		system("cls");
		                filterMagazine(l);
					}
	            	break;
	            case '5':
	            	{
	            		system("cls");
		                filterType(l);
					}
	            	break;
	            case 8:
	            	system("cls");
	            	Menu(l);
	            	break;
	            case '0':
	            	exit(0);
			}
			ch = getch();
		}
    }while(ch!='0');
}

void menuSort(List &l)
{
	char ch;
	do
    {	
		int x = 106;
      	cout<<"\n\n\n\n";
      	cout<<setw(x)<<right<<"_______________________________________________\n";
      	cout<<setw(x)<<right<<"||                                           ||\n";
      	cout<<setw(x)<<right<<"||     HE THONG QUAN LY BAI BAO KHOA HOC     ||\n";
      	cout<<setw(x)<<right<<"||___________________________________________||\n";
      	cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"|| 1.Sap Xep Theo Nam San Xuat.              ||\n";
        cout<<setw(x)<<right<<"|| 2.Sap Xep Theo Tieu De Bai Bao.           ||\n";
        cout<<setw(x)<<right<<"|| <.Quay Lai.                               ||\n";
        cout<<setw(x)<<right<<"|| 0.Ket Thuc.                               ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"||                                           ||\n";
        cout<<setw(x)<<right<<"|_____________________________________________|\n";
        cout<<"\n\n\n"<<setw(75)<<right<<"CHON CONG VIEC : ";
        ch = getch();
        while(true)
		{
			switch(ch)
	        {
	            case '1': 
	           		{
		                sortYear(l);
		                cout<<right<<"Da Sap Xep!";
		                sleep(1);
		                system("cls");
		                menuSort(l);
	            	}
	                break;
	            case '2':
	            	{
		                sortTitle(l);
		                cout<<right<<"Da Sap Xep!";
		                sleep(1);
		                system("cls");
		                menuSort(l);
					}
	            	break; 
	            case 8:
	            	system("cls");
	            	Menu(l);
	            	break;
	            case '0':
	            	exit(0);
			}
			ch = getch();
		}
    }while(ch!='0');
}

void filterMagazine(List &l)
{
	string magazine;
	cout<<"Nhap ten bai bao: ";
	fflush(stdin);
	getline(cin,magazine,'\n');
	Article *p = l.pHead;
	header();
	while(p != NULL)
	{
		if(p->magazine.find(magazine) != string::npos)
		{
			showArticle(p);
			break;
		}
		p = p->pNext;
	}
	ender();
	e = w = 5;
	ender();
	char ch;
	cout<<setw(50)<<"|<: Back | Esc: Exit|";
	ch = getch();
	if(ch == 8) menuFilter(l);
	if(ch == 27) exit(0);
}

void filterType(List &l)
{
	string type;
	cout<<"Nhap loai bai bao: ";
	fflush(stdin);
	getline(cin,type,'\n');
	Article *p = l.pHead;
	header();
	while(p != NULL)
	{
		if(p->type == type)
			showArticle(p);
		p = p->pNext;
	}
	e = w = 5;
	ender();
	char ch;
	cout<<setw(50)<<"|<: Back | Esc: Exit|";
	ch = getch();
	if(ch == 8) menuFilter(l);
	if(ch == 27) exit(0);
}

void filterMainAuthor(List &l)
{
	string tacgia;
	cout<<"Nhap ten tac gia: ";
	fflush(stdin);
	getline(cin,tacgia,'\n');
	Article *p = l.pHead;
	header();
	while(p != NULL)
	{
		Author *q = p->mainAHead;
		while(q != NULL)
		{
			if(q->tacgia.find(tacgia) != string::npos)
			{
				showArticle(p);
				break;
			}
			q = q->aNext;
		}
		p = p->pNext;
	}
	e = w = 5;
	ender();
	char ch;
	cout<<setw(50)<<"|<: Back | Esc: Exit|";
	ch = getch();
	if(ch == 8) menuFilter(l);
	if(ch == 27) exit(0);
}

void filterCoAuthor(List &l)
{
	string tacgia;
	cout<<"Nhap ten tac gia: ";
	getline(cin,tacgia,'\n');
	Article *p = l.pHead;
	header();
	while(p != NULL)
	{
		Author *q = p->coAHead;
		while(q != NULL)
		{
			if(q->tacgia.find(tacgia) != string::npos)
			{
				showArticle(p);
				break;
			}
			q = q->aNext;
		}
		p = p->pNext;
	}
	e = w = 5;
	ender();
	char ch;
	cout<<setw(50)<<"|<: Back | Esc: Exit|";
	ch = getch();
	if(ch == 8) menuFilter(l);
	if(ch == 27) exit(0);
}

void filterYear(List &l)
{
	int nam;
	do
	{
		cout<<"Nhap nam: ";
		cin>>nam;
		if(cin.fail())
		{
			cout<<"Ban nhap sai dinh dang, moi nhap lai!"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		else
			break;
	}while(true);
	Article *p = l.pHead;
	header();
	while(p != NULL)
	{
		if(p->year == nam)
			showArticle(p);
		p = p->pNext;
	}
	e = w = 5;
	ender();
	char ch;
	cout<<setw(50)<<"|<: Back | Esc: Exit|";
	ch = getch();
	if(ch == 8) menuFilter(l);
	if(ch == 27) exit(0);
}

void sortYear(List &l)
{
	for(Article *a = l.pHead; a!= l.pTail; a = a->pNext)
	{
		for(Article *b = a->pNext; b != NULL; b = b->pNext)
		{
			if(a->year > b->year)
				swap(a,b);
		}
	}
}

void sortTitle(List &l)
{	
	for(Article *a = l.pHead; a!= l.pTail; a = a->pNext)
	{
		for(Article *b = a->pNext; b != NULL; b = b->pNext)
		{
			char* text1 = new char[a->title.length()];
			strcpy(text1, a->title.c_str());
			char* text2 = new char[b->title.length()];
			strcpy(text2, b->title.c_str());
			text1 = strlwr(text1);
			text2 = strlwr(text2);
			if(strcmp(text1, text2) > 0) 
				swap(a,b);
		}
	}
}

void findTitle(List &l)
{
	system("cls");
	fflush(stdin);
	bool isHave = false;
	string title;
	cout<<"Nhap ten bai bao: ";
	getline(cin,title,'\n');
	Article *p = l.pHead;
	header();
	while(p != NULL)
	{
		if(p->title.find(title) != string::npos)
			{
				showArticle(p);
				isHave = true;
			}
		p = p->pNext;
	}
	e = w = 5;
	ender();
	cout<<endl;
	if(!isHave) 
		cout<<"KHONG CO KET QUA NAO TRUNG!"<<endl;
	char ch;
	cout<<"\n"<<setw(50)<<"|<: Back | R: Try Again | Esc: Exit|";
	ch = getch();
	if(ch == 8) Menu(l);
	if(ch == 'r') findTitle(l);
	if(ch == 27) exit(0);
}

	void editArticle(List &l)
{
	system("cls");
	cout<<"De trong hoac nhap \"0\" neu khong muon thay doi"<<endl;
	int position;
	inputPosition(l,position);
	
	Article* p = findPosition(l,position);
	detailArticle(l,p->id);
	Article* x = inputAnArticle(l);
	if(x != NULL)
	{
		
		checkChangeStr(x->id,p->id);
		checkChangeStr(x->title,p->title);
		checkChangeStr(x->magazine,p->magazine);
		checkChangeStr(x->type,p->type);
		checkChangeInt(x->issue,p->issue);
		checkChangeInt(x->volume,p->volume);
		checkChangeInt(x->year,p->year);
		checkChangeStr(x->publisher,p->publisher);
		if(x->mainAHead != NULL)
		{
			HoanVi(x->mainAHead,p->mainAHead);
			HoanVi(x->mainATail,p->mainATail);
		}
		if(x->coAHead != NULL)
		{
			HoanVi(x->coAHead,p->coAHead);
			HoanVi(x->coATail,p->coATail);
		}
		cout<<"Da Sua Thanh Cong!"<<endl;
	}
	char ch;
	cout<<"\n"<<setw(50)<<"|<: Back | R: Try Again | Esc: Exit|";
	ch = getch();
	if(ch == 8) Menu(l);
	if(ch == 'r') editArticle(l);
	if(ch == 27) exit(0);
}

void checkChangeStr(string &a, string &b)
{
	if(a != "" && a != "0")
	{
		b = a;
	}
}

void checkChangeInt(int &a, int &b)
{
	if(a != 0)
	{
		b = a;
	}
}

void inputPosition(List &l, int &position)
{
	do
	{
		cout<<"Nhap vi tri: ";
		cin>>position;
		if(cin.fail())
		{
			cout<<"Ban nhap sai dinh dang, moi nhap lai!"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		else
		{
			if(position < 0 || position > lengthList(l))
			{
				cout<<"Vi tri khong hop le!"<<endl;
			}
			else
			{
				break;
			}
		}
			
	}while(true);
	
}

Article* inputAnArticle(List &l)
{
	fflush(stdin);
	Article *x = new Article;
	string enter;
	cout<<"Nhap id: ";
	getline(cin,x->id,'\n');
	cout<<"Nhap title: ";
	getline(cin,x->title,'\n');
	cout<<"Nhap tap chi: ";
	getline(cin,x->magazine,'\n');
	cout<<"Nhap loai tap chi: ";
	getline(cin,x->type,'\n');
	do
	{
			cout<<"Nhap so xuat ban, tap xuat ban va nam xuat ban (issue volume year): ";
			cin>>x->issue;
			cin>>x->volume;
			cin>>x->year;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"Nhap sai dinh dang!"<<endl;
			}
			else
				break;
	}while(true);
	getline(cin,enter,'\n');
	cout<<"Nhap nha xuat ban: ";
	getline(cin,x->publisher,'\n');
	Article *q = l.getArticle(x);
	int m;
	do
	{
			cout<<"Nhap so luong tac gia chinh: ";
			cin>>m;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"Nhap sai dinh dang!"<<endl;
			}else
			if(m < 1)
			{
				cout<<"So ban nhap phai lon hon 0!"<<endl;
			}
			else
				break;
	}while(true);
	getline(cin,enter,'\n');
	l.initA(q);
	for(int j = 0; j < m; j++)
	{
		string tg;
		cout<<"Nhap tac gia "<<j+1<<" : ";
		getline(cin,tg,'\n');
		Author *a = l.getAuthor(tg);
		l.addTailMainAuthor(q,a);
	}
	do
	{
			cout<<"Nhap so luong dong tac gia: ";
			cin>>m;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"Nhap sai dinh dang!"<<endl;
			}else
			if(m < 0)
			{
				cout<<"So ban nhap phai lon hon 0!"<<endl;
			}
			else
				break;
	}while(true);
	getline(cin,enter,'\n');
	for(int g = 0; g < m; g++)
	{
		string dtg;
		cout<<"Nhap tac gia "<<g+1<<" : ";
		getline(cin,dtg,'\n');
		Author *b = l.getAuthor(dtg);
		l.addTailCoAuthor(q,b);
	}
	return x;
}

void inputAddArticle(List &l, int mode)
{
	system("cls");
	cout<<"THEM BAI BAO VAO DU LIEU"<<endl;
	int position;
	if(mode == 3)
	{
		inputPosition(l,position);
	}
	Article* x = inputAnArticle(l);
	if(x != NULL)
	{
		if(mode == 1)
			l.addHead(x);
		if(mode == 2)
			l.addTail(x);
		if(mode == 3)
		{
			if(position == 1)
				l.addHead(x);
			else
			{
				if(position == lengthList(l))
					l.addTail(x);
				else
					l.addPosition(x,position);
			}
		}
		cout<<"\nDa Chen Thanh Cong!!"<<endl;
	}
	char ch;
	cout<<"\n"<<setw(50)<<"|<: Back| R: Try Again | Esc: Exit|";
	ch = getch();
	if(ch == 8) menuInsert(l);
	if(ch == 'r') inputAddArticle(l,mode);
	if(ch == 27) exit(0);
}


void header()
{
	int x = 10;
	int y = 28;
	int z = 15;
	int h=z;
	int k= 23;
	int q1 = GetSystemMetrics(SM_CXSCREEN);
	int q2 = GetSystemMetrics(SM_CYSCREEN);
	if(q1 <= 1366 && q2 <= 800)
			{
				x = 10;
				z = 7;
				y = 17;
				int h = z + 5;
				k = 20;
				cout<<" ___________________________________________________________________________________________________________________________________"<<endl;
			cout<<"|                                                                                                                                   |"<<endl;
			}
			else
			{
	cout<<" _________________________________________________________________________________________________________________________________________________________________________"<<endl;
	cout<<"|                                                                                                                                                                         |"<<endl;
	}
	cout<<"|"<<setw(x)<<left<<"ID";
	cout<<setw(y)<<left<<"TITLE";
	cout<<setw(y)<<left<<"MAGAZINE";
	cout<<setw(z)<<left<<"TYPE";
	cout<<setw(x)<<left<<"ISSUE";
	cout<<setw(x)<<left<<"VOLUME";
	cout<<setw(x)<<left<<"YEAR";
	cout<<setw(h)<<left<<"PUBLISHER";
	cout<<setw(k)<<left<<"TAC GIA CHINH";
	if(q1 <= 1366 && q2 <= 800)
		cout<<"DONG TAC GIA "<<"     |"<<endl;
	else
		cout<<"DONG TAC GIA "<<"       |"<<endl;
}
void ender()
{
	int q1 = GetSystemMetrics(SM_CXSCREEN);
	int q2 = GetSystemMetrics(SM_CYSCREEN);
	if(q1<=1366 &&q2<=800)
				cout<<" ____________________________________________________________________________________________________________________________________"<<endl;
			else
				cout<<"|_________________________________________________________________________________________________________________________________________________________________________|"<<endl;
	}
void showArticle(Article *p)
{	
	int x = 10;
	int y = 28;
	int z = 15;
	int k = GetSystemMetrics(SM_CXSCREEN);
	int l = GetSystemMetrics(SM_CYSCREEN);
	if(k <= 1366 && l <= 800)
		{
			x = 10;
			z = 7;
			y = 17;
			cout<<"|___________________________________________________________________________________________________________________________________|"<<endl;
		}
		else
		cout<<"|_________________________________________________________________________________________________________________________________________________________________________|"<<endl;
		cout<<" "<<setw(x)<<left<<p->id;
		if(k > 1366 && l > 800)
		{
			cout<<setw(y)<<left<<fitText(p->title,23);
			cout<<setw(y)<<left<<fitText(p->magazine,23);
		}
		else
		{
			cout<<setw(y)<<left<<fitText(p->title,13);
			cout<<setw(y)<<left<<fitText(p->magazine,13);
		}
		cout<<setw(z)<<left<<p->type;
		cout<<setw(x)<<left<<p->issue;
		cout<<setw(x)<<left<<p->volume;
		cout<<setw(x)<<left<<p->year;
		cout<<setw(z)<<left<<fitText(p->publisher,9);
		Author *a = new Author;
		a = p->mainAHead;
		int s1 = 0,s2 = 0;
		if(k > 1366 && l > 800)
		{
			s1 = x*4+y*2+2*z;
			s2 = x*4+3*y+2*z-5;
		}
		else
		{
			s1 = x*3+y*2+2*z+z+8;
			s2 = x*3+3*y+2*z+z+8;
		}
		while(a != NULL)
		{
			gotoxy(s1,w);
			cout<<setw(20)<<left<<fitText(a->tacgia,15);
			a = a->aNext;
			++w;
		}
		cout<<endl;
		Author *b = new Author;
		b = p->coAHead;
		while(b != NULL)
		{	
			gotoxy(s2,e);
			cout<<left<<fitText(b->tacgia,15);
			b = b->aNext;
			++e;
		}
		if(w > e) {e = ++w;}
		if(w <= e){ w = ++e;}
		cout<<endl;	
}

void output(List &l)
{
	system("cls");
	cout<<"BANG THONG KE CAC BAI BAO KHOA HOC"<<endl;
	int x = 10;
	int y = 28;
	int z = 15;
	int h=z;
	int k= 23;
	int q1 = GetSystemMetrics(SM_CXSCREEN);
	int q2 = GetSystemMetrics(SM_CYSCREEN);
	if(q1<=1366 &&q2<=800)
		{
			x=10;
			z=7;
			y=17;
			int h=z+5;
			k=20;
			cout<<" ___________________________________________________________________________________________________________________________________"<<endl;
			cout<<"|                                                                                                                                   |"<<endl;
		}
	else
		{
			cout<<" _________________________________________________________________________________________________________________________________________________________________________"<<endl;
			cout<<"|                                                                                                                                                                         |"<<endl;
		}
	cout<<"|"<<setw(x)<<left<<"ID";
	cout<<setw(y)<<left<<"TITLE";
	cout<<setw(y)<<left<<"MAGAZINE";
	cout<<setw(z)<<left<<"TYPE";
	cout<<setw(x)<<left<<"ISSUE";
	cout<<setw(x)<<left<<"VOLUME";
	cout<<setw(x)<<left<<"YEAR";
	cout<<setw(h)<<left<<"PUBLISHER";
	cout<<setw(k)<<left<<"TAC GIA CHINH";
	if(q1<=1366 &&q2<=800)
		cout<<"DONG TAC GIA "<<"  |"<<endl;
	else
		cout<<"DONG TAC GIA "<<"       |"<<endl;
	Article *p = new Article;
	p = l.pHead;
	while(p != NULL)
	{
		showArticle(p);
		p = p->pNext;
	}
	e = w = 5;
	if(q1<=1366 &&q2<=800)
				cout<<" ____________________________________________________________________________________________________________________________________"<<endl;
			else
				cout<<" _________________________________________________________________________________________________________________________________________________________________________"<<endl;
	char ch;
	cout<<setw(50)<<"|<: Back | D: Detail | Esc: Exit|";
	ch = getch();
	if(ch == 'd')
	{
		string idArticle;
		cout<<"Nhap ID bai bao can xem chi tiet: ";
		getline(cin,idArticle,'\n');
		detailArticle(l,idArticle);
	}
	if(ch == 8) Menu(l);
	if(ch == 27) exit(0);
}

void detailArticle(List &l, string idArticle)
{
	system("cls");
	int line = 0;
	Article* p = l.pHead;
	while(p != NULL)
	{
		if(p->id == idArticle)
			break;
		p = p->pNext;
	}
	if(p != NULL)
	{
		int srow = 30;
		int scol = 120;
		for(int row = 0; row < srow; row++)
		{
			for(int col = 0; col < scol; col++)
			{
				if(row == 0 || row == srow-1 || col == 0 && (row != 0 && row != srow-1) || col == scol-1 && (row != 0 && row != srow-1))
				{
					gotoxy(col+20,row);
					if(row == 0 || row == srow-1)
						cout<<"_";
					else
						cout<<"|";
				}
			}
		}
		line = 4;
		gotoxy(scol/3+20,line++);
		cout<<"XEM THONG TIN BAI BAO KHOA HOC";
		for(int i = 1; i <= scol-2; i++)
		{
			gotoxy(20+i,line);
			cout<<"_";
		}
		line += 3;
		gotoxy(scol/10+20,++line);
		cout<<"ID bai bao: "<<p->id;
		gotoxy(scol/10+20,++line);
		cout<<"Tieu de bai bao: ";
		for(int i = 0; i < p->title.length(); i++)
		{
			if( i%100 == 80)
				gotoxy(scol/10+20, ++line);
			cout<<p->title[i];
		}
		gotoxy(scol/10+20,++line);
		cout<<"Tap chi: "<<p->magazine;
		gotoxy(scol/10+20,++line);
		cout<<"Loai: "<<p->type;
		gotoxy(scol/10+20,++line);
		cout<<"So phat hanh: "<<p->issue;
		gotoxy(scol/10+20,++line);
		cout<<"Tap phat hanh: "<<p->volume;
		gotoxy(scol/10+20,++line);
		cout<<"nam phat hanh: "<<p->year;
		gotoxy(scol/10+20,++line);
		cout<<"Nha xuat ban: "<<p->publisher;
		gotoxy(scol/10+20,++line);
		Author* a = p->mainAHead;
		cout<<"Tac gia chinh: ";
		while(a != NULL)
		{
			if(a != p->mainATail)
				cout<<a->tacgia<<", ";
			else
				cout<<a->tacgia;
			a = a->aNext;
		}
		gotoxy(scol/10+20,++line);
		Author* b = p->coAHead;
		if(b != NULL)
		{
			cout<<"Dong tac gia: ";
			while(b != NULL)
			{
				if(b != p->coATail)
					cout<<b->tacgia<<", ";
				else
					cout<<b->tacgia;
				b = b->aNext;
			}
		}
		line = 30;
	}
	else
	{
		cout<<"ID ban da nhap khong ton tai trong du lieu";
	}
//	char ch;
	gotoxy(0,line+3);
//	cout<<setw(50)<<"|<: Back | Esc: Exit|";
//	ch = getch();
//	if(ch == 8) output(l);
//	if(ch == 27) exit(0);
}

void importData(List &l, ifstream &f) // doc du lieu tu file
{
	while(!f.eof()) //doc den khi ket thuc file
	{
		Article *x = new Article;	//tao bien tam de luu gia tri doc vao
		fflush(stdin);
		string enter;
		getline(f,x->id,'\n'); //doc id
		getline(f,x->title,'\n'); //doc title
		getline(f,x->magazine); // doc magazine
		f>>x->type; // doc type
		f>>x->issue; // doc issue
		f>>x->volume; // doc volume
		f>>x->year; // doc year
		getline(f,x->publisher, '\n');
		l.addTail(x);
		l.initA(l.pTail); //tao link list cho tac gia
		string temp;//bat dau doc tac gia chinh
		getline(f,temp, '\n');
		string temp2;//doc dong tac gia phu
		getline(f,temp2,'\n');
		if(temp2 != "") //neu doc duoc tac gia phu thi xuong dong them lan nua
		{
			getline(f,enter,'\n');
		}
		/*			bat dau xu li tach chuoi			*/
		char* tacgiachinh = new char[temp.length()]; //tao bien char tac gia bang do dai cua string temp
		strcpy(tacgiachinh, temp.c_str()); //copy dong tac gia chinh string vao kieu char
		{
			int dauphay = 0;
			for(int index = 0; index < strlen(tacgiachinh); index++)
			{
				if(tacgiachinh[index] == ',') dauphay++;
			}
			string author_temp;
			if(dauphay == 0)
			{
				author_temp = tacgiachinh;
				Author *a = l.getAuthor(author_temp);
				l.addTailMainAuthor(l.pTail,a);
			}
			else
			{	
				char tac_gia[dauphay+1][25]; //moi bien co 25 ky tu
				int dem = 0;
				char* p = strtok(tacgiachinh, ","); //lay dia chi tacgia vao p
				while(p != '\0') //khi p chay toi cuoi chuoi
				{
					strcpy(tac_gia[dem], p); //copy tacgia vua tim duoc vao tac[i]
					if(tac_gia[dem][0] == ' ') //neu chuoi tac[i] co dau space o dau thi xoa
					{
						for(int i = 0; i < strlen(tac_gia[dem]); i++)
						{
							tac_gia[dem][i] = tac_gia[dem][i+1];
						}
					}
					dem++; //chay qua tac gia tiep theo
					p = strtok(NULL, ",");
				}
				for(int i = 0; i< dauphay+1; i++)//sau khi xu li xong thi dua vao ham nay de copy char sang string va dua vao link list
				{
					author_temp = tac_gia[i];
					Author *a = l.getAuthor(author_temp);
					l.addTailMainAuthor(l.pTail,a);
				}
			}
		}
		if(temp2 != "") //neu co tac gia phu thi xu li
		{
			char* tacgiaphu = new char[temp2.length()];
			strcpy(tacgiaphu, temp2.c_str());
			{
				int dauphay = 0;
				for(int i = 0; i < strlen(tacgiaphu); i++)
				{
					if(tacgiaphu[i] == ',') dauphay++;
				}
				string author_temp;
				if(dauphay == 0)
				{
					author_temp = tacgiaphu;
					Author *a = l.getAuthor(author_temp);
					l.addTailMainAuthor(l.pTail,a);
				}
				else
				{	//neu co nhieu tac gia thi copy chuoi vao tac[i]
					char tac[dauphay+1][25]; //moi bien co 25 ky tu
					int dem = 0; //bien chay
					char* p = strtok(tacgiaphu, ","); //lay dia chi tacgia vao p
					while(p != '\0') //khi p chay toi cuoi chuoi
					{
						strcpy(tac[dem], p); //copy tacgia vua tim duoc vao tac[i]
						if(tac[dem][0] == ' ') //neu chuoi tac[i] co dau space o dau thi xoa
						{
							for(int i = 0; i < strlen(tac[dem]); i++)
							{
								tac[dem][i] = tac[dem][i+1];
							}
						}
						dem++; //chay qua tac gia tiep theo
						p = strtok(NULL, ",");
					}
					for(int i = 0; i < dauphay+1; i++)	//sau khi xu li xong thi dua vao ham nay de copy char sang string va dua vao link list
					{
						author_temp = tac[i];
						Author *a = l.getAuthor(author_temp);
						l.addTailCoAuthor(l.pTail,a);
					}
				}
			}
		}
	}
}

void exportData(List &l) //xuat du lieu
{					
	string time = getNameNow();
	char* exportName = new char[time.length()]; //chuyen string thanh char
	strcpy(exportName, time.c_str());
	fstream f;	//mo file moi de ghi
	f.open(exportName, ios::out);
	Article *p = new Article;	//cho con tro p tro toi dau linked list
	p = l.pHead;
	while(p != NULL) //chay cho den khi toi cuoi link list
	{
		{	//ghi cac thong tin ra
			f << p->id + '\n';
			f << p->title + '\n';
			f << p->magazine + '\n';
			f << p->type + ' ';
			f << p->issue;
			f << ' ';
			f << p->volume;
			f << ' ';
			f << p->year;
			f << ' ';
			f << p->publisher + '\n';
			Author *a = new Author;	//ghi thong tin ve tac gia chinh
			a = p->mainAHead;
			while(a != NULL)
			{
				if(a == p->mainATail)
				{
					f << a->tacgia + '\n';
					break;
				}
				f << a->tacgia +", ";
				a = a->aNext;
			}
			Author *b = new Author;//ghi thong tin ve dong tac gia
			b = p->coAHead;
			while(b != NULL)
			{
				if(b == p->coATail)
				{
					f << b->tacgia + '\n';
					break;
				}
				f << b->tacgia +", ";
				b = b->aNext;
			}
		}
		f<< '\n'; //tao ra dong trong sau khi ghi xong 1 article
		p = p->pNext; //tro den article tiep theo
	}
}

void deletePosition(List &l)
{
	system("cls");
	int position;
	do
	{
		cout<<"Nhap vi tri: ";
		cin>>position;
		if(cin.fail())
		{
			cout<<"Ban nhap sai dinh dang, moi nhap lai!"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		else
			break;
	}while(true);
	int count = 1;
	Article *p = l.pHead;
	if(position < 1 || position > lengthList(l))
		cout<<"Vi tri xoa khong hop le!";
	else 
	{
		if(position == 1)
			l.pHead=l.pHead->pNext;
		else
		{
			while(p != NULL && count != position-1)
			{
				count++;
				p = p->pNext;
			}
			p->pNext = p->pNext->pNext;
		}
		cout<<"\nDa Xoa!\n";
	}
	char ch;
	cout<<"\n"<<setw(50)<<"|<: Back|R: Try Again | Esc: Exit|";
	ch = getch();
	if(ch == 8) Menu(l);
	if(ch == 'r') deletePosition(l);
	if(ch == 27) exit(0);
}

Article* findPosition(List &l, int position)
{
	int i = 0;
	Article *p = new Article;
	p = l.pHead;
	while(p != NULL && position - 1 != i)
	{
		i++;
		p = p->pNext;
	}
	return p;
}



string NumtoString(int Number)
{
	stringstream convert;
	convert << Number;
	return convert.str();
}

string getNameNow()
{
	time_t getTime = time(0);	//lay thoi gian cua he thong
	tm *timeNow = localtime(&getTime); //doi qua struct tm	//ghep thanh chuoi	
	string time = "Export\\[" + NumtoString(timeNow->tm_mday) + "-" + NumtoString(timeNow->tm_mon+1) + "-" + NumtoString(timeNow->tm_year+1900) + "]" 
						+NumtoString(timeNow->tm_hour) + "h" + NumtoString(timeNow->tm_min) + "m" + NumtoString(timeNow->tm_sec) + "s" + ".txt";
	return time;
}

string fitText(string str, int num)
{
	if(str.length() <= num)
		return str;
	return str.substr(0,num-3) + "...";
}

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

int lengthList(List &l)
{
	Article *p = l.pHead;
	int i = 0;
	while(p != NULL)
	{
		++i;
		p = p->pNext;
	}
	return i;
}
void swap(Article *a, Article *b)
{
	HoanVi(a->id,b->id);
	HoanVi(a->title,b->title);
	HoanVi(a->magazine,b->magazine);
	HoanVi(a->type,b->type);
	HoanVi(a->issue,b->issue);
	HoanVi(a->volume,b->volume);
	HoanVi(a->year,b->year);
	HoanVi(a->publisher,b->publisher);
	HoanVi(a->mainAHead,b->mainAHead);
	HoanVi(a->mainATail,b->mainATail);
	HoanVi(a->coAHead,b->coAHead);
	HoanVi(a->coATail,b->coATail);
}

template <typename T>
void HoanVi(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

