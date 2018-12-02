/// @author : hoppang@gmail.com

#include "inc/main_form.h"
#include "inc/cbzfile.h"

int main(int argc, char** argv)
{
	auto mf = new MainForm;
	mf->init(argc, argv);

	auto cbz = new CBZFile("test1.cbz");
	auto data = cbz->get_data(0);
	unsigned char *uc = &data[0];
	mf->set_image_data(uc);

	return mf->run();
}
