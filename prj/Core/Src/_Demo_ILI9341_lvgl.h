#include "MainApp.h"

// #include "paCoreInc/drv/paSPI.h"
#include "paCoreInc/all"
#include "paMods/display/ILI9341/pa_ILI9341.h"
#include "paMods/display/lvgl/lvgl.h"
#include "main.h"
struct App
{
    pa_ILI9341 lcd;

    /* data */
};
App app;

#define MY_DISP_HOR_RES 240
#define MY_DISP_VER_RES 320

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    int32_t bufSize = (area->x2 - area->x1) * (area->y2 - area->y1);
    /*It's a very slow but simple implementation.
     *`set_pixel` needs to be written by you to a set pixel on the screen*/
    app.lcd.transmitBuf((uint8_t *)color_p, bufSize * 2);
    // for (y = area->y1; y <= area->y2; y++)
    // {
    //     for (x = area->x1; x <= area->x2; x++)
    //     {
    //         set_pixel(x, y, *color_p);
    //         color_p++;
    //     }
    // }

    lv_disp_flush_ready(disp); /* Indicate you are ready with the flushing*/
}
void lv_app_init()
{
    static lv_disp_draw_buf_t draw_buf;
    static lv_color_t buf1[1]; /*Declare a buffer for 1/10 screen size*/
    sizeof(buf1);
    lv_disp_draw_buf_init(&draw_buf, buf1, NULL, MY_DISP_HOR_RES * MY_DISP_VER_RES / 10); /*Initialize the display buffer.*/

    lv_disp_drv_t disp_drv;             /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);        /*Basic initialization*/
    disp_drv.flush_cb = my_disp_flush;  /*Set your driver function*/
    disp_drv.draw_buf = &draw_buf;      /*Assign the buffer to the display*/
    disp_drv.hor_res = MY_DISP_HOR_RES; /*Set the horizontal resolution of the display*/
    disp_drv.hor_res = MY_DISP_VER_RES; /*Set the verizontal resolution of the display*/
    lv_disp_drv_register(&disp_drv);    /*Finally register the driver*/
}
void mainAppEntry()
{
    _G_paSPI.init(0);
    app.lcd.init(0, pa_ILI9341::Rotation_HORIZONTAL_1);
    /////////////////////////////////////////////////////////////
    lv_init();
    lv_app_init();
    //if lcd turned to black, it means success.
    while (1)
    {
        lv_tick_inc(1);
        /* USER CODE END WHILE */
        // // ESP_LOGI("App", "hello world!");
        _G_paBase.output("hello world");
        // // vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
        // HAL_Delay(1000);
        _G_paBase.delayMs(1);
    }
}