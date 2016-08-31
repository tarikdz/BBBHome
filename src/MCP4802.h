/*
 * MCP4802.h
 *
 *  Created on: Aug 29, 2016
 *      Author: tarik
 */

#ifndef MCP4802_H_
#define MCP4802_H_
#include"SPIDevice.h"

namespace TestARM {


	/**
	 * Class that represents MCP4802 DAC used for sending analog values via SPI from BBB
	 */
	class MCP4802:protected SPIDevice {

	private:
		short combineValues(unsigned char upper, unsigned char lower);

	public:
		MCP4802(unsigned int busNumber, unsigned int device, unsigned int gpioNumber);
		virtual void setChipSelectForDAC(GPIO::VALUE value);
		virtual void sendDigitalValuesToDAC(int outputNumber, int outputValue);
		virtual ~MCP4802();
	};

}





#endif /* MCP4802_H_ */
