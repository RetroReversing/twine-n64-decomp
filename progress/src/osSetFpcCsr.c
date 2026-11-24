/* Writes the FPU control/status register and returns its previous value. */ unsigned int osSetFpcCsr(unsigned int newCsr) { return __builtin_mips_exchange_fcsr(newCsr); }
