
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

	for(int i = 0; i < 7; i++){
		
		Gtk::MessageDialog *menu;
		
		if(i==0)
			menu = new Gtk::MessageDialog("<b>Enter Title</b>",true);
		if(i==1)
			menu = new Gtk::MessageDialog("<b>Enter Author</b>",true);
		if(i==2)
			menu = new Gtk::MessageDialog("<b>Enter Copyright year</b>",true);
		if(i==3)
			menu = new Gtk::MessageDialog("<b>Enter Genre</b>",true);
		if(i==4)
			menu = new Gtk::MessageDialog("<b>Enter Media</b>",true);
		if(i==5)
			menu = new Gtk::MessageDialog("<b>Enter Age</b>",true);
		if(i==6)
			menu = new Gtk::MessageDialog("<b>Enter ISBN</b>",true);

		menu->set_title("Add Publication");
		
		Gtk::Entry *entry = new Gtk::Entry{};
		entry->set_text("");
		entry->set_max_length(50);
		entry->show();
		menu->get_vbox()->pack_start(*entry);
			
		//buttons
		
		menu->set_default_response(1);
		
		//starts dialog msg
		menu->run(); 

		if(i==0)
			title = entry->get_text();
		if(i==1)
			author = entry->get_text();
		if(i==2)
			copyright = entry->get_text();
		if(i==3)
			genre = entry->get_text();
		if(i==4)
			media = entry->get_text();
		if(i==5)
			age = entry->get_text();
		if(i==6)
			isbn = entry->get_text();	
		
		menu->close();

		while(Gtk::Main::events_pending()) Gtk::Main::iteration();
		delete entry;
		delete menu;
	}
	
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





