#include "controller.hpp"

Com::Uart::Controller::Controller(void)
    : _interface(Com::Uart::Interface::getInstance())
{}