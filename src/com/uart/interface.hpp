#ifndef __UART_INTERFACE_HPP__
#define __UART_INTERFACE_HPP__

namespace Com::Uart
{

class Interface
{
public:
    static Interface& getInstance(void); 

    unsigned char receive(void) const;
    void transmit(const unsigned char&) const;

private:
    Interface(void);

    void initialize(const unsigned long& baudrate) const;
};

}

#endif //__UART_INTERFACE_HPP__