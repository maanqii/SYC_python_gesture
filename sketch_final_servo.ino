#include <Servo.h>

Servo myServo;  // 创建一个舵机对象
int servoPin = 9;  // 连接舵机的引脚

void setup() {
  myServo.attach(servoPin);  // 将舵机连接到指定引脚
}

void loop() {
  // 等待从Python接收到的角度指令
  if (Serial.available() > 0) {
    int angle = Serial.parseInt();
    if (angle >= 0 && angle <= 180) {
      myServo.write(angle);  // 将舵机旋转到指定角度
    }
  }
}
