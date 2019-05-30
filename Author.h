#include <iostream>
#include <string>
using namespace std;
#ifndef AUTHOR_H
#define AUTHOR_H
class Author
{
	public:
		string tacgia;
		Author* aNext;
	public:
		Author();
		Author(string, Author*);
		Author(string);
		Author(Author &);
		string getTacgia();
		void setTacgia(string );
		Author* getNext();
		void setNext(Author*);
};
#endif
