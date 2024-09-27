@ -1,16 +1,14 @@
// S24 Homework 1 - Converter Tool
// TODO: Write name below and delete this line.
// Name:
// Name: Colin Edsall
//
// This program is a converter tool that helps you with your homework.
// It should convert the scenarios in Problems 3, 4, and 5.
//
// Problem 1.1: Convert decimal to 8-bit unsigned binary, add leading 0s
// Problem 1.2: Convert decimal to 2-digit hexadecimal
//
// Problem 2: Convert decimal to 8-bit signed 2's complement binary, add leading
// 0s
//
// Problem 3: Convert 8-bit signed 2's complement binary to decimal
//
// The program should ask the user to enter a decimal or 8-bit signed 2's
@ -31,27 +29,26 @@

#include <stdio.h>

void reverseString(char *str, int length)
void reverseString(char* str, int length)
{
  int start = 0;
  int end = length - 1;
  while (start < end)
  {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int decimalToBinary(int decimal, char *binary)
int decimalToBinary(int decimal, char* binary)
{
  // Problem 1.1
  // TODO: check if the input is outside of the range of 8-bit unsigned binary
  //          if so, return 1;

  // TODO: Convert decimal to 8-bit unsigned binary, add leading 0s
    // Problem 1.1
    // TODO: check if the input is outside of the range of 8-bit unsigned binary
    //          if so, return 1;
    if (decimal < 0 || decimal > 255) {
        return 1; //bounds of input
    }
    else {
@ -64,25 +61,24 @@ int decimalToBinary(int decimal, char *binary)
        }
    }

  binary[8] = '\0';
  return 0;
    binary[8] = '\0';
    return 0;
}

int decimalToHex(int decimal, char *hex)
int decimalToHex(int decimal, char* hex)
{
  // Problem 1.2

  // TODO: check if the input is outside of the range of 2-digit hexadecimal
  //          if so, return 1;
    //same bounds as above in 1.1
    // Problem 1.2
    // TODO: check if the input is outside of the range of 2-digit hexadecimal
    //          if so, return 1;
      //same bounds as above in 1.1
    if (decimal < 0 || decimal > 255) {
        return 1; //bounds of input
    }
    else {
        //let's split up the decimal into two nibbles, i.e. its remainder and its raw value after
        //being divided by the hex conversion (16)
        int nibbleDivide = decimal / 16;
        int nibbleMod = decimal % 16;
        int nibbleDivide = decimal / 16; //divide
        int nibbleMod = decimal % 16; //mod

        //now that we have two nibbles (position 0 and 1 for the array)
        //we can use a for loop, but since we only have two nibbles, we can just state them below
@ -102,19 +98,15 @@ int decimalToHex(int decimal, char *hex)
        }
    }

  // TODO: Convert decimal to 2-digit hexadecimal
  // Hint: The reverseString function might be useful

  hex[2] = '\0';
  return 0;
    hex[2] = '\0';
    return 0;
}

int decimalToTwosComplement(int decimal, char *binary)
int decimalToTwosComplement(int decimal, char* binary)
{
  // Problem 2

  // TODO: check if the input is outside of the range of 8-bit signed 2's complement binary
  //          if so, return 1;
    // Problem 2
    // TODO: check if the input is outside of the range of 8-bit signed 2's complement binary
    //          if so, return 1;
    if (decimal < -128 || decimal > 127) {
        return 1; //bounds of input
    }
@ -137,7 +129,7 @@ int decimalToTwosComplement(int decimal, char *binary)
    }
    else {
        //flip the sign to take abs value
        decimal = -1*decimal;
        decimal = -1 * decimal;

        //convert
        for (i = 7; i >= 0; i--) {
@ -159,36 +151,33 @@ int decimalToTwosComplement(int decimal, char *binary)
        //so instead we'll sort downwards
        for (i = 7; i >= 0; i--) {
            if (binary[i] == '0') { //checks the first value, and if it is zero,
                                    //add the 1
                //add the 1
                binary[i] = '1';
                break;
            } else {
            }
            else {
                binary[i] = '0';    //moves the zeros down (reverse adding)
            }
        }

    }
  // TODO: Convert decimal to 8-bit signed 2's complement binary, add leading 0s

  binary[8] = '\0';
  return 0;
    binary[8] = '\0';
    return 0;
}



