@ -1,4 +1,7 @@
/*
 * COLIN EDSALL
 * ECE 2564 FALL 2024
 *
 * This project is related to the problem 1 of HW3, ECE2564 Fall 2024.
 * It is important that you read the PDF homework description to understand what you need to do.
 * The comments and TODO items in this document may not be self-sufficient to tell you how to complete this project.
@ -13,7 +16,16 @@
void main()
{
    // You should change starting_value to different values and test the code you write below to check if it works for all cases.
    unsigned int starting_value = 0xF300F0A2;

    //since we need to change this, let's go with something that regardless of actions below will be TRUE
    //this means MSB (bit 31) and LSB (bit 0) will be 1
    //we will toggle bit0 at the end, so set it to zero
    //this means that for any hex value, it has to be even (xxx0)
    //MSB needs to be above or equal to the value of 8 (1xxx)

    //so we can go with 0x8FFFFFF0

    unsigned int starting_value = 0x8FFFFFF0;
    bool test_v;

    unsigned k = starting_value;
@ -33,16 +45,40 @@ void main()
     * without affecting any other bits of k. Store the result back into k. 5 points
     */

    //we want to set the bits (4,6,8) of k to 1
    //to do this, we can use an OR statement such that bits 4,6,8 of k will be 1, regardless
    //of if they are 1 to begin with

    k = (k | BIT4 | BIT6 | BIT8);


    /*
     * TODO #2: Write a snippet of code that will cause the second least-significant nibble (4-bit chunk) of k to contain
     * the bit pattern 1010 without affecting any other bits of k. Store the result back into k. 5 points
     * Hint: The least-significant nibble are bits 0, 1, 2, and 3. Your goal is to make bits 4,5,6 and 7 be 1, 0, 1, and 0, respectively.
     */

    k = (k | BIT4);
    k = (k & (~BIT5));
    k = (k | BIT6);
    k = (k & (~BIT7));

    /*
     * TODO #3: Write a snippet of code that toggles bit 0 and 1, sets bit 4 and 5 to 1, and resets bit 10 and 11 to 0. Store the result back into k. 5 points
     */

    //to toggle a bit, we should use the XOR operator
    k = (k ^ BIT0);
    k = (k ^ BIT1);

    //to set bits, we use the set operator
    k = (k | BIT4);
    k = (k | BIT5);

    //to reset bits 10 and 11, we use the reset operator & ~
    k = (k & (~BITA));
    k = (k & (~BITB));

    /*
     * TODO #4: Write the expression that computes variable test_v, the Boolean value that is True if the second MSB of k equal to the second LSB of k.
     * You need to remove the word "true" that is assigned to test_v and replace it with some other expression.
@ -50,7 +86,17 @@ void main()
     */

    // Implement the evaluation for test_v here
    test_v = true;

    //we are given the task to evaluate the MSB relation to the LSB of k
    //the MSB has value BIT32 (not actual name) and LSB has value BIT0
    //let's just shift it over 31 times
    unsigned p = k & BIT(31); //this creates a mask for the MSB
    unsigned q = k & BIT0; //this creates a mask for the LSB

    //now to compare the values of the bits, simply shift the value of the LSB to the position of MSB (or vice-versa)
    q = q << 31;

    test_v = q & p; //changed this to show if the two bits are the same, if not then 0 (false)

    if (test_v)
        printf("The test variable is true.\n");
