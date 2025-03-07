#ifndef ONEBITADDER_H
#define ONEBITADDER_H

#include <systemc.h>

SC_MODULE(OneBitAdder){
    sc_in<sc_logic> a;
    sc_in<sc_logic> b;
    sc_in<sc_logic> cin;
    sc_out<sc_logic> sum;
    sc_out<sc_logic> cout;

    void process();
    
    void print();

    SC_CTOR(OneBitAdder){
        SC_METHOD(process);
        sensitive << a << b << cin;
    }
};
#endif