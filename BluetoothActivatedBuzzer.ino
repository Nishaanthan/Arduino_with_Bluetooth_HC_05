#include <SoftwareSerial.h>// import the serial library
const int buzzer = 9; //buzzer to arduino pin 9
 
SoftwareSerial BT(10, 11); // RX, TX
String BluetoothData; // the data given from Computer
int intBluetoothData;

void setup()
{
  // put your setup code here, to run once:
  BT.begin(9600);
  BT.println("Bluetooth On please Enter frequency to make sound ..");
  // Set buzzer - pin 9 as an output
  pinMode(buzzer, OUTPUT);
}
 
void loop()
{
  // put your main code here, to run repeatedly:
  if (BT.available())
  {
    BluetoothData=BT.readString();
    intBluetoothData = BluetoothData.toInt();
    BT.print("Input recieved : ");
    BT.println(intBluetoothData);
    if(intBluetoothData > 0)
    {
      // if number 1 pressed ....
      tone(buzzer, intBluetoothData ); // Send 10KHz sound signal...
      //delay(10);        // ...for 1 sec
      BT.println("Sending signals .... ");
      //types(BluetoothData);
    }
    if (intBluetoothData == 0)
    {
      // if number 0 Entered ....
      noTone(buzzer);     // Stop sound...
      BT.println("Stopped sending signals .... ");
    }
  }
delay(10);// prepare for next data ...
}
