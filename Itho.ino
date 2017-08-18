//#######################################################################################################
//############################## Plugin 054: Itho ventilation unit 868Mhz remote ########################
//#######################################################################################################

// List of commands:
// JOIN to join ESP8266 with Itho ventilation unit
// LOW - set Itho ventilation unit to lowest speed
// MEDIUM - set Itho ventilation unit to medium speed
// HIGH - set Itho ventilation unit to max speed

// Usage (not case sensitive):
// http://ip/control?cmd=ITHOSEND,join
// http://ip/control?cmd=ITHOSEND,low
// http://ip/control?cmd=ITHOSEND,medium
// http://ip/control?cmd=ITHOSEND,high


//This code needs the library made by 'supersjimmie': https://github.com/supersjimmie/IthoEcoFanRFT/tree/master/Master/Itho
// A CC1101 868Mhz transmitter is needed
// See https://gathering.tweakers.net/forum/list_messages/1690945 for more information

#include <SPI.h>
#include "IthoCC1101.h"
#include "IthoPacket.h"
IthoCC1101 rf;
IthoPacket packet;

#define PLUGIN_054
#define PLUGIN_ID_054         54
#define PLUGIN_NAME_054       "Itho ventilation remote"
#define PLUGIN_VALUENAME1_054 ""
boolean Plugin_054(byte function, struct EventStruct *event, String& string)
{
	boolean success = false;

	switch (function)
	{

		case PLUGIN_DEVICE_ADD:
		{
			Device[++deviceCount].Number = PLUGIN_ID_054;
			break;
		}

		case PLUGIN_GET_DEVICENAME:
		{
			string = F(PLUGIN_NAME_054);
			break;
		}

		case PLUGIN_GET_DEVICEVALUENAMES:
		{
			break;
		}

		case PLUGIN_INIT:
		{
			rf.init();
			//rf.sendCommand(IthoJoin);
			addLog(LOG_LEVEL_INFO, F("CC1101 868Mhz transmitter initialized"));
			success = true;
			break;
		}

		case PLUGIN_WRITE: {

			String tmpString = string;

			String cmd = parseString(tmpString, 1);
			String param1 = parseString(tmpString, 2);


			if (cmd.equalsIgnoreCase(F("ITHOSEND")))
			{

				if (param1.equalsIgnoreCase(F("join")))
				{
					rf.sendCommand(IthoJoin);
					addLog(LOG_LEVEL_INFO, F("Sent command for 'join' to Itho unit"));
					printWebString += F("Sent command for 'join' to Itho unit");
					success = true;
				}

				if (param1.equalsIgnoreCase(F("leave")))
				{
					rf.sendCommand(IthoLeave);
					addLog(LOG_LEVEL_INFO, F("Sent command for 'leave' to Itho unit"));
					printWebString += F("Sent command for 'leave' to Itho unit");
					success = true;
				}

				if (param1.equalsIgnoreCase(F("low")))
				{
					rf.sendCommand(IthoLow);
					addLog(LOG_LEVEL_INFO, F("Sent command for 'low speed' to Itho unit"));
					printWebString += F("Sent command for 'low speed' to Itho unit");
					success = true;
				}

				if (param1.equalsIgnoreCase(F("medium")))
				{
					rf.sendCommand(IthoMedium);
					addLog(LOG_LEVEL_INFO, F("Sent command for 'medium speed' to Itho unit"));
					printWebString += F("Sent command for 'medium speed' to Itho unit");
					success = true;
				}

				if (param1.equalsIgnoreCase(F("high")))
				{
					rf.sendCommand(IthoFull);
					addLog(LOG_LEVEL_INFO, F("Sent command for 'full speed' to Itho unit"));
					printWebString += F("Sent command for 'full speed' to Itho unit");
					success = true;
				}

				if (param1.equalsIgnoreCase(F("timer1")))
				{
					rf.sendCommand(IthoTimer1);
					addLog(LOG_LEVEL_INFO, F("Sent command for 'timer 1' to Itho unit"));
					printWebString += F("Sent command for 'timer 1' to Itho unit");
					success = true;
				}				

				if (param1.equalsIgnoreCase(F("timer2")))
				{
					rf.sendCommand(IthoTimer2);
					addLog(LOG_LEVEL_INFO, F("Sent command for 'timer 2' to Itho unit"));
					printWebString += F("Sent command for 'timer 2' to Itho unit");
					success = true;
				}		

				if (param1.equalsIgnoreCase(F("timer3")))
				{
					rf.sendCommand(IthoTimer3);
					addLog(LOG_LEVEL_INFO, F("Sent command for 'timer 3' to Itho unit"));
					printWebString += F("Sent command for 'timer 3' to Itho unit");
					success = true;
				}	

			}
		}

	break;
	}
	return success;
}
