/*
 File:              recursion.c
 Purpose:           Exercises for CPSC259 lab 4
 Author:			Robin Yuan, Jerry Shao
 Student #s:		88011879 and 84982321
 CS Accounts:		b9k3b  and c1i3b
 Date:				Nov 13, 2020
 */

 /******************************************************************
  PLEASE EDIT THIS FILE

  Comments that start with // should be replaced with code
  Comments that are surrounded by * are hints
  ******************************************************************/

#define _CRT_SECURE_NO_WARNINGS
  /* Preprocessor directives */
#include "recursion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 Calculates the power.
 PARAM:     base is an integer
 PARAM:     power is an integer
 PRE:       power >= 0
 PRE:       base != 0
 RETURN:    base^power
 */
int calculate_power(int base, int power)
{
    if (power == 0) return 1;
    if (power == 1) return base;
    return base * calculate_power(base, power - 1);
}

/*
 Returns the number of digits in an integer
 PARAM:     number is an integer
 PRE:       0 < number <= INT_MAX
 RETURN:    the number of digits in the number
 */
int count_digits(int number)
{
    if (number < 10) return 1;
    return count_digits(number / 10) + 1;
}

/*
 Returns the length of the specified string.
 PARAM:  string, a pointer to an array of char
 PRE:    the string pointer is not a dangling pointer
 RETURN: the length of the string passed as a parameter
 */
int string_length(char* string)
{
    if (*string == '\0') return 0;
    return string_length(string + 1) + 1;
}

/*
 Determines if a string is a palindrome.  DOES NOT skip spaces!
 For example,
 ""     -> returns 1 (an empty string is a palindrome)
 "the"  -> returns 0
 "abba" -> returns 1
 "Abba" -> returns 0
 "never odd or even" -> returns 0
 For the recursive call, be aware that both parameters can be modified.
 PARAM:  string, a pointer to an array of char
 PARAM:  string_length, the length of the string
 PRE:    the string pointer is not a dangling pointer
 PRE:    string_length is the correct length of the string
 RETURN: IF string is a palindrome
         THEN 1
         END 0
 */
int is_palindrome(char* string, int string_length)
{
    if (string_length <= 1) return 1;
    if (*string != *(string + string_length - 1)) return 0;
    if (*string == *(string + string_length - 1))
        return  is_palindrome(string + 1, string_length - 2);
}

/*
 Draws a ramp.  The length of the longest rows is specified by the parameter.
 For the recursive call, be aware that both parameters can be modified.
 PARAM:     number, an integer
 PARAM:     buffer, a character array of sufficient length
 PRE:       number >= 1
            buffer has sufficient length and contains null characters from the buffer
            address to the end of its length
 POST:      draws a ramp whose height is the specified number into buffer
 RETURN:    the number of characters written into buffer. Don't forget to count your
            newline characters!
 */
int draw_ramp(int number, char* buffer)
{
    /*strcat(buffer, "\n");
    draw_row(number, buffer);

    if (number == 1)
    {
        if (buffer[0] == '\n') strcpy(buffer, buffer + 1);
        return 0;
    }
    else draw_ramp(number - 1, buffer);

    strcat(buffer, "\n");
    draw_row(number, buffer);

    if (string_length(buffer) == 0) return 0;
    if (*buffer == '\n') strcpy(buffer, buffer + 1);

    return strlen(buffer);*/

    static int len = 0;
    if (strlen(buffer) == 0) {//why
        len = 0;
    }
    if (number == 1) {
        strcat(buffer, "*");
        len++;
        //return len;
    }
    else {
        len += draw_row(number, buffer+len);
        strcat(buffer, "\n");
        len++;
        draw_ramp(number - 1, buffer);
        strcat(buffer, "\n");
        len++;
        len += draw_row(number, buffer+len);
    }
    return len;
    /*static int len = 0;
    static int max;

    if (strlen(buffer) == 0) {//why
        len = 0;
        max = number;
        number = 1;
    }
    if (number == max) {
        
        len += draw_row(number, buffer + len);
        
    }
    else {
        len += draw_row(number, buffer + len);
        strcat(buffer, "\n");
        len++;
        draw_ramp(number + 1, buffer);
        strcat(buffer, "\n");
        len++;
        len += draw_row(number, buffer + len);

    }
    return len;*/
}


/*
 Draws a row of asterisks of the specified length
 For the recursive call, be aware that both parameters can be modified.
 PARAM:  size, an integer
 PARAM:  buffer, a character array of sufficient length
 PRE:    size >= 1
         buffer has sufficient length and contains null characters from the buffer
         address to the end of its length
 POST:   draws a row of asterisks of specified length to buffer
 RETURN: the number of characters drawn
 */
int draw_row(int size, char* buffer)
{
    int n;
    if (1 == size) {
        buffer[0] = '*';
        return strlen(buffer);
    }
    else {
        buffer[size - 1] = '*';
        draw_row(size - 1, buffer);
    }
    n = strlen(buffer);
    return n;

    /*int length = strlen(buffer);

    if(size == 1) {
        buffer[1] = '*';
    } else {
        buffer[size] = '*';
        draw_row(size - 1, buffer);
    }
    return strlen(buffer);
    */
}