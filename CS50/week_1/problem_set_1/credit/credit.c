#include<cs50.h>
#include<stdio.h>
//AMEX has 15 digits. Starts with 34 or 37.
//MASTERCARD has 16 digits. Starts with 51 or 52 or 53 or 54 or 55.
//VISA can have 13 or 16 digits. Starts with 4.

//                    --VARIABLES--:
// number: user input
// length: number of digits
// l1: variable equall to "number". Used for length function
// l2: variable equal to "length". Used as counter to find "rem"
// rem: remainder function. Used to identify digits.
// n1-n16: individual digits of the original number.

int main(void)
{
    //input command
    long number;
    int length = 0;
    long rem = 1;


    // get number

    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    // find length
    long l1 = number;
    do
    {
        l1 = (l1 / 10);
        length++;
    }
    while (l1 > 0);



    // find digits and do checksum
    int l2 = length;
    do
    {
        rem = (rem * 10);
        l2--;
    }
    while (l2 > 0);


    int luun = 0;
    int n1 = 0;
    int n2 = 0;

    // for 13 digits

    if (length == 13)
    {
        n1 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        n2 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n3 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n4 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n5 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n6 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n7 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n8 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n9 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n10 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n11 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n12 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n13 = (((number % rem) - (number % (rem / 10))) / (rem / 10));

        luun = (((((n12 * 2) % 100) - ((n12 * 2) % 10)) / 10) + ((n12 * 2) % 10) + ((((n10 * 2) % 100) - ((n10 * 2) % 10)) / 10) + ((
                    n10 * 2) % 10) + ((((n8 * 2) % 100) - ((n8 * 2) % 10)) / 10) + ((n8 * 2) % 10) + ((((n6 * 2) % 100) - ((n6 * 2) % 10)) / 10) + ((
                                n6 * 2) % 10) + ((((n4 * 2) % 100) - ((n4 * 2) % 10)) / 10) + ((n4 * 2) % 10) + ((((n2 * 2) % 100) - ((n2 * 2) % 10)) / 10) + ((
                                            n2 * 2) % 10) + n13 + n11 + n9 + n7 + n5 + n3 + n1) % 10;
    }
    // for 15 digits

    else if (length == 15)
    {
        n1 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        n2 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n3 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n4 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n5 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n6 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n7 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n8 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n9 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n10 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n11 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n12 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n13 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n14 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n15 = (((number % rem) - (number % (rem / 10))) / (rem / 10));

        luun = (((((n14 * 2) % 100) - ((n14 * 2) % 10)) / 10) + ((n14 * 2) % 10) + ((((n12 * 2) % 100) - ((n12 * 2) % 10)) / 10) + ((
                    n12 * 2) % 10) + ((((n10 * 2) % 100) - ((n10 * 2) % 10)) / 10) + ((n10 * 2) % 10) + ((((n8 * 2) % 100) - ((n8 * 2) % 10)) / 10) + ((
                                n8 * 2) % 10) + ((((n6 * 2) % 100) - ((n6 * 2) % 10)) / 10) + ((n6 * 2) % 10) + ((((n4 * 2) % 100) - ((n4 * 2) % 10)) / 10) + ((
                                            n4 * 2) % 10) + ((((n2 * 2) % 100) - ((n2 * 2) % 10)) / 10) + ((n2 * 2) % 10) + n15 + n13 + n11 + n9 + n7 + n5 + n3 + n1) % 10;
    }
    // for 16 digits

    else if (length == 16)
    {
        n1 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        n2 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n3 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n4 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n5 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n6 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n7 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n8 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n9 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n10 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n11 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n12 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n13 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n14 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n15 = (((number % rem) - (number % (rem / 10))) / (rem / 10));
        rem = (rem / 10);
        int n16 = (((number % rem) - (number % (rem / 10))) / (rem / 10));

        luun = (((((n15 * 2) % 100) - ((n15 * 2) % 10)) / 10) + ((n15 * 2) % 10) + ((((n13 * 2) % 100) - ((n13 * 2) % 10)) / 10) + ((
                    n13 * 2) % 10) + ((((n11 * 2) % 100) - ((n11 * 2) % 10)) / 10) + ((n11 * 2) % 10) + ((((n9 * 2) % 100) - ((
                                n9 * 2) % 10)) / 10) + ((n9 * 2) % 10) + ((((n7 * 2) % 100) - ((n7 * 2) % 10)) / 10) + ((n7 * 2) % 10) + ((((
                                            n5 * 2) % 100) - ((n5 * 2) % 10)) / 10) + ((n5 * 2) % 10) + ((((n3 * 2) % 100) - ((n3 * 2) % 10)) / 10) + ((n3 * 2) % 10) + ((((
                                                    n1 * 2) % 100) - ((n1 * 2) % 10)) / 10) + ((n1 * 2) % 10) + n16 + n14 + n12 + n10 + n8 + n6 + n4 + n2) % 10;
    }

    // Print card or invalid


    if ((length == 13 && n1 == 4 && luun == 0) || (length == 16 && n1 == 4 && luun == 0))
    {
        printf("VISA\n");
    }
    else if ((length == 15 && n1 == 3 && n2 == 4 && luun == 0) || (length == 15 && n1 == 3 && n2 == 7 && luun == 0))
    {
        printf("AMEX\n");
    }
    else if ((length == 16 && n1 == 5 && n2 == 1 && luun == 0) || (length == 16 && n1 == 5 && n2 == 2 && luun == 0) || (length == 16
             && n1 == 5 && n2 == 3 && luun == 0) || (length == 16
                     && n1 == 5 && n2 == 4 && luun == 0) || (length == 16 && n1 == 5 && n2 == 5
                             && luun == 0))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }





}