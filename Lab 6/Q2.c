#include <LPC17xx.h>
unsigned int i,j;
unsigned long LED = 0x00000FF0;

int main()
{
	SystemInit();
	SystemCoreClockUpdate();

	LPC_PINCON->PINSEL0 = 0;
	LPC_GPIO0->FIODIR = 0x00000FF0;

	while(1){
		if(!(LPC_GPIO2->FIOPIN & (1<<12))){
		//LED = 0x00000010;
		for(i=1;i<257;i++)
		{
			LPC_GPIO0->FIOPIN = LED;
			for(j=0;j<100000;j++);
				LED=LED+0x00000010;
		}
	}
	else{	
	//LED = 0x00000FF0;
		for(i=1;i<257;i++)
		{
			LPC_GPIO0->FIOPIN = LED;
			for(j=0;j<100000;j++);
				LED=LED-0x00000010;
		}
	}

	}

		
}