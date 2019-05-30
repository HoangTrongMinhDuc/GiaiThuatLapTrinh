#include <iostream>
#include "List.h"

List::List()
{
	this->pHead = NULL;
	this->pTail = NULL;
}

Article* List::getArticle(Article* x)
{
	Article *p = new Article;
	if(p==NULL) return NULL;
	p = x;
	p->setNext(NULL);
	return p;
}

void List::addHead(Article* p)
{
	if(this->pHead == NULL)
	{
		this->pHead = this->pTail = p;
	}
	else
	{
		p->setNext(this->pHead);
		this->pHead = p;
	}
}

void List::addTail(Article* p)
{
	if(this->pTail == NULL)
	{
		this->pHead = this->pTail = p;
		//p->pNext=NULL;
	}
	else
	{
		this->pTail->setNext(p);
		this->pTail = p;
	}
}

void List::addPosition(Article* p, int position)
{
	Article *q = this->pHead; //cho con tro vao dau man
	int i = 1; //bien dem
	while(q!=NULL && i != (position-1)) //lap cho toi khi bien dem = gia tri vi tri muon chen
	{
		i++;
		q = q->pNext;
	}
	p->pNext = q->pNext; //tro cho con tro next cua p tro den vi tri article i cu~
	q->pNext = p; //tro vi tri i-1 toi article p
}

void List::initA(Article* p)
{
	p->setMainAHead(NULL);
	p->setMainATail(NULL);
	p->setCoAHead(NULL);
	p->setCoATail(NULL);
}

Author* List::getAuthor(string tacgia)
{
	Author *a = new Author;
	if(a == NULL) return NULL;
	a->setTacgia(tacgia);
	a->setNext(NULL);
	return a;
}

void List::addTailMainAuthor(Article* p, Author* a)
{
	if(p->getMainATail() == NULL)
	{
		p->setMainAHead(a);
		p->setMainATail(a);
		a->setNext(NULL);
	}
	else
	{
		p->getMainATail()->setNext(a);
		p->setMainATail(a);
	}
}

void List::addTailCoAuthor(Article* p, Author* a)
{
	if(p->getCoATail() == NULL)
	{
		p->setCoAHead(a);
		p->setCoATail(a);
		a->setNext(NULL);
	}
	else
	{
		p->getCoATail()->setNext(a);
		p->setCoATail(a);
	}
}
