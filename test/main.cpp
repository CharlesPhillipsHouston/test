//  main.cpp
//  test
//
//  Created by Charles Phillips on 2/11/22.
//  based on

#include <stdio.h> // standard input, output
#include <string.h> //
#include <math.h> //
#include <stdlib.h> //
#include <fstream> //

#include <cstdlib>  // for atof - needed?
#include <ctype.h>  // for isdigit
// #include "date.h"   // for Date, Locate
#define OBSERVATION_LINE_LENGTH 80

using namespace std;

/* dimensions & gravity of earth, World Geodetic System 1972 values */

const double
de2ra = .0174532925199433,
tu = .0093380977083333,   // time unit in days ~ 13 minutes
pi = 3.14159265358979323846,
xj3 = -2.53881E-6,
ck2 = 5.413079E-4,
xke = 7.43669161E-2;   /* = (G*M)^(1/2)*(er/min)^(3/2) where G =
                               Newton's grav const, M = earth mass */

///////////// declare global variables ////////////////////////////////////////
double la, lo, hh; // latitude, longitude, height of observer
int nobs=3; // number of observations (always 3)
double rr2[3], vv2[3];  // position and velocity vector probably

// set up "Observation"
class OBSERVATION // this is an observation, duh read from iod_line
{
public:
    char iod_line[OBSERVATION_LINE_LENGTH];  // line is one observation line
    int ssn;  // satellite number
    int yr; // year
   
    char desig[7] = "/0/0/0"; // international designator (COSPAR)
    int station = 9999;  // default station number. Normally will be 3981 or 3982
    char condition[1]; // site condition, normally G as is good
    int year; // year
    int month;
    int day;
    int hour;
    int min;
    int sec; // seconds
    int uncertainty; // time uncertainty, ignore
    int format; // time format
    int code; // epoch code (year of epoch)
    float ra; // right ascension hours (first two digits of RA)
    float mm; // right ascension minutes (second two digits of RA)
    float ss; // right ascension seconds

    char sn; // sign of declination + or -
    float dc; // first two numbers of declination
    float dd; // second two numbers
    char dbuf; // some buffer for third two numbers?
    
    // there are two more fields that we can ignore - positional uncertainty and optical behavior

/*
OBSERVATION(){}; // empty constructor, was Tle now OBSERVATION

   OBSERVATION(char * iod)  //
   {
    strncpy(iod_line, iod, sizeof(iod_line));
       // ssn is number of satellite
    
    //   scan the observation and put it into usable pieces
       sscanf(iod_line, "%d %d %4s %d %1s",
           //   %3s %2d%f %f %s %s %d %4d",
              &ssn,
              &yr,
              &desig,
              &station,
              &condition
              
             // will have to add a comma here &year,
            //  &month, &day,
            //  &hour,
            //  &min,
            //  &sec,  // seconds
            //  &uncertainty,  // not really used
            //  &format
          //   &code
              ); // epoch code or year
   
   }  // end  definition
 */
    
}; // end of observation definition


int main()
{

   FILE* spInputObs;  // a file of all the observations
    FILE* spOutput; // duh
       
   //    FILE* spOutput; // output points to file to write calculate results to
    
    char iod_line[OBSERVATION_LINE_LENGTH];  // line is one observation line

    spInputObs = fopen("/Users/Charles/Desktop/common_files/iod_input.txt", "r");
    spOutput = fopen("/Users/Charles/Desktop/common_files/iod_output.txt", "w");
     
  //  OBSERVATION track[3];  // type OBSERVATION gives us a track of 3 IOD lines??
    
    int i = 0;  // this should read three observations
       while (feof(spInputObs) == 0) // read in all observations
       {
           // either of the next two lines will work so I duplicated something
     //   fgets(iod_line, sizeof(iod_line), spInputObs);  // get first line of observation

    fgets(iod_line, OBSERVATION_LINE_LENGTH, spInputObs);  // get first line of observation
                    // scan the observation and put it into usable pieces
                         
    sscanf(iod_line, "%d %d %4s %d %1s",
                             //   %3s %2d%f %f %s %s %d %4d",
                  &OBSERVATION::ssn,
                  &OBSERVATION::yr,
                  &OBSERVATION::desig,
                    &OBSERVATION::station,
                  &OBSERVATION::condition
                          // OBSERVATION:: requested by XCode
                  
                               // will have to add a comma here &year,
                              //  &month, &day,
                              //  &hour,
                              //  &min,
                              //  &sec,  // seconds
                              //  &uncertainty,  // not really used
                              //  &format
                              //  &code
                                ); // epoch code or year
        fprintf(spOutput, "%s\n",iod_line);
    
        i++ ;   // increment i
       }  // end of while loop, reads observations
     
  
    fclose(spInputObs);
   fclose(spOutput);
    
    return 0;
}
