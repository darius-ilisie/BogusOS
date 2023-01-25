#include <stdint.h>

#include <include/stdio.h>

typedef struct {
  uint16_t baseLow;
  uint16_t segmentSelector;
  uint8_t ist;
  uint8_t flags;
  uint16_t baseMiddle;
  uint32_t baseHigh;
  uint32_t zero;
} IDTEntry;

typedef struct {
  uint16_t limit;
  IDTEntry *ptr;
} IDTDescriptor;

volatile IDTEntry IDT[256];
volatile IDTDescriptor IDTDesc = {sizeof(IDT) - 1, IDT};

void setGateIDT(int interupt, void* base, uint16_t segDesc, uint8_t flags, uint8_t ist) {
    IDT[interupt].baseLow = ((uint64_t) base) & 0xFFFF;
    IDT[interupt].baseMiddle = ((uint64_t) base >> 16) & 0xFFFF;
    IDT[interupt].baseHigh = ((uint64_t) base >> 32) & 0xFFFFFFFF;

    IDT[interupt].zero = 0;
    IDT[interupt].segmentSelector = segDesc;
    IDT[interupt].flags = flags;
    IDT[interupt].ist = ist;
}

void initIDT() {
    //__asm__ ("lidt %0" : : "m" (IDTDesc));

    printf("%d -- %d", IDTDesc, &IDTDesc);
}