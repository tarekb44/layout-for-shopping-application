//
// Created by twak on 14/10/2019.
//

#include "responsive_window.h"
#include "responsive_layout.h"
#include "screenshot.h"
#include <iostream>
#include <QApplication>

ResponsiveWindow::ResponsiveWindow() {

    setWindowTitle("2811: Coursework 1");
    setMinimumSize(320, 320);

    createWidgets();

}

void ResponsiveWindow::createWidgets() {

    ResponsiveLayout * rl = new ResponsiveLayout();

    //add all widgets we need to demonstrate all layout
    //header widgets
    rl->addWidget(new ResponsiveLabel(kBackButton));
    rl->addWidget(new ResponsiveLabel(kHomeLink));

    //body widgets
    rl->addWidget(new ResponsiveLabel(kSearchOptions));
    rl->addWidget(new ResponsiveLabel(kAdvert));
    rl->addWidget(new ResponsiveLabel(kSignIn));
    rl->addWidget(new ResponsiveLabel(kShoppingBasket));
    rl->addWidget(new ResponsiveLabel(kFooter));
    rl->addWidget(new ResponsiveLabel(kSearchBackward));
    rl->addWidget(new ResponsiveLabel(kSearchForward));

    //Multiple Search Results
    rl->addWidget(new ResponsiveLabel(kSearchResult));
    rl->addWidget(new ResponsiveLabel(kSearchResult));
    rl->addWidget(new ResponsiveLabel(kSearchResult));
    rl->addWidget(new ResponsiveLabel(kSearchResult));

    rl->addWidget(new ResponsiveLabel(kNavTabs));
    rl->addWidget(new ResponsiveLabel(kSearchButton));
    rl->addWidget(new ResponsiveLabel(kSearchResult));
    rl->addWidget(new ResponsiveLabel(kSearchResult));
    rl->addWidget(new ResponsiveLabel(kSearchText));

    setLayout(rl);

}

int main(int argc, char *argv[]){

    //let's just check that Qt is operational first
    cout << "Qt version: " << QT_VERSION_STR << endl;

    // create the Qt Application
    QApplication app(argc,argv);

    // create a window. See respsonsive_window.cpp!
    if(argc-1) {
        // grading-mode - run the screenshot subclass
        Screenshot screenshot;
        screenshot.show();
        //wait for the app to terminate
        return app.exec();
    } else {
        // interactive mode -run the regular superclass
        ResponsiveWindow window;
        window.show();
        // wait for the app to terminate
        return app.exec();
    }
}

