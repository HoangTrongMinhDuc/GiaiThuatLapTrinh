#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
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

void addArticle(list &l, ifstream &f)
{
	article *x = new article;
	cout<<"Nhap id: ";
	getline(f,x->id,'\n');
	cout<<"Nhap title: ";
	getline(f,x->title,'\n');
	cout<<"Nhap tap chi: ";
	getline(f,x->magazine);
	cout<<"Nhap loai tap chi: ";
	f>>x->type;
	cout<<"Nhap so xuat ban: ";
	f>>x->issue;
	cout<<"Nhap tap xuat ban: ";
	f>>x->volume;
	f>>x->year;
	f>>x->publisher;
	article *q=getArticle(x);
	addTail(l,q);
	
//	string enter;
//	getline(f,enter,'\n');
//	
//	string tempA;
//	getline(f,tempA, '\n');
//	string tempB;
//	getline(f,tempB,'\n');
//	if(tempB != "") 
//	{
//		getline(f,enter,'\n');
//	}
//	
//	char* tacgiaA = new char[tempA.length()];
//	strcpy(tacgiaA, tempA.c_str());
//	char* tacgiaB = new char[tempB.length()];
//	strcpy(tacgiaB, tempB.c_str());
//		
//	initA(l.pTail);
//	
//	for(int j=0; j<m; j++)
//	{
//		string tg;
//		cout<<"Nhap tac gia "<<j+1<<" : ";
//		getline(cin,tg,'.');
//		author *a=getAuthor(tg);
//		addTailMainAuthor(l.pTail,a);
//	}
//	
//	int k;
//	cout<<"Nhap so luong dong tac gia: ";
//	cin>>k;
//	for(int g=0; g<k; g++)
//	{
//		string dtg;
//		cout<<"Nhap tac gia "<<g+1<<" : ";
//		getline(cin,dtg,'.');
//		author *b=getAuthor(dtg);
//		addTailCoAuthor(l.pTail,b);
//	}
}
void showArticle(article *p);
void input(list &l, ifstream &f)
{
	init(l);
	string temp;
	while(!f.eof())
		{
			fflush(stdin);
			article *x = new article;
			getline(f,x->id,'\n');
			getline(f,x->title,'\n');
			getline(f,x->magazine, '\n');
			f>>x->type;
			f>>x->issue;
			f>>x->volume;
			f>>x->year;
			f>>x->publisher;
			getline(f, temp, '\n');
			article *q=getArticle(x);
			addTail(l,q);
			showArticle(q);
//			cout<<x->id<<endl;
//			cout<<x->title<<endl;
//			cout<<x->magazine<<endl;
		}
}
void showArticle(article *p)
{
	cout<<"\n====================================================="<<endl;
		cout<<p->id<<endl;
		cout<<p->title<<endl;
		cout<<p->magazine<<endl;
		cout<<p->type<<endl;
		cout<<p->issue<<endl;
		cout<<p->volume<<endl;
		cout<<p->year<<endl;
		cout<<p->publisher<<endl;
		
//		cout<<"Tac gia chinh: "<<endl;
//		author *a = new author;
//		a = p->mainAHead;
//		while(a!=NULL)
//		{
//			cout<<a->tacgia;
//			a = a->aNext;
//		}
//		
//		cout<<endl;
//		
//		cout<<"Dong ac gia: "<<endl;
//		author *b = new author;
//		b = p->coAHead;
//		while(b!=NULL)
//		{
//			cout<<b->tacgia;
//			b = b->aNext;
//		}
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

int main()
{
	ifstream f;
	f.open("datanew.txt");
	list l;
	input(l,f);
	f.close();
	//output(l);
	return 0;
}
