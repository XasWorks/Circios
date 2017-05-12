
#if defined(__AVR_328P_)
#else
#error "Sorry, this Chip-Type isn't supported yet!"
#endif

#ifndef __HAMSTER_H
#define HAMSTER_H

void vor(unsigned byte n);
void linksUm();
void rechtsUm();

#endif
