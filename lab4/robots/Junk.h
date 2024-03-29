/**
 * Copyright (C) David Wolfe, 1999.  All rights reserved.
 * Ported to Qt and adapted for TDDD86, 2015.
 */

#ifndef JUNK_H
#define JUNK_H

#include "Robot.h"
#include <QGraphicsScene>

class Junk : public Robot {
public:

    Junk(const Point& p): Robot(p){}

    /*
    * Draws this junk onto the given QGraphicsScene.
    */
    void draw(QGraphicsScene* scene) const override;


    void moveTowards(const Unit&) override;
    void doCrash() override;
    bool justCrashed() const override;
    bool canMove() const override;
    Robot* clone() const override;

};

#endif // JUNK_H
