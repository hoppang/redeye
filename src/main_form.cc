#include "../inc/main_form.h"

#include <memory>

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Widget.H>

#include "../inc/magickwand_image.h"
#include "../inc/cbzfile.h"

MainForm::MainForm(int w, int h, const char *title)
: Fl_Window(w, h, title)
{
}

void MainForm::real_btn_cb(Fl_Widget* widget, void*)
{
	delete Fl::first_window();
}

void MainForm::init(int argc, char **argv)
{
	this->fullscreen();
	this->begin();
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
	this->end();
	this->show();
}

int MainForm::run()
{
	return Fl::run();
}

bool MainForm::load_cbz(char *filename)
{
	_cbz = std::make_shared<CBZFile>(filename);
	if(_cbz == nullptr)
		return false;
	else
		return true;
}

void MainForm::set_current_image()
{
	auto picdata = _cbz->get_current_data();
	unsigned char *uc = &picdata[0];

	auto pic = std::make_shared<MagickWandImage>(picdata);
	auto width = w();
	auto height = h();
	if(this->fullscreen_active()) {
		width = Fl::w();
		height = Fl::h();
	}
	pic->shrink(width, height);
	set_image_data(pic->get_blob(), pic->get_blob_size());
	_imgview->redraw();
}

void MainForm::set_image_data(uint8_t *data, size_t data_length)
{
	delete _imgview->image();
	auto fl_imag = new Fl_JPEG_Image("name", data);
	_imgview->image(fl_imag);
}

void fake_btn_cb(Fl_Widget *widget, void *data)
{
	auto obj = reinterpret_cast<MainForm*>(data);
	obj->real_btn_cb(widget, nullptr);
}

int MainForm::handle(int event)
{
	static int accu_dy = 0;
	switch(event) {
		case FL_MOUSEWHEEL:
		{
			auto dy = Fl::event_dy();
			accu_dy += dy;
			if(accu_dy > 1 || (accu_dy == 0 && dy > 0)) {
				accu_dy = 0;
				_cbz->go_next();
			}
			else if(accu_dy < -1 || (accu_dy == 0 && dy < 0)) {
				accu_dy = 0;
				_cbz->go_prev();
			}
			set_current_image();
		}
			break;
		default:
			return Fl_Window::handle(event);
	}
}
