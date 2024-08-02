<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <p>
        <a href="https://www.youtube.com/@NielS2_Oficial" target="_blank" title="Visite meu canal no YouTube">
            <img src="https://img.shields.io/badge/YouTube-%40niels2_oficial-%23FF0000?style=plastic&logo=youtube&logoColor=white" alt="YouTube Video Views">
        </a>
        <a href="https://www.instagram.com/niels2_oficial/" target="_blank" title="Siga no Instagram">
            <img src="https://badgen.net/badge/icon/Instagram?icon=instagram&label=@niels2_oficial" alt="Instagram Followers">
        </a>
    </p>
</body>
</html>

+ NielS2🥰🥰🥰

> Status: Developing. O texto pode conter alguns erros e principalmente no código, como alguns vícios, pois sou novato. Mas, em geral, o projetinho está funcional! xD ⚠️⚠️⚠️

# Itens Utilizados.
+ Arduino Uno R3
+ Display LCD 16X2 I2C
+ Protoboard (Opcional)
+ Fios/Jump's

# 1º Como montar o circuito com o display junto ao Arduino.
![bandicam 2024-08-02 03-58-34-168](https://github.com/user-attachments/assets/4ee48fbe-4c60-4998-a03d-42863b6af592)

# 2º Carregar código no arduino (Primeiramente pela IDE do arduino).
### Por Que Carregar o Código Arduino Primeiro?
+ Configuração do Hardware: O código Arduino configura o display LCD e a comunicação serial. Sem essa configuração, o Arduino não saberá como interagir com o display e não estará preparado para receber dados da comunicação serial.
+ Preparação para Receber Dados: O código Arduino precisa estar pronto e em execução para processar os dados enviados pelo Python. Se você tentar enviar dados antes de carregar o código Arduino, o Arduino não terá a lógica necessária para lidar com os dados recebidos.
+ Comunicação Serial Estável: Carregar o código Arduino primeiro garante que a comunicação serial esteja configurada corretamente e que o Arduino esteja pronto para aceitar e processar as mensagens enviadas do Python.

![bandicam 2024-08-02 06-06-28-757](https://github.com/user-attachments/assets/ff8078b1-8b31-4a34-a228-ef9434d51983)

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');
    lcd.clear();
    displayMessage(message);
  }
}

void displayMessage(String message) {
  lcd.setCursor(0, 0);
  if (message.length() > 16) {
    lcd.print(message.substring(0, 16));
    lcd.setCursor(0, 1);
    lcd.print(message.substring(16));
  } else {
    lcd.print(message);
  }
}
```

# 3º Upar o código Python para o funcionamento do "Sistema".

```cpp
import serial
import time


arduino = serial.Serial('COM6', 9600) # Porta tem que ajustar de acordo com a porta do seu Arduino xD.
time.sleep(2)  

def send_message(message):
    arduino.write(f"{message}\n".encode('utf-8'))
    time.sleep(1)

if __name__ == "__main__":
    try:
        while True:
            msg = input("Digite a mensagem para o display (ou 'sair' para terminar): ")
            if msg.lower() == 'sair':
                break
            send_message(msg)
    except KeyboardInterrupt:
        print("Programa terminado pelo usuário.")
    finally:
        arduino.close()

```
![Imagem 1](https://github.com/user-attachments/assets/402a637f-1c8b-4635-a8ef-86b9dedf0c5b)


