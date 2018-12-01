#pragma once

#include <memory>

class Fl_Window;
class Fl_Widget;

class MainForm
{
public:
	MainForm();
	void init(int argc, char **argv);
	int run();

	void real_btn_cb(Fl_Widget* widget, void*);

private:
	Fl_Window *_win;
};

void fake_btn_cb(Fl_Widget *widget, void*);
