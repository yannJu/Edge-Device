import paho.mqtt.client as mqtt
import json 
import time

client = mqtt.Client()
topic = "iot/yanjo/control"
control = {
    "led" : 1,
    "door" : "open"
}

value = json.dumps(control)

try:
    client.connect("localhost")
    while(True):
        client.publish(topic, value)

        client.loop(2)
        print("Publish Success -- ")
        time.sleep(3)
except Exception as e:
    print(f"Error : {e}")