#include "com/uart/controller.hpp"

extern "C" __attribute__((noreturn))
int __entry(void)
{
    Com::Uart::Controller controller;

    // Insert sleep here

    void (*main)(void) = (void (*)(void))0x0000;
    main(); 
}