#include "interface.hpp"

#include <avr/io.h>

Com::Uart::Interface& Com::Uart::Interface::getInstance(void)
{
    static Interface instance;
    return instance;
}

unsigned char Com::Uart::Interface::receive(void) const
{
    while (!(UCSR1A & (1 << RXC)))
    {}

    return UDR1;
}

void Com::Uart::Interface::transmit(const unsigned char& byte) const
{
    while (!(UCSR1A & (1 << UDRE1)))
    {}

    UDR1 = byte;    
}

Com::Uart::Interface::Interface(void)
{
    constexpr unsigned long defaultBaudrate = 115200;
    initialize(defaultBaudrate);
}
    
void Com::Uart::Interface::initialize(const unsigned long& baudrate) const
{
    UCSR1B |= (1 << RXEN) | (1 << TXEN);
    UCSR1C |= (1  << UCSZ0) | (1 << UCSZ1);    

    const unsigned int baudPrescale = (F_CPU + baudrate * 8) / (baudrate * 16) - 1;
    UBRR1L = baudPrescale & 0xff;
    UBRR1H = (baudPrescale >> 8) & 0xff;
}