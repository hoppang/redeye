#include "../inc/main_form.h"

#include <memory>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

MainForm::MainForm()
{

}

void MainForm::init()
{
	_win = std::make_shared<Fl_Window>(100, 100);
}

void MainForm::run()
{

}
