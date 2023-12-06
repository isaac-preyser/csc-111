/* temperature_data.c


   B. Bird - 2023-11-06
*/

#include <stdio.h>
#include "temperature_data.h"

/* Do not copy the typedef statements for the structure types into this file
   (they should only be in the .h file)
*/


/* read_observation(input_file, obs)
   Given a file object input_file and a pointer obs to an Observation 
   structure, try to read a single observation from the file into the structure
   pointed to by obs. If the complete observation is read successfully, return 1.
   Otherwise, return 0.

   Parameters: input_file (FILE pointer), obs (pointer to Observation object)
   Return value (integer):
     - If the observation was read successfully, return 1
     - Otherwise, return 0
*/
int read_observation(FILE* input_file, Observation* obs){
    /* Your code here */
    //printf("Attempting to read observation\n");
    //lets try to scanf the first observation, and if it fails return 0. else return 1
      if (fscanf(input_file, "%d %d %d %d %d %d %lf", &obs->obs_date.year, &obs->obs_date.month, &obs->obs_date.day, &obs->hour, &obs->minute, &obs->station_id, &obs->temperature) == 7){
       //  printf("Read: Year: %d Month: %d Day: %d Hour: %d Minute: %d Station ID: %d Temperature: %lf\n", obs->obs_date.year, obs->obs_date.month, obs->obs_date.day, obs->hour, obs->minute, obs->station_id, obs->temperature);
         return 1;
      } else{
      //   printf("Failed to read full observation\n");
         return 0;
      }
    
}


/* count_observations(filename)
   Given a filename, count and return the number of temperature observations in
   the file. If the file cannot be opened, return -1.

   Parameters: filename (string)
   Return value (integer):
     - If the file cannot be opened for reading, return -1
     - Otherwise, return the number of temperature observations in the file.
*/
int count_observations(char filename[]){
    /* Your code here */
    if (fopen(filename, "r") == NULL){
        return -1;
    } else{
        FILE* input_file = fopen(filename, "r");
        int count = 0;
        Observation obs;
        while (read_observation(input_file, &obs) == 1){
            count++;
        }
        if (fclose(input_file) != 0) {
            //printf("Error: Unable to close the file.\n");
         } else {
            //printf("File closed successfully.\n");
         }
        return count;
    }
}

/* load_all_observations(filename, array_size, observation_array)
   Given a filename and an array of Observation objects, read as many 
   observations from the file as possible (up to the size of the array)
   and store each observation (in order) into the array.

   If the file cannot be opened, return -1. Otherwise, return the number of 
   observations read.

   If the file contains fewer observations then there are elements in the array,
   stop reading after the last observation in the file. Otherwise, stop reading
   once array_size observations are read.

   Parameters: filename (string), array_size (integer), observation_array (array of Observation)
   Return value (integer):
     - If the file could not be opened, return -1
     - Otherwise, return the total number of observations read and stored into 
       the array.
*/
int load_all_observations(char filename[], int array_size, Observation observation_array[array_size]){
    /* Your code here */
      if (fopen(filename, "r") == NULL){
         //we failed to open the file
         return -1;
      } else{
         FILE* input_file = fopen(filename, "r");
         int count = 0;
         Observation obs;
         for (int i = 0; i < array_size; i++){
            if (read_observation(input_file, &obs) == 1){
               observation_array[i] = obs;
               count++;
            } else{
               break;
            }
         }
         if (fclose(input_file) != 0) {
            //printf("Error: Unable to close the file.\n");
         } else {
            //printf("File closed successfully.\n");
         }
         return count;
      }
}




