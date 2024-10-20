#ifndef __UART_CONTROLLER_HPP__
#define __UART_CONTROLLER_HPP__

#include "interface.hpp"

namespace Com::Uart
{

class Controller
{
public:
    Controller(void);

private:
    const Interface _interface;
};

}

#endif //__UART_CONTROLLER_HPP__