int twosComplementToDecimal(int binary, char *decimalOut)
int twosComplementToDecimal(int binary, char* decimalOut)
{
  // Problem 3

  // TODO: check if the input is not 8 bits or is not binary
  //          if so, return 1;
    //check if the input is not 8 bits (aka the size of the integer doesn't have length 8)
    // Problem 3
    // TODO: check if the input is not 8 bits or is not binary
    //          if so, return 1;
      //check if the input is not 8 bits (aka the size of the integer doesn't have length 8)
    int checkBinary = binary;
    int isBinary = 1;
    while (checkBinary > 0) {
        if (checkBinary % 10 > 1) {
            isBinary=0; //if the remainder isn't 1 or zero, then we know it isn't
                          //binary
            isBinary = 0; //if the remainder isn't 1 or zero, then we know it isn't
            //binary
        }
        checkBinary /= 10;
    }
@ -227,10 +216,11 @@ int twosComplementToDecimal(int binary, char *decimalOut)
        //add 1 to the binary
        for (i = 7; i >= 0; i--) {
            if (binaryChar[i] == '0') { //checks the first value, and if it is zero,
                                    //add the 1
                //add the 1
                binaryChar[i] = '1';
                break;
            } else {
            }
            else {
                binaryChar[i] = '0';    //moves the zeros down (reverse adding)
            }
        }
@ -243,7 +233,8 @@ int twosComplementToDecimal(int binary, char *decimalOut)
        }
        decimal = -decimal;

    } else {
    }
    else {
        for (i = 0; i < 8; i++) {
            if (binaryChar[i] == '1') {
                decimal += (1 << (7 - i));
@ -260,67 +251,68 @@ int twosComplementToDecimal(int binary, char *decimalOut)

int main()
{
  int choice, decimal, binary;
  char tempString[9];
  printf("Enter a decimal or 8-bit signed 2's complement binary number: ");
  scanf("%d", &decimal);
  printf("Enter the conversion type:\n");
  printf("1. Decimal to 8-bit unsigned binary\n");
  printf("2. Decimal to 2-digit hexadecimal\n");
  printf("3. Decimal to 8-bit signed 2's complement binary\n");
  printf("4. 8-bit signed 2's complement binary to decimal\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:

    if (decimalToBinary(decimal, tempString))
    {
      printf("Overflow error: input is outside the range of an 8-bit unsigned "
             "integer.\n");
    }
    else
    {
      printf("The result is %s\n", tempString);
    }
    break;
  case 2:
    if (decimalToHex(decimal, tempString))
    int choice, decimal, binary;
    char tempString[9];
    printf("Enter a decimal or 8-bit signed 2's complement binary number: ");
    scanf("%d", &decimal);
    printf("Enter the conversion type:\n");
    printf("1. Decimal to 8-bit unsigned binary\n");
    printf("2. Decimal to 2-digit hexadecimal\n");
    printf("3. Decimal to 8-bit signed 2's complement binary\n");
    printf("4. 8-bit signed 2's complement binary to decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
      printf("Overflow error: input is outside the range of 2-digit hex\n");
    }
    else
    {
      printf("The result is %s\n", tempString);
    }
    break;
    case 1:

  case 3:
    if (decimalToTwosComplement(decimal, tempString))
    {
      printf("Overflow error: input is outside the range of an 8-bit signed integer.\n");
    }
    else
    {
      printf("The result is %s\n", tempString);
    }
    break;
        if (decimalToBinary(decimal, tempString))
        {
            printf("Overflow error: input is outside the range of an 8-bit unsigned "
                "integer.\n");
        }
        else
        {
            printf("The result is %s\n", tempString);
        }
        break;
    case 2:
        if (decimalToHex(decimal, tempString))
        {
            printf("Overflow error: input is outside the range of 2-digit hex\n");
        }
        else
        {
            printf("The result is %s\n", tempString);
        }
        break;

  case 4:
    if (twosComplementToDecimal(decimal, tempString))
    {
      printf("Overflow error: input is outside the range of 2-digit hex or is not binary\n");
    }
    else
    {
      printf("The result is %s\n", tempString);
    }
    break;
    case 3:
        if (decimalToTwosComplement(decimal, tempString))
        {
            printf("Overflow error: input is outside the range of an 8-bit signed integer.\n");
        }
        else
        {
            printf("The result is %s\n", tempString);
        }
        break;

  default:
    printf("Invalid choice\n");
  }
  return 0;
    case 4:
        if (twosComplementToDecimal(decimal, tempString))
        {
            printf("Overflow error: input is outside the range of 2-digit hex or is not binary\n");
        }
        else
        {
            printf("The result is %s\n", tempString);
        }
        break;

    default:
        printf("Invalid choice\n");
    }
    return 0;
}

//this is a GitHub test, disregard.
