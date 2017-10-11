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
	
	//file dropdown menu
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File",true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);
	
	//append quit to the file menu
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit",true));
	menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
	filemenu->append(*menuitem_quit);

	//publication dropdown menu
	Gtk::MenuItem *menuitem_pub = Gtk::manage(new Gtk::MenuItem("_Publication",true));
	menubar->append(*menuitem_pub);
	Gtk::Menu *pub_menu = Gtk::manage(new Gtk::Menu());
	menuitem_pub->set_submenu(*pub_menu);
	
	//append list to publication menu
	Gtk::MenuItem *list = Gtk::manage(new Gtk::MenuItem("_List",true));
	list->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_list_click));
	pub_menu->append(*list);

	//append add to publication menu
	Gtk::MenuItem *add = Gtk::manage(new Gtk::MenuItem("_Add",true));
	add->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_click));
	pub_menu->append(*add);	

	//append checkout to publication menu
	Gtk::MenuItem *checkout = Gtk::manage(new Gtk::MenuItem("_Check Out",true));
	checkout->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_checkout_click));
	pub_menu->append(*checkout);

	//append check in to publication menu
	Gtk::MenuItem *checkin = Gtk::manage(new Gtk::MenuItem("_Check In",true));
	checkin->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_checkin_click));
	pub_menu->append(*checkin);

	//Help dropdown menu
	Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help",true));
	menubar->append(*menuitem_help);
	Gtk::Menu *help_menu = Gtk::manage(new Gtk::Menu());
	menuitem_help->set_submenu(*help_menu);

	//append about to help menu
	Gtk::MenuItem *about = Gtk::manage(new Gtk::MenuItem("_About",true));
	about->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_about_click));
	help_menu->append(*about);

	vbox->show_all();
	
}

void Main_window::on_about_click(){
	control.execute_cmd(9);
}
void Main_window::on_checkin_click(){
	control.execute_cmd(4);
}

void Main_window::on_checkout_click(){
	control.execute_cmd(3);
}
void Main_window::on_list_click(){
	control.execute_cmd(2);
}

void Main_window::on_add_click(){
	control.execute_cmd(1);
}

void Main_window::on_quit_click(){
	hide();
}
