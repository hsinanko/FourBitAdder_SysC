#ifndef FOURBITADDER_H
#define FOURBITADDER_H

#include <systemc.h>
#include "OneBitAdder.h"

static const int NUM_MODULES = 4;

SC_MODULE(FourBitAdder){
    // define input and output port
    sc_in< sc_logic > A[NUM_MODULES];
    sc_in< sc_logic > B[NUM_MODULES];
    sc_in< sc_logic > C_in;
    sc_out< sc_logic > SUM[NUM_MODULES];
    sc_out< sc_logic > C_out;

    // instantiate 4 1-bit-full-adder
    OneBitAdder* FourAdder[NUM_MODULES];
    // carry-in from each level
    sc_signal< sc_logic > C[NUM_MODULES];

    // constructor
    SC_CTOR(FourBitAdder){

        for(int i = 0; i < NUM_MODULES; i++){
            // connecting port from least significant to most significant
            FourAdder[i] = new OneBitAdder(sc_gen_unique_name("FourBitAdder"));
            FourAdder[i]->a(A[i]);
            FourAdder[i]->b(B[i]);
            FourAdder[i]->sum(SUM[i]);

            // select the correct carry-in to do full-adder
            if(i == 0) FourAdder[i]->cin(C_in);
            else FourAdder[i]->cin(C[i-1]);

            /*
            !!Notic!! one signal can only drive on one port (signal).
            Therefore, just the last carry-in connect to the carry-out
            */
            if( i ==  3) FourAdder[i]->cout(C_out);
            else FourAdder[i]->cout(C[i]);
        }
    }

    // destructor
    ~FourBitAdder(){
        for(int i = 0; i < NUM_MODULES; i++){
            delete FourAdder[i];
        }
    }
};

#endif