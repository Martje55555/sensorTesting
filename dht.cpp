Jesus Martinez
#6490

Jesus Martinez
 — 
02/10/2022
Israel Hernandez
 — 
02/10/2022
Perros
Alonso Gonzalez Gonzalez
 — 
02/10/2022
make it general babe @Tyresse
Tyresse
 — 
02/10/2022
https://www.nationalgeographic.org/encyclopedia/irrigation/
National Geographic Society
irrigation
To irrigate is to water crops by bringing in water from pipes, canals, sprinklers, or other man-made means, rather than relying on rainfall alone.
Jesus Martinez
 — 
02/10/2022
https://www.instructables.com/Fast-and-Easy-PVC-Garden-Watering-System-for-under/
Instructables
Fast and Easy, PVC Garden Watering System (for Under $70)
Fast and Easy, PVC Garden Watering System (for Under $70): Gardening is one of my main summer activities and over the past several years, my garden (as they tend to do) has grown. With that growth, the amount of time and water my garden takes has also grown. For years, I've wanted a watering system that I c…
Alonso Gonzalez Gonzalez
 — 
02/10/2022
feature of irrigation system
Tyresse
 — 
02/10/2022
future
Alonso Gonzalez Gonzalez
 — 
02/10/2022
https://www.citationmachine.net/ieee
Citation Machine®: IEEE Format & IEEE Citation Generator
Generate IEEE citations in seconds. Start citing books, websites, journals, and more with the Citation Machine® IEEE Citation Generator.
Kristopher Klimmss
Alonso Gonzalez Gonzalez
 — 
02/10/2022
gay generation
gen z
pinche tyress
pinche tyresse
many the cat
Alonso Gonzalez Gonzalez
 — 
02/10/2022
tyresse Lopez IPadress
Jesus Martinez
 — 
02/11/2022
Alonso Gonzalez Gonzalez
 — 
02/11/2022
abu dhabi
Jesus Martinez
 — 
02/12/2022
R we still meeting today or nah
Alonso Gonzalez Gonzalez
 — 
02/12/2022
Mmm
Monday or what xd
Jesus Martinez
 — 
02/16/2022
http://www.keil.com/download/docs/84.asp
Jesus Martinez
 — 
02/16/2022
https://discord.com/channels/@me/808560756324171807/941582815013773352
Alonso Gonzalez Gonzalez
 — 
02/16/2022
https://discordapp.com/channels/@me/808560756324171807/941582815013773352
Alonso Gonzalez Gonzalez
 — 
02/18/2022
@Tyresse
Jesus Martinez
 — 
02/19/2022
I'm barely sleeping, 
Spam me if i don't wake up before the meeting lmao
Alonso Gonzalez Gonzalez
 — 
02/19/2022
Oki
Jesus Martinez
 — 
02/19/2022
Meow
Tyresse
 — 
02/19/2022
https://utrgv.zoom.us/j/8924514874
Zoom Video
Join our Cloud HD Video Meeting
Zoom is the leader in modern enterprise video communications, with an easy, reliable cloud platform for video and audio conferencing, chat, and webinars across mobile, desktop, and room systems. Zoom Rooms is the original software-based conference room solution used around the world in board, conference, huddle, and training rooms, as well as ex...
Alonso Gonzalez Gonzalez
 — 
02/19/2022
Bro
Let me in
Tyresse
 — 
02/19/2022
join
i just started it
Alonso Gonzalez Gonzalez
 — 
02/19/2022
It says please wair for the host to start this meeting
Tyresse
 — 
02/19/2022
try again
Alonso Gonzalez Gonzalez
 — 
02/19/2022
Ya estamos adentro
@Jesus Martinez @Israel Hernandez
Jesus Martinez
 — 
02/19/2022
Abraham goat
Tyresse
 — 
02/19/2022
khan
Israel Hernandez
 — 
02/19/2022
Image
console.log('verga')
Jesus Martinez
 — 
02/19/2022
lmao
easter egg
u found it
Alonso Gonzalez Gonzalez
 — 
Today at 2:07 PM
@everyone 3:30
Jesus Martinez
 — 
Today at 2:07 PM
👨‍🦯
Tyresse
 — 
