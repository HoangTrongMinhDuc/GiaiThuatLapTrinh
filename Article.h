#include <iostream>
#include <string>
#include "Author.h"
using namespace std;
#ifndef ARTICLE_H
#define ARTICLE_H
class Article
{
	public:
		string id;
		string title;
		string magazine;
		string type;
		int issue;
		int volume;
		int year;
		string publisher;
		Author *mainAHead;
		Author *mainATail;
		Author *coAHead;
		Author *coATail;
		Article *pNext;
	public:
		Article();
		Article(string, string, string, string, int, int, int, string, Author*, Author*, Author*, Author*, Article*);
		
		string getId();
		string getTitle();
		string getMagazine();
		string getType();
		int getIssue();
		int getVolume();
		int getYear();
		string getPublisher();
		Author* getMainAHead();
		Author* getMainATail();
		Author* getCoAHead();
		Author* getCoATail();
		Article* getNext();
		
		void setId(string);
		void setTitle(string);
		void setMagazine(string);
		void setType(string);
		void setIssue(int);
		void setVolume(int);
		void setYear(int);
		void setPublisher(string);
		void setMainAHead(Author*);
		void setMainATail(Author*);
		void setCoAHead(Author*);
		void setCoATail(Author*);
		void setNext(Article*);
};
#endif
