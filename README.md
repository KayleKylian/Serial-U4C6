# Serial-U4C6

Tarefa de introdução à comunicação serial com RP2040 usando UART, I2C.

## Descrição do Projeto
Este projeto demonstra a utilização da comunicação serial com o microcontrolador RP2040, utilizando UART e I2C. O projeto inclui a leitura de caracteres via USB, controle de LEDs e exibição de informações em um display SSD1306 e uma matriz de LEDs WS2812B.

## Funcionalidades Principais
- **Leitura de Caracteres via USB:** Recebe caracteres via comunicação serial USB e exibe no console.
- **Controle de LEDs:** Alterna o estado dos LEDs verde e azul ao pressionar os botões A e B, respectivamente.
- **Exibição em Display SSD1306:** Exibe o caractere recebido e o estado dos LEDs em um display OLED SSD1306.
- **Exibição em Matriz de LEDs WS2812B:** Exibe números de 0 a 9 em uma matriz de LEDs 5x5.

## Vídeo Demonstração
[![Demonstração do Projeto realizado por Italo Cauã da Silva Santos](https://img.youtube.com/vi/4yq1NBuGysc/0.jpg)](https://www.youtube.com/watch?v=4yq1NBuGysc)

## Como Executar o Projeto

### Pré-requisitos
- Raspberry Pi Pico
- Cabo micro-USB
- Display SSD1306
- Matriz de LEDs WS2812B 5x5
- Ambiente de desenvolvimento configurado com suporte à linguagem C e CMake
- Ferramentas de compilação (como `cmake`)

### Passos para Compilação e Execução
1. Clone o repositório:
    ```sh
    git clone https://github.com/KayleKylian/Serial-U4C6.git
    cd Serial-U4C6
    ```

2. Crie um diretório de build e navegue até ele:
    ```sh
    mkdir build
    cd build
    ```

3. Configure e compile o projeto com CMake:
    ```sh
    cmake ..
    cmake --build .
    ```

4. Carregue o firmware na Raspberry Pi Pico:
    - Conecte a Raspberry Pi Pico ao seu computador via cabo micro-USB.
    - Pressione e segure o botão BOOTSEL na Raspberry Pi Pico e conecte-a ao computador.
    - Solte o botão BOOTSEL após a conexão.
    - Copie o arquivo `.uf2` gerado no diretório `build` para a unidade de armazenamento que aparecerá no seu computador.

5. O sistema deve começar a funcionar automaticamente após o upload do firmware.

## Tecnologia Utilizada
* Raspberry Pi Pico
* Linguagem de programação C
* CMake
* Display SSD1306
* Matriz de LEDs WS2812B

## Licença
Este projeto é licenciado sob a Licença MIT.
