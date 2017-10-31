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
void cut(char* tacgia);

int lengthList(list &l)
{
	article *p = l.pHead;
	int i=0;
	while(p!=NULL)
	{
		i++;
		p = p->pNext;
	}
	return i;
}

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
void addHead(list &l, article *p) //them node aticle vao dau danh sach bai bao
{
	if(l.pHead==NULL)
	{
		l.pHead=l.pTail=p;
	}
	else
	{
		p->pNext=l.pHead;
		l.pHead=p;
	}
}
void addPosition(list &l, article *p, int position)
{
	article *q = l.pHead;
	int i = 1;
	while(q!=NULL && i!=(position-1))
	{
		i++;
		q = q->pNext;
	}
	p->pNext = q->pNext;
	q->pNext = p;
}
void processAddArticle(list &l, article *p, int position)
{
	if(position<1 || position>lengthList(l)+1)
		cout<<"Vi tri chen khong hop le!"<<endl;
	else if(position=1)
		addHead(l,p);
		else if(position=lengthList(l))
			addTail(l,p);
			else
				addPosition(l,p,position);
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
	cout<<"Nhap nam xuat ban: ";
	f>>x->year;
	cout<<"Nhap nha xuat ban: ";
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
void inputAddArticle(list &l)
{
	article *x = new article;
	int position;
	cout<<"Nhap vi tri muon them: ";
	cin>>position;
	
	cout<<"Nhap id: ";
	getline(cin,x->id,'.');
	cout<<"Nhap title: ";
	getline(cin,x->title,'.');
	cout<<"Nhap tap chi: ";
	getline(cin,x->magazine,'.');
	cout<<"Nhap loai tap chi: ";
	getline(cin,x->type,'.');
	cout<<"Nhap so xuat ban: ";
	cin>>x->issue;
	cout<<"Nhap tap xuat ban: ";
	cin>>x->volume;
	cout<<"Nhap nam xuat ban: ";
	cin>>x->year;
	cout<<"Nhap nha xuat ban: ";
	getline(cin,x->publisher,'.');
	article *q=getArticle(x);
	processAddArticle(l,q,position);
	
	int m;
	cout<<"Nhap so luong tac gia chinh: ";
	cin>>m;
	initA(l.pTail);
	for(int j=0; j<m; j++)
	{
		string tg;
		cout<<"Nhap tac gia "<<j+1<<" : ";
		getline(cin,tg,'.');
		author *a=getAuthor(tg);
		addTailMainAuthor(l.pTail,a);
	}
	
	int k;
	cout<<"Nhap so luong dong tac gia: ";
	cin>>k;
	for(int g=0; g<k; g++)
	{
		string dtg;
		cout<<"Nhap tac gia "<<g+1<<" : ";
		getline(cin,dtg,'.');
		author *b=getAuthor(dtg);
		addTailCoAuthor(l.pTail,b);
	}
	
}
void input(list &l, ifstream &f)
{
	init(l);
	while(!f.eof())
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
		cout<<"Nhap nam xuat ban: ";
		f>>x->year;
		cout<<"Nhap nha xuat ban: ";
		f>>x->publisher;
		article *q=getArticle(x);
		addTail(l,q);
		string enter;
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
	}
		
}
void fixArticle(list &l)
{
	string id;
	cout<<"Nhap vi tri muon sua: ";
	cin>>id;
	article *x;
	cout<<"Nhap id: ";
	getline(cin,x->id,'.');
	cout<<"Nhap title: ";
	getline(cin,x->title,'.');
	cout<<"Nhap tap chi: ";
	getline(cin,x->magazine,'.');
	cout<<"Nhap loai tap chi: ";
	getline(cin,x->type,'.');
	cout<<"Nhap so xuat ban: ";
	cin>>x->issue;
	cout<<"Nhap tap xuat ban: ";
	cin>>x->volume;
	cout<<"Nhap nam xuat ban: ";
	cin>>x->year;
	cout<<"Nhap nha xuat ban: ";
	getline(cin,x->publisher,'.');
	int count = 1;
	article *p = l.pHead;
	while(p!=NULL && p->id!=id)
	{
		p = p->pNext;
	}
	p = x;
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
	int dem = 0;
	while(p!=NULL)
	{
		cout<<"\n_____"<<dem<<"_____\n";
		showArticle(p);
		p = p->pNext;	
		dem++;
	}
}
void deletePosition(list &l)
{
	int position;
	cout<<"Nhap vi tri muon xoa: ";
	cin>>position;
	int count = 1;
	article *p = l.pHead;
	if(position<1 || position>lengthList(l))
		cout<<"Vi tri xoa khong hop le!";
	else if(position == 1)
			l.pHead=l.pHead->pNext;
		else
		{
			while(p!=NULL && count!=position-1)
			{
				count++;
				p = p->pNext;
			}
			p->pNext = p->pNext->pNext;
		}
}

void filterYear(list &l)
{
	int nam;
	cout<<"Nhap nam: ";
	cin>>nam;
	article *p = l.pHead;
	while(p!=NULL)
	{
		if(p->year==nam)
			showArticle(p);
		p = p->pNext;
	}	
}
void filterTitle(list &l)
{
	string title;
	cout<<"Nhap ten bai bao: ";
	getline(cin,title,'.');
	article *p = l.pHead;
	while(p!=NULL)
	{
		if(p->title.find(title) != string::npos)
			showArticle(p);
		p = p->pNext;
	}	
}
void filterType(list &l)
{
	string type;
	cout<<"Nhap loai bai bao: ";
	getline(cin,type,'.');
	article *p = l.pHead;
	while(p!=NULL)
	{
		if(p->type==type)
			showArticle(p);
		p = p->pNext;
	}	
}
void filterMainAuthor(list &l)
{
	string tacgia;
	cout<<"Nhap ten tac gia: ";
	getline(cin,tacgia,'.');
	article *p = l.pHead;
	while(p!=NULL)
	{
		author *q = p->mainAHead;
		while(q!=NULL)
		{
			if(q->tacgia.find(tacgia)!=string::npos)
				showArticle(p);
			q = q->aNext;
		}
		p = p->pNext;
	}	
}
void filterCoAuthor(list &l)
{
	string tacgia;
	cout<<"Nhap ten tac gia: ";
	getline(cin,tacgia,'.');
	article *p = l.pHead;
	while(p!=NULL)
	{
		author *q = p->coAHead;
		while(q!=NULL)
		{
			if(q->tacgia.find(tacgia)!=string::npos)
				showArticle(p);
			q = q->aNext;
		}
		p = p->pNext;
	}	
}
void swap(article &a,article &b)
{
	article c=a;
			a=b;
			b=c;
}
void sortID(list &l)
{	
	article *h= l.pHead;
	article *q=l.pHead->pNext;
	while (h!=NULL)
	{
		while(q!=NULL)
		{
			if(h->id>=q->id) swap(*h,*q);
			q=q->pNext;
		}
		h=h->pNext;
	}
}
void sortTitle(list &l)
{	
	article *h= l.pHead;
	article *q=l.pHead->pNext;
	while (h!=NULL)
	{
		while(q!=NULL)
		{
			if(h->title>=q->title) swap(*h,*q);
			q=q->pNext;
		}
		h=h->pNext;
	}
}
int main()
{
	ifstream f;
	f.open("datanew.txt");
	list l;
	input(l,f);
	output(l);
	f.close();
	return 0;
}
