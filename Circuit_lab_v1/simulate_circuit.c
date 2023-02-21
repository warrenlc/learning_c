#include <stdio.h>

#include "simulate_circuit.h"
#include "components.h"

void 
run_simulation_1(int run_iter, int print_iter, double time_interval, double battery_charge)
{
/*
 * Dynamically allocate space for our connection pointers
 * */

    Connection* p    = malloc(sizeof(double));
    Connection* n    = malloc(sizeof(double));
    Connection* r124 = malloc(sizeof(double));
    Connection* r23  = malloc(sizeof(double)); 
/*
 * Initialize values of the connections
 * */
    p->volts = 0.0; 
    n->volts = 0.0;
    r124->volts = 0.0;
    r23->volts  = 0.0;

    /*
     * Every component has a name, 2 connections and a current.
     * Each one also has a UNIQUE VALUE depending on its component type: 
     *       Battery   -> Charge
     *       Resistor  -> Ohm
     *       Capacitor -> Farad
     * */    

 // Components       NAME  CONN  CONN   UNIQUE VAL     CURRENT 
    Battery  b1 = { "b1", p,    n,     battery_charge,   0 };
    Resistor r1 = { "r1", p,    r124,  6.0,              0 };
    Resistor r2 = { "r2", r124, r23,   4.0,              0 };
    Resistor r3 = { "r3", r23,  n,     8.0,              0 };
    Resistor r4 = { "r4", r124, n,    12.0,              0 };

    printf("             b1             r1            r2            r3             r4\n");
    printf("    volt   curr    volt   curr   volt   curr   volt   curr     volt  curr\n");
    for (int i = 1; i <= run_iter; ++i)
    {
        battery_update(&b1);
        resistor_update(&r1, time_interval);
        resistor_update(&r2, time_interval);
        resistor_update(&r3, time_interval);
        resistor_update(&r4, time_interval);

        if (i % (run_iter / print_iter) == 0) 
        {
            battery_print(&b1);
            resistor_print(&r1);
            resistor_print(&r2);
            resistor_print(&r3);
            resistor_print(&r4);
            printf("\n");
        }
    }
    printf("\n");

    /*
     * free the allocated memory
     * */
    free(p);
    free(n);
    free(r124);
    free(r23);
}

void 
run_simulation_2(int run_iter, int print_iter, double time_interval, double battery_charge)
{
    Connection* p = malloc(sizeof(double));
    Connection* r = malloc(sizeof(double));
    Connection* n = malloc(sizeof(double));
    Connection* l = malloc(sizeof(double));

    p->volts = 0;
    r->volts = 0;
    n->volts = 0;
    l->volts = 0;


 // Components       NAME  CONN  CONN   UNIQUE VAL     CURRENT 
    Battery  b1 = { "b1", p,    n,      battery_charge,   0 };
    Resistor r1 = { "r1", p,    l,      150,              0 };
    Resistor r2 = { "r2", p,    r,       50,              0 };
    Resistor r3 = { "r3", r,    l,      100,              0 };
    Resistor r4 = { "r4", l,    n,      300,              0 };
    Resistor r5 = { "r5", n,    r,      250,              0 };


    printf("             b1             r1            r2            r3             r4            r5\n");
    printf("    volt   curr    volt   curr   volt   curr   volt   curr     volt  curr    volt  curr\n");
    for (int i = 1; i <= run_iter; ++i)
    {
        battery_update(&b1);
        resistor_update(&r1, time_interval);
        resistor_update(&r2, time_interval);
        resistor_update(&r3, time_interval);
        resistor_update(&r4, time_interval);
        resistor_update(&r5, time_interval);

        if (i % (run_iter / print_iter) == 0) 
        {
            battery_print(&b1);
            resistor_print(&r1);
            resistor_print(&r2);
            resistor_print(&r3);
            resistor_print(&r4);
            resistor_print(&r5); 
            printf("\n");
        }
    }
    printf("\n");

    /*
     * free the allocated memory
     * */
    free(p);
    free(r);
    free(n);
    free(l);
}

void 
run_simulation_3(int run_iter, int print_iter, double time_interval, double battery_charge)
{
    Connection* p = malloc(sizeof(double));
    Connection* r = malloc(sizeof(double));
    Connection* n = malloc(sizeof(double));
    Connection* l = malloc(sizeof(double));

    p->volts = 0;
    r->volts = 0;
    n->volts = 0;
    l->volts = 0;


 // Components        NAME  CONN  CONN    UNIQUE VAL     CURRENT 
    Battery   b1 =  { "b1", p,    n,      battery_charge,   0 };
    Resistor  r1 =  { "r1", p,    l,      150,              0 };
    Resistor  r2 =  { "r2", p,    r,      50,               0 };
    Capacitor c3 =  { "c3", l,    r,      1.0,              0 };
    Resistor  r4 =  { "r4", l,    n,      300,              0 };
    Capacitor c5 =  { "r5", n,    r,      0.75,             0 };


    printf("             b1             r1            r2            c3             r4            c5\n");
    printf("    volt   curr    volt   curr   volt   curr   volt   curr     volt  curr    volt  curr\n");
    for (int i = 1; i <= run_iter; ++i)
    {
        battery_update(&b1);
        resistor_update(&r1, time_interval);
        resistor_update(&r2, time_interval);
        capacitor_update(&c3, time_interval);
        resistor_update(&r4, time_interval);
        capacitor_update(&c5, time_interval);

        if (i % (run_iter / print_iter) == 0) 
        {
            battery_print(&b1);
            resistor_print(&r1);
            resistor_print(&r2);
            capacitor_print(&c3);
            resistor_print(&r4);
            capacitor_print(&c5); 
            printf("\n");
        }
    }
    printf("\n");

    /*
     * free the allocated memory
     * */
    free(p);
    free(r);
    free(n);
    free(l);
}
