#include "library.h"
#include "publication.h"
#include <iostream>
#include <string>
#include <gtkmm.h>
using namespace std;

class Main{
	public:
		void show_menu(){
			Gtk::Dialog *menu = new Gtk::Dialog();
			menu->set_title("Main Menu"); 

			string list =
			"===============================\nC1325 Library Management System\n===============================\n\nPublications\n------------\n(1) Add publications\n(2) List all publications\n(3) Check out publication\n(4) Check in publication\n\nUtility\n-------\n(9) Help\n(0) Exit\n";
			
			Gtk::Label *label = new Gtk::Label(list);
			menu->get_content_area()->pack_start(*label);
			label->show();//shows the menu
			
			Gtk::Entry *entry = new Gtk::Entry{};
			entry->set_text("");
			entry->set_max_length(50);
			entry->show();
			menu->get_vbox()->pack_start(*entry);
			
			menu->add_button("Cancel",0);
			menu->add_button("OK",1);
			menu->set_default_response(1);
			
			menu->run(); //this makes dialog pop up
			string text = entry->get_text();
		
			menu->close();
			
			while(Gtk::Main::events_pending()) Gtk::Main::iteration();
			delete entry;
			delete label;
			delete menu;
		}	

		void list_publications(){
			for(int i = 0; i < library.number_of_publications();i++)
				cout << i << ": " << library.publication_to_string(i) << endl;
		}

		void execute_cmd(int cmd){
			int n;
			if(cmd == 0)
				exit(0);
			if(cmd == 1)
				library.add_publication();	
			if(cmd == 3){
				string name,phone;
				cout << "Enter Publication # to check out:";
				cin >> n;
				cout << "Enter name:";
				cin.ignore();
				getline(cin,name);
				cout << "Enter Phone Number:";
				cin >> phone;
				library.check_out(n,name,phone);
			}
			if(cmd == 2)
				list_publications();
			if(cmd == 4){
				cout << "Enter index to check in:";
				cin >> n;
				library.check_in(n);
			}
			if(cmd == 9)
				show_help_menu();
			
		}
		void show_help_menu(){
			cout << "Command 1: Add Publications\n";
			cout << "Options for Genre: fiction, nonfiction, selfhelp, performance" << endl;
			cout << "Options for Media: book, periodical, newspaper, audio, video" <<endl;
			cout << "Options for Age: children, teen, adult, restricted" << endl;
			cout << "Command 2: List all publications including patron and patron number for checkout publications" << endl;
			cout << "Command 3: Checkout publication" << endl;
			cout << "Enter publication index, then patron, and number" << endl;
			cout << "Command 4: Check in publication" << endl;
			cout << "Enter publication index to check in publication" << endl << endl;
		}
	private:
		Library library;
};

int main(int argc, char *argv[]) {
	Gtk::Main kit(argc, argv); //initialize gtkmm

	Main h;
	h.show_menu();
	int cmd;

	
	/*while(true){
		cin >> cmd;
		h.execute_cmd(cmd);
		h.show_menu();
	}*/
		
}






