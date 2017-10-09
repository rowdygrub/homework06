#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "library.h"
#include "publication.h"
#include <string>
#include <gtkmm.h>
using namespace std;
//for the callbacks, whatever dropdown is selected pass the number corresponding to the exe cmd method i.e. on_add_publication_click() pass 1
class Main_window : public Gtk::Window{
	public:
		Main_window();
		virtual ~Main_window();
	protected:
		void on_new_click();
		void on_quit_click();
		void
