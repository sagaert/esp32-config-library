#include <Arduino.h>
#include "esp32-config-lib.hpp"

esp32config::Configuration config("Example Config",{
	new esp32config::Namespace("First namespace", "ns1", {
		new esp32config::Entry("Text", esp32config::TEXT, "text", false, "Default text"),
		new esp32config::Entry("Textarea", esp32config::TEXTAREA, "multiline\ntext", false, "Default\ntext"),
		new esp32config::Entry("Secret", esp32config::PASSWORD, "secret", true, "Default secret"),
		new esp32config::Entry("Integer", esp32config::INTEGER, "num", false, "123")
	}),
    new esp32config::Namespace("Second namespace", "ns2", {
		new esp32config::Entry("Text", esp32config::TEXT, "text"),
		new esp32config::Entry("Textarea", esp32config::TEXTAREA, "multiline\ntext"),
		new esp32config::Entry("Secret", esp32config::PASSWORD, "secret"),
		new esp32config::Entry("Integer", esp32config::INTEGER, "num")
	})}
);

esp32config::Server configServer(config);

void setup()
{
	Serial.begin(115200);
	Serial.println();
	configServer.begin("My Device", "mysecret");
}

void loop()
{
	configServer.loop();
}
