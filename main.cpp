#include "library.h"
#include "publication.h"
#include <string>
#include <gtkmm.h>
using namespace std;

class Main{
	public:
		int show_menu(){
			Gtk::MessageDialog *menu = new Gtk::MessageDialog("<b><big>C1325\nLibrary Management System<sup>TM</sup></big></b>",true);
			menu->set_title("Main Menu"); 

			string list =
			"\n<b><u>Publications</u></b>\n(1) Add publications\n(2) List all publications\n(3) Check out publication\n(4) Check in publication\n\n<b><u>Utility</u></b>\n<span fgcolor='#00ff00'>(9) Help</span>\n(0) Exit\n";
			menu->set_secondary_text(list,true);
			//Gtk::Label *label = new Gtk::Label(list);
			//menu->get_content_area()->pack_start(*label);
			//label->show();//shows the menu
			
			Gtk::Entry *entry = new Gtk::Entry{};
			entry->set_text("");
			entry->set_max_length(50);
			entry->show();
			menu->get_vbox()->pack_start(*entry);
			
			menu->add_button("Cancel",0);
			//menu->add_button("OK",1);
			//menu->set_default_response(1);
			
			menu->run(); //this makes dialog pop up
			
			string text = entry->get_text();
			int _text = stoi(text.c_str());
			
			menu->close();
			
			while(Gtk::Main::events_pending()) Gtk::Main::iteration();
			delete entry;
			//delete label;
			delete menu;
			
			return _text;
		}	

		void list_publications(){
			Gtk::Dialog *menu = new Gtk::Dialog();
			menu->set_title("Publications"); 

			string list = "Publication List\n=============\n";
			for(int i = 0; i < library.number_of_publications();i++)
				list = list + to_string(i) + ": " + library.publication_to_string(i) + "\n";
			
			Gtk::Label *label = new Gtk::Label(list);
			menu->get_content_area()->pack_start(*label);
			label->show();
			
			menu->add_button("OK",1);
			menu->set_default_response(1);
			
			menu->run();
			menu->close();
			
			while(Gtk::Main::events_pending()) Gtk::Main::iteration();
			delete label;
			delete menu;
		}

		void input_validation(){
			Gtk::Dialog *menu = new Gtk::Dialog();
			menu->set_title("Check Out/In Publication");
			Gtk::Label *label = new Gtk::Label("Error: No publications!");
			menu->get_content_area()->pack_start(*label);
			label->show();
			menu->add_button("OK",1);
			menu->set_default_response(1);
			menu->run(); 
			menu->close();

			while(Gtk::Main::events_pending()) Gtk::Main::iteration();
			delete label;
			delete menu;
		}

		void execute_cmd(int cmd){
			if(cmd == 0)
				exit(0);
			if(cmd == 1)
				library.add_publication();	
			if(cmd == 3){
				if(library.number_of_publications() == 0){
					input_validation();
					return;
				}

				string n, name,phone;
								 
				for(int i = 0;i<3;i++){
					Gtk::Dialog *menu = new Gtk::Dialog();
					menu->set_title("Check Out Publication");
					Gtk::Label *label;
					
					if(i==0)
						label = new Gtk::Label("Enter Publication # to check out");
					if(i==1)
						label = new Gtk::Label("Enter Name");
					if(i==2)
						label = new Gtk::Label("Enter Phone Number");
					
					menu->get_content_area()->pack_start(*label);
					label->show();

					Gtk::Entry *entry = new Gtk::Entry{};
					entry->set_text("");
					entry->set_max_length(50);
					entry->show();
					menu->get_vbox()->pack_start(*entry);
			
					//buttons
					menu->add_button("OK",1);
					menu->set_default_response(1);
		
					//starts dialog msg
					menu->run(); 
					
					if(i==0)
						n = entry->get_text();
					if(i==1)
						name = entry->get_text();
					if(i==2)
						phone = entry->get_text();
						
					menu->close();

					while(Gtk::Main::events_pending()) Gtk::Main::iteration();
					delete entry;
					delete label;
					delete menu;
				}
				int _n = stoi(n.c_str());
		
				library.check_out(_n,name,phone);
			}
			
			if(cmd == 2)
				list_publications();
			if(cmd == 4){
				if(library.number_of_publications() == 0){
					input_validation();
					return;
				}
				string n;
				int _n;
				Gtk::Dialog *menu = new Gtk::Dialog();
				menu->set_title("Check in Publication");
				Gtk::Label *label = new Gtk::Label("Enter index to check in");
				menu->get_content_area()->pack_start(*label);
				label->show();

				Gtk::Entry *entry = new Gtk::Entry{};
				entry->set_text("");
				entry->set_max_length(50);
				entry->show();
				menu->get_vbox()->pack_start(*entry);
			
				//buttons
				menu->add_button("OK",1);
				menu->set_default_response(1);
		
				//starts dialog msg
				menu->run(); 
				n = entry->get_text();
				menu->close();

				while(Gtk::Main::events_pending()) Gtk::Main::iteration();
				delete entry;
				delete label;
				delete menu;
				
				_n = stoi(n.c_str());
				library.check_in(_n);
			}
			if(cmd == 9)
				show_help_menu();
		}
		
		void show_help_menu(){
			string list = "<b>Command 1:</b> Add Publications\nOptions for Genre: fiction, nonfiction, selfhelp, performance\nOptions for Media: book, periodical, newspaper, audio, video\nOptions for Age: children, teen, adult, restricted\n\n<b>Command 2:</b> List all publications including patron and patron number for checkout publications\n\n<b>Command 3:</b> Checkout publication\nEnter publication index, then patron, and number\n\n<b>Command 4:</b> Check in publication\nEnter publication index to check in publication\n";
			Gtk::MessageDialog *help_menu = new Gtk::MessageDialog(list,true);
			help_menu->set_title("Help Menu");
				
			help_menu->set_default_response(1);
			
			help_menu->run(); //this makes dialog pop up
			help_menu->close();
			
			while(Gtk::Main::events_pending()) Gtk::Main::iteration();
			
			delete help_menu;
		}
	private:
		Library library;
};

int main(int argc, char *argv[]) {
	Gtk::Main kit(argc, argv); //initialize gtkmm

	Main h;
	int cmd = -1;
	
	
	while(cmd){
		cmd = h.show_menu();
		h.execute_cmd(cmd);
	}
		
}







