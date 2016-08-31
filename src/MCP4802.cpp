/*
 * MCP4802.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: tarik
 */

#include "MCP4802.h"
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

namespace TestARM {

	short MCP4802::combineValues(unsigned char upper, unsigned char lower){
		return ((short)upper<<8)|(short)lower;
	}


	MCP4802::MCP4802(unsigned int busNumber, unsigned int device, unsigned int gpioNumber):
			SPIDevice(busNumber, device, gpioNumber) {
		this->setMode(SPIDevice::MODE0);
		this->setSpeed(4000000);
	}

	void MCP4802::setChipSelectForDAC(GPIO::VALUE value){

			setChipSelect(value);
		}

	/**
	 * output number 1 - DACb; 0 - DACa
	 */
	void MCP4802::sendDigitalValuesToDAC(int outputNumber, int outputValue){
		int dacConfigurationBits = 0b11111111;
		dacConfigurationBits |= outputNumber << 1; //On 2. MSB (14.bit) we choose on which output do we want the value

		int firstThreeBits = outputValue >> 5;
		int lastFiveBits = outputValue && 0b00011111;

		unsigned char send[2], receive[2];
		send[0] = dacConfigurationBits && firstThreeBits;
		send[1] = lastFiveBits & 0b11111111;

		this->transfer(send, receive, 2);
	}

	MCP4802::~MCP4802() {}

}




