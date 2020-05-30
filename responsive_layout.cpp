//
// Created by twak on 07/10/2019.
//

#include "responsive_layout.h"
#include "responsive_label.h"
#include <iostream>

using namespace std;

//function that calls the appropriate functions based on screen size
void ResponsiveLayout::setGeometry(const QRect &r /* our layout should always fit inside r */ ) {

    QLayout::setGeometry(r);

    int count = 0;

    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) // null: cast failed on pointer
                cout << "warning, unknown widget class in layout" << endl;

            else if (r.width() > 699.999 && r.height() > 376.001){
                mediumSize(label, r);
                mediumSizeResult(label, r);
                footer(label,r);

            } else if (r.width() > 811 && r.height() > 299 && r.height() < 376) {
                wideSize(label, r);
                wideSizeResult(label, r);


            } else if (r.width() < 698 && r.height() < 1051) {
                smallSize(label, r);
                smallSizeResult(label,r);

            } else // otherwise: disappear label by moving out of bounds
                label->setGeometry(-1, -1, 0, 0);

        }

        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }

    }
}

//function for a wide size resolution
void ResponsiveLayout::wideSize(ResponsiveLabel *label, const QRect &r){

    int count = 0;

    //loops through widgets to call a widget
    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) // null: cast failed on pointer
                cout << "warning, unknown widget class in layout" << endl;

            else if (label->text() == kBackButton)
                label->setGeometry((r.left()), 0, 60, 60);

            else if (label->text() == kHomeLink)
                label->setGeometry((r.left() + 60), 0, 60, 60);

            else if (label->text() == kSignIn)
                label->setGeometry(r.right() - 120, 0, 60, 60);

            else if (label->text() == kShoppingBasket)
                label->setGeometry(r.right() - 60, 0, 60, 60);

            else if (label->text() == kNavTabs)
                label->setGeometry(r.x() + 0, 60, r.width(), 30);

            else if (label->text() == kSearchOptions )
                label->setGeometry(r.x() + 0, r.height() / 2.88, r.width() / 5, r.height() / 1.89);

            //only show when resolution gets big (replace search button)
            else if(label->text() == kSearchText && r.width() > 570)
                label->setGeometry(r.left() + 120, 0, r.width() / 2.59, 60);

            else if (label->text() == kSearchButton && r.width() < 569 && r.height() < 1049)
                label->setGeometry(r.left() + 120, 0, r.width() / 4, 60);

        }

        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }
    }
}

//function to implement search results for wide size resolutions
void ResponsiveLayout::wideSizeResult(ResponsiveLabel *label, const QRect &r) {

    int count = 0;

    // for all the Widgets added in ResponsiveWindow.cpp
    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {

            //creates multiple search results with screen width greater than 299 and less than 569 pixals
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());
            if (label->text() == kSearchResult && count == 0) {
                label->setGeometry(r.width() / 4.516, r.height() / 2.88, r.width() / 4.329, r.height() / 1.667);
                count++;

                } else if (label->text() == kSearchResult && count == 1) {
                    label->setGeometry(r.width() / 2.083, r.height() / 2.88, r.width() / 4.329, r.height() / 1.667);
                    count++;

                    } else if (label->text() == kSearchResult && count == 2) {
                        label->setGeometry(r.width() / 1.353, r.height() / 2.88, r.width() / 4.329, r.height() / 1.667);
                        count++;
            }

        }

        catch (bad_cast) {
                    // bad_case: cast failed on reference...
                    cout << "warning, unknown widget class in layout" << endl;
        }
    }
}

//function for a bigger screen
void ResponsiveLayout::mediumSize(ResponsiveLabel *label, const QRect &r) {

    int count = 0;
    // for all the Widgets added in ResponsiveWindow.cpp
    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) // null: cast failed on pointer
                cout << "warning, unknown widget class in layout" << endl;

            //header widgets
            else if (label->text() == kBackButton)
                label->setGeometry((r.left()), 0, 60, 60);

            else if (label->text() == kHomeLink)
                label->setGeometry((r.left() + 60), 0, 60, 60);

            else if(label->text() == kSearchText && r.width() > 570)
                label->setGeometry(r.left() + 120, 0, r.width() / 2.59, 60);

            else if (label->text() == kSignIn)
                label->setGeometry(r.right() - 120, 0, 60, 60);

            else if (label->text() == kShoppingBasket)
                label->setGeometry(r.right() - 60, 0, 60, 60);

                //Navigation tab Geometry
            else if (label->text() == kNavTabs)
                label->setGeometry(r.x() + 0, 60, r.width(), 30);

            else if (label->text() == kAdvert)
                label->setGeometry(r.left() + 0, r.height() / 1.3953, r.width() / 5, r.height() / 7.1664);

            else if (label->text() == kSearchOptions )
                label->setGeometry(r.x() + 0, r.height() / 6.05, r.width() / 5, r.height() / 1.89);

            else if (label->text() == kSearchButton && r.width() > 320 && r.width() < 567 && r.height() < 1049)
                label->setGeometry(r.left() + 120, 0, r.width() / 4, 60);


        }

        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }
    }
}

