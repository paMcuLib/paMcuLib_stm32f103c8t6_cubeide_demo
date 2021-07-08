#include "MainApp.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"

#include "paMods/display/SSD1306/pa_oled.h"
// #include "paCoreHead/paIIC.h"
// #include "paCoreHead/paBase.h"
#include "paCoreInc/drv/paSPI.h"
#include "paMods/display/ILI9341/pa_ILI9341.h"
#include "main.h"

struct App
{
    pa_ILI9341 lcd;
    /* data */
};
App app;

void mainAppEntry()
{
    // _G_paSPI.init(0);
    // app.lcd.init(0, pa_ILI9341::Rotation_HORIZONTAL_1);

    _G_paIIC.init(0);
    OLED_Init(0);
    // OLED_On();
    OLED_ShowString(0, 0, "121", 12);
    while (1)
    {
        // ESP_LOGI("App", "hello world!");
        _G_paBase.output("hello world");
        // vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
        HAL_Delay(1000);
    }
}