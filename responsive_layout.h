//
// Created by twak on 07/10/2019.
//

#ifndef RESPONSIVELAYOUT_H
#define RESPONSIVELAYOUT_H

#include <QtGui>
#include <QList>
#include <QLayout>
#include "responsive_label.h"

class ResponsiveLayout : public QLayout
{
public:
    ResponsiveLayout(): QLayout() {}
    ~ResponsiveLayout();

    //setGeometry used to call functions for different resolution
    void setGeometry(const QRect &rect);

    //implemented two functions for medium/large size resolutions and it's results
    void mediumSize(ResponsiveLabel *label, const QRect &r);
    void mediumSizeResult(ResponsiveLabel *label, const QRect &r);

    //implemented two functions for wide size resolutions and it's results
    void wideSize(ResponsiveLabel *label, const QRect &r);
    void wideSizeResult(ResponsiveLabel *label, const QRect &r);

    //implemented two functions for small size resolutions and it's results
    void smallSize(ResponsiveLabel *label, const QRect &r);
    void smallSizeResult(ResponsiveLabel *label, const QRect &r);

    //function for search forward, search backwards, and footer
    void footer(ResponsiveLabel *label, const QRect &r);

    void addItem(QLayoutItem *item);
    QSize sizeHint() const;
    QSize minimumSize() const;
    int count() const;
    QLayoutItem *itemAt(int) const;
    QLayoutItem *takeAt(int);

private:
    QList<QLayoutItem*> list_;
};
#endif // RESPONSIVELAYOUT_H
