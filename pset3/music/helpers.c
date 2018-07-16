// Helper functions for music
#include <math.h>
#include <cs50.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    // 1/8 = 1 , 1/4 = 2, 3/8 = 3, 1/2 = 4 notes 2/8 with bar
  int t = (int) fraction;

   return t;

}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
  // TODO
  // Math: Up: var=440*2^(n/12)  Down: var=440/2^(n/12)
  // next octive: var= 880 * 2(n/12)
  // ex.- 493.883301256 = 440*2^(2/12) rounding is needed
  // tested in google calc to have any number in N and got a right answer.
    int n=(int) note;
    return n;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    string rest=get_string(s);
    int r=(int) rest;
    if (r ==10) {
        return 1;
    }
}

