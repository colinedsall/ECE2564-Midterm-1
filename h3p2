@ -1,10 +1,13 @@
/*
 * COLIN EDSALl
 * ECE 2564 FALL 2024
 *
 *
 * This project is related to the problem 2 of HW3, ECE2564 Spring 2023.
 * It is important that you read the PDF homework description to understand what you need to do.
 * The comments and TODO items in this document are not self-sufficient to tell you how to complete this project.
 */


#include <stdio.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

@ -12,16 +15,18 @@
// You need to change the rest from 0 to the appropriate value.
// The position in this context means the lowest index in the bitmask that contains a 1
#define INTENSITY_MASK (BIT1 | BIT2)
#define COLOR_MASK 0
#define FLICKER_MASK 0
#define COLOR_MASK (BIT3 | BIT4)
#define FLICKER_MASK (BIT0)
//completed as per assignment specification

//-----------------------------------
// TODO #2: complete the below bitmask positions. Color mask position is given to you as an example.
// You need to change the rest from 0 to the appropriate value.
// The position of the mask is the index of the lowest bit of the mask.
#define INTENSITY_BIT_POS 1
#define COLOR_BIT_POS 0
#define COLOR_BIT_POS 3
#define FLICKER_BIT_POS 0
//completed based on assignment specification

//-----------------------------------
// TODO #3: Use typedef and enum keywords to define three new types called color_t, intensity_t, and flickering_t.
@ -30,6 +35,8 @@
// For flickering_t, use format FLICK_* where * is OFF or ON
// color_t is done for you as an example.
typedef enum {WHITE, BLUE, RED, GREEN} color_t;
typedef enum {INT_OFF, INT_LOW, INT_MED, INT_HIGH} intensity_t;
typedef enum {FLICK_OFF, FLICK_ON} flickering_t;

//-----------------------------------
// TODO #4: There is no action item here for you except for reading the below line.
@ -42,6 +49,7 @@ typedef unsigned char LSR_t;
typedef struct {
    LSR_t lightSetting;           // the setting of the light
    unsigned int x;               // the x coordinate of the light
    unsigned int y;               // ADDED: y coordinate of light
} light_t;

// function declarations
@ -63,7 +71,6 @@ LSR_t makeLSR(intensity_t newIntensity, color_t newColor, flickering_t newFlicke
void increaseLight(LSR_t *LSR_p);



void main() {

    LSR_t tempLSR = 0xB7;
@ -125,6 +132,22 @@ void main() {
    * You have to use the functions you developed earlier to achieve this.
    */
   
   //first, we need to write an if statement for the x-coordinate being less than 50
   //to start, we need to grab the x-coordinate and check its value for ALL 5 lights
   int i;
   for(i = 0; i < 5; i++) {
       if (stageLights[i].x < 50) {
           increaseLight(&stageLights[i].lightSetting);
       }

       //now we need to check if the x and y coords are more than 50
       if (stageLights[i].x > 50 && stageLights[i].y > 50) {
           updateColor(&stageLights[i].lightSetting, GREEN);
       }
       else {
           updateFlicker(&stageLights[i].lightSetting, FLICK_ON);
       }
   }
   
   
}
@ -161,7 +184,8 @@ color_t getColorSetting(LSR_t inLSR)
 */
intensity_t getIntensitySetting(LSR_t inLSR)
{
    
    intensity_t intensitySetting = ((inLSR & INTENSITY_MASK) >> INTENSITY_BIT_POS);
    return intensitySetting;
}

/*
@ -176,7 +200,8 @@ intensity_t getIntensitySetting(LSR_t inLSR)
 */
flickering_t getFlickeringSetting(LSR_t inLSR)
{
    
    flickering_t flickeringSetting = ((inLSR & FLICKER_MASK) >> FLICKER_BIT_POS);
    return flickeringSetting;
}

/*
@ -189,7 +214,12 @@ flickering_t getFlickeringSetting(LSR_t inLSR)
 */
void updateIntensity(LSR_t* LSR_p, intensity_t newIntensity)
{
    //to update these settings, we use the pointer and update the struct type with the data
    //first grab data with the intensity mask
    *LSR_p &= ~INTENSITY_MASK;
    
    //now we can insert the intensity at that pointer value
    *LSR_p |= (newIntensity << INTENSITY_BIT_POS);
}

/*
@ -203,7 +233,12 @@ void updateIntensity(LSR_t* LSR_p, intensity_t newIntensity)
 */
void updateColor(LSR_t* LSR_p, color_t newColor)
{
    //to update these settings, we use the pointer and update the struct type with the data
    //first grab data with the color mask
    *LSR_p &= ~COLOR_MASK;
    
    //now we can insert the color at that pointer value
    *LSR_p |= (newColor << COLOR_BIT_POS);
}

/*
@ -216,7 +251,12 @@ void updateColor(LSR_t* LSR_p, color_t newColor)
 */
void updateFlicker(LSR_t* LSR_p, flickering_t newFlicker)
{
    //to update these settings, we use the pointer and update the struct type with the data
    //first grab data with the color mask
    *LSR_p &= ~FLICKER_MASK;
    
    //now we can insert the flicker at that pointer value
    *LSR_p |= (newFlicker << FLICKER_BIT_POS);
}

/*
@ -231,7 +271,14 @@ void updateFlicker(LSR_t* LSR_p, flickering_t newFlicker)
 */
LSR_t makeLSR(intensity_t newIntensity, color_t newColor, flickering_t newFlickering)
{
    LSR_t newLSR = 0; //initialize for struct
    
    //now we can insert each bit of information to their right position
    newLSR |= (newIntensity << INTENSITY_BIT_POS);
    newLSR |= (newColor << COLOR_BIT_POS);
    newLSR |= (newFlickering << FLICKER_BIT_POS);

    return newLSR;
}

/*
@ -247,6 +294,12 @@ void increaseLight(LSR_t *LSR_p)
    intensity_t tempIntensity = getIntensitySetting(*LSR_p);
    if (tempIntensity != INT_HIGH)
    {
        //we can't just add 1 to the value of the LSR, so we need to mask first
        //this is done above (getIntensitySetting), so we just need to increment
        tempIntensity++;
        
        //if we CAN update the intensity, update below
        updateIntensity(LSR_p, tempIntensity);
    }

}
