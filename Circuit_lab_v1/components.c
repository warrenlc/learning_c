#include <stdio.h>
#include <math.h>

#include "components.h"

// Function definitions for components

// Battery
void 
battery_print(Battery *b)
{
    printf(" : %.2f : %.2f", b->volt, b->current);
}

void 
battery_update(Battery *b)
{
    b->in->volts = b->volt;
    b->out->volts = 0.0;
}

// Resistor
void 
resistor_print(Resistor* r)
{
    printf(" : %.2f : %.2f", resistor_get_voltage(r), r->current);
}

void 
resistor_update(Resistor *r, double time)
{
    double diff = fabs(r->in->volts - r->out->volts);
    double volts_to_move = (diff / r->ohm) * time;
    if (r->in->volts > r->out->volts)
    {
        r->in->volts  -= volts_to_move;
        r->out->volts += volts_to_move;
    } 
    else
    {
        r->out->volts -= volts_to_move;
        r->in->volts  += volts_to_move;
    }
    r->current = resistor_get_current(r);
}

double 
resistor_get_voltage(Resistor *r)
{
    return fabs( r->in->volts - r->out->volts );
}

double 
resistor_get_current(Resistor *r)
{
    return ( resistor_get_voltage(r) / r->ohm ); 
}

// Capacitor
void 
capacitor_print(Capacitor *c)
{
    printf(" : %.2f : %.2f", capacitor_get_voltage(c), capacitor_get_current(c));
}

void 
capacitor_update(Capacitor *c, double time)
{
    double diff = fabs(c->in->volts -c->out->volts);
    double volts_to_move = c->farad * ( diff - c->storage ) * time;
    if (c->in->volts > c->out->volts)
    {
        c->in->volts  -= volts_to_move;
        c->out->volts += volts_to_move;
    }
    else
    {
        c->in->volts  += volts_to_move;
        c->out->volts -= volts_to_move;
    }
    c->storage += volts_to_move;
}

double 
capacitor_get_voltage(Capacitor *c)
{
    return fabs(c->in->volts - c->out->volts);
}

double 
capacitor_get_current(Capacitor *c)
{
    return c->farad * fabs(capacitor_get_voltage(c) - c->storage);
}


