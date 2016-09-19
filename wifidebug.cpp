#include "Particle.h"

// To build:
// particle compile photon --target 0.4.9 wifidebug.cpp --saveTo wifidebug.bin

SYSTEM_MODE(MANUAL);
STARTUP(WiFi.selectAntenna(ANT_INTERNAL));

const char *securityString(int value); // forward declaration
void wifi_scan_callback(WiFiAccessPoint* wap, void* data); // forward declaration

const unsigned long reportPeriodMs = 10000;
unsigned long lastReport = 0;

void setup() {
	Serial.begin(9600);
	WiFi.on();

	WiFi.useDynamicIP();
}

void loop() {
	if (millis() - lastReport >= reportPeriodMs) {
		lastReport = millis();

		if (WiFi.hasCredentials()) {
			Serial.printlnf("configured credentials:");
			WiFiAccessPoint ap[5];
			int found = WiFi.getCredentials(ap, 5);
			for(int ii = 0; ii < found; ii++) {
				Serial.printlnf("ssid=%s security=%s cipher=%d", ap[ii].ssid, securityString(ap[ii].security), ap[ii].cipher);
			}
		}

		Serial.printlnf("available access points:");
		WiFi.scan(wifi_scan_callback);
	}
}

const char *securityString(int value) {
	const char *sec = "unknown";
	switch(value) {
	case WLAN_SEC_UNSEC:
		sec = "unsecured";
		break;

	case WLAN_SEC_WEP:
		sec = "wep";
		break;

	case WLAN_SEC_WPA:
		sec = "wpa";
		break;

	case WLAN_SEC_WPA2:
		sec = "wpa2";
		break;

	case WLAN_SEC_NOT_SET:
		sec = "not set";
		break;
	}
	return sec;
}

void wifi_scan_callback(WiFiAccessPoint* wap, void* data) {


	Serial.printlnf("SSID=%s security=%s channel=%d rssi=%d",
			wap->ssid, securityString(wap->security), wap->channel, wap->rssi);

}


