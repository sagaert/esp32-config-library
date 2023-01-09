#include <Arduino.h>
#include "esp32-config-lib.hpp"

String configStyle()
{
  return "body { background-color: cyan; }";
}

ConfigServer configServer({
	ConfigNamespace("First namespace", "ns1", {
		ConfigEntry("Text", TEXT, "text", "Default text"),
		ConfigEntry("Secret", PASSWORD, "secret", "Default secret"),
		ConfigEntry("Integer", INTEGER, "num", "123")
	}),
    ConfigNamespace("Second namespace", "ns2", {
		ConfigEntry("Text", TEXT, "text"),
		ConfigEntry("Secret", PASSWORD, "secret"),
		ConfigEntry("Integer", INTEGER, "num")
	})},
    &configStyle
);

ConfigCli configCLI({
	ConfigNamespace("First namespace", "ns1", {
		ConfigEntry("Text", TEXT, "text", "Default text"),
		ConfigEntry("Secret", PASSWORD, "secret", "Default secret"),
		ConfigEntry("Integer", INTEGER, "num", "123")
	}),
    ConfigNamespace("Second namespace", "ns2", {
		ConfigEntry("Text", TEXT, "text"),
		ConfigEntry("Secret", PASSWORD, "secret"),
		ConfigEntry("Integer", INTEGER, "num")
	})}
);

void setup()
{
	Serial.begin(115200);
	Serial.println();
	configCLI.begin(&Serial);
	configServer.begin();
}

void loop()
{
	configCLI.loop();
	configServer.loop();
}
