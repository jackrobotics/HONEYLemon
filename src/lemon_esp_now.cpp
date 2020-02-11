#ifndef __HONEYLemon_ESP_NOW_CPP__
#define __HONEYLemon_ESP_NOW_CPP__

#include "HONEYLemon.h"

void HONEYLemon::setupESPNOW()
{
	WiFi.mode(WIFI_STA);

	if (esp_now_init() == ESP_OK)
		DEBUG_PRINTLN("ESPNow Init Success");
	else
		DEBUG_PRINTLN("ESPNow Init Failed");

	this->esp_now_slave.channel = 1;
	this->esp_now_slave.encrypt = 0;

	memcpy(this->esp_now_slave.peer_addr, this->esp_now_broadcastAddr, 6);
	ESP_ERROR_CHECK(esp_now_add_peer(&this->esp_now_slave));
};

bool HONEYLemon::espnow_broadcast(char *str)
{
	esp_err_t result = esp_now_send(this->esp_now_broadcastAddr, (uint8_t *)str, strlen(str));
	if (result == ESP_OK){
		DEBUG_PRINTLN("ESPNow->Send OK");
		return true;
	}else{
		DEBUG_PRINTLN("ESPNow->Send fail");
		return false;
	}
};

bool HONEYLemon::espnow_broadcast(String str) { return this->espnow_broadcast((char *)str.c_str()); };

bool HONEYLemon::espnow_send(char *mac, char *str)
{
	uint8_t _mac[6];
	uint8_t i = sscanf(mac, "%x:%x:%x:%x:%x:%x", (unsigned int *)&_mac[0], (unsigned int *)&_mac[1], (unsigned int *)&_mac[2], (unsigned int *)&_mac[3], (unsigned int *)&_mac[4], (unsigned int *)&_mac[5]);
	if (i != 6)
		return false;

	if (!esp_now_is_peer_exist(_mac))
	{
		memcpy(esp_now_slave.peer_addr, _mac, 6);
		ESP_ERROR_CHECK(esp_now_add_peer(&this->esp_now_slave));
	}

	if(strlen(str)>250){
		DEBUG_PRINTLN("ESPNow Error max 250 characters");
		return false;
	}

	esp_err_t result = esp_now_send(_mac, (uint8_t *)str, strlen(str));
	if (result == ESP_OK){
		DEBUG_PRINTLN("ESPNow->Send OK");
		return true;
	}else{
		DEBUG_PRINTLN("ESPNow->Send fail");
		return false;
	}
};

bool HONEYLemon::espnow_send(String mac, String str) { return espnow_send((char *)mac.c_str(), (char *)str.c_str()); };
#endif