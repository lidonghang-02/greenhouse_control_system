#ifndef __UPDATE_H_
#define __UPDATE_H_
#include "window.h"
#include "stdint.h"

void update_threshold(int flag);
void update_status(int flag);


void update_data_threshold(struct threshold *value,int flag,int *save);
void update_data_status(uint8_t *Light_status,uint8_t *Water_status,uint8_t *Ven_status,int flag);




#endif