Today at 2:14 PM
Image
Israel Hernandez
 — 
Today at 4:11 PM

//

//    FILE: dht22.cpp

// VERSION: 0.1.00

// PURPOSE: DHT22 Temperature & Humidity Sensor library for Arduino

//

// DATASHEET: 

//

// HISTORY:

// 0.1.0 by Rob Tillaart (01/04/2011)

// inspired by DHT11 library

//



#include "dht.h"



#define TIMEOUT 10000



/////////////////////////////////////////////////////

//

// PUBLIC

//





// return values:

//  0 : OK

// -1 : checksum error

// -2 : timeout

int dht::read11(uint8_t pin)

{

	// READ VALUES

	int rv = read(pin);

	if (rv != 0) return rv;



	// CONVERT AND STORE

	humidity    = bits[0];  // bit[1] == 0;

	temperature = bits[2];  // bits[3] == 0;



	// TEST CHECKSUM

	uint8_t sum = bits[0] + bits[2]; // bits[1] && bits[3] both 0

	if (bits[4] != sum) return -1;



	return 0;

}



// return values:

//  0 : OK

// -1 : checksum error

// -2 : timeout

int dht::read22(uint8_t pin)

{

	// READ VALUES

	int rv = read(pin);

	if (rv != 0) return rv;



	// CONVERT AND STORE

	humidity    = word(bits[0], bits[1]) * 0.1;



	int sign = 1;

	if (bits[2] & 0x80) // negative temperature

	{

		bits[2] = bits[2] & 0x7F;

		sign = -1;

	}

	temperature = sign * word(bits[2], bits[3]) * 0.1;





	// TEST CHECKSUM

	uint8_t sum = bits[0] + bits[1] + bits[2] + bits[3];

	if (bits[4] != sum) return -1;



	return 0;

}



/////////////////////////////////////////////////////

//

// PRIVATE

//



// return values:

//  0 : OK

// -2 : timeout

int dht::read(uint8_t pin)

