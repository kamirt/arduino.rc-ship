// #include <G433_crc.h>
// #include <Gyver433.h>

// #define joyX A0
// #define joyY A1

// Gyver433_TX<2> tx;

// int previousData[2] {513, 519};
// int dataError {10};


// int button=2;
// void setup() {
//   pinMode(3,OUTPUT);
//   Serial.begin(9600);
// }
 
// void loop() {
    
//  int xValue = analogRead(joyX);
//  int yValue = analogRead(joyY);
 
//   Serial.print(xValue);
//   Serial.print("\t");
//   Serial.println(yValue);

//   bool xChanged = xValue <= previousData[0] - dataError || xValue >= previousData[0] + dataError;
//   bool yChanged = yValue <= previousData[1] - dataError || yValue >= previousData[1] + dataError;

//   if (xChanged || yChanged) {
//     char data[] = "HELLO";

//     // int data[2] { xValue, yValue };
//     tx.sendData(data);
//     previousData[0] = xValue;
//     previousData[1] = yValue;
//     Serial.println(">> Data sent");
//     Serial.println(data);
//   }
//   delay(50);
// }