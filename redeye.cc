/// @author : hoppang@gmail.com

#include "inc/main_form.h"
#include "inc/cbzfile.h"
#include "inc/magickwand_image.h"

#include <memory>

int main(int argc, char** argv)
{
	MagickWandGenesis();

	auto mf = new MainForm(300, 300, "Redeye");
	mf->init(argc, argv);
	if(argc == 2) {
		if(mf->load_cbz(argv[1]) == false) {
			printf("failed to load %s\n", argv[1]);
			return -1;
		}
		printf("bbb\n");
		mf->set_current_image();
	}
	else {
		printf("usage: %s [cbz_filename]\n", argv[0]);
		return 0;
	}

	return mf->run();
}
