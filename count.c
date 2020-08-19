#include "count.h"
#include "ssd.h"
#include "push_button.h"

static unsigned int counter;

void CNT_Init(unsigned int initial_count)
{
    counter = initial_count;
}

void CNT_Update(void)
{
    /* Get buttons state */
    if (PB_GetState(PB_RESET) == PB_PRE_RELEASED)
    {
        counter = 0;
    }
    else if (PB_GetState(PB_PLUS) == PB_PRE_PRESSED)
    {
        if (counter < 9999)
        {
            counter++;
        }
    }
    else if (PB_GetState(PB_MINUS) == PB_PRE_PRESSED)
    {
        if (counter > 0)
        {
            counter--;
        }
    }
    /* Set SSD symbols */
    SSD_SetSymbol(SSD_L, counter/1000);
    SSD_SetSymbol(SSD_M, (counter%1000)/100);
    SSD_SetSymbol(SSD_N, ((counter%1000)%100)/10);
    SSD_SetSymbol(SSD_R, counter %10);
}
