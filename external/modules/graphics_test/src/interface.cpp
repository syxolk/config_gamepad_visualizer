#include <graphics_test.h>

extern "C" {
void* getInstance () {
    return new GraphicsTest();
}
}
