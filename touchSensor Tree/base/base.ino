/*
  Arduino Wireless Network - Multiple NRF24L01 Tutorial
          == Base/ Master Node 00==
  by Dejan, www.HowToMechatronics.com
  Libraries:
  nRF24/RF24, https://github.com/nRF24/RF24
  nRF24/RF24Network, https://github.com/nRF24/RF24Network
*/

#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

RF24 radio(7,8);                 // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 00;   // Address of this node in Octal format ( 04,031, etc)

void setup() {
  SPI.begin();
  Serial.begin(9600);
  radio.begin();
  network.begin(80, this_node);       // (channel, node address)
  radio.setPALevel(RF24_PA_MAX);     // Power Level setting
}

int arr[20] = {0,};     // 받은 데이터를 저장할 변수. 
int tmp[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1};    // Serial.print가 값의 변경이 있을 때만 실행되게 하기 위한 임시 변수


void loop() {
  bool netstate;
  network.update();
  //===== Receiving =====//
  if ( netstate = network.available()) {     // Is there any incoming data?
    RF24NetworkHeader header;
    unsigned long incomingData;
    network.read(header, &incomingData, sizeof(incomingData));// Read the incoming data
      switch(incomingData){
        case 1: arr[0]++; break;
        case 2: arr[1]++; break;
        case 3: arr[2]++; break;
        case 4: arr[3]++; break;
        case 5: arr[4]++; break;
        case 6: arr[5]++; break;
        case 7: arr[6]++; break;
        case 8: arr[7]++; break;
        case 9: arr[8]++; break;
        case 10: arr[9]++; break;
        case 11: arr[10]++; break;
        case 12: arr[11]++; break;
        case 13: arr[12]++; break;
        case 14: arr[13]++; break;
        case 15: arr[14]++; break;
        case 16: arr[15]++; break;
        case 17: arr[16]++; break;
        case 18: arr[17]++; break;
        case 19: arr[18]++; break;
        case 20: arr[19]++; break;
      }
  }
  //===== Displaying =====//
  for(int i=0;i<20;i++){
     if (tmp[i] != arr[i]){     // tmp 값이 arr과 다른 경우에만 Serial.print 실행
       Serial.print(arr[0]);
       Serial.print('/');Serial.print(arr[1]);
       Serial.print('/');Serial.print(arr[2]);
       Serial.print('/');Serial.print(arr[3]);
       Serial.print('/');Serial.print(arr[4]);
       Serial.print('/');Serial.print(arr[5]);
       Serial.print('/');Serial.print(arr[6]);
       Serial.print('/');Serial.print(arr[7]);
       Serial.print('/');Serial.print(arr[8]);
       Serial.print('/');Serial.print(arr[9]);
       Serial.print('/');Serial.print(arr[10]);
       Serial.print('/');Serial.print(arr[11]);
       Serial.print('/');Serial.print(arr[12]);
       Serial.print('/');Serial.print(arr[13]);
       Serial.print('/');Serial.print(arr[14]);
       Serial.print('/');Serial.print(arr[15]);
       Serial.print('/');Serial.print(arr[16]);
       Serial.print('/');Serial.print(arr[17]);
       Serial.print('/');Serial.print(arr[18]);
       Serial.print('/');Serial.print(arr[19]);
       Serial.print('/');Serial.println();
               
       tmp[i]=arr[i];       // tmp 값을 arr 값과 같도록 갱신해서 계속 Serial.print하지 않도록 막음.
      }
   }

   //===== Resetting =====//
   if (Serial.available()){
    unsigned long reading = Serial.read();
    if( reading == true){
       arr[20]={0,};
       tmp[20] = {0,}; tmp[19] = {-1};  
      }
   }
}
