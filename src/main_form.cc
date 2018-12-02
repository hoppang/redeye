#include "../inc/main_form.h"

#include <memory>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Widget.H>

MainForm::MainForm()
{

}

void MainForm::real_btn_cb(Fl_Widget* widget, void*)
{
	printf("HAHA\n");
	delete Fl::first_window();
}

void MainForm::init(int argc, char **argv)
{
	_win = new Fl_Window(500, 500);
	_win->fullscreen();
	_win->begin();
	{
		auto width = Fl::w();
		auto height = Fl::h();
		_imgview = new Fl_Box(0, 0, width, height);
		auto img = new Fl_JPEG_Image("test1.jpg");
		_imgview->image(img);
		_imgview->redraw();

		auto box = new Fl_Box(20, 40, 200, 100, "Hello, world!");
		box->box(FL_UP_BOX);
		box->labelsize(20);
		box->labelfont(FL_BOLD);
		box->labeltype(FL_SHADOW_LABEL);

		auto btn = new Fl_Button(240, 40, 200, 100, "Byeeee");
		btn->callback((Fl_Callback*)fake_btn_cb, (void*)this);
	}
	_win->end();
	_win->show(argc, argv);
}

int MainForm::run()
{
	return Fl::run();
}

void MainForm::set_image_data(unsigned char *data)
{
	auto img = new Fl_JPEG_Image("name", data);
	_imgview->image(img);
}

void fake_btn_cb(Fl_Widget *widget, void *data)
{
	auto obj = reinterpret_cast<MainForm*>(data);
	obj->real_btn_cb(widget, nullptr);
}
