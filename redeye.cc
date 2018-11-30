/// @author : hoppang@gmail.com

#include "inc/main_form.h"

int main(int argc, char** argv)
{
	auto mf = std::make_shared<MainForm>();
	mf->init();
	mf->run();
}
