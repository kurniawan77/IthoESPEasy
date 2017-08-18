# IthoESPEasy

https://gathering.tweakers.net/forum/view_message/51762393

HTTP:
http://192.168.6.25/control?cmd=ITHOSEND,join
http://192.168.6.25/control?cmd=ITHOSEND,low
http://192.168.6.25/control?cmd=ITHOSEND,medium
http://192.168.6.25/control?cmd=ITHOSEND,high

MQTT:
mosquitto_pub -t /IthoRemote/cmd -m ithosend,join
mosquitto_pub -t /IthoRemote/cmd -m ithosend,low
mosquitto_pub -t /IthoRemote/cmd -m ithosend,medium
mosquitto_pub -t /IthoRemote/cmd -m ithosend,high

(mijn devicename is 'IthoRemote', kun je instellen via tabje 'Config' in de WebGUI).
Helaas nog niet kunnen ontdekken hoe ik kan zorgen voor terugkoppeling via MQTT.

Ik ben geen C/C++ programmeur, dus het zou kunnen dat er wat bugs in zitten. Uiteraard heb je wel de library van supersjimmie nodig.

Voor de luie mensen, hier een kant-en-klare binary: IthoRemote_ESPEasy2.0.bin (gebaseerd op ESPEasy 'Release v2.0.0-dev10') zodat je de Arduino IDE en libraries e.d. niet nodig hebt. Flashen kan met deze tools (uitpakken, .bin in dezelfde folder zetten en dan FlashESP8266.exe uitvoeren)

Enjoy! _/-\o_
