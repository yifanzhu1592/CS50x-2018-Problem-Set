// Learn to read sheet music.
// Learn to read code.
// Convert musical notes to frequencies.
// Synthesize songs.


// Helper functions for music

#include <cs50.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    return atoi(&fraction[0]) * 8 / atoi(&fraction[2]);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double frequency = 440;

    if (note[1] == 'b' || note[1] == '#')
    {
        frequency = frequency * pow(2, (atoi(&note[2]) - 4));

        if (note[1] == 'b')
            frequency = round(frequency * pow(2, -1.000000 / 12));
        else
            frequency = round(frequency * pow(2, 1.000000 / 12));

        if (note[0] == 'B')
            frequency = frequency * pow(2, 2.000000 / 12);
        else if (note[0] == 'C')
            frequency = round(frequency * pow(2, -9.000000 / 12));
        else if (note[0] == 'D')
            frequency = round(frequency * pow(2, -7.000000 / 12));
        else if (note[0] == 'E')
            frequency = frequency * pow(2, -5.000000 / 12);
        else if (note[0] == 'F')
            frequency = round(frequency * pow(2, -4.000000 / 12));
        else if (note[0] == 'G' && atoi(&note[2]) != 5)
            frequency = round(frequency * pow(2, -2.000000 / 12));
        else if (note[0] == 'G' && atoi(&note[2]) == 5)
            frequency = round(frequency * pow(2, -2.000000 / 12)) + 1;
    }
    else
    {
        frequency = round(frequency * pow(2, (atoi(&note[1]) - 4)));

        if (note[0] == 'B')
            frequency = round(frequency * pow(2, 2.000000 / 12));
        else if (note[0] == 'C')
            frequency = round(frequency * pow(2, -9.000000 / 12));
        else if (note[0] == 'D')
            frequency = round(frequency * pow(2, -7.000000 / 12));
        else if (note[0] == 'E')
            frequency = round(frequency * pow(2, -5.000000 / 12));
        else if (note[0] == 'F')
            frequency = round(frequency * pow(2, -4.000000 / 12));
        else if (note[0] == 'G')
            frequency = round(frequency * pow(2, -2.000000 / 12));
    }

    return frequency;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
        return true;
    else
        return false;
}
