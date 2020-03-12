// Helper functions for music
#include <math.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    if(fraction[0] == '1')
    {
        if(fraction[2] == '8')
        {
            return 1;
        }
        else if(fraction[2] == '4')
        {
            return 2;
        }
        else if(fraction[2] == '2')
        {
            return 4;
        }
        else if(fraction[2] == '1')
        {
            return 8;
        }
    }
    else if(fraction[0] == '3' && fraction[2] == '8')
    {
        return 3;
    }
    else
    {
        return 0;
    }
    return 0;

}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO

    int n = note[strlen(note) - 1];
    n -= 48;
    double freq = 0.0;

    switch(note[0])
    {
        case 'C' :
            freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
            break;
        case 'D' :
            freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
            break;
        case 'E' :
            freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
            break;
        case 'F' :
            freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
            break;
        case 'G' :
            freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
            break;
        case 'A' :
            freq = 440.0;
            break;
        case 'B' :
            freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
            break;
        default :
            return 0;
    }
    if(n > 4)
    {
        for(int i = 0; i < n - 4; i++)
        {
            freq *= 2.0;
        }
    }
    else if(n < 4)
    {
        for(int i = 0; i < 4 - n; i++)
        {
            freq /= 2.0;
        }
    }

    if(note[1] == 'b')
    {
        freq /= (pow(2.0, (1.0 / 12.0)));
    }
    else if(note[1] == '#')
    {
        freq *= (pow(2.0, (1.0 / 12.0)));
    }

    int ret = round(freq);
    return ret;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO

    if(strlen(s))
    {
    return 0;
    }else {
        return 1;
    }

}
