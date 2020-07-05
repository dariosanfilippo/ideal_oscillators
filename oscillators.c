/*******************************************************************************
 *
 * Fundamental ideal oscillators.
 *
 * The code below shows how to create and initialise objects based on 
 * structures to generate some of the common ideal oscillators.
 *
 * As an example, the code prints in screen the first
 * 96 samples of phasor, sine, square, sawtooth, and triangle oscillators
 * at a frequency of 1000 Hz at a samplerate of 96000 Hz.
 *
 * Copyright(C) 2020 Dario Sanfilippo – All rights reserved.
 *
 * Reference: Boulanger and Lazzarini 2010 – The Audio Programming Book.
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "oscillators.h"

int main(void) {
    /* Main parameters. */
    long int SR = 96000;
    long int size = 96;
    double freq = 1000.0;
    double ph = 0.0;
    /* Creation of pointers to memory locations of phase objects. */
    PH *ph_ph = ph_new(SR);
    PH *ph_sine = ph_new(SR);
    PH *ph_square = ph_new(SR);
    PH *ph_sawtooth = ph_new(SR);
    PH *ph_triangle = ph_new(SR);
    /* Pointers are passed as arguments to the generating functions. */
    for (int i = 0; i < size; i++) {
        printf("%f\t", phasor_gen(ph_ph, freq, ph));
        printf("%f\t", sine_gen(ph_sine, freq, ph));
        printf("%f\t", square_gen(ph_square, freq, ph));
        printf("%f\t", sawtooth_gen(ph_sawtooth, freq, ph));
        printf("%f\n", triangle_gen(ph_triangle, freq, ph));
    }
    /* Free memory at the end of the process. */
    ph_free(ph_ph);
    ph_free(ph_sine);
    ph_free(ph_square);
    ph_free(ph_triangle);

    return 0;
}
