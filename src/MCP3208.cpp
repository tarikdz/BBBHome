/*
 * MCP3208.cpp
 *
 *  Created on: Aug 26, 2016
 *      Author: tarik
 */

#include "MCP3208.h"
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

namespace TestARM {

	short MCP3208::combineValues(unsigned char upper, unsigned char lower){
		return ((short)upper<<8)|(short)lower;
	}


	MCP3208::MCP3208(unsigned int busNumber, unsigned int device, unsigned int gpioNumber):
			SPIDevice(busNumber, device, gpioNumber) {
		this->setMode(SPIDevice::MODE0);
		this->setSpeed(4000000);
	}

	void MCP3208::setChipSelectForADC(GPIO::VALUE value){

		setChipSelect(value);
	}

	int MCP3208::getADCValue(int channelNumber){

	    unsigned char send[3], receive[3];

	    send[0] = 0b00000111 & ((channelNumber >>2)&1); // 3. bit from end (1) is the Start Bit to inform the device that a sample is being requested
	    //2. bit from end(1) implies that mode is single, 0 for differential
	    //last bit(0) along with the 2 first bits of send[1] forms a channel number
	    send[1] = 0b00000000 & ((channelNumber >>0)&11); // The MSB is the Single/Diff bit and it is followed by 000 for CH0
	    send[2] = 0;          // This byte doesn't need to be set, just for a clear display
	    this->transfer(send, receive, 3);
	    cout << "Response bytes are " << (int)receive[1] << "," << (int)receive[2] << endl;

	    // Use the 8-bits of the second value and the two LSBs of the first value
	    int value = combineValues(receive[1]&0b00001111, receive[2]);

		return value;
	}

	int* MCP3208::getADCValues(){
		int* adcValues = new int[8];

		for(int i=0; i<8; i++){
			adcValues[i] = getADCValue(i);
		}

		return adcValues;
	}

	MCP3208::~MCP3208() {}

}