/* print_station_extremes(num_observations, obs_array)
   Given an array of Observation objects, compute and print the
    _extreme observations_ (lowest temperature observed and highest
   temperature observed) for each station that has at least one
   observation in the dataset.

   The output will contain one line for each station with at least one 
   observation in the dataset, using a format equivalent to the following:
      Station 1: Minimum = -1.87 degrees (2023-11-21 06:10), Maximum = 10.6 degrees (2023-01-11 01:16)

   You should use the following printf format string to achieve the correct 
   output format.
      "Station %d: Minimum = %.2f degrees (%04d-%02d-%02d %02d:%02d), Maximum = %.2f degrees (%04d-%02d-%02d %02d:%02d)\n"
 
   The output must be ordered by station number (with lower numbered station 
   numbers appearing first). No more than one line of output should be 
   generated for a particular station number.

   In cases where multiple observations achieve the extreme value (e.g. if the
   minimum temperature at a particular station is -1.87, but there are several 
   observations with this temperature), print the date/time of the 
   chronologically earliest observation with that extreme temperature.

   You may assume that all observations contain a station number between 
   1 and 250 (inclusive).

   This function must _not_ use any file I/O features whatsoever.

   Parameters: num_observations (integer), observation_array (array of Observation)
   Return value: None
   Side Effect: A printed representation of station extremes is output to the user.
*/


void print_station_extremes(int num_observations, Observation obs_array[num_observations]){
   Observation null_obs = {{0, 0, 0}, 0, 0, 0, 0.0};
   Observation min_obs = null_obs;
   Observation max_obs = null_obs; 
   int completed_stations[num_observations];
   //sort the observation_array by station_id, so the outputs will be in order.
   for (int i = 0; i < num_observations; i++){
      for (int j = 0; j < num_observations; j++){
         if (obs_array[i].station_id < obs_array[j].station_id){
            Observation temp = obs_array[i];
            obs_array[i] = obs_array[j];
            obs_array[j] = temp;
         }
      }
   }
   
   for (int i = 0; i < num_observations; i++){
      completed_stations[i] = 255; //255 is NOT within the allowable range, and therefore no stations can be equal to it. 
   } 
   int completed_index = 0; //might need to be zero

   for (int i = 0; i < num_observations; i++){
    //if the current station_id is within our completed_stations array, continue; the for loop, skipping that data entry. 
    
      int station_id = obs_array[i].station_id;
      int station_completed = 0;
      for (int j = 0; j < completed_index; j++){
         if (completed_stations[j] == station_id){
            station_completed = 1;
            break;
         }
      }
      if (station_completed == 1){
         continue;
      }
      //if the current station_id is not within our completed_stations array, add it to the array. 
      completed_stations[completed_index] = station_id;
      completed_index++;
      max_obs = obs_array[i];
      min_obs = obs_array[i];
      //now we have the first observation for the current station_id. lets find the min and max for that station_id. 
      for (int j = i; j < num_observations; j++){
         if (obs_array[j].station_id == station_id){
            if (obs_array[j].temperature < min_obs.temperature){
               min_obs = obs_array[j];
            }
            if (obs_array[j].temperature > max_obs.temperature){
               max_obs = obs_array[j];
            }
            //if the temp is equal, check if the date is earlier, and if it is, set the date to the earlier one.
            if (obs_array[j].temperature == min_obs.temperature){
               if (obs_array[j].obs_date.year < min_obs.obs_date.year){
                  min_obs = obs_array[j];
               } else if (obs_array[j].obs_date.year == min_obs.obs_date.year){
                  if (obs_array[j].obs_date.month < min_obs.obs_date.month){
                     min_obs = obs_array[j];
                  } else if (obs_array[j].obs_date.month == min_obs.obs_date.month){
                     if (obs_array[j].obs_date.day < min_obs.obs_date.day){
                        min_obs = obs_array[j];
                     } else if (obs_array[j].obs_date.day == min_obs.obs_date.day){
                        if (obs_array[j].hour < min_obs.hour){
                           min_obs = obs_array[j];
                        } else if (obs_array[j].hour == min_obs.hour){
                           if (obs_array[j].minute < min_obs.minute){
                              min_obs = obs_array[j];
                           }
                        }
                     }
                  }
               }
            }
            //we must do this again for the max_obs, because we want the earliest date for the max_obs as well.
            if (obs_array[j].temperature == max_obs.temperature){
               if (obs_array[j].obs_date.year < max_obs.obs_date.year){
                  max_obs = obs_array[j];
               } else if (obs_array[j].obs_date.year == max_obs.obs_date.year){
                  if (obs_array[j].obs_date.month < max_obs.obs_date.month){
                     max_obs = obs_array[j];
                  } else if (obs_array[j].obs_date.month == max_obs.obs_date.month){
                     if (obs_array[j].obs_date.day < max_obs.obs_date.day){
                        max_obs = obs_array[j];
                     } else if (obs_array[j].obs_date.day == max_obs.obs_date.day){
                        if (obs_array[j].hour < max_obs.hour){
                           max_obs = obs_array[j];
                        } else if (obs_array[j].hour == max_obs.hour){
                           if (obs_array[j].minute < max_obs.minute){
                              max_obs = obs_array[j];
                           }
                        }
                     }
                  }
               }
            }
         }
      }
     
      //now we have the min and max for the current station_id. lets print it out.
      printf("Station %d: Minimum = %.2f degrees (%04d-%02d-%02d %02d:%02d), Maximum = %.2f degrees (%04d-%02d-%02d %02d:%02d)\n", station_id, min_obs.temperature, min_obs.obs_date.year, min_obs.obs_date.month, min_obs.obs_date.day, min_obs.hour, min_obs.minute, max_obs.temperature, max_obs.obs_date.year, max_obs.obs_date.month, max_obs.obs_date.day, max_obs.hour, max_obs.minute);
      
  
   }
}

