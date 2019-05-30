#include <iostream>
#include "Author.h"

Author::Author()
{
	this->tacgia = "";
	this->aNext = NULL;
}

Author::Author(string tacgia, Author *a)
{
	this->tacgia = tacgia;
	a->aNext = this->aNext;
	this->aNext = NULL;
}

Author::Author(string tacgia)
{
	this->tacgia = tacgia;
	this->aNext = NULL;
}

Author::Author(Author &a)
{
	this->tacgia = a.tacgia;
	this->aNext = a.aNext;
}

string Author::getTacgia()
{
	return this->tacgia;
}

void Author::setTacgia(string tacgia)
{	
	this->tacgia = tacgia;
}

Author* Author::getNext()
{
	return this->aNext;
}

void Author::setNext(Author *a)
{
	this->aNext = a;
}
