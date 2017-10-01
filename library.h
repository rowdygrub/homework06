#ifndef LIBRARY_H_
#define LIBRARY_H_
#include <iostream>
#include <string>
#include "publication.h"
#include <vector>
using namespace std;

class Library {
	public:
		void add_publication();
		void check_out(int publication_index, string patron_name, string patron_phone);
		void check_in(int publication_index);
		string publication_to_string(int publication_index);
		int number_of_publications();//return sizeof()vector
	private:
		vector<Publication> publications;
};
#endif
