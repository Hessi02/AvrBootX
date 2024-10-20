#include "com/uart/controller.hpp"

extern "C" int __entry(void)
{
    Com::Uart::Controller controller;

    // Insert sleep here

    int (*main)(void) = (int (*)(void))0x0000;
    return main(); 
}