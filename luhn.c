//      Name:           luhn.c
//      Start date: 	12-3-2014
//      Completed:  	12-17-2014
//      By:             Seaver Milnor
//      Purpose:        Compute the Luhn checksum of the
//                              number supplied to argv[1]
//      Reference:      en.wikipedia.org/wiki/Luhn_algorithm
//      Note:           nothing challenging; just practice!

#include <stdio.h>
#include <string.h>

#define MAXLEN  25

int main( int argc, char* argv[] )
{

        int length;             // number of digits supplied by user
        length = strlen(argv[1]);
        // line below was a diagnostic
        // printf("\nLength=%d\n", length);
        if (length > MAXLEN) {
                printf("\nError! Limit is %d digits.\n", MAXLEN);
              return -1;
        }

        int i;          // index of for loop
        int sum = 0, tempsum = 0, odd = 1;
        /* variables for the total sum, smaller sums that
        get added to it, and--essentially a bool--to keep
        track of whether or not we double the digit */

        for(i = length - 1; i >= 0; i--) {
                if(odd) {
                // working on the first, third, fifth... digit
                        tempsum = 2 * (argv[1][i] - '0');
                        if(tempsum > 9) {
                                tempsum = 1 + (tempsum - 10);
                        }
                        odd = 0;
                } else {
                // working on the second, fourth, sixth... digit

                        tempsum = (argv[1][i] - '0');
                        odd = 1;
                }
                sum += tempsum;
                // line below was from debugging
                // printf("\ni=%d tmp=%d odd=%d sum=%d", i, tempsum, odd, sum);
        }

        // calculate the final checksum
        sum *= 9;       // multiply sum by 9
        sum %= 10;      // grab just the last digit

        printf("\nThe Luhn check digit is %d\n", sum);
        return 0;
}

