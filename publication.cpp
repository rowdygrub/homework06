#include <iostream>
#include <string>
#include "publication.h"
using namespace std;

void Publication::check_out(string patron_name, string patron_phone){
	_patron_name = patron_name;
	_patron_phone = patron_phone;
	checked_out = true;
}

void Publication::check_in(){
	_patron_name = "";
	_patron_phone = "";
	checked_out = false;
}

bool Publication::is_checked_out(){
	return checked_out;
}	

string Publication::to_string(){    
	string s = "\"" + title + "\" " + "By " + author + ", " + copyright  + genre_to_string(genre) + 	 		media_to_string(media) + age_to_string(age) + "ISBN:" + isbn;
	if(is_checked_out())
		return s + "\nChecked out to " + _patron_name + " " + _patron_phone; 
	return s;
}

//convert enum values
string Publication::genre_to_string(int genre){
	if(genre == 0)
		return " (fiction ";
	if(genre == 1)
		return " (nonfiction ";
	if(genre == 2)
		return " (self-help ";
	if(genre == 3)
		return " (performance ";
}

string Publication::media_to_string(int media){
	if(media == 0)
		return "book ";
	if(media == 1)
		return "periodical ";
	if(media == 2)
		return "newspaper ";
	if(media == 3)
		return "audio ";
	if(media == 4)
		return "video ";
}

string Publication::age_to_string(int age){
	if(age == 0)
		return "children) ";
	if(age == 1)
		return "teen) ";
	if(age == 2)
		return "adult) ";
	if(age == 3)
		return "restricted) ";
}




		
