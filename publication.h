#ifndef publication.h
#define publication.h
#include <iostream>
#include <string>
using namespace std;
	enum Genre{fiction,nonfiction,selfhelp,performance};
	enum Media{book,periodical,newspaper,audio,video};
	enum Age{children,teen,adult,restricted};

class Publication {
	public:
		Publication(string title, string author, string copyright, Genre genre, Media media, Age age,string isbn)
			: title{title}, author{author}, copyright{copyright}, genre{genre},
			media{media}, age{age}, isbn{isbn}, checked_out{false} {}
		void check_out(string patron_name, string patron_phone);
		void check_in();
		bool is_checked_out();
		string to_string();

	private:
		string genre_to_string(int genre);
		string media_to_string(int media);
		string age_to_string(int age);
		string title;
		string author;
		string copyright;
		Genre genre;
		Media media;
		Age age;
		string isbn;
		bool checked_out;
		string _patron_name;
		string _patron_phone;
};
#endif
