#include "main_window.h"
#include <gtkmm.h>
Main_window::~Main_window(){}
Main_window::Main_window(){
	set_default_size(400,200);
	
	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0));
	add(*vbox);
	
	//menu bar at the top
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menubar,Gtk::PACK_SHRINK,0);
	
	//file menu
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File",true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);
	
	//append quit to the file menu
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit",true));
	menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
	filemenu->append(*menuitem_quit);

	vbox->show_all();
	
}

void Main_window::on_quit_click(){
	hide();
}