{

	// INIT BUFFERVAR TO RECEIVE DATA

	uint8_t cnt = 7;

	uint8_t idx = 0;



	// EMPTY BUFFER

	for (int i=0; i< 5; i++) bits[i] = 0;



	// REQUEST SAMPLE

	pinMode(pin, OUTPUT);

	digitalWrite(pin, LOW);

	delay(20);

	digitalWrite(pin, HIGH);

	delayMicroseconds(40);

	pinMode(pin, INPUT);



	// GET ACKNOWLEDGE or TIMEOUT

	unsigned int loopCnt = TIMEOUT;

	while(digitalRead(pin) == LOW)

... (223 lines left)

Collapse
dht.cpp8 KB

// 
//    FILE: dht.h
// VERSION: 0.1.00
// PURPOSE: DHT Temperature & Humidity Sensor library for Arduino
//
//     URL: http://arduino.cc/playground/Main/DHTLib

Expand
dht.h3 KB
^Libraries

#include <dht.h>


#define dht_apin0 A0 // Analog Pin sensor is connected to
#define dht_apin1 A1 // Analog Pin sensor is connected to
 

Expand
DHT_test.ino4 KB
^arduino source code
﻿

//

//    FILE: dht22.cpp

// VERSION: 0.1.00

// PURPOSE: DHT22 Temperature & Humidity Sensor library for Arduino

//

// DATASHEET: 

//

// HISTORY:

// 0.1.0 by Rob Tillaart (01/04/2011)

// inspired by DHT11 library

//



#include "dht.h"



#define TIMEOUT 10000



/////////////////////////////////////////////////////

//

// PUBLIC

//





// return values:

//  0 : OK

// -1 : checksum error

// -2 : timeout

int dht::read11(uint8_t pin)

{

	// READ VALUES

	int rv = read(pin);

	if (rv != 0) return rv;



	// CONVERT AND STORE

	humidity    = bits[0];  // bit[1] == 0;

	temperature = bits[2];  // bits[3] == 0;



	// TEST CHECKSUM

	uint8_t sum = bits[0] + bits[2]; // bits[1] && bits[3] both 0

	if (bits[4] != sum) return -1;



	return 0;

}



// return values:

//  0 : OK

// -1 : checksum error

// -2 : timeout

int dht::read22(uint8_t pin)

{

	// READ VALUES

	int rv = read(pin);

	if (rv != 0) return rv;



	// CONVERT AND STORE

	humidity    = word(bits[0], bits[1]) * 0.1;



	int sign = 1;

	if (bits[2] & 0x80) // negative temperature

	{

		bits[2] = bits[2] & 0x7F;

		sign = -1;

	}

	temperature = sign * word(bits[2], bits[3]) * 0.1;





	// TEST CHECKSUM

	uint8_t sum = bits[0] + bits[1] + bits[2] + bits[3];

	if (bits[4] != sum) return -1;



	return 0;

}



/////////////////////////////////////////////////////

//

// PRIVATE

//



// return values:

//  0 : OK

// -2 : timeout

int dht::read(uint8_t pin)

{

	// INIT BUFFERVAR TO RECEIVE DATA

	uint8_t cnt = 7;

	uint8_t idx = 0;



	// EMPTY BUFFER

	for (int i=0; i< 5; i++) bits[i] = 0;



	// REQUEST SAMPLE

	pinMode(pin, OUTPUT);

	digitalWrite(pin, LOW);

	delay(20);

	digitalWrite(pin, HIGH);

	delayMicroseconds(40);

	pinMode(pin, INPUT);



	// GET ACKNOWLEDGE or TIMEOUT

	unsigned int loopCnt = TIMEOUT;

	while(digitalRead(pin) == LOW)

		if (loopCnt-- == 0) return -2;



	loopCnt = TIMEOUT;

	while(digitalRead(pin) == HIGH)

		if (loopCnt-- == 0) return -2;



	// READ THE OUTPUT - 40 BITS => 5 BYTES

	for (int i=0; i<40; i++)

	{

		loopCnt = TIMEOUT;

		while(digitalRead(pin) == LOW)

			if (loopCnt-- == 0) return -2;



		unsigned long t = micros();



		loopCnt = TIMEOUT;

		while(digitalRead(pin) == HIGH)

			if (loopCnt-- == 0) return -2;



		if ((micros() - t) > 40) bits[idx] |= (1 << cnt);

		if (cnt == 0)   // next byte?

		{

			cnt = 7;   

			idx++;      

		}

		else cnt--;

	}



	return 0;

}

//

// END OF FILE

//



























/*//

//    FILE: dht.cpp

//  AUTHOR: Rob Tillaart

// VERSION: 0.1.14

// PURPOSE: DHT Temperature & Humidity Sensor library for Arduino

//     URL: https://arduino.cc/playground/Main/DHTLib

//

// HISTORY:

// 0.1.14 replace digital read with faster (~3x) code => more robust low MHz machines.

// 0.1.13 fix negative temperature

// 0.1.12 support DHT33 and DHT44 initial version

// 0.1.11 renamed DHTLIB_TIMEOUT

// 0.1.10 optimized faster WAKEUP + TIMEOUT

// 0.1.09 optimize size: timeout check + use of mask

// 0.1.08 added formula for timeout based upon clockspeed

// 0.1.07 added support for DHT21

// 0.1.06 minimize footprint (2012-12-27)

// 0.1.05 fixed negative temperature bug (thanks to Roseman)

// 0.1.04 improved readability of code using DHTLIB_OK in code

// 0.1.03 added error values for temp and humidity when read failed

// 0.1.02 added error codes

// 0.1.01 added support for Arduino 1.0, fixed typos (31/12/2011)

// 0.1.00 by Rob Tillaart (01/04/2011)

//

// inspired by DHT11 library

//

// Released to the public domain

//



#include "dht.h"



/////////////////////////////////////////////////////

//

// PUBLIC

//



// return values:

// DHTLIB_OK

// DHTLIB_ERROR_CHECKSUM

// DHTLIB_ERROR_TIMEOUT

int dht::read11(uint8_t pin)

{

    // READ VALUES

    int rv = _readSensor(pin, DHTLIB_DHT11_WAKEUP);

    if (rv != DHTLIB_OK)

    {

        humidity = DHTLIB_INVALID_VALUE; // invalid value, or is NaN prefered?

        temperature = DHTLIB_INVALID_VALUE; // invalid value

        return rv;

    }



    // CONVERT AND STORE

    humidity = bits[0];  // bits[1] == 0;

    temperature = bits[2];  // bits[3] == 0;



    // TEST CHECKSUM

    // bits[1] && bits[3] both 0

    uint8_t sum = bits[0] + bits[2];

    if (bits[4] != sum) return DHTLIB_ERROR_CHECKSUM;



    return DHTLIB_OK;

}





// return values:

// DHTLIB_OK

// DHTLIB_ERROR_CHECKSUM

// DHTLIB_ERROR_TIMEOUT

int dht::read(uint8_t pin)

{

    // READ VALUES

    int rv = _readSensor(pin, DHTLIB_DHT_WAKEUP);

    if (rv != DHTLIB_OK)

    {

        humidity = DHTLIB_INVALID_VALUE;  // invalid value, or is NaN prefered?

        temperature = DHTLIB_INVALID_VALUE;  // invalid value

        return rv; // propagate error value

    }



    // CONVERT AND STORE

    humidity = word(bits[0], bits[1]) * 0.1;

    temperature = word(bits[2] & 0x7F, bits[3]) * 0.1;

    if (bits[2] & 0x80)  // negative temperature

    {

        temperature = -temperature;

    }



    // TEST CHECKSUM

    uint8_t sum = bits[0] + bits[1] + bits[2] + bits[3];

    if (bits[4] != sum)

    {

        return DHTLIB_ERROR_CHECKSUM;

    }

    return DHTLIB_OK;

}



/////////////////////////////////////////////////////

//

// PRIVATE

//



// return values:

// DHTLIB_OK

// DHTLIB_ERROR_TIMEOUT

int dht::_readSensor(uint8_t pin, uint8_t wakeupDelay)

{

    // INIT BUFFERVAR TO RECEIVE DATA

    uint8_t mask = 128;

    uint8_t idx = 0;



    // replace digitalRead() with Direct Port Reads.

    // reduces footprint ~100 bytes => portability issue?

    // direct port read is about 3x faster

    uint8_t bit = digitalPinToBitMask(pin);

    uint8_t port = digitalPinToPort(pin);

    volatile uint8_t* PIR = portInputRegister(port);



    // EMPTY BUFFER

    for (uint8_t i = 0; i < 5; i++) bits[i] = 0;



    // REQUEST SAMPLE

    pinMode(pin, OUTPUT);

    digitalWrite(pin, LOW); // T-be 

    delay(wakeupDelay);

    digitalWrite(pin, HIGH);   // T-go

    delayMicroseconds(40);

    pinMode(pin, INPUT);



    // GET ACKNOWLEDGE or TIMEOUT

    uint16_t loopCntLOW = DHTLIB_TIMEOUT;

    while ((*PIR & bit) == LOW)  // T-rel

    {

        if (--loopCntLOW == 0) return DHTLIB_ERROR_TIMEOUT;

    }



    uint16_t loopCntHIGH = DHTLIB_TIMEOUT;

    while ((*PIR & bit) != LOW)  // T-reh

    {

        if (--loopCntHIGH == 0) return DHTLIB_ERROR_TIMEOUT;

    }



    // READ THE OUTPUT - 40 BITS => 5 BYTES

    for (uint8_t i = 40; i != 0; i--)

    {

        loopCntLOW = DHTLIB_TIMEOUT;

        while ((*PIR & bit) == LOW)

        {

            if (--loopCntLOW == 0) return DHTLIB_ERROR_TIMEOUT;

        }



        uint32_t t = micros();



        loopCntHIGH = DHTLIB_TIMEOUT;

        while ((*PIR & bit) != LOW)

        {

            if (--loopCntHIGH == 0) return DHTLIB_ERROR_TIMEOUT;

        }



        if ((micros() - t) > 40)

        {

            bits[idx] |= mask;

        }

        mask >>= 1;

        if (mask == 0)   // next byte?

        {

            mask = 128;

            idx++;

        }

    }

    pinMode(pin, OUTPUT);

    digitalWrite(pin, HIGH);



    return DHTLIB_OK;

}

//

// END OF FILE

//*/