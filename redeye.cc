/// @author : hoppang@gmail.com

#include "inc/main_form.h"

int main(int argc, char** argv)
{
	auto mf = new MainForm;
	mf->init(argc, argv);

	return mf->run();
}
