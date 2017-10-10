#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "library.h"
#include "publication.h"
#include <string>
#include <gtkmm.h>

class controller{
	public:
		void list_publications();
		void input_validation();
		void execute_cmd(int cmd);
		void show_help_menu();
	private:
		Library library;
};
#endif
