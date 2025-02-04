#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs e do botão
#define LED_BLUE_PIN    11
#define LED_RED_PIN     12
#define LED_GREEN_PIN   13
#define BUTTON_PIN      5

// Variável para controlar se a sequência de LEDs está ativa
volatile bool is_led_sequence_active = false;

// Callback para desligar o LED verde após um intervalo de tempo
int64_t turn_off_green_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_GREEN_PIN, 0);  // Desliga o LED verde
    is_led_sequence_active = false;  // Indica que a sequência de LEDs terminou
    return 0;  // Retorna 0 para indicar que o alarme não deve ser repetido
}

// Callback para desligar o LED vermelho após um intervalo de tempo
int64_t turn_off_red_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_RED_PIN, 0);  // Desliga o LED vermelho
    add_alarm_in_ms(3000, turn_off_green_callback, NULL, false);  // Agenda o desligamento do LED verde após 3 segundos
    return 0;  // Retorna 0 para indicar que o alarme não deve ser repetido
}

// Callback para desligar o LED azul após um intervalo de tempo
int64_t turn_off_blue_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_BLUE_PIN, 0);  // Desliga o LED azul
    add_alarm_in_ms(3000, turn_off_red_callback, NULL, false);  // Agenda o desligamento do LED vermelho após 3 segundos
    return 0;  // Retorna 0 para indicar que o alarme não deve ser repetido
}

// Callback para lidar com o evento de pressionar o botão
void button_callback(uint gpio, uint32_t events) {
    if (!is_led_sequence_active) {  // Verifica se a sequência de LEDs não está ativa
        is_led_sequence_active = true;  // Ativa a sequência de LEDs
        gpio_put(LED_BLUE_PIN, 1);  // Liga o LED azul
        gpio_put(LED_RED_PIN, 1);   // Liga o LED vermelho
        gpio_put(LED_GREEN_PIN, 1); // Liga o LED verde
        add_alarm_in_ms(3000, turn_off_blue_callback, NULL, false);  // Agenda o desligamento do LED azul após 3 segundos
    }
}

// Função para debounce do botão (evitar leituras falsas devido a ruídos)
bool debounce_button() {
    sleep_ms(50);  // Aguarda 50ms para estabilizar o sinal do botão
    return gpio_get(BUTTON_PIN) == 0;  // Retorna true se o botão ainda estiver pressionado
}

int main() {
    // Inicializa os pinos dos LEDs como saída
    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

    // Inicializa o pino do botão como entrada com pull-up
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    // Habilita a interrupção no pino do botão para detectar borda de descida (botão pressionado)
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    // Loop principal do programa
    while (true) {
        sleep_ms(100);  // Aguarda 100ms para reduzir o uso da CPU
    }
}