#include <string.h>
#include <stdlib.h>

// Components for simple circuit simulation

// Connection
typedef struct {
    double volts;
}Connection;

// Battery
typedef struct {
    char name[10];
    Connection* in;
    Connection* out;
    double volt;
    double current;
}Battery; 

// Resistor
typedef struct {
    char name[10];
    Connection* in;
    Connection* out;
    double ohm;
    double current;
}Resistor;

// Capacitor
typedef struct {
    char name[10];
    Connection* in;
    Connection* out;
    double farad;
    double storage;
}Capacitor;

// Function declarations for components

// Battery
void battery_print(Battery *b);
void battery_update(Battery *b);
// Resistor
void resistor_print(Resistor *r);
void resistor_update(Resistor *r, double time);
double resistor_get_voltage(Resistor *r);
double resistor_get_current(Resistor *r);

// Capacitor
void capacitor_print(Capacitor *c);
void capacitor_update(Capacitor *c, double time);
double capacitor_get_voltage(Capacitor *c);
double capacitor_get_current(Capacitor *c);
