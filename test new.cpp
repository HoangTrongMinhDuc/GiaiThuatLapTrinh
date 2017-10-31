#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;
struct author
{
	string 	tacgia;
	struct author* aNext;
};

struct article
{
	string id;
	string title;
	string magazine;
	string type;
	int issue;
	int volume;
	int year;
	string publisher;
	struct author *mainAHead;
	struct author *mainATail;
	struct author *coAHead;
	struct author *coATail;
	struct article *pNext;
};

struct list
{
	article *pHead;
	article *pTail;	
};


void init(list &l) //khoi tao danh sach rong
{
	l.pHead=l.pTail=NULL;
}

article* getArticle(article *x)  //tao them 1 article
{
	article *p = new article;
	if(p==NULL) return NULL;
	p = x;
	p->pNext = NULL;
	return p;
}

void addTail(list &l, article *p) //them node aticle vao cuoi danh sach bai bao
{
	if(l.pTail==NULL)
	{
		l.pHead=l.pTail=p;
		p->pNext=NULL;
	}
	else
	{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}

void initA(article *p)  //khoi tao danh sach rong cho 2 danh sach tac gia chinh va dong tac gia
{
	p->coAHead=p->coATail=NULL;
	p->mainAHead=p->mainATail=NULL;
}

author* getAuthor(string tg) //tao 1 node author moi de dua thong tin tac gia vao node
{
	author *a = new author;
	if(a==NULL) return NULL;
	a->tacgia = tg;
	a->aNext = NULL;
	return a;
}

void addTailMainAuthor(article *p, author *a) //them node auhtor vao cuoi danh sach mainAuthor
{
	if(p->mainATail==NULL)
	{
		p->mainAHead=p->mainATail=a;
		a->aNext=NULL;
	}
	else
	{
		p->mainATail->aNext=a;
		p->mainATail=a;
	}
}

void addTailCoAuthor(article *p, author *a) //them node author vao cuoi danh sach coAuthor
{
	if(p->coATail==NULL)
	{
		p->coAHead=p->coATail=a;
		a->aNext=NULL;
	}
	else
	{
		p->coATail->aNext=a;
		p->coATail=a;
	}
}


void docfile(list &l, ifstream &f)
{
	init(l); //khoi tao link list
	
		cout<<"Bat dau doc file"<<endl;
		while(!f.eof()) //doc den khi ket thuc file
		{
		
		article *x = new article;	//tao bien tam de luu gia tri doc vao
		
		string thongtin[10], tacgiachinh[10], tacgiaphu[10];
		string* maintg;
		string* cotg;
		stringstream ss;
		fflush(stdin);
		string enter;
		int n=0, m=0, i=0;
		
		//bat dau doc
		getline(f,x->id,'\n'); //doc id
		getline(f,x->title,'\n'); //doc title
		getline(f,x->magazine); // doc magazine
		f>>x->type; // doc type
		f>>x->issue; // doc issue
		f>>x->volume; // doc volume
		f>>x->year; // doc year
		f>>x->publisher; // doc publisher
		
		//doc xong thi dua vao danh sach lien ket
		article *q=getArticle(x);
		addTail(l,q);
		
		initA(l.pTail); //tao link list cho tac gia
		
		//xuong hang sau khi doc xong
		getline(f,enter,'\n');
		
		//bat dau doc tac gia chinh
		string temp;
		getline(f,temp, '\n');
		
		//doc tac gia phu
		string temp2;
		getline(f,temp2,'\n');
		
		//neu doc duoc tac gia phu thi xuong dong them lan nua
		if(temp2 != "") 
		{
			getline(f,enter,'\n');
		}
		
		
		char* tacgia = new char[temp.length()]; //tao bien char tac gia bang do dai cua string temp
		strcpy(tacgia, temp.c_str()); //copy dong tac gia chinh string vao kieu char
		//xu li bien tac gia kieu char thanh mang kieu string
		
		{
			int dauphay = 0;
			//dem so dau phay de biet so tac gia
			for(int index = 0; index < strlen(tacgia); index++)
			{
				if(tacgia[index] == ',') dauphay++;
			}
			string author_string;
			
			//return chinh bang tac gia
			if(dauphay == 0)
			{
				author_string = tacgia;
				author *a = getAuthor(author_string);
				addTailMainAuthor(l.pTail,a);
			}
			else
			{	
				//neu co nhieu tac gia thi copy chuoi vao tac[i]
				char tac[dauphay+1][25]; //moi bien co 25 ky tu
				int dem = 0; //bien chay
				char* p = strtok(tacgia, ","); //lay dia chi tacgia vao p
				while(p != '\0') //khi p chay toi cuoi chuoi
				{
					strcpy(tac[dem], p); //copy tacgia vua tim duoc vao tac[i]
					if(tac[dem][0] == ' ') //neu chuoi tac[i] co dau space o dau thi xoa
					{
						for(int giam = 0; giam < strlen(tac[dem]); giam++)
						{
							tac[dem][giam] = tac[dem][giam+1];
						}
					}
					
					dem++; //chay qua tac gia tiep theo
					p = strtok(NULL, ",");
				}
				//sau khi xu li xong thi dua vao ham nay de copy char sang string va dua vao link list
				for(int tang = 0; tang< dauphay+1; tang++)
				{
					
					author_string = tac[tang];
					//author *a = new author;
					author *a = getAuthor(author_string);
					addTailMainAuthor(l.pTail,a);
				}
			}
		}
		
		//neu ton tai tac gia phu thi xu li
		if(temp2 != "") 
		{
			char* tacgia2 = new char[temp2.length()];
			strcpy(tacgia2, temp2.c_str());
			int dauphay = 0;
			//dem so dau phay de biet so tac gia
			for(int index = 0; index < strlen(tacgia2); index++)
			{
				if(tacgia2[index] == ',') dauphay++;
			}
			string author_string;
			
			//return chinh bang tac gia
			if(dauphay == 0)
			{
				
				author_string = tacgia2;
				//author *a = new author;
				author *a = getAuthor(author_string);
				addTailMainAuthor(l.pTail,a);
			}
			else
			{	
				//neu co nhieu tac gia thi copy chuoi vao tac[i]
				char tac[dauphay+1][25]; //moi bien co 25 ky tu
				int dem = 0; //bien chay
				char* p = strtok(tacgia2, ","); //lay dia chi tacgia vao p
				while(p != '\0') //khi p chay toi cuoi chuoi
				{
					strcpy(tac[dem], p); //copy tacgia vua tim duoc vao tac[i]
					if(tac[dem][0] == ' ') //neu chuoi tac[i] co dau space o dau thi xoa
					{
						for(int giam = 0; giam < strlen(tac[dem]); giam++)
						{
							tac[dem][giam] = tac[dem][giam+1];
						}
					}
					
					dem++; //chay qua tac gia tiep theo
					p = strtok(NULL, ",");
				}
				//sau khi xu li xong thi dua vao ham nay de copy char sang string va dua vao link list
				for(int tang = 0; tang< dauphay+1; tang++)
				{
					author_string = tac[tang];
					author *a = getAuthor(author_string);
					addTailCoAuthor(l.pTail,a);
				}
			}
		}
		
		cout<<"\n++++++++\n";
	}
}

void showArticle(article *p)
{
	cout<<"\n====================================================="<<endl;
		cout<<p->id;
		cout<<p->title;
		cout<<p->magazine;
		cout<<p->type;
		cout<<p->issue<<endl;
		cout<<p->volume<<endl;
		cout<<p->year;
		cout<<p->publisher<<endl;
		
		cout<<"Tac gia chinh: "<<endl;
		author *a = new author;
		a = p->mainAHead;
		while(a!=NULL)
		{
			cout<<a->tacgia<<"|";
			a = a->aNext;
		}
		
		cout<<endl;
		
		cout<<"Dong ac gia: "<<endl;
		author *b = new author;
		b = p->coAHead;
		while(b!=NULL)
		{
			cout<<b->tacgia<<"|";
			b = b->aNext;
		}
}
void output(list &l)
{
	article *p = new article;
	p = l.pHead;
	while(p!=NULL)
	{
		showArticle(p);
		p = p->pNext;
	}
}

string NumtoString(int Number)
{
	stringstream convert;
	convert << Number;
	return convert.str();
}
void writeFile(list &l)
{
	time_t timenow = time(0);
	tm *time = localtime(&timenow);
	string exportName = "Export\\" +NumtoString(time->tm_hour) + "-" + NumtoString(time->tm_min) + "-" + 
						NumtoString(time->tm_sec) + "_(" + NumtoString(time->tm_mday) + "-" + 
						NumtoString(time->tm_mon+1) + "-" + NumtoString(time->tm_year+1900) + ")" +".txt";
	char* thoigian = new char[exportName.length()];
	strcpy(thoigian, exportName.c_str());
	fstream f;
	f.open(thoigian, ios::out);

	article *p = new article;
	p = l.pHead;
	while(p!=NULL)
	{
		{
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
			
			author *a = new author;
			a = p->mainAHead;
			while(a!=NULL)
			{
				if(a == p->mainATail)
				{
					f << a->tacgia + '\n';
					break;
				}
				f << a->tacgia +", ";
				a = a->aNext;
			}
			
			author *b = new author;
			b = p->coAHead;
			while(b!=NULL)
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
		f<< '\n';
		p = p->pNext;
	}
}
int main()
{
	list l;
	ifstream f;
	f.open("datanew.txt");
	docfile(l , f);
	f.close();
	writeFile(l);
	output(l);
	return 0;
}
