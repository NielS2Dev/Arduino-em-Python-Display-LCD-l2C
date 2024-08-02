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
