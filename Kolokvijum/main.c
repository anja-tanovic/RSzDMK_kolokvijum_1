/**
 * @file main.c
 * @brief Zadatak
 * @author Anja Tanovic
 * @date 16-05-2021
 * @version 1.0
 */

#include <stdlib.h>
#include <stdint.h>
#include <avr/pgmspace.h>
#include "../usart/usart.h"
#include "../pin_driver/pin.h"
#include "../timer0/timer0.h"
#include "util.h"

/**
 * main - Funkcija koja implementira glavni deo programa
 * @return - Nema povratnu vrednost
 */
int main()
{
	usartInit(9600);
	timer0InteruptInit();
	pinInit(PORT_B, 5, OUTPUT);
	pinSetValue(PORT_B, 5, LOW);

	int8_t tmp[30];
	int16_t duzina;

	while (1)
	{
		usartPutString_P(PSTR("Unesite duzinu niza\r\n\0"));

		while (usartAvailable() == 0)
		;
		timer0DelayMs(100);

		duzina = usartParseInt();

		int16_t niz[duzina];

		usartPutString_P(PSTR("Unesite clanove niza\r\n\0"));

		//cekanje na unos niza
		usartPutString_P(PSTR("Uneli ste niz { \0"));
		pinSetValue(PORT_B, 5, HIGH);


		for (uint8_t i = 0; i < duzina; i++)
		{
			while (usartAvailable() == 0)
			;
			timer0DelayMs(100);

			niz[i] = usartParseInt();
			sprintf(tmp, "%d \0", niz[i]);
			usartPutString(tmp);
		}
		usartPutString_P(PSTR("}\r\n\0"));
		pinSetValue(PORT_B, 5, LOW);

		//Sortiranje u rastucem poretku
		Sort(niz, duzina, DOWN);

		//Provera da li je niz aritmeticki
		int8_t ok = Check(niz);

		//ISPIS
		usartPutString_P(PSTR("{ \0"));
		for (uint8_t i = 0; i < duzina; i++)
		{
			sprintf(tmp, "%d \0", niz[i]);
			usartPutString(tmp);
		}
		usartPutString_P(PSTR("}\r\n\0"));

		if (ok)
			usartPutString_P(PSTR("Niz je aritmeticki, \0"));
		else
			usartPutString_P(PSTR("Niz nije aritmeticki, \0"));

		uint32_t t0 = timer0millis();
		sprintf(tmp, "proteklo vreme = %dms\r\n\0", t0);
		usartPutString(tmp);

	}
	return 0;
}
