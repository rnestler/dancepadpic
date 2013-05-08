#ifndef MYSPI_H
#define MYSPI_H

#include <spi.h>
#include <stdint.h>

void spi_initialize();
uint16_t spi_readWord();

#endif // MYSPI_H
