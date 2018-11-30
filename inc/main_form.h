#pragma once

#include <memory>

class Fl_Window;

class MainForm
{
public:
	MainForm();
	void init();
	void run();
	
private:
	std::shared_ptr<Fl_Window> _win;
};
