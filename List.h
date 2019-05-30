#include <iostream>
#include <string>
#include "Article.h"
#include "Author.h"
#ifndef LIST_H
#define LIST_H
class List
{
	public:
		Article *pHead;
		Article *pTail;
	public:
		List();
		Article* getArticle(Article*);
		void addHead(Article*);
		void addTail(Article*);
		void addPosition(Article*, int);
		void initA(Article*);
		Author* getAuthor(string);
		void addTailMainAuthor(Article*, Author*);
		void addTailCoAuthor(Article*, Author*);
};
#endif
