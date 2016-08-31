/*
 * DS1307.h
 *
 *  Created on: Aug 23, 2016
 *      Author: tarik
 */

#ifndef DS1307_H_
#define DS1307_H_
#include"I2CDevice.h"

#define BUFFER_SIZE 0x40 // Real-time clock has 64 registers, first 8 are used to get time and date
#define bus 1
#define adress 0x68

namespace TestARM {

	typedef struct
	{
		char sec;
		char min;
		char hour;
		char dayofweek;
		char dayofmon;
		char mon;
		char year;
	}dateFormat;

	class DS1307:protected I2CDevice {

	private:
		unsigned int I2CBus, I2CAddress;
		unsigned char *registers;

	    char convert_hex2dec(char hex_date);
	    char convert_dec2hex(char dec_date);

	public:
	    DS1307(unsigned int I2CBus = bus, unsigned int I2CAddress = adress);
	    virtual void readFullDS1307(void);
	    virtual dateFormat getDate();
	    virtual void setDate(char sec,char min,char hour,char dayofweek,char dayofmon,char mon,char year);
	    virtual ~DS1307();
	};

}


#endif /* DS1307_H_ */
