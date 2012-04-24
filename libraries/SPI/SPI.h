/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED

#include "variant.h"
#include <stdio.h>

#define SPI_MODE0 0x00
#define SPI_MODE1 0x01
#define SPI_MODE2 0x02
#define SPI_MODE3 0x03

class SPIClass {
  public:
	SPIClass(Spi *_spi, uint32_t _id, void(*_initCb)(void), uint32_t *_ss);

	byte transfer(byte _data, uint8_t _channel = 0, bool _last = true);

	// SPI Configuration methods

	void attachInterrupt(void);
	void detachInterrupt(void);

	void begin(void);
	void addSlave(uint8_t _channel);
	void end(void);

	// These methods sets the same parameters on all channels
	void setBitOrder(uint8_t);
	void setDataMode(uint8_t);
	void setClockDivider(uint8_t);

	// These methods sets a parameter on a single channel
	void setBitOrder(uint8_t, uint8_t _channel);
	void setDataMode(uint8_t, uint8_t _channel);
	void setClockDivider(uint8_t, uint8_t _channel);

  private:
	Spi *spi;
	uint32_t id;
	uint32_t divider[SPI_CHANNELS_NUM];
	uint32_t mode[SPI_CHANNELS_NUM];
	uint32_t ssPins[SPI_CHANNELS_NUM];
	void (*initCb)(void);
};

#if SPI_INTERFACES_COUNT > 0
extern SPIClass SPI_0;
#endif

#endif
