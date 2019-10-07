#include "ets_sys.h"
#include "osapi.h"
#include "gpio.h"
#include "driver/gpio16.h"
#include "os_type.h"
#include "user_interface.h"
#include "espconn.h"
#include "mem.h"

#define SERIALBAUD 9600

#define SERVER_LOCAL_PORT         8080

LOCAL struct espconn esp_conn;
LOCAL esp_tcp esptcp;
LOCAL os_timer_t ip_test_timer;

const char index_html[] = \
        "<!DOCTYPE html>"\
        "<html>"\
        "<body>"\
            "<h1>ESP8266 HTTP server demo </h1>"\
        "</body>"\
        "</html>";

static os_timer_t blinky_timer;
static void blinky_timer_handler(void *prv);
static uint8 led_on = 0;

LOCAL void ICACHE_FLASH_ATTR http_resp(struct espconn *pespconn, int error, char *html_txt){
    char *buffer = NULL;
    int html_len = 0;

    buffer = (char*) os_malloc(256*sizeof(char));
    if(buffer != NULL){
        if(html_txt != NULL){
            html_len = os_strlen(html_txt);
        }
        else{
            html_len = 0;
        }

        os_sprintf(buffer, "HTTP/1.1 %d OK\r\n"
                                    "Content-Length: %d\r\n"
                                    "Content-Type: text/html\r\n"
                                    "Connection: Closed\r\n"
                                    "\r\n"
        ,error, html_len);

        if(html_len>0){
            buffer = (char*) os_realloc(buffer,(256+html_len)*sizeof(char));
            os_strcat(buffer,html_txt);
        }

        espconn_sent(pespconn,buffer,os_strlen(buffer));
        os_free(buffer);
    }
}

LOCAL void ICACHE_FLASH_ATTR tcp_server_sent_cb(void *arg){
    os_printf("tcp data sent\r\n");
}

LOCAL void ICACHE_FLASH_ATTR tcp_server_recv_cb(void *arg,char *pusrdata, unsigned short len){
    char *ptr = 0;

    struct espconn *pespconn = arg;
    ptr = (char*) os_strstr(pusrdata,"\r\n");
    ptr[0] = '\0';

// Define all HTTP request here
    if (os_strcmp(pusrdata, "GET / HTTP/1.1") == 0){
        http_resp(pespconn,200,(char*)index_html);
    }
    else{
        http_resp(pespconn,200,NULL);
    }
}

LOCAL void ICACHE_FLASH_ATTR tcp_server_disconn_cb(void *arg){
    os_printf("tcp disconnected\r\n");
}

LOCAL void ICACHE_FLASH_ATTR tcp_server_reconn_cb(void *arg,int8 err){
    os_printf("reconnecting, error code %d !!! \r\n",err);

}

LOCAL void ICACHE_FLASH_ATTR tcp_server_listen(void *arg){
    struct espconn *pesp_conn = arg;

    os_printf("tcp_server_listen !!! \r\n");

    espconn_regist_recvcb(pesp_conn, tcp_server_recv_cb);
    espconn_regist_sentcb(pesp_conn, tcp_server_sent_cb);

    espconn_regist_reconcb(pesp_conn, tcp_server_reconn_cb);
    espconn_regist_disconcb(pesp_conn, tcp_server_disconn_cb);
}

void ICACHE_FLASH_ATTR user_tcpserver_init(uint32 port){
    esp_conn.type = ESPCONN_TCP;
    esp_conn.state = ESPCONN_NONE;
    esp_conn.proto.tcp = &esptcp;
    esp_conn.proto.tcp->local_port = port;

    espconn_regist_connectcb(&esp_conn,tcp_server_listen);

    int8 ret = espconn_accept(&esp_conn);
    os_printf("espconn_accepted at [%d]\r\n", ret);
}

void ICACHE_FLASH_ATTR user_esp_platform_check_ip(void){
    struct ip_info ipconfig;

    os_timer_disarm(&ip_test_timer);

    wifi_get_ip_info(STATION_IF,&ipconfig);

    if(wifi_station_get_connect_status() == STATION_GOT_IP && ipconfig.ip.addr !=0 ){
        os_printf("got ip !!! \r\n");
        user_tcpserver_init(SERVER_LOCAL_PORT);
    }else{
        if (wifi_station_get_connect_status() == STATION_WRONG_PASSWORD ||
            wifi_station_get_connect_status() == STATION_NO_AP_FOUND ||
            wifi_station_get_connect_status() == STATION_CONNECT_FAIL){

            os_printf("connect fail !!! \r\n");
        }
        else{
            os_timer_setfn(&ip_test_timer, (os_timer_func_t *)user_esp_platform_check_ip, NULL);
            os_timer_arm(&ip_test_timer, 100, 0);
        }
    }
}

void ICACHE_FLASH_ATTR user_set_station_conf(void){
    char ssid[32] = "AchmadiGamePhone";
    char password[64] = "abu_musa2015";
    struct station_config stationConf;

    os_memset(stationConf.ssid, 0, 32);
    os_memset(stationConf.password, 0, 64);
    stationConf.bssid_set = 0;

    os_memcpy(&stationConf.ssid, ssid, 32);
    os_memcpy(&stationConf.password, password, 64);
    wifi_station_set_config(&stationConf);

    os_timer_disarm(&ip_test_timer);
    os_timer_setfn(&ip_test_timer, (os_timer_func_t *)user_esp_platform_check_ip, NULL);
    os_timer_arm(&ip_test_timer, 100, 0);
}

void ICACHE_FLASH_ATTR user_init(){
    uart_init(SERIALBAUD, SERIALBAUD);
    os_printf("\nSDK version:%s\n", system_get_sdk_version());
    os_printf("Serial Jalan OK\n");

    gpio_init();
    gpio16_output_conf();

    os_timer_setfn(&blinky_timer, (os_timer_func_t *)blinky_timer_handler, NULL);
    os_timer_arm(&blinky_timer, 500, 1);

    wifi_set_opmode(STATION_MODE);
    user_set_station_conf();
}

void blinky_timer_handler(void *prv){
  	if (led_on==1) {
    		gpio16_output_set(1);
    		led_on=0;
  	}
  	else {
    		gpio16_output_set(0);
    		led_on=1;
  	}
}
