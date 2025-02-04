Projeto de Sequência de LEDs Controlada por Botão
Este projeto implementa uma sequência de LEDs controlada por um botão utilizando um microcontrolador Raspberry Pi Pico. Quando o botão é pressionado, três LEDs (azul, vermelho e verde) são acionados em sequência, cada um permanecendo ligado por 3 segundos antes de ser desligado.

Descrição do Código
O código é escrito em C e utiliza a SDK do Raspberry Pi Pico para controlar os GPIOs e gerenciar temporizações. O comportamento do programa é o seguinte:

Inicialização dos GPIOs:

Os pinos dos LEDs são configurados como saídas.

O pino do botão é configurado como entrada com pull-up.

Interrupção do Botão:

Quando o botão é pressionado, uma interrupção é acionada, chamando a função button_callback.

A função button_callback verifica se a sequência de LEDs já está ativa. Se não estiver, ela liga todos os LEDs e agenda o desligamento do LED azul após 3 segundos.

Sequência de Desligamento dos LEDs:

Após 3 segundos, o LED azul é desligado e o desligamento do LED vermelho é agendado para mais 3 segundos.

Após mais 3 segundos, o LED vermelho é desligado e o desligamento do LED verde é agendado para mais 3 segundos.

Finalmente, após mais 3 segundos, o LED verde é desligado e a sequência é considerada concluída.

Debounce do Botão:

A função debounce_button é usada para evitar leituras falsas devido a ruídos no sinal do botão.

Estrutura do Código
Definições dos Pinos:

LED_BLUE_PIN, LED_RED_PIN, LED_GREEN_PIN: Pinagens dos LEDs azul, vermelho e verde, respectivamente.

BUTTON_PIN: Pino do botão.

Variáveis Globais:

is_led_sequence_active: Controla se a sequência de LEDs está ativa.

Callbacks de Temporização:

turn_off_blue_callback, turn_off_red_callback, turn_off_green_callback: Funções que desligam os LEDs e agendam o próximo desligamento.

Callback de Interrupção:

button_callback: Função chamada quando o botão é pressionado, iniciando a sequência de LEDs.

Função de Debounce:

debounce_button: Função para evitar leituras falsas do botão.

Função Principal:

main: Inicializa os GPIOs, configura a interrupção do botão e entra em um loop infinito.

Como Usar
Conectar os Componentes:

Conecte os LEDs aos pinos GPIO 11 (azul), 12 (vermelho) e 13 (verde) do Raspberry Pi Pico.

Conecte o botão ao pino GPIO 5 e ao terra (GND).

Compilar e Carregar o Código:

Utilize a SDK do Raspberry Pi Pico para compilar o código e carregá-lo no microcontrolador.

Executar o Programa:

Ao pressionar o botão, a sequência de LEDs será iniciada, com cada LED permanecendo ligado por 3 segundos antes de ser desligado.

Requisitos
Raspberry Pi Pico

LEDs (azul, vermelho e verde)

Resistor (220Ω para cada LED)

Botão

Jumpers e protoboard

Licença
Este projeto é licenciado sob a licença MIT. Sinta-se à vontade para modificar e distribuir o código conforme necessário.

Autor
DIEGO MICKAEL DE SÁ PEREIRA

Agradecimentos
Agradeço à comunidade Raspberry Pi por fornecer uma plataforma acessível e poderosa para projetos de hardware e software.