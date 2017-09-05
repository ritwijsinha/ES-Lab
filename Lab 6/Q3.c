#include <LPC17xx.h>
unsigned int i,j;
unsigned long LED = 0x00000010;

int main()
{
	SystemInit();
	SystemCoreClockUpdate();

	LPC_PINCON->PINSEL0 = 0;
	LPC_GPIO0->FIODIR = 0x00000FF0;

	while(1){
		if(!(LPC_GPIO2->FIOPIN & (1<<12))){
			LED = 0x00000800;
		for(i=1;i<9;i++)
		{
			LPC_GPIO0->FIOPIN = LED;
			for(j=0;j<6000;j++);
				LED>>=1;
		}
			
		
	}
	else
	{
	LED = 0x00000010;
		for(i=1;i<9;i++)
		{
			LPC_GPIO0->FIOPIN = LED;
			for(j=0;j<6000;j++);
				LED<<=1;
		}
	}

	}

		
}