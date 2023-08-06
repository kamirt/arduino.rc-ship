#include <Arduino.h>
#include <Servo.h>

#define TROTTLE_TIME 500

/*
  Поворот осуществляется с помощью функции turn,
  при определении класса нужно передать не пин подключения сервомотора,
  начальное и конечное значение градусов поворота необходимых,
  а также начальное и конечное значение диапазона каких-либо значений,
  из которых пропорционально будет вычисляться поворот.
  Если будет задаваться поворот в граусах, но minValue и maxValue должны быть равны
  minDegrees и maxDegrees соответственно
*/
class ServoControl {
  public:
    ServoControl (byte pin, double minDegrees, double maxDegrees, double minValue, double maxValue) {
      _servo.attach(pin);
      Serial.println(_servo.attached());
      Serial.println(_servo.read());
      _servo.write(0);
      _currentDegrees = 45;
      _minValue = minValue;
      _maxValue = maxValue;
      _minDegrees = minDegrees;
      _maxDegrees = maxDegrees;
    }
    void turn(int value) {
      if (millis() - _tmr >= TROTTLE_TIME) {
        _tmr = millis();
        int degreeValue = round((value-_minValue)/(_maxValue-_minValue)*(_maxDegrees-_minDegrees)+_minDegrees);
        int previousDegrees = _servo.read();
        _currentDegrees = previousDegrees - degreeValue;
        Serial.println(previousDegrees);
        _servo.write(_currentDegrees);
        Serial.println(_servo.read());
      }
    }
  private:
    uint32_t _tmr;
    int _currentDegrees;
    double _minDegrees;
    double _maxDegrees;
    double _minValue;
    double _maxValue;
    Servo _servo;
};