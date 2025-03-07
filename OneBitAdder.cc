#include "OneBitAdder.h"

void OneBitAdder::process(){
    // full adder operaton
    sum.write( a.read() ^ b.read() ^ cin.read() );
    cout.write( ((a.read() ^ b.read()) & cin) | (a.read() & b.read()) );
}
