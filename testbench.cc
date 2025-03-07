#include "sysc/datatypes/bit/sc_logic.h"
#include <systemc.h>
#include "FourBitAdder.h"


SC_MODULE(testbench){
    sc_signal< sc_logic > A_sig[4], B_sig[4];
    sc_signal< sc_logic > Cin_sig, Cout_sig;
    sc_signal< sc_logic > SUM_sig[4];

    FourBitAdder *adder;
    void test() {
        A_sig[0].write(SC_LOGIC_0);
        A_sig[1].write(SC_LOGIC_0);
        A_sig[2].write(SC_LOGIC_1);
        A_sig[3].write(SC_LOGIC_0);

        B_sig[0].write(SC_LOGIC_1);
        B_sig[1].write(SC_LOGIC_0);
        B_sig[2].write(SC_LOGIC_0);
        B_sig[3].write(SC_LOGIC_1);

        Cin_sig.write(SC_LOGIC_1);

        wait(5, SC_NS);
        cout << "A: " << A_sig[3].read() << A_sig[2].read() <<  A_sig[1].read() <<  A_sig[0].read()
             << " B: "<< B_sig[3].read() << B_sig[2].read() << B_sig[1].read() << B_sig[0].read()
             << " Cin: " << Cin_sig.read()
             << " Sum: " << SUM_sig[3].read() << SUM_sig[2].read() << SUM_sig[1].read() << SUM_sig[0].read() 
             << " Cout: " << Cout_sig.read() << endl;
        
        sc_stop();
    }

    SC_CTOR(testbench) {
        adder = new FourBitAdder("FourBitAdder");

        adder->A[0](A_sig[0]);
        adder->A[1](A_sig[1]);
        adder->A[2](A_sig[2]);
        adder->A[3](A_sig[3]);

        adder->B[0](B_sig[0]);
        adder->B[1](B_sig[1]);
        adder->B[2](B_sig[2]);
        adder->B[3](B_sig[3]);

        adder->C_in(Cin_sig);

        adder->SUM[0](SUM_sig[0]);
        adder->SUM[1](SUM_sig[1]);
        adder->SUM[2](SUM_sig[2]);
        adder->SUM[3](SUM_sig[3]);

        adder->C_out(Cout_sig);
        
        SC_THREAD(test);
    }
    
    ~testbench() {
        delete adder;
    }
};

int sc_main(int argc, char* argv[]) {
    testbench tb("tb");
    sc_start();
    return 0;
}