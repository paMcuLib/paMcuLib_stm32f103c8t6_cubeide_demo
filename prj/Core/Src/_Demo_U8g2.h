#include "MainApp.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"

// #include "paMods/display/SSD1306/pa_oled.h"
// #include "paCoreHead/paIIC.h"
// #include "paCoreHead/paBase.h"
// #include "paCoreInc/drv/paSPI.h"
// #include "paMods/display/ILI9341/pa_ILI9341.h"
#include "main.h"
// #include "paMods/display/u8g2/src/u8g2.h"
#include "paMods/display/u8g2/u8g2_paMcuLibPort_i2c_ssd1306.h"
// struct App
// {
//     pa_ILI9341 lcd;

//     /* data */
// };
// App app;

void mainAppEntry()
{
    // _G_paSPI.init(0);
    // app.lcd.init(0, pa_ILI9341::Rotation_HORIZONTAL_1);

    _G_paIIC.init(0);
    // HAL_Delay(10);

    u8g2_t u8g2; // a structure which will contain all the data for one display
    // u8g2_Setup_ssd1306_i2c_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_hw_i2c, STM32_gpio_and_delay); // init u8g2 structure
    u8g2_i2c_ssd1306_init(&u8g2, 0);
    u8g2_InitDisplay(&u8g2); // send init sequence to the display, display is in sleep mode after this,
    u8g2_SetPowerSave(&u8g2, 0);

    // OLED_Init(0);
    // OLED_On();
    // OLED_ShowString(0, 0, "121", 12);
    while (1)
    {
        /* USER CODE END WHILE */
        static int x = 30, y = 10;
        u8g2_ClearBuffer(&u8g2);
        u8g2_SetFont(&u8g2, u8g2_font_10x20_mf);
        u8g2_DrawStr(&u8g2, x, y, "u8g2");
        if (x >= 70)
        {
            x = y = 0;
        }
        else
        {
            x++;
            y++;
        }

        u8g2_SendBuffer(&u8g2);
        // // ESP_LOGI("App", "hello world!");
        // _G_paBase.output("hello world");
        // // vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
        // HAL_Delay(1000);
    }
}