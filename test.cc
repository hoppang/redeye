/// @author : hoppang@gmail.com

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.H>

void btn_cb(Fl_Widget* widget, void*)
{
	widget->label("HAHAHA");
	delete Fl::first_window();
}

int main(int argc, char** argv)
{
	auto win = new Fl_Window(300, 300);
//	win->fullscreen();
	win->begin();
	{
//		auto imgview = new Fl_Box(0, 0, 1920, 1080);
//		auto img = new Fl_JPEG_Image("tsugumi.jpg");
//		imgview->image(img);
//		imgview->redraw();

//		auto box = new Fl_Box(20, 40, 200, 100, "Hello, world!");
//		box->box(FL_UP_BOX);
//		box->labelsize(20);
//		box->labelfont(FL_BOLD);
//		box->labeltype(FL_SHADOW_LABEL);

		auto btn = new Fl_Button(240, 40, 200, 100, "Bye");
		btn->callback((Fl_Callback*) btn_cb);

	}
	win->end();
	win->show(argc, argv);

	return Fl::run();
}
