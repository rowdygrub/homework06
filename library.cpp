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
	string title, author, copyright, genre, media, age, isbn;

	//title
	Gtk::Dialog *menu = new Gtk::Dialog();
	menu->set_title("Add Publication");

	Gtk::Label *label = new Gtk::Label("Enter Title");
	menu->get_content_area()->pack_start(*label);
	label->show();

	Gtk::Entry *entry = new Gtk::Entry{};
	entry->set_text("");
	entry->set_max_length(50);
	entry->show();
	menu->get_vbox()->pack_start(*entry);
			
	menu->add_button("OK",1);
	menu->set_default_response(1);

	menu->run(); 	
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
	label2->show();

	Gtk::Entry *entry2 = new Gtk::Entry{};
	entry2->set_text("");
	entry2->set_max_length(50);
	entry2->show();
	menu2->get_vbox()->pack_start(*entry2);
			
	menu2->add_button("OK",1);
	menu2->set_default_response(1);

	menu2->run(); 		
	author = entry2->get_text();
	menu2->close();

	while(Gtk::Main::events_pending()) Gtk::Main::iteration();
	delete entry2;
	delete label2;
	delete menu2;

	//copyright
	Gtk::Dialog *menu3 = new Gtk::Dialog();
	menu3->set_title("Add Publication");

	Gtk::Label *label3 = new Gtk::Label("Enter Copyright Year");
	menu3->get_content_area()->pack_start(*label3);
	label3->show();

	Gtk::Entry *entry3 = new Gtk::Entry{};
	entry3->set_text("");
	entry3->set_max_length(50);
	entry3->show();
	menu3->get_vbox()->pack_start(*entry3);
			
	menu3->add_button("OK",1);
	menu3->set_default_response(1);

	menu3->run(); 		
	copyright = entry3->get_text();
	menu3->close();

	while(Gtk::Main::events_pending()) Gtk::Main::iteration();
	delete entry3;
	delete label3;
	delete menu3;
	
	//genre
	Gtk::Dialog *menu4 = new Gtk::Dialog();
	menu4->set_title("Add Publication");

	Gtk::Label *label4 = new Gtk::Label("Enter Genre");
	menu4->get_content_area()->pack_start(*label4);
	label4->show();

	Gtk::Entry *entry4 = new Gtk::Entry{};
	entry4->set_text("");
	entry4->set_max_length(50);
	entry4->show();
	menu4->get_vbox()->pack_start(*entry4);
			
	menu4->add_button("OK",1);
	menu4->set_default_response(1);

	menu4->run(); 		
	genre = entry4->get_text();
	menu4->close();

	while(Gtk::Main::events_pending()) Gtk::Main::iteration();
	delete entry4;
	delete label4;
	delete menu4;
	
	//media
	Gtk::Dialog *menu5 = new Gtk::Dialog();
	menu5->set_title("Add Publication");

	Gtk::Label *label5 = new Gtk::Label("Enter Media");
	menu5->get_content_area()->pack_start(*label5);
	label5->show();

	Gtk::Entry *entry5 = new Gtk::Entry{};
	entry5->set_text("");
	entry5->set_max_length(50);
	entry5->show();
	menu5->get_vbox()->pack_start(*entry5);
			
	menu5->add_button("OK",1);
	menu5->set_default_response(1);

	menu5->run(); 		
	media = entry5->get_text();
	menu5->close();

	while(Gtk::Main::events_pending()) Gtk::Main::iteration();
	delete entry5;
	delete label5;
	delete menu5;
	
	//age
	Gtk::Dialog *menu6 = new Gtk::Dialog();
	menu6->set_title("Add Publication");

	Gtk::Label *label6 = new Gtk::Label("Enter Age");
	menu6->get_content_area()->pack_start(*label6);
	label6->show();

	Gtk::Entry *entry6 = new Gtk::Entry{};
	entry6->set_text("");
	entry6->set_max_length(50);
	entry6->show();
	menu6->get_vbox()->pack_start(*entry6);
			
	menu6->add_button("OK",1);
	menu6->set_default_response(1);

	menu6->run(); 		
	age = entry6->get_text();
	menu6->close();

	while(Gtk::Main::events_pending()) Gtk::Main::iteration();
	delete entry6;
	delete label6;
	delete menu6;
	
	//isbn
	Gtk::Dialog *menu7 = new Gtk::Dialog();
	menu7->set_title("Add Publication");

	Gtk::Label *label7 = new Gtk::Label("Enter ISBN");
	menu7->get_content_area()->pack_start(*label7);
	label7->show();

	Gtk::Entry *entry7 = new Gtk::Entry{};
	entry7->set_text("");
	entry7->set_max_length(50);
	entry7->show();
	menu7->get_vbox()->pack_start(*entry7);
			
	menu7->add_button("OK",1);
	menu7->set_default_response(1);

	menu7->run(); 	
	isbn = entry7->get_text();
	menu7->close();

	while(Gtk::Main::events_pending()) Gtk::Main::iteration();
	delete entry7;
	delete label7;
	delete menu7;
	
	
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





