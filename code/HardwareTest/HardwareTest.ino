/************************************************************************************/
/* Arduino Script for testing Seeed Studio XIAO ESP32-C3 Module								*/
/*																					*/
/* RISC-V CPU, 4MB Flash memory, 400 KB SRAM.		*/
/*																					*/
/* Developed at:																	*/
/* Laboratory of Electronics and Instrumentation,									*/
/* Portalegre Polytechnic University, Portalegre, Portugal							*/
/*																					*/
/* @author Prof. Sergio D. Correia													*/
/* @date July, 2023																	*/
/* @version 0.0																		*/
/* @file HardwareTest.ino															*/
/* @see https://sites.google.com/ipportalegre.pt/scorreia/home						*/
/*																					*/
/************************************************************************************/

#define SerialDEBUG		Serial
#define UART_BAUD     115200
#define MAXNUM        1000000

unsigned long start, t;
unsigned long i = 2;

void setup() {

  SerialDEBUG.begin(UART_BAUD);

	// Model Information
	SerialDEBUG.println();
	SerialDEBUG.println("====================================================");
	SerialDEBUG.println("***                   ESP32-C3                   ***");
	SerialDEBUG.printf("*** ESP32 Model %s with %dx cores at %dMHz ***\n",ESP.getChipModel(),ESP.getChipCores(),ESP.getCpuFreqMHz());
	SerialDEBUG.println("***                 Firmware v0.0                ***");
	SerialDEBUG.println("====================================================");
	SerialDEBUG.println();

	// Memory Information
	SerialDEBUG.println("====================================================");
	SerialDEBUG.printf("Flash Memory: %d, at %d MHz \n",ESP.getFlashChipSize(),ESP.getFlashChipSpeed()/1000000);
	SerialDEBUG.println("====================================================");
	SerialDEBUG.printf("Internal RAM  size   : %u \n", ESP.getHeapSize());
	SerialDEBUG.printf("Internal RAM  free   : %u \n", ESP.getFreeHeap());
	SerialDEBUG.println("====================================================");
	SerialDEBUG.println();

  start = millis(); 

}

void loop() {

  u_int8_t p = isPrime(i);
  i++;

  if(i>MAXNUM){
    i = 2;
    SerialDEBUG.println(millis() - start);
    start = millis();
  }
    
}


u_int8_t isPrime(unsigned long x) {
  u_int8_t prime = true;
  
  for(int i = 2; i <= x/2; i++) {     // Loop up to half the number
    if(x % i == 0) {                  // Check if divisible
      prime = false;                  // NOT prime
      break;
    }
  }

  return prime;
}
