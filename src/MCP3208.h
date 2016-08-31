/*
 * MCP3208.h
 *
 *  Created on: Aug 26, 2016
 *      Author: tarik
 */

#ifndef MCP3208_H_
#define MCP3208_H_
#include"SPIDevice.h"

namespace TestARM {


	/**
	 * Class that represents MCP3208 ADC used for getting analog values(temperatures) via SPI to the BBB
	 */
	class MCP3208:protected SPIDevice {

	private:
		short combineValues(unsigned char upper, unsigned char lower);

	public:
		MCP3208(unsigned int busNumber, unsigned int device, unsigned int gpioNumber);
		virtual void setChipSelectForADC(GPIO::VALUE value);
		virtual int getADCValue(int channelNumber);
		virtual int* getADCValues();
		virtual ~MCP3208();
	};

}






#endif /* MCP3208_H_ */
