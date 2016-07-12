#include <iostream>
#include <gtkmm.h>

#include "view/window/MainWindow.hpp"

int main(int argc, char *argv[])
{
    std::cout << "hej man" << "\n";

    auto app =
        Gtk::Application::create(argc, argv,
                                 "org.gtkmm.examples.base");


    protobuf_decoder::MainWindow window;

    // Shows the window and returns when it is closed.
    return app->run(window);
}

