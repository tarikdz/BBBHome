//============================================================================
// Name        : TestARM.cpp
// Author      : Tarik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "DS1307.h"
#include "MCP3208.h"
#include "SPIDevice.h"
#include"GPIO.h"
#include"SocketServer.h"
using namespace std;
using namespace TestARM;

int main(int argc,char* argv[]) {

	/*DS1307 RTC(1, 0x68);
	MCP3208 ADC(1, 0, 66);
	if(argc>1)
		RTC.setDate(atoi(argv[3]),atoi(argv[2]),atoi(argv[1]),atoi(argv[4]),atoi(argv[5]),atoi(argv[6]),atoi(argv[7]));

	while(1)
	{
		RTC.readFullDS1307();
		dateFormat cur_date = RTC.getDate();
		printf("%02d:%02d:%02d\n",cur_date.hour,cur_date.min,cur_date.sec);
		printf("%02d/%02d/%02d\n",cur_date.dayofmon,cur_date.mon,cur_date.year);
		printf ("--------------------------------------------------------------\n");

		ADC.setChipSelectForADC(GPIO::LOW);
		int* adcValues = ADC.getADCValues();
		for(int i=0; i<8; i++){
			cout<<"Channel number: "<<i<<" Value: "<<adcValues[i]<<endl;
		}


		sleep(1);

	}*/

	/*cout << "Starting EBB SPI ADC Example" << endl;

	SPIDevice *spiArduino = new SPIDevice(1,0); //Using first SPI bus
	spiArduino->setMode(SPIDevice::MODE0);
	spiArduino->setSpeed(500000);



    unsigned char send[2], receive[2];
    send[0] = 'A';
    send[1] = 'B';

    spiArduino->transfer(send, receive, 2);
    cout << "Response bytes are " << (int)receive[0] << "," << (int)receive[1] << endl;

    cout<<"End of BBB SPI Example"<<endl;*/

	cout << "Starting EBB Server Example" << endl;
	SocketServer server(54321);
	cout << "Listening for a connection..." << endl;
	server.threadedListen();
	cout << "End of EBB Server Example" << endl;

	return 0;
}
