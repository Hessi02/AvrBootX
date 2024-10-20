#include "com/uart/controller.hpp"

extern "C" __attribute__((section(".bootloader")))
int __entry(void)
{
    Com::Uart::Controller controller;

    // Insert sleep here

    int (*userMain)(void) = (int (*)(void))0x0000;
    return userMain(); 
}