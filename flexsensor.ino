const int Flex_Pin = A0;

const float vdd = 4.98; //아두이노 5V 측정
const float r_div = 43000.0; //(저항 병렬연결을 해서 43K 짜리에 근사해서 사용)

const float straight_resi = 37300.0; //휘지 않고 똑바로 서있을때
const float bend_resi = 90000.0; //휨 정도가 90도 일때 저항
void setup()
{
  Serial.begin(9600);
  pinMode(Flex_Pin, INPUT);
}

void loop()
{
  //ADC 과정을 거친 후, 전압과 저항을 계산
  int flexADC = analogRead(Flex_Pin);
  float flexV = flexADC * vdd / 1023.0;
  float flexR = r_div * (vdd / flexV - 1.0);
  Serial.println("저항:" +String(flexR)+ "옴");
  //flex 센서의 휘어진 각도를 측정
  float angle = map(flexR, straight_resi,bend_resi, 0, 90.0);
  Serial.println("휘어짐:" +String(angle)+ "도");
  Serial.println();

  delay(500);
  
}

