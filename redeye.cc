/// @author : hoppang@gmail.com

#include "inc/main_form.h"
#include "inc/cbzfile.h"
#include "inc/magickwand_image.h"

#include <memory>
#include <wand/magick_wand.h>

int main(int argc, char** argv)
{
	MagickWandGenesis();

	auto mf = new MainForm;
	mf->init(argc, argv);

	std::shared_ptr<CBZFile> cbz;
	if(argc == 2) {
		cbz = std::make_shared<CBZFile>(argv[1]);
	}
	else {
		cbz = std::make_shared<CBZFile>("test1.cbz");
	}
	auto picdata = cbz->get_data(0);
	unsigned char *uc = &picdata[0];

	auto pic = std::make_shared<MagickWandImage>(picdata);
	pic->shrink(1920, 1080);
	mf->set_image_data(pic->get_blob(), pic->get_blob_size());

	// mf->set_image_data(uc);

	return mf->run();
}