/* print_daily_averages(num_observations, obs_array)
   Given an array of observation objects, compute and print the average 
   temperature for each day which has at least one observation in the 
   dataset.

   The output must contain only dates which actually appear in at least 
   one observation object in the array. The dates must be in ascending 
   chronological order (so an earlier date must be printed before a later 
   one) and each date may only appear once.

   Each line of output will have the form "year month day average", for 
   example "2023 11 20 10.6" (which would be interpreted to mean that 
   the average temperature on Nov. 21, 2023 was 10.6 degrees).

   Your code may assume that all dates are from years between 2015 and 2023 
   (inclusive) and that the month/day entries are all valid (that is, month
   will always be between 1 and 12 inclusive and day will always be between
   1 and 31 inclusive).
   
   This function must _not_ use any file I/O features whatsoever.

   Parameters: num_observations (integer), observation_array (array of Observation)
   Return value: None
   Side Effect: A printed representation of the average daily temperature is
                output to the user.
*/
typedef struct{
   Date date;
   int count; //total of how many observations there are for this day. 
   double total_temperature;
} Average;

void print_daily_averages(int num_observations, Observation obs_array[num_observations]){
    /* Your code here */
   //sort the observations by date, from earliest to latest.
   for (int i = 0; i < num_observations; i++){
      for (int j = 0; j < num_observations; j++){
         if (obs_array[i].obs_date.year < obs_array[j].obs_date.year){
            Observation temp = obs_array[i];
            obs_array[i] = obs_array[j];
            obs_array[j] = temp;
         } else if (obs_array[i].obs_date.year == obs_array[j].obs_date.year){
            if (obs_array[i].obs_date.month < obs_array[j].obs_date.month){
               Observation temp = obs_array[i];
               obs_array[i] = obs_array[j];
               obs_array[j] = temp;
            } else if (obs_array[i].obs_date.month == obs_array[j].obs_date.month){
               if (obs_array[i].obs_date.day < obs_array[j].obs_date.day){
                  Observation temp = obs_array[i];
                  obs_array[i] = obs_array[j];
                  obs_array[j] = temp;
               }
            }
         }
      }
   }
   //find the average temperature for each day.
   Average averages[num_observations];
   int averages_index = 0;
   for (int i = 0; i < num_observations; i++){
      int date_found = 0;
      for (int j = 0; j < averages_index; j++){
         if (obs_array[i].obs_date.year == averages[j].date.year && obs_array[i].obs_date.month == averages[j].date.month && obs_array[i].obs_date.day == averages[j].date.day){
            averages[j].count++;
            averages[j].total_temperature += obs_array[i].temperature;
            date_found = 1;
            break;
         }
      }
      if (date_found == 0){
         Average new_average;
         new_average.date = obs_array[i].obs_date;
         new_average.count = 1;
         new_average.total_temperature = obs_array[i].temperature;
         averages[averages_index] = new_average;
         averages_index++;
      }
   }
   //print the averages.
   for (int i = 0; i < averages_index; i++){
      double average = averages[i].total_temperature / averages[i].count;
      printf("%04d %d %d %.1f\n", averages[i].date.year, averages[i].date.month, averages[i].date.day, average);
   }

  
}