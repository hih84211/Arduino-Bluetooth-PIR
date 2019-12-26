# Arduino-Bluetooth-PIR
## 材料
* Arduino uno x2
* 藍芽模組 x2
* PIR 感測器 x2
* LED 燈
* 電阻

## 功能說明
### 計數閃爍
#### 一顆PIR感測到動作後，對應的LED閃爍次數逐次增加
 * Sensor端感測到PIR的值，透過藍牙傳送到Reciever端，收到一次就LED亮一次，以此類推

### 兩顆PIR偵測
#### 兩顆PIR感測到後發送訊息至另一端讓相對應的LED亮
 * 兩顆PIR裝在Sensor端，兩顆PIR感測到的值傳送至另一端讓對應之LED燈亮
##### 例如：
  - pir1 偵測到有動，此時對應的LED燈亮起
  - pir2 偵測到有動，此時對應的LED燈亮起
  - pir1和pir2同時感測到，此時兩顆LED都要亮起
