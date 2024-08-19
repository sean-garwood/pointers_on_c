/*
 * well-designed rng return values that appear to be random, yet are uniform
 * over time.
 *
 * Numbers derived from the random values should also have these properties.
 *
 * For ex: poorly designed rng might return values that appear random but
 * alternate between even and odd.
 *
 * Another faw would be a generator that returned only odd values.
 *
 * Write a program to test the rng on your system. generate 10,000 random
 * numbers and perform two types of test:
 *
 * 1. frequency
 *
 * take each random number modulo 2 and count how man times the result is zero
 * and one. do the same for mods 3 through 10. the results will not be precisely
 * uniform, but there would not be any large peaks or valleys in the frequencies.
 *
 * 2. cyclic frequency
 *
 * Take each random num and the preceding one mod two. Use these remainders as
 * the subscripts of a 2-d array and increment the specified location. repeat
 * for mod 3-10. the results should be uniformly distributed.
 *
 * Modify the program so that you can provide different values to seed the rng,
 * and run tests with several seeds. how good is it?
 */

#include "../headers.h"