//function that implements search results for medium to large screen sizes
void ResponsiveLayout::mediumSizeResult(ResponsiveLabel *label, const QRect &r) {

    int count = 0;
    // for all the Widgets added in ResponsiveWindow.cpp
    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {

            //creates multiple search results with screen width greater than 299 and less than 569 pixals
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label->text() == kSearchResult && count == 0) {
                label->setGeometry(r.width() / 4.516, r.height() / 6.05, r.width() / 4.329, r.height() / 3.79);
                count++;

            } else if (label->text() == kSearchResult && count == 1) {
                label->setGeometry(r.width() / 2.083, r.height() / 6.05, r.width() / 4.329, r.height() / 3.79);
                count++;

                } else if (label->text() == kSearchResult && count == 2) {
                label->setGeometry(r.width() / 1.353, r.height() / 6.05, r.width() / 4.329, r.height() / 3.79);
                count++;

                    } else if (label->text() == kSearchResult && count == 3) {
                            label->setGeometry(r.width() / 4.516, r.height() / 2.2211, r.width() /4.329, r.height() / 3.79);
                            count++;

                        }
        }

        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }
    }
}

//function for a small size screen
void ResponsiveLayout::smallSize(ResponsiveLabel *label, const QRect &r) {

    int count = 0;

    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());
            if (label == NULL) // null: cast failed on pointer
                cout << "warning, unknown widget class in layout" << endl;

            else if (label->text() == kBackButton)
                label->setGeometry((r.left()), 0, 60, 60);

            else if (label->text() == kHomeLink)
                label->setGeometry((r.left() + 60), 0, 60, 60);

            else if (label->text() == kSignIn)
                label->setGeometry(r.right() - 120, 0, 60, 60);

            else if (label->text() == kShoppingBasket)
                label->setGeometry(r.right() - 60, 0, 60, 60);

            else if (label->text() == kNavTabs)
                label->setGeometry(r.x() + 0, 60, r.width(), 30);

            else if (label->text() == kSearchBackward && r.height() > 800)
                label->setGeometry(r.width() / 2.745, r.height() / 1.1111, 30, 30);

            else if (label->text() == kSearchForward && r.height() > 800)
                label->setGeometry(r.width() / 1.739, r.height() / 1.1111, 30, 30);

            else // otherwise: disappear label by moving out of bounds
                label->setGeometry(-1, -1, 0, 0);
        }

        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }
    }
}

//function to implement results for small size screen
void ResponsiveLayout::smallSizeResult(ResponsiveLabel *label, const QRect &r) {

    int count = 0;

    // for all the Widgets added in ResponsiveWindow.cpp
    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {

            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            //uses count to call search at different positions based on the foor loop
            if (label->text() == kSearchResult && count == 0 && r.height() < 566) {
                label->setGeometry(r.width() / 20, r.height() / 3.04, r.width() / 2.35, r.height() / 1.66);
                count++;
            }  else if (label->text() == kSearchResult && count == 1 && r.height() < 566) {
                label->setGeometry(r.width() / 1.902, r.height() / 3.04, r.width() / 2.35, r.height() / 1.66);
                count++;

            } else if (label->text() == kSearchResult && count == 0 && r.height() > 567) {
                label->setGeometry(r.width() / 21.33, r.height() / 5.409, r.width() / 2.375, r.height() / 4.20);
                count++;

            } else if (label->text() == kSearchResult && count == 1 && r.height() > 567 ) {
                label->setGeometry(r.width() /1.93, r.height() / 5.406, r.width() /2.375, r.height() / 4.20);
                count++;

            } else if (label->text() == kSearchResult && count == 2 && r.height() > 567) {
                label->setGeometry(r.width() / 21.33, r.height() / 2.227, r.width() / 2.375, r.height() / 4.20);
                count++;

            } else if (label->text() == kSearchResult && count == 3 && r.height() > 567) {
                label->setGeometry(r.width() / 1.93, r.height() / 2.227, r.width() / 2.375, r.height() / 4.20);
                count++;

            } else if(label->text() == kSearchText && r.width() > 570)
                label->setGeometry(r.left() + 120, 0, r.width() / 2.59, 60);

            //only appear for small resolution
            else if (label->text() == kSearchButton && r.width() < 569)
                label->setGeometry(r.left() + 120, 0, r.width() / 4, 60);

            else if (label->text() == kFooter && r.height() > 800)
                label->setGeometry(r.x(),r.height() - r.height() / 21, r.width(), 45);

        }

        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }
    }
}

//function to implement footer, forward and back buttons for medium to large screen sizes
void ResponsiveLayout::footer(ResponsiveLabel *label, const QRect &r) {

    int count = 0;
    // for all the Widgets added in ResponsiveWindow.cpp
    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {

            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            //only appears when the height of the screen is greater than 720
            if (label->text() == kSearchForward && r.height() > 800)
                label->setGeometry(r.width() / 1.739, r.height() / 1.111, 30, 30);

            else if (label->text() == kFooter && r.height() > 800)
                label->setGeometry(r.x(), r.height() - r.height() / 20, r.width(), 60);

            else if (label->text() == kSearchBackward && r.height() > 800)
                label->setGeometry(r.width() / 2.745, r.height() / 1.111, 30, 30);
        }

        catch (bad_cast) {
            // bad_case: cast failed on reference...
            cout << "warning, unknown widget class in layout" << endl;
        }
    }
}


// following methods provide a trivial list-based implementation of the QLayout class
int ResponsiveLayout::count() const {
    return list_.size();
}

QLayoutItem *ResponsiveLayout::itemAt(int idx) const {
    return list_.value(idx);
}

QLayoutItem *ResponsiveLayout::takeAt(int idx) {
    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;
}

void ResponsiveLayout::addItem(QLayoutItem *item) {
    list_.append(item);
}

QSize ResponsiveLayout::sizeHint() const {
    return minimumSize();
}

QSize ResponsiveLayout::minimumSize() const {
    return QSize(320,320);
}

ResponsiveLayout::~ResponsiveLayout() {
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}
