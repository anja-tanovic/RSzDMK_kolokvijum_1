/**
 * @file util.h
 * @brief biblioteka koja deklarise funkcije za nizove
 * @author Anja Tanovic
 * @date 16-05-2021
 * @version 1.0
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <stdint.h>

///Makro za definisanje opadajuceg smera sortiranja
#define UP 1

///Makro za definisanje rastuceg smera sortiranja
#define DOWN 2

///Makro za definisanje tacnog iskaza
#define TRUE 1

///Makro za definisanje netacnog iskaza
#define FALSE 0

/**
 * Sort - Funkcija koja implementiran sortiranje niza
 * @param array - ulaz tipa in16_t - Ulazni niz koji treba sortirati
 * @param array_length - ulaz tipa int16_t - Duzina niza
 * @param mode - ulaz tipa int8_t - Smer prema kojem je potrebno sortirati niz
 * @return Nema povratnu vrednost
 */
void Sort(int16_t *array, int16_t array_length, int8_t mode);

/**
 * Check - Funkcija koja proverava da li je niz aritmeticki
 * @param array - ulaz tipa int16_t - niz koji se proverava
 * @param array_length - ulaz tipa int16_t - duzina niza
 * @return - Povratna vrednost TRUE ili FALSE
 */
int8_t Check(int16_t *array, int16_t array_length);

#endif /* UTIL_H_ */
