#include "MainApp.h"

// #include "paCoreInc/drv/paSPI.h"
#include "paCoreInc/all"
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
    _G_paSPI.init(0);
    app.lcd.init(0, pa_ILI9341::Rotation_HORIZONTAL_1);
    //if lcd turned to black, it means success.
    while (1)
    {
        /* USER CODE END WHILE */
        // // ESP_LOGI("App", "hello world!");
        _G_paBase.output("hello world");
        // // vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
        // HAL_Delay(1000);
        _G_paBase.delayMs(1000);
    }
}