#include <iostream>
#include "gui.hpp"

using std::cout; using std::endl; using std::string;

int main(int argc, char** argv)
{
	cout << "Hello blinstall!" << endl;
	QApplication app(argc, argv);
	QWidget window;
	initWindowSettings(window);
	QGridLayout* layout = initLayout(window);
	window.show();
	return app.exec();

	return 0;
}
