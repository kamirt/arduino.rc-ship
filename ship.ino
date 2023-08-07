#include "Gyver433.h"

Gyver433_TX<2> tx;  // указали пин

void setup() {
}

char data[] = "xx"; // строка для отправки
byte count = 0; // счётчик для отправки

void loop() {
  // добавляем счётчик в строку
  data[0] = 234 + '0';
  data[1] = 98 + '0';
  if (++count >= 100) count = 0;
  tx.sendData(data);
  delay(100);
}