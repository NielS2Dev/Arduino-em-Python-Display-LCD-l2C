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
