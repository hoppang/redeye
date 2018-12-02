#pragma once

#include <memory>

class Fl_Window;
class Fl_Widget;
class Fl_Box;

class MainForm
{
public:
	MainForm();
	void init(int argc, char **argv);
	int run();
	void set_image_data(unsigned char *data);

	void real_btn_cb(Fl_Widget* widget, void*);

private:
	Fl_Window *_win;
	Fl_Box *_imgview;
};

void fake_btn_cb(Fl_Widget *widget, void*);
