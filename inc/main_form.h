#pragma once

#include <memory>
#include <FL/Fl_Window.H>

class Fl_Window;
class Fl_Widget;
class Fl_Box;
class CBZFile;

class MainForm : public Fl_Window
{
public:
	explicit MainForm(int w, int h, const char *title);
	void init(int argc, char **argv);
	int run();
	void set_image_data(uint8_t *data, size_t data_length);
	void set_current_image();
	
	bool load_cbz(char *filename);
	void real_btn_cb(Fl_Widget* widget, void*);
	int handle(int event);

private:
	Fl_Box *_imgview;
	std::shared_ptr<CBZFile> _cbz;
};

void fake_btn_cb(Fl_Widget *widget, void*);
