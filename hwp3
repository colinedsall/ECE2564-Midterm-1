@ -86,7 +86,7 @@ int main(void) {
  // from source to destination.
  char string3[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  // Copies 7 charactes from "EE+CPE!" to string3.
  strncpy(string3, "EE+CPE!", 7);
  strncpy(string3, "EE+CPE!", 9); //FIX: make n = size of string3 - 1 (9)
  // optional space for you to use

  // Look at your kit before and after stepping over this line
@ -140,7 +140,7 @@ int main(void) {
}

/*******************************************************************
 * NAME :            make_date_string(int month, int day, int year, unsigned char *string)
 * NAME :  COLIN EDSALL    make_date_string(int month, int day, int year, unsigned char *string)
 *
 * DESCRIPTION :     Creates a string from three numbers to represent date in
 * months, days, and years
@ -174,6 +174,11 @@ int main(void) {
void make_date_string(int month, int day, int year, unsigned char *string) {
  // TODO: Write this function according to the above specification and the
  // description in the homework assignment.
    snprintf((char *)string, 11, "%02d/%02d/%04d", month, day, year);
    //uses snprintf with typcast for string (character array)
    //size is 11 as described in homework
    //casts the digits and the slashes, the inserts month, day, and year
    //if the month/day/year isn't exactly 2, 2, or 4 digits, fills zero
}

/*
