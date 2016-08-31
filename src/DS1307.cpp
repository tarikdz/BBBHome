/*
 * DS1307.cpp
 *
 *  Created on: Aug 23, 2016
 *      Author: tarik
 */
#include "DS1307.h"
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace std;

namespace TestARM {

	char DS1307::convert_dec2hex(char dec_date)
	{
		char a=0;
		char result=0;
		a=dec_date;
		result=(dec_date/10)*16;
		result=a%10+result;
		return result;
	}

	char DS1307::convert_hex2dec(char hex_date)
	{
	    char hex=0;
	    char result=0;
	    hex=hex_date;
	    result=(hex_date/16)*10;
	    result=hex%16+result;
	    return result;
	}

	DS1307::DS1307(unsigned int I2CBus, unsigned int I2CAddress):
			I2CDevice(I2CBus, I2CAddress){
		this->I2CAddress = I2CAddress;
		this->I2CBus = I2CBus;
		this->registers = NULL;
	}



	void DS1307::readFullDS1307(void)
	{
		this->registers = this->readRegisters(BUFFER_SIZE, 0x00);
	}

	dateFormat DS1307::getDate()
	{
		dateFormat cur_date;


	    cur_date.sec=convert_hex2dec(registers[0]);
	    cur_date.min=convert_hex2dec(registers[1]);
	    cur_date.hour=convert_hex2dec(registers[2]);
	    cur_date.dayofweek=convert_hex2dec(registers[3]);
	    cur_date.dayofmon=convert_hex2dec(registers[4]);
	    cur_date.mon=convert_hex2dec(registers[5]);
	    cur_date.year=convert_hex2dec(registers[6]);

	    return cur_date;
	}

	void DS1307::setDate(char sec, char min, char hour, char dayofweek, char dayofmon, char mon, char year)
	{
	    char wr_buf[8];
	    wr_buf[0]=0;
	    wr_buf[1]=convert_dec2hex(sec);
	    wr_buf[2]=convert_dec2hex(min);
	    wr_buf[3]=convert_dec2hex(hour);
	    wr_buf[4]=convert_dec2hex(dayofweek);
	    wr_buf[5]=convert_dec2hex(dayofmon);
	    wr_buf[6]=convert_dec2hex(mon);
	    wr_buf[7]=convert_dec2hex(year);

	    this->writeByteArray(wr_buf, 8);
	}

	DS1307::~DS1307() {}

}






