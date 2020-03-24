/*
 * macros.h
 *
 * Created: 3/22/2020 4:49:16 PM
 *  Author: AbdElrahman
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define SetBit(var, bit) var |= (1<<bit)
#define ClrBit(var, bit) var &= (~(1<<bit))
#define TogBit(var, bit) var ^= (1<<bit)

#define GetBit(Var, BitNo) ((Var & (1<<BitNo)) >> BitNo)

#define HoldHighNibble(hVar,var) hVar= (var & 0xf0)    // hVar will hold value of high nibble of var
#define HoldLowNibble(lVar,var) lVar= (var<<4)        // lVar will hold the value of low nibble of var





#endif /* MACROS_H_ */