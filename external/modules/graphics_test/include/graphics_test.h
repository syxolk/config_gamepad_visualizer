#ifndef GRAPHICS_TEST_H
#define GRAPHICS_TEST_H

#include "lms/module.h"
#include "lms/imaging/image.h"
#include "lms/imaging/format.h"

class GraphicsTest : public lms::Module {
public:
    bool initialize() override;
    bool deinitialize() override;
    bool cycle() override;
private:
    lms::imaging::Image *imagePtr;
    const lms::type::ModuleConfig *config;
};

#endif /* GRAPHICS_TEST_H */
