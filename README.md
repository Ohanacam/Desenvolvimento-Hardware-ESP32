# 🌐 Projeto: ESP32-C6 com Display ST7735 e Comunicação MQTT

Este projeto tem como objetivo a integração do microcontrolador **ESP32-C6** com um display **ST7735** e um servidor **MQTT**, permitindo a exibição em tempo real de mensagens recebidas via broker MQTT. O sistema demonstra a aplicação prática de conceitos de **Internet das Coisas (IoT)**, comunicação sem fio e interfaces gráficas.

---

## 🧰 Componentes e Tecnologias Utilizadas

### Hardware
- **ESP32-C6**
- **Display ST7735** (80x160 pixels, IPS)
- Conexões SPI para comunicação com o display
- Rede Wi-Fi para comunicação com o broker MQTT

### Software
- **Arduino IDE** (C/C++)
- Bibliotecas:
  - `WiFi.h`
  - `PubSubClient.h`
  - `SPI.h`
  - `Adafruit_GFX.h`
  - `Adafruit_ST7735.h`

### Serviços
- **Broker MQTT**: `broker.mqtt.cool`
- **Tópico MQTT**: `esp32/display`

---

## 🛠️ Funcionalidades

- ✅ Conexão Wi-Fi automática e reconexão em caso de falha
- ✅ Subscrição a um tópico MQTT
- ✅ Recebimento de mensagens via MQTT
- ✅ Exibição das mensagens no display ST7735 em tempo real
- ✅ Interface gráfica simples com inicialização e mensagens de status

---

## 📋 Pinagem (ESP32-C6 → ST7735)

| Função          | Pino ESP32-C6 | Descrição                     |
|------------------|---------------|-------------------------------|
| MOSI (Data)      | 7             | Dados para o display          |
| SCLK (Clock)     | 6             | Clock do SPI                  |
| CS (Chip Select) | 10            | Seleção do dispositivo        |
| DC (Data/Command)| 11            | Define dado ou comando        |
| RST (Reset)      | 8             | Reset do display              |
| VCC              | 3.3V          | Alimentação                   |
| GND              | GND           | Terra                         |
| BLK              | 3.3V          | Backlight                     |

---

## 🧩 Estrutura do Código

### Configurações Iniciais
- Inclusão das bibliotecas
- Definição dos pinos e parâmetros de rede
- Inicialização do display com mensagem “Iniciando...”

### Conexão Wi-Fi
- Função `setup_wifi()` para conectar à rede

### Cliente MQTT
- Configuração do broker e tópico
- Função `reconnect()` para tentar reconexão em caso de queda
- Callback para processar mensagens recebidas

### Exibição no Display
- Função `showMessage()` para limpar a tela e exibir texto

### Loop Principal
- Verificação contínua da conexão MQTT
- Processamento de novas mensagens

---

## 🎥 Demonstração

Confira o vídeo de demonstração do projeto em funcionamento:

👉 [Assistir no YouTube]([https://youtube.com/shorts/Ra8GyTvHJ6g?si=5Eppq5CFYIJX8614](https://youtube.com/shorts/Ra8GyTvHJ6g?feature=share))

No vídeo, é possível ver:
- Inicialização do display
- Recebimento de mensagens via MQTT
- Exibição em tempo real no display

---

## 📌 Resultados Obtidos

- Comunicação estável com broker MQTT
- Exibição confiável de mensagens no display
- Reconexão automática em caso de perda de comunicação
- Sistema funcional e escalável para projetos de IoT

---

## 📚 Referências

- [MakerHero - Display IPS LCD 0,96”](https://www.makerhero.com/blog/como-utilizar-o-display-ips-lcd-0-9-6-colorido/)
- [Instructables - Display para ESP32](https://www.instructables.com/Select-Color-Display-for-ESP32/)
- [Vida de Silício - ST7735 com NodeMCU](https://portal.vidasilicio.com.br/controlando-display-tft-st7735-nodemcu/)
- [Crescer Engenharia - MQTT com ESP32](https://www.crescerengenharia.com/post/mqtt-esp32)
- [Newton Braga - MQTT com ESP32](https://www.newtoncbraga.com.br/index.php/microcontroladores/143-tecnologia/17117-comunicando-se-via-mqtt-com-o-esp32-mic404.html)
- [Espressif - ESP32-C6 DevKitC-1](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32c6/esp32-c6-devkitc-1/user_guide.html)
- [Winstar - Display ST7735](https://www.winstar.com.tw/pt/products/tft-lcd/ips-tft/0_96-st7735.html)

---

## 👨‍💻 Autor

**Obana Camargo**  
Disciplina: Desenvolvimento de Aplicações Computacionais

---

Se você quiser, também posbo ajudar a criar um repositório modelo com essa descrição e uma estrutura de pastas organizada. 😊
