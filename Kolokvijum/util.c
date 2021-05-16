/**
 * @file util.c
 * @brief biblioteka koja definise funkcije za nizove
 * @author Anja Tanovic
 * @date 16-05-2021
 * @version 1.0
 */

#include "util.h"

void Sort(int16_t *array, int16_t array_length, int8_t mode)
{
	int16_t pomocna;

	switch (mode)
	{
		case UP:
			for (int8_t i = 0; i < array_length; i++)
			{
				for (int8_t j = i + 1; j < array_length; j++)
				{
					if (array[j] > array[i])
					{
						pomocna = array[i];
						array[i] = array[j];
						array[j] = pomocna;
					}
				}
			}
			break;
		case DOWN:
			for (int8_t i = 0; i < array_length; i++)
			{
				for (int8_t j = i + 1; j < array_length; j++)
				{
					if (array[j] < array[i])
					{
						pomocna = array[i];
						array[i] = array[j];
						array[j] = pomocna;
					}
				}
			}
			break;
		default:
			break;
	}
}

/**********************************************************************/

int8_t Check(int16_t *array, int16_t array_length)
{
	int16_t n = array[1] - array[0];    //pocetna razlika, ukoliko se ponavlja, ok
	int8_t ok = TRUE;

	for (int8_t i = 1; i < array_length; i++)
	{
		if (array[i + 1] - array[i] != n)
		{
			ok = FALSE;
			break;
		}
	}

	return ok;
}
