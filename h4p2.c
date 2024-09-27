@ -8,6 +8,79 @@
// Abstraction Layer (HAL). The main function is easy to read, but the HAL
// functions themselves are hard to write since we do not use Driverlib.

//COLIN EDSALL
//ECE2564 HW4
//24 SEPT 2024


/*
PART D of Project 1
We want to have this relationship for the buttons in our kit:

INPUT:
    BB1 is PRESSED (1)
    BB1 is RELEASED (2)

OUTPUT:
    BLB is ON (1)
    BLB is OFF (2)

So we need to write a function that checks the value of S1 on the BoosterPack.
Then, we need to find the memory-mapped address for the blue LED on the
BoosterPack and assign it to turn on when S1 is pressed (BB1) and then turn off
whenever it is not.

First, let's look at the datasheet to find these addresses and values.
BB1: Has connection at J4.33. This connects to P5.1 on the Launchpad as per
our class OneNote. We also know these are driven to pin low when pressed
(same as LB2). This information is found on page 8 of the BoosterPack user
guide.

BLB: Has connection at J4.37. This connects to P5.6 on the Launchpad as per
our class OneNote. We also know these turn on when a pin high is assigned.
This information is found on page 7 of the BoosterPack user guide.

So, we know know which pins. Now we need port forwarding. These are taken from
p. 685 of the MSP432 Datasheet.
  P5IN_pointer = (unsigned char *)0x40004C 40;
  P5OUT_pointer = (unsigned char *)0x40004C 42;
  P5REN_pointer = (unsigned char *)0x40004C 46;
  P5DIR_pointer = (unsigned char *)0x40004C 44;

So we can start implementing the masking and helper functions
for the intended function.

*/



//According to the BoosterPack user guide,
//BoosterPack Button 1 is connected to Port 5, pin 1 (bit 1)
#define BB1 (1 << 1)

//According to the BoosterPack user guide,
//BoosterPack Blue LED is connected to Port 5, pin 6 (bit 6)
#define BLB (1 << 6)

//we can keep the same definition for PRESSED as used below,
//since BB1 is turned on at 0

void TurnOn_BoosterPack_BLB();
void TurnOff_BoosterPack_BLB();
char BB1isPressed();

unsigned char *P5IN_pointer;
unsigned char *P5OUT_pointer;
unsigned char *P5REN_pointer;
unsigned char *P5DIR_pointer;








// According to the schematics on page 37 of the Launchpad user guide,
// Right button (button 2, S2) is connected to pin 4 (bit4)
#define LB2 (1 << 4)
@ -44,12 +117,21 @@ int main(void) {

  while (1) {
    // If the button is not pressed, keep the LED off
    if (!LB2isPressed()) TurnOff_Launchpad_LL1();

    // otherwise, turn the LED on
    else
    if (!LB2isPressed()) {
        TurnOff_Launchpad_LL1();
    }
    else {
      TurnOn_Launchpad_LL1();
    }

    //booster pack, same if statement since buttons are similar
    if (!BB1isPressed()) {
        TurnOff_BoosterPack_BLB();
    }
    // otherwise, turn the LED on
    else {
      TurnOn_BoosterPack_BLB();
    }
  }
}

@ -79,6 +161,27 @@ void initialize() {

  // step 3.3: write a 1 to PxOUT for the specific bit you want
  *P1OUT_pointer |= LB2;  // select pull-up



  //begin port setup (work shown above)
  P5IN_pointer = (unsigned char *)0x40004C40;
  P5OUT_pointer = (unsigned char *)0x40004C42;
  P5REN_pointer = (unsigned char *)0x40004C46;
  P5DIR_pointer = (unsigned char *)0x40004C44;

  //Initializing BLB
  //According to table 12.4 on page 696 of MSP432 User guide,
  //to create an output you need to write HIGH to the DIR bit.
  *P5DIR_pointer |= BLB; //creates output

  //the button on the BoosterPack has value 1 when high
  *P5DIR_pointer &= ~BB1;

  *P5REN_pointer |= BB1;

  *P5OUT_pointer |= BB1;

}

void TurnOn_Launchpad_LL1() { *P1OUT_pointer = *P1OUT_pointer | LL1; }
@ -86,3 +189,12 @@ void TurnOn_Launchpad_LL1() { *P1OUT_pointer = *P1OUT_pointer | LL1; }
void TurnOff_Launchpad_LL1() { *P1OUT_pointer = *P1OUT_pointer & ~LL1; }

char LB2isPressed() { return ((*P1IN_pointer & LB2) == PRESSED); }



//definitions for the turnon and press state
void TurnOn_BoosterPack_BLB() { *P5OUT_pointer = *P5OUT_pointer | BLB; }

void TurnOff_BoosterPack_BLB() { *P5OUT_pointer = *P5OUT_pointer & ~BLB; }

char BB1isPressed() { return ((*P5IN_pointer & BB1) == PRESSED); }
