//2nd
1. sudo apt update
2. sudo apt install gcc
3. gcc --version
4. touch helloworld.c
5. gedit helloworld.c
  - write the c code in the gedit editor
 - save the code
6. gcc helloworld.c
7. ./a.out


//3rd
1. gcloud projects create project-id
2. gcloud projects list
1. gcloud config set project [project_id]
2. gcloud app create
3. git clone https://github.com/GoogleCloudPlatform/python-docs-samples
4. cd python-docs-samples/appengine/standard/hello_world/
5. dev_appserver.py app.yaml

// 4th

1. gcloud auth login
2. gcloud projects list
3. gcloud config set project nk-project-mei
4. gcloud app create
5. google-cloud-sdk\bin\dev_appserver.py "C:\Users\navee\OneDrive\Desktop\potti\google-app-engine-python-main"


//9th

docker pull sequenceiq/hadoop-docker:latest
docker run -it -p 50070:50070 -p 8088:8088 -p 8042:8042 sequenceiq/hadoop-docker:latest /etc/bootstrap.sh -bash
cd usr/local/hadoop
vi input/data.txt
bin/hadoop fs -mkdir /input
bin/hadoop fs -put input/data.txt /input
bin/hadoop jar share/hadoop/mapreduce/hadoop-mapreduce-examples-2.7.0.jar wordcount /input/data.txt /output
bin/hdfs dfs -cat /output/*




//10th

#define BLYNK_TEMPLATE_ID "TMPL3Qj1iNzZa"
#define BLYNK_TEMPLATE_NAME "Sample"
#define BLYNK_AUTH_TOKEN "1gp0B5cM2AEQQxzvVQg_GnrvRVgb6-mC"
#define BLYNK_PRINT Serial
#define LED 26
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHTesp.h>

char auth[] = BLYNK_AUTH_TOKEN ;

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

const int DHT_PIN = 15;
DHTesp dht;

BlynkTimer timer;


void sendSensor()
{
 TempAndHumidity  data = dht.getTempAndHumidity();


Serial.print("Temperature: ");
Serial.print(data.temperature);
Serial.println(" C ");
Serial.print("Humidity: ");
Serial.print(data.humidity);
Serial.println(" % ");

Blynk.virtualWrite(V0, data.temperature);
Blynk.virtualWrite(V1, data.humidity);
}

int SW_State=0;

BLYNK_WRITE (V2)
{
  SW_State = param.asInt();
  if (SW_State == 1)
  {
    digitalWrite(LED, HIGH);
    Serial.println("LAMP ON");
    Blynk.virtualWrite(V1, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
    Serial.println("LAMP OFF");
    Blynk.virtualWrite(V1, LOW);
  }
}


void setup()
{
// Debug console
Serial.begin(115200);
dht.setup(DHT_PIN, DHTesp::DHT22);

Blynk.begin(auth, ssid, pass);
timer.setInterval(1000, sendSensor);
pinMode(LED, OUTPUT);
}

void loop()
{

Blynk.run();
timer.run();
}
