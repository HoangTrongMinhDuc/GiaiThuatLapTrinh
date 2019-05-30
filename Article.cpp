#include <iostream>
#include "Article.h"

Article::Article()
{
	this->id = "";
	this->title = "";
	this->magazine = "";
	this->type = "";
	this->issue = 0;
	this->volume = 0;
	this->year = 0;
	this->publisher = "";
	this->mainAHead = NULL;
	this->mainATail = NULL;
	this->coAHead = NULL;
	this->coATail = NULL;
	this->pNext = NULL;
}

Article::Article(string id, string title, string magazine, string type, int issue, int volume, int year, string publisher, Author* mainAHead, Author* mainATail, Author* coAHead, Author* coATail, Article* pNext)
{
	this->id = id;
	this->title = title;
	this->magazine = magazine;
	this->type = type;
	this->issue = issue;
	this->volume = volume;
	this->year = year;
	this->publisher = publisher;
	this->mainAHead = mainAHead;
	this->mainATail = mainATail;
	this->coAHead = coAHead;
	this->coATail = coATail;
	this->pNext = pNext;
}

string Article::getId()
{
	return this->id;
}

string Article::getTitle()
{
	return this->title;
}

string Article::getMagazine()
{
	return this->magazine;
}

string Article::getType()
{
	return this->type;
}

int Article::getIssue()
{
	return this->issue;
}

int Article::getVolume()
{
	return this->volume;
}

int Article::getYear()
{
	return this->year;
}

string Article::getPublisher()
{
	return this->publisher;
}

Author* Article::getMainAHead()
{
	return this->mainAHead;
}

Author* Article::getMainATail()
{
	return this->mainATail;
}

Author* Article::getCoAHead()
{
	return this->coAHead;
}

Author* Article::getCoATail()
{
	return this->coATail;
}

Article* Article::getNext()
{
	return this->pNext;
}

void Article::setId(string id)
{
	this->id  = id;
}

void Article::setTitle(string title)
{
	this->title = title;
}

void Article::setMagazine(string magazine)
{
	this->magazine = magazine;
}

void Article::setType(string type)
{
	this->type = type;
}

void Article::setIssue(int issue)
{
	this->issue = issue;
}

void Article::setVolume(int volume)
{
	this->volume = volume;
}

void Article::setYear(int year)
{
	this->year = year;
}

void Article::setMainAHead(Author* mainAHead)
{
	this->mainAHead = mainAHead;
}

void Article::setMainATail(Author* mainATail)
{
	this->mainATail = mainATail;
}

void Article::setCoAHead(Author* coAHead)
{
	this->coAHead = coAHead;
}

void Article::setCoATail(Author* coATail)
{
	this->coATail = coATail;
}

void Article::setNext(Article* pNext)
{
	this->pNext = pNext;
}



