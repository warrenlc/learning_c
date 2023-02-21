#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "components.h"
#include "simulate_circuit.h"


int main(int argc, char* argv[]) 
{
    /*
     * Check command line arguments
     * */

    int run_iterations = 0;
    int print_iterations = 0;
    double time_interval = 0;
    double battery_charge = 0;
    char *usage = "USAGE:\n<./a.out> <RUN_ITERATIONS(int)> <PRINT_ITERATIONS(int)> <TIME_INTERVAL(double)> <BATTERY_CHARGE(double)>";
    
    if ( argc != 5 )
    {
        fprintf(stderr, "Wrong number of arguments!\n%s\n", usage);
        return 1;
    }
    
    for ( int i = 1; i < argc; i++ )
    {
        if ( atol(argv[i]) < 0 )
        {
            fprintf(stderr, "Values must be non-negative!\n%s\n", usage);
            return 1;
        }
        
        if ( !isdigit(*argv[i]) )
        {
            fprintf(stderr, "Values must be either int or double!\n%s\n", usage);
            return 1;
        }
    }
    
    /*
     * Convert argv[] values to either int or double.
     * */
    run_iterations = atoi(argv[1]);
    print_iterations = atoi(argv[2]);
    time_interval = atof(argv[3]);
    battery_charge = atof(argv[4]); 

    run_simulation_1(run_iterations, print_iterations, time_interval, battery_charge);
    run_simulation_2(run_iterations, print_iterations, time_interval, battery_charge);
    run_simulation_3(run_iterations, print_iterations, time_interval, battery_charge);

    return 0;
}

