#include "graphics_test.h"
#include "lms/imaging/image.h"
#include "lms/imaging/format.h"
#include "lms/datamanager.h"
#include "lms/imaging/graphics.h"

bool GraphicsTest::initialize() {
    imagePtr = datamanager()
        ->writeChannel<lms::imaging::Image>(this, "IMAGE");

    config = getConfig();

    logger.debug() << getPriority();

    return true;
}

bool GraphicsTest::deinitialize() {
    return true;
}

bool GraphicsTest::cycle() {
    int width = config->get<int>("width");
    int height = config->get<int>("height");

    imagePtr->resize(width, height, lms::imaging::Format::BGRA);
    if(config->get<int>("draw") == 1) {
        imagePtr->fill(255);
    } else {
        imagePtr->fill(0);
    }

    logger.time("predraw");
    lms::imaging::BGRAImageGraphics g(*imagePtr);
    logger.timeEnd("predraw");


    logger.time("draw");
    g.setColor(lms::imaging::blue);

    static int linex = 0, linedelta = 1;

    if(config->get<int>("draw") == 1) {
        if(linex >= 100) {
            linedelta = -1;
        } else if(linex < 0) {
            linedelta = 1;
        }
        linex += linedelta;
        g.drawLine(200, 200, linex, (int)sqrt(100*100 - linex * linex));

        static int size = 100, delta = -1;
        if(size == 0) delta = 1;
        if(size == 200) delta = -1;
        size += delta;

        g.setColor(lms::imaging::red);
        g.drawRect(150, 150, 2*size, size);
        g.setColor(lms::imaging::yellow);
        g.drawRect(151, 151, 2*size-2, size-2);
    } else {
        if(linex >= 100) {
            linedelta = -1;
        } else if(linex < 0) {
            linedelta = 1;
        }
        linex += linedelta;
        g.drawLine(0, 0, linex, (int)sqrt(100*100 - linex * linex));

        static int size = 100, delta = -1;
        if(size == 0) delta = 1;
        if(size == 200) delta = -1;
        size += delta;

        g.setColor(lms::imaging::red);
        g.drawRect(50, 50, 2*size, size);
        g.setColor(lms::imaging::yellow);
        g.drawRect(51, 51, 2*size-2, size-2);
    }
    logger.timeEnd("draw");

    return true;
}
