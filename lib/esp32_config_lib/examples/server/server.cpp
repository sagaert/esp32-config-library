#include <Arduino.h>
#include "esp32-config-lib.hpp"

esp32config::Configuration config("Example Config",{
	new esp32config::Namespace("First namespace", "ns1", {
		new esp32config::Entry("Text", esp32config::TEXT, "text", "Default text"),
		new esp32config::Entry("Secret", esp32config::PASSWORD, "secret", "Default secret"),
		new esp32config::Entry("Integer", esp32config::INTEGER, "num", "123")
	}),
    new esp32config::Namespace("Second namespace", "ns2", {
		new esp32config::Entry("Text", esp32config::TEXT, "text"),
		new esp32config::Entry("Secret", esp32config::PASSWORD, "secret"),
		new esp32config::Entry("Integer", esp32config::INTEGER, "num")
	})}
);

esp32config::Server configServer(config);

void setup()
{
	Serial.begin(115200);
	Serial.println();
	configServer.begin();
}

void loop()
{
	configServer.loop();
}
