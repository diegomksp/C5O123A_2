# Projeto de Sequência de LEDs Controlada por Botão

## Descrição
Este projeto implementa uma sequência de LEDs controlada por um botão utilizando um microcontrolador Raspberry Pi Pico. Quando o botão é pressionado, três LEDs (azul, vermelho e verde) são acionados em sequência, cada um permanecendo ligado por 3 segundos antes de ser desligado.

## Funcionamento
O código é escrito em C e utiliza a SDK do Raspberry Pi Pico para controlar os GPIOs e gerenciar temporizações. O comportamento do programa segue os seguintes passos:

1. **Inicialização dos GPIOs:**
   - Configura os pinos dos LEDs como saídas.
   - Configura o pino do botão como entrada com pull-up.

2. **Interrupção do Botão:**
   - Quando o botão é pressionado, uma interrupção chama a função `button_callback`.
   - A função verifica se a sequência de LEDs já está ativa. Se não estiver, inicia a sequência e agenda o desligamento dos LEDs.

3. **Sequência de Desligamento:**
   - O LED azul é desligado após 3 segundos e o desligamento do LED vermelho é agendado para mais 3 segundos.
   - O LED vermelho é desligado após 6 segundos e o desligamento do LED verde é agendado para mais 3 segundos.
   - O LED verde é desligado após 9 segundos, concluindo a sequência.

4. **Debounce do Botão:**
   - A função `debounce_button` evita leituras falsas devido a ruídos no sinal do botão.

## Estrutura do Código
- **Definição de Pinos:**
  - `LED_BLUE_PIN`, `LED_RED_PIN`, `LED_GREEN_PIN`: Pinos dos LEDs azul, vermelho e verde.
  - `BUTTON_PIN`: Pino do botão.
- **Variáveis Globais:**
  - `is_led_sequence_active`: Controla se a sequência está ativa.
- **Callbacks de Temporização:**
  - `turn_off_blue_callback`, `turn_off_red_callback`, `turn_off_green_callback`: Funções que desligam os LEDs e agendam o próximo desligamento.
- **Callback de Interrupção:**
  - `button_callback`: Função chamada quando o botão é pressionado, iniciando a sequência.
- **Função de Debounce:**
  - `debounce_button`: Filtra ruídos do botão.
- **Função Principal:**
  - `main`: Inicializa os GPIOs, configura a interrupção do botão e entra em um loop infinito.

## Como Usar
### Conectar os Componentes
- LEDs:
  - Azul: GPIO 11
  - Vermelho: GPIO 12
  - Verde: GPIO 13
- Botão:
  - Conectar ao GPIO 5 e ao terra (GND)

### Compilar e Carregar o Código
1. Instale a SDK do Raspberry Pi Pico.
2. Compile o código.
3. Carregue o firmware no Raspberry Pi Pico.

### Executar o Programa
- Pressione o botão para iniciar a sequência de LEDs.
- Cada LED permanecerá ligado por 3 segundos antes de desligar.

## Requisitos
- Raspberry Pi Pico
- LEDs (azul, vermelho e verde)
- Resistores de 220Ω para cada LED
- Botão
- Jumpers e protoboard

## Licença
Este projeto está licenciado sob a [MIT License](LICENSE). Você pode modificá-lo e distribuí-lo conforme necessário.

## Autor
Diego Mickael de Sá Pereira

