#include <iostream>
#include <string>
#include "library.h"
#include "publication.h"
#include <vector>
#include <map>
#include <gtkmm.h>
using namespace std;

//enum enter as strings then check if the string equals fiction, nonfiction..., to pass fiction into enum. find a different way
void Library::add_publication(){
	Gtk::Dialog *menu = new Gtk::Dialog();
	menu->set_title("Add Publication");

	string title, author, copyright, genre, media, age, isbn;

	//title
	Gtk::Label *label = new Gtk::Label("Enter Title");
	menu->get_content_area()->pack_start(*label);
	label->show();//shows the menu

	Gtk::Entry *entry = new Gtk::Entry{};
	entry->set_text("");
	entry->set_max_length(50);
	entry->show();
	menu->get_vbox()->pack_start(*entry);
			
	menu->add_button("OK",1);
	menu->set_default_response(1);

	menu->run(); //this makes dialog pop up		
	
	title = entry->get_text();

	menu->close();

	while(Gtk::Main::events_pending()) Gtk::Main::iteration();
	delete entry;
	delete label;
	delete menu;

	//author
	Gtk::Dialog *menu2 = new Gtk::Dialog();
	menu2->set_title("Add Publication");

	Gtk::Label *label2 = new Gtk::Label("Enter Author");
	menu2->get_content_area()->pack_start(*label2);
	label2->show();//shows the menu

	Gtk::Entry *entry2 = new Gtk::Entry{};
	entry2->set_text("");
	entry2->set_max_length(50);
	entry2->show();
	menu2->get_vbox()->pack_start(*entry2);
			
	menu2->add_button("OK",1);
	menu2->set_default_response(1);

	menu2->run(); //this makes dialog pop up		
	author = entry2->get_text();
	menu2->close();

	while(Gtk::Main::events_pending()) Gtk::Main::iteration();
	delete entry2;
	delete label2;
	delete menu2;

	
	
	//TODO the rest
	
	cout << "Enter copyright year:";
	
	cout << "Enter genre:";
	
	cout << "Enter media:";
	
	cout << "Enter age:";
	
	cout << "Enter isbn number:";
	
	
	//maps
	map<string,Genre> string_to_enum;
	map<string,Media> string_to_enum2;
	map<string,Age> string_to_enum3;
	string_to_enum["fiction"] = fiction;
	string_to_enum["nonfiction"] = nonfiction;
	string_to_enum["selfhelp"] = selfhelp;
	string_to_enum["performance"] = performance;
	string_to_enum2["book"] = book;
	string_to_enum2["periodical"] = periodical;
	string_to_enum2["newspaper"] = newspaper;
	string_to_enum2["audio"] = audio;
	string_to_enum2["video"] = video;
	string_to_enum3["children"] = children;
	string_to_enum3["teen"] = teen;
	string_to_enum3["adult"] = adult;
	string_to_enum3["restricted"] = restricted;


	Publication pub{title,author,copyright,string_to_enum[genre],string_to_enum2[media],
	string_to_enum3[age],isbn};
	publications.push_back(pub);
	
}

string Library::publication_to_string(int publication_index){
	string s = publications[publication_index].to_string();
	return s;
} 

void Library::check_out(int publication_index, string patron_name, string patron_phone){
	publications[publication_index].check_out(patron_name,patron_phone);
}
void Library::check_in(int publication_index){
	publications[publication_index].check_in();
}

int Library::number_of_publications(){return publications.size();}